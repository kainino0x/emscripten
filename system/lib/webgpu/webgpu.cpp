/**
 * @license
 * Copyright 2023 The Emscripten Authors
 * SPDX-License-Identifier: MIT
 */

/*
 * This file and library_webgpu.js together implement <webgpu/webgpu.h>.
 */

#include <webgpu/webgpu.h>

#include <atomic>
#include <cassert>
#include <map>
#include <memory>
#include <utility>
#include <vector>

using FutureID = uint64_t;

//
// Declarations for JS emwgpu functions (defined in library_webgpu.js)
//

extern "C" {

void emwgpuAddRef(void* id);
void emwgpuRelease(void* id);
void emwgpuSetLabel(void* id, const char* label);
void emwgpuDestroy(void* id);

void emwgpuRequestAdapter(WGPUInstance instance, FutureID futureID, const WGPURequestAdapterOptions* options);

} // extern "C"

//
// Implementation helpers
//

// Shorthands for methods defined on many objects

#define DEFINE_ADDREF_RELEASE(Name) \
  void wgpu##Name##Reference(WGPU##Name o) { emwgpuAddRef(o); } \
  void wgpu##Name##Release(WGPU##Name o) { emwgpuRelease(o); }
#define DEFINE_SETLABEL(Name) \
  void wgpu##Name##SetLabel(WGPU##Name o, const char* label) { emwgpuSetLabel(o, label); }
#define DEFINE_DESTROY(Name) \
  void wgpu##Name##Destroy(WGPU##Name o) { emwgpuDestroy(o); }

// Memory management

// A base class to make a class non-copyable.
class NonCopyable {
  protected:
    constexpr NonCopyable() = default;
    ~NonCopyable() = default;

    NonCopyable(NonCopyable&&) = default;
    NonCopyable& operator=(NonCopyable&&) = default;

  private:
    NonCopyable(const NonCopyable&) = delete;
    void operator=(const NonCopyable&) = delete;
};

// A base class to make a class non-movable.
//class NonMovable : NonCopyable {
//  protected:
//    constexpr NonMovable() = default;
//    ~NonMovable() = default;
//
//  private:
//    NonMovable(NonMovable&&) = delete;
//    void operator=(NonMovable&&) = delete;
//};

// An object which is refcounted, but only managed by calling AddRef()/Release() explicitly.
class ManuallyRefCounted : public NonCopyable {
  public:
    ManuallyRefCounted() = default;
    virtual ~ManuallyRefCounted() = default;

    void AddRef() {
      ++mRefCount;
    }
    void Release() {
      uint64_t newRefCount = --mRefCount;
      if (newRefCount == 0) {
        delete this;
      }
    }
  protected:
    std::atomic<uint64_t> mRefCount{1};
};

// Futures

class TrackedEvent : public NonCopyable {
  public:
    virtual ~TrackedEvent() = default;

    virtual void Complete() && = 0;

    const WGPUCallbackMode mMode{};
    // True if the event is ready (but hasn't been completed yet).
    // If it gets completed, it will always be deleted immediately afterward.
    bool mReady = false;

  protected:
    explicit TrackedEvent(WGPUCallbackMode mode) : mMode(mode) {}
};

struct RequestAdapterEvent : public TrackedEvent {
    RequestAdapterEvent(WGPURequestAdapterCallbackInfo info)
      : TrackedEvent(info.mode), mCallback(info.callback), mUserdata(info.userdata) {}

    ~RequestAdapterEvent() override = default;

    void SetReady(WGPURequestAdapterStatus status, WGPUAdapter adapter, const char* message) {
      assert(!mReady);
      mReady = true;

      mStatus = status;
      mAdapter = adapter;
      mMessage = message;
    }

    void Complete() && override {
      assert(mReady);
      mCallback(mStatus, mAdapter, mMessage, mUserdata);
    }

    WGPURequestAdapterCallback const mCallback = nullptr;
    void* const mUserdata = nullptr;

    WGPURequestAdapterStatus mStatus{};
    WGPUAdapter mAdapter = nullptr;
    const char* mMessage = nullptr;
};

//
// WebGPU object definitions
//

struct WGPUInstanceImpl : public ManuallyRefCounted {
  public:
    void ProcessEvents() {
      for (FutureID futureID : mEventsReadyToProcess) {
        auto it = mTrackedEvents.find(futureID);
        if (it == mTrackedEvents.end()) {
          // The event must have completed already (via WaitAny).
          continue;
        }

        std::unique_ptr<TrackedEvent>& trackedEvent = it->second;
        std::move(*trackedEvent).Complete();
        mTrackedEvents.erase(it);
      }
    }

    WGPUWaitStatus WaitAny(size_t futureCount, WGPUFutureWaitInfo* futures, uint64_t timeoutNS) {
      if (timeoutNS > 0) {
        return WGPUWaitStatus_UnsupportedTimeout;
      }

      bool anyCompleted = false;
      for (size_t i = 0; i < futureCount; ++i) {
        WGPUFutureWaitInfo& info = futures[i];
        info.completed = false;

        auto it = mTrackedEvents.find(info.future.id);
        if (it == mTrackedEvents.end()) {
          // The event must have completed already.
          info.completed = true;
          anyCompleted = true;
          continue;
        }

        std::unique_ptr<TrackedEvent>& trackedEvent = it->second;
        if (trackedEvent->mReady) {
          std::move(*trackedEvent).Complete();
          mTrackedEvents.erase(it);
          info.completed = true;
          anyCompleted = true;
        }
      }

      return anyCompleted ? WGPUWaitStatus_Success : WGPUWaitStatus_TimedOut;
    }

    FutureID TrackEvent(std::unique_ptr<TrackedEvent>&& event) {
      FutureID futureID = mNextFutureID++;
      mTrackedEvents.emplace(futureID, std::move(event));
      return futureID;
    }

    template <typename Event, typename... ReadyArgs>
    void SetFutureReady(FutureID futureID, ReadyArgs&&... readyArgs) {
      auto it = mTrackedEvents.find(futureID);
      assert(it != mTrackedEvents.end()); // future is not tracked (already completed, or bogus id)
      std::unique_ptr<TrackedEvent>& trackedEvent = it->second;

      static_cast<Event*>(trackedEvent.get())->SetReady(std::forward<ReadyArgs>(readyArgs)...);

      switch (trackedEvent->mMode) {
        case WGPUCallbackMode_AllowSpontaneous:
          std::move(*trackedEvent).Complete();
          mTrackedEvents.erase(it);
          break;
        case WGPUCallbackMode_AllowProcessEvents:
          mEventsReadyToProcess.push_back(futureID);
          break;
        case WGPUCallbackMode_WaitAnyOnly:
        case WGPUCallbackMode_Force32:
          break;
      }
    }

  private:
    // TODO: Make this thread-safe
    std::map<FutureID, std::unique_ptr<TrackedEvent>> mTrackedEvents;
    std::atomic<FutureID> mNextFutureID{1};
    // List of AllowProcessEvents events that should complete in the next ProcessEvents call.
    std::vector<FutureID> mEventsReadyToProcess;
};

//
// Definitions for C++ emwgpu functions (callable from library_webgpu.js)
//

extern "C" {

void emwgpuOnRequestAdapterCompleted(WGPUInstance instance, FutureID futureID, WGPURequestAdapterStatus status, WGPUAdapter adapter, const char* message) {
  instance->SetFutureReady<RequestAdapterEvent>(futureID, status, adapter, message);
}

} // extern "C"

//
// WebGPU function definitions, with methods organized by "class"
//

// Standalone (non-method) functions

WGPUInstance wgpuCreateInstance(const WGPUInstanceDescriptor* descriptor) {
  assert(descriptor == nullptr); // descriptor not implemented yet
  return new WGPUInstanceImpl();
}

// Instance

void wgpuInstanceReference(WGPUInstance instance) { instance->AddRef(); }
void wgpuInstanceRelease(WGPUInstance instance) { instance->Release(); }

void wgpuInstanceProcessEvents(WGPUInstance instance) {
  instance->ProcessEvents();
}

WGPUWaitStatus wgpuInstanceWaitAny(WGPUInstance instance, size_t futureCount, WGPUFutureWaitInfo * futures, uint64_t timeoutNS) {
  return instance->WaitAny(futureCount, futures, timeoutNS);
}

WGPUFuture wgpuInstanceRequestAdapterF(WGPUInstance instance, WGPU_NULLABLE WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo callbackInfo) {
  FutureID futureID = instance->TrackEvent(std::make_unique<RequestAdapterEvent>(callbackInfo));
  emwgpuRequestAdapter(instance, futureID, options);
  return WGPUFuture{futureID};
}

void wgpuInstanceRequestAdapter(WGPUInstance instance, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallback callback, void * userdata) {
  WGPURequestAdapterCallbackInfo callbackInfo{};
  callbackInfo.mode = WGPUCallbackMode_AllowSpontaneous;
  callbackInfo.callback = callback;
  callbackInfo.userdata = userdata;
  wgpuInstanceRequestAdapterF(instance, options, callbackInfo);
}

// Surface

DEFINE_ADDREF_RELEASE(Surface)

// SwapChain

DEFINE_ADDREF_RELEASE(SwapChain)

// Adapter

DEFINE_ADDREF_RELEASE(Adapter)

// Device

DEFINE_ADDREF_RELEASE(Device)
DEFINE_SETLABEL(Device)
DEFINE_DESTROY(Device)

// Queue

DEFINE_ADDREF_RELEASE(Queue)
DEFINE_SETLABEL(Queue)

// CommandBuffer

DEFINE_ADDREF_RELEASE(CommandBuffer)
DEFINE_SETLABEL(CommandBuffer)

// CommandEncoder

DEFINE_ADDREF_RELEASE(CommandEncoder)
DEFINE_SETLABEL(CommandEncoder)

// RenderPassEncoder

DEFINE_ADDREF_RELEASE(RenderPassEncoder)
DEFINE_SETLABEL(RenderPassEncoder)

// ComputePassEncoder

DEFINE_ADDREF_RELEASE(ComputePassEncoder)
DEFINE_SETLABEL(ComputePassEncoder)

// BindGroup

DEFINE_ADDREF_RELEASE(BindGroup)
DEFINE_SETLABEL(BindGroup)

// Buffer

DEFINE_ADDREF_RELEASE(Buffer)
DEFINE_SETLABEL(Buffer)
// wgpuBufferDestroy is implemented in library_webgpu.js.

// Sampler

DEFINE_ADDREF_RELEASE(Sampler)
DEFINE_SETLABEL(Sampler)

// Texture

DEFINE_ADDREF_RELEASE(Texture)
DEFINE_SETLABEL(Texture)
DEFINE_DESTROY(Texture)

// TextureView

DEFINE_ADDREF_RELEASE(TextureView)
DEFINE_SETLABEL(TextureView)

// QuerySet

DEFINE_ADDREF_RELEASE(QuerySet)
DEFINE_SETLABEL(QuerySet)
DEFINE_DESTROY(QuerySet)

// BindGroupLayout

DEFINE_ADDREF_RELEASE(BindGroupLayout)
DEFINE_SETLABEL(BindGroupLayout)

// PipelineLayout

DEFINE_ADDREF_RELEASE(PipelineLayout)
DEFINE_SETLABEL(PipelineLayout)

// RenderPipeline

DEFINE_ADDREF_RELEASE(RenderPipeline)
DEFINE_SETLABEL(RenderPipeline)

// ComputePipeline

DEFINE_ADDREF_RELEASE(ComputePipeline)
DEFINE_SETLABEL(ComputePipeline)

// ShaderModule

DEFINE_ADDREF_RELEASE(ShaderModule)
DEFINE_SETLABEL(ShaderModule)

// RenderBundleEncoder

DEFINE_ADDREF_RELEASE(RenderBundleEncoder)
DEFINE_SETLABEL(RenderBundleEncoder)

// RenderBundle

DEFINE_ADDREF_RELEASE(RenderBundle)
DEFINE_SETLABEL(RenderBundle)
