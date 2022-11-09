#include "webgpu/webgpu.h"

#include <cassert>
#include <cstdio>
#include <vector>
#include <map>
#include <memory>
#include <emscripten.h>

// "Internal" library_webgpu.js functions

extern "C" {
WGPU_EXPORT WGPUBuffer js_wgpuDeviceCreateBuffer(WGPUDevice device, WGPUBufferDescriptor const * descriptor);
WGPU_EXPORT void js_readBuffer(WGPUBuffer buffer, size_t offset, size_t size, void * outData, WGPUBufferMapCallback callback, void * userdata);
}

// C++ internals

struct MappedRange {
    size_t offset = 0;
    size_t size;
};

struct BufferSidecar {
    WGPUQueue queue = nullptr;
    size_t size = 0;

    WGPUMapModeFlags currentMapMode = WGPUMapMode_None;
    size_t currentMapOffset = 0;
    // WASM heap memory for the mapping. Same size as mapAsync.
    std::vector<char> stage{};
    // Ranges to write on unmap, if writable. One for each getMappedRange.
    std::vector<MappedRange> mappedRanges{};
};

// TODO: Ideally we would just define a struct for WGPUBufferImpl here and put
// all the sidecar data in there, but doing so requires shimming every function
// that takes a WGPUBuffer as an argument. This is a temporary workaround so
// we don't have to do that.
// FIXME: This map doesn't get cleaned up at all right now, so it leaks.
// Fix by either doing the TODO above, or by cleaning it up on Release.
static std::map<WGPUBuffer, std::unique_ptr<BufferSidecar>> bufferSidecars{};

void implMap(BufferSidecar* sidecar, WGPUMapModeFlags mode, size_t offset, size_t size) {
    if (size == static_cast<size_t>(WGPU_WHOLE_SIZE)) {
        assert(offset <= sidecar->size);
        size = sidecar->size - offset;
    }

    sidecar->currentMapMode = mode;
    sidecar->currentMapOffset = offset;
    sidecar->stage = std::vector<char>(size);
}

// Implementation of webgpu.h

WGPUBuffer wgpuDeviceCreateBuffer(WGPUDevice device, WGPUBufferDescriptor const * descriptor) {
    assert(descriptor);

    WGPUBufferDescriptor desc = *descriptor;
    if (desc.mappedAtCreation ||
        (desc.usage & WGPUBufferUsage_MapWrite)) {
        desc.usage &= ~WGPUBufferUsage_MapWrite;
        desc.usage |= WGPUBufferUsage_CopyDst;
    }

    BufferSidecar* sidecar = new BufferSidecar;
    sidecar->queue = wgpuDeviceGetQueue(device);
    sidecar->size = desc.size;
    if (desc.mappedAtCreation) {
        implMap(sidecar, WGPUMapMode_Write, 0, static_cast<size_t>(WGPU_WHOLE_SIZE));
        desc.mappedAtCreation = false;
    }

    WGPUBuffer buffer = js_wgpuDeviceCreateBuffer(device, &desc);
    bufferSidecars[buffer] = std::unique_ptr<BufferSidecar>(sidecar);
    return buffer;
}

void wgpuBufferMapAsync(WGPUBuffer buffer, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallback callback, void * userdata) {
    BufferSidecar* sidecar = bufferSidecars[buffer].get();
    assert(sidecar->currentMapMode == 0);
    implMap(sidecar, mode, offset, size);

    struct CallbackData {
        WGPUBufferMapCallback callback;
        void* userdata;
    };
    CallbackData* cbdata = new CallbackData;
    cbdata->callback = callback;
    cbdata->userdata = userdata;

    if (mode == WGPUMapMode_Write) {
        emscripten_async_call([](void* vp_cbdata) {
            CallbackData* cbdata = static_cast<CallbackData*>(vp_cbdata);
            cbdata->callback(WGPUBufferMapAsyncStatus_Success, cbdata->userdata);
        }, cbdata, 0);
    } else if (mode == WGPUMapMode_Read) {
        js_readBuffer(buffer, offset, size, sidecar->stage.data(), [](WGPUBufferMapAsyncStatus status, void* vp_cbdata) {
            CallbackData* cbdata = static_cast<CallbackData*>(vp_cbdata);
            assert(status == WGPUBufferMapAsyncStatus_Success); // error case unimplemented
            cbdata->callback(status, cbdata->userdata);
            delete cbdata;
        }, cbdata);
    } else {
        assert(false);
    }
}

void * impl_wgpuBufferGetMappedRange(BufferSidecar* sidecar, size_t offset, size_t size) {
    assert(sidecar->currentMapMode);

    if (size == static_cast<size_t>(WGPU_WHOLE_SIZE)) {
        size = sidecar->stage.size();
    }
    if (sidecar->currentMapMode & WGPUMapMode_Write) {
        MappedRange range{};
        range.offset = offset;
        range.size = size;
        sidecar->mappedRanges.push_back(std::move(range));
    }

    assert(offset >= sidecar->currentMapOffset);
    return &sidecar->stage[offset - sidecar->currentMapOffset];
}

void * wgpuBufferGetMappedRange(WGPUBuffer buffer, size_t offset, size_t size) {
    BufferSidecar* sidecar = bufferSidecars[buffer].get();
    assert(sidecar->currentMapMode & WGPUMapMode_Write);
    return impl_wgpuBufferGetMappedRange(sidecar, offset, size);
}

void const * wgpuBufferGetConstMappedRange(WGPUBuffer buffer, size_t offset, size_t size) {
    BufferSidecar* sidecar = bufferSidecars[buffer].get();
    return impl_wgpuBufferGetMappedRange(sidecar, offset, size);
}

void wgpuBufferUnmap(WGPUBuffer buffer) {
    BufferSidecar* sidecar = bufferSidecars[buffer].get();
    if (sidecar->currentMapMode & WGPUMapMode_Write) {
        for (const MappedRange& range : sidecar->mappedRanges) {
            size_t relativeOffset = range.offset - sidecar->currentMapOffset;
            wgpuQueueWriteBuffer(sidecar->queue, buffer, range.offset, &sidecar->stage[relativeOffset], range.size);
        }
    }

    sidecar->currentMapMode = 0;
    sidecar->mappedRanges.clear(); // Frees all of the "stage" memory
}
