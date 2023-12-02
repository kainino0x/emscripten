/**
 * @license
 * Copyright 2023 The Emscripten Authors
 * SPDX-License-Identifier: MIT
 */

/*
 * Implementation of webgpu.h + html5_webgpu.h over library_emwebgpu.js.
 */

#include <webgpu/webgpu.h>

#include <atomic>
#include <cassert>
#include <cstdint>

// FIXME
#include <cstdio>

using ObjID = uint64_t;
struct AdapterRequest;

// Declarations for library_emwebgpu.js
extern "C" {

void emwgpuSetLabel(ObjID id, const char* label);
void emwgpuDestroy(ObjID id);
void emwgpuDelete(ObjID id);

using WGPUBool = int32_t;
void emwgpuRequestAdapter(AdapterRequest* request, WGPUPowerPreference powerPreference, WGPUBool forceFallbackAdapter);


// Implementation helpers

#define DEFINE_REF_RELEASE(Name) \
  void wgpu##Name##Reference(WGPU##Name o) { o->Reference(); } \
  void wgpu##Name##Release(WGPU##Name o) { o->Release(); }

class ManuallyRefCounted {
  public:
    ManuallyRefCounted() = default;
    virtual ~ManuallyRefCounted() = default;

    void Reference() {
      ++mRefCount;
    }
    void Release() {
      uint64_t newRefCount = --mRefCount;
      if (newRefCount == 0) {
        OnBeforeDelete();
        delete this;
      }
    }
  protected:
    virtual void OnBeforeDelete() {}
    std::atomic<uint64_t> mRefCount{1};
  private:
    // Non-copyable
    ManuallyRefCounted(const ManuallyRefCounted&) = delete;
    void operator=(const ManuallyRefCounted&) = delete;
};

class ObjectFromInstance : public ManuallyRefCounted {
  public:
    ObjectFromInstance(WGPUInstance instance, ObjID id)
      : mInstance(instance), mHandle(id) {
      wgpuInstanceReference(mInstance);
    }
    virtual ~ObjectFromInstance() override {
      emwgpuDelete(mHandle);
    }
  private:
    WGPUInstance mInstance;
    ObjID mHandle;
};

struct AdapterRequest {
  WGPUInstance instance;
  WGPURequestAdapterCallback callback;
  void* userdata;
};

// WGPU object definitions

struct WGPUInstanceImpl : public ManuallyRefCounted {};

struct WGPUAdapterImpl : public ObjectFromInstance {
  using ObjectFromInstance::ObjectFromInstance;
};


// Implementations for JS->WASM calls back from library_emwebgpu.js

void emwgpuOnRequestAdapter(AdapterRequest* request, ObjID adapterHandle, WGPURequestAdapterStatus status) {
  WGPUAdapter adapter = nullptr;
  const char* message = nullptr;
  if (status == 0) {
    assert(adapterHandle);
    adapter = new WGPUAdapterImpl(request->instance, adapterHandle);
  } else {
    message = "failed";
  }
  request->callback(status, adapter, message, request->userdata);
  wgpuInstanceRelease(request->instance);
  delete request;
}

// Standalone functions

WGPUInstance wgpuCreateInstance(WGPUInstanceDescriptor const * descriptor) {
  return new WGPUInstanceImpl();
}

// Methods of Instance

DEFINE_REF_RELEASE(Instance);

void wgpuInstanceRequestAdapter(WGPUInstance instance, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallback callback, void * userdata) {
  wgpuInstanceReference(instance);
  auto* request = new AdapterRequest{instance, callback, userdata};
  WGPUPowerPreference powerPreference = WGPUPowerPreference_Undefined;
  WGPUBool forceFallbackAdapter = false;
  if (options) {
    powerPreference = options->powerPreference;
    forceFallbackAdapter = options->forceFallbackAdapter;
  }
  emwgpuRequestAdapter(request, powerPreference, forceFallbackAdapter);
}

// FIXME

void wgpuBufferRelease(WGPUBuffer) {}
WGPUBuffer wgpuDeviceCreateBuffer(WGPUDevice, WGPUBufferDescriptor const *) {
  return nullptr;
}
void wgpuDeviceRelease(WGPUDevice) {}

} // extern "C"
