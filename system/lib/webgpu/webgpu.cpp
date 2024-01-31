// Copyright 2024 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.

//
// This file and library_webgpu.js together implement <webgpu/webgpu.h>.
//

#include <webgpu/emwgpu.h>
#include <webgpu/webgpu.h>

#include <cassert>
#include <cstdint>
#include <vector>

//
// FIXME: need a comment to explain externref stuff
// Documentation:
// - https://clang.llvm.org/docs/LanguageExtensions.html#webassembly-features
// - https://webassembly.github.io/spec/core/syntax/instructions.html#table-instructions
// - https://webassembly.github.io/spec/core/syntax/types.html#reference-types
// - https://webassembly.github.io/spec/core/syntax/modules.html#syntax-table
//

// FIXME: It would be nice to export this for direct access from JS, but not
// sure how. __attribute__((export_name(""))) is only allowed on functions
EMSCRIPTEN_KEEPALIVE
static __externref_t emwgpuTable_HEAPU32[0];
EMSCRIPTEN_KEEPALIVE
static __externref_t emwgpuTable_RenderPassEncoder[0];
EMSCRIPTEN_KEEPALIVE
static __externref_t emwgpuTable_BindGroup[0];
EMSCRIPTEN_KEEPALIVE
static __externref_t emwgpuTable_RenderPipeline[0];

__externref_t emwgpuTable_HEAPU32_Get() {
  return __builtin_wasm_table_get(emwgpuTable_HEAPU32, 0);
}

__externref_t emwgpuTable_RenderPassEncoder_Get(void* ptr_id) {
  uintptr_t id = reinterpret_cast<uintptr_t>(ptr_id);
  return __builtin_wasm_table_get(emwgpuTable_RenderPassEncoder, id);
}

__externref_t emwgpuTable_BindGroup_Get(void* ptr_id) {
  uintptr_t id = reinterpret_cast<uintptr_t>(ptr_id);
  return __builtin_wasm_table_get(emwgpuTable_BindGroup, id);
}

__externref_t emwgpuTable_RenderPipeline_Get(void* ptr_id) {
  uintptr_t id = reinterpret_cast<uintptr_t>(ptr_id);
  return __builtin_wasm_table_get(emwgpuTable_RenderPipeline, id);
}

//
// WebGPU function definitions, with methods organized by "class". Note these
// don't need to be extern "C" because they are already declared in webgpu.h.
//

// Standalone (non-method) functions

WGPUInstance wgpuCreateInstance(const WGPUInstanceDescriptor* descriptor) {
  assert(descriptor == nullptr); // descriptor not implemented yet

  if (__builtin_wasm_table_size(emwgpuTable_HEAPU32) < 1) {
    // FIXME: This assumes the heap will never be resized (invalidating HEAPU32)
    __externref_t heapU32 = emwgpuGetHEAPU32();
    __builtin_wasm_table_grow(emwgpuTable_HEAPU32, heapU32, 1);
  }
  return reinterpret_cast<WGPUInstance>(1);
}

// Instance

void wgpuInstanceReference(WGPUInstance) { /* no-op for now */ }
void wgpuInstanceRelease(WGPUInstance) { /* no-op for now */ }

// Device

WGPUBindGroup wgpuDeviceCreateBindGroup(WGPUDevice device, WGPUBindGroupDescriptor const * descriptor) {
  int tableIndex = 0;
  __externref_t obj = emwgpuDeviceCreateBindGroup(device, descriptor, &tableIndex);

  int currentTableSize = __builtin_wasm_table_size(emwgpuTable_BindGroup);
  if (tableIndex >= currentTableSize) {
    int growSize = tableIndex + 1 - currentTableSize;
    // We don't care what's in any of the other entries in the table so, out of
    // laziness, just fill the table with garbage.
    __builtin_wasm_table_grow(emwgpuTable_BindGroup, obj, growSize);
  } else {
    __builtin_wasm_table_set(emwgpuTable_BindGroup, tableIndex, obj);
  }

  return reinterpret_cast<WGPUBindGroup>(static_cast<uintptr_t>(tableIndex));
}

WGPURenderPipeline wgpuDeviceCreateRenderPipeline(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor) {
  int tableIndex = 0;
  __externref_t obj = emwgpuDeviceCreateRenderPipeline(device, descriptor, &tableIndex);

  int currentTableSize = __builtin_wasm_table_size(emwgpuTable_RenderPipeline);
  if (tableIndex >= currentTableSize) {
    int growSize = tableIndex + 1 - currentTableSize;
    // We don't care what's in any of the other entries in the table so, out of
    // laziness, just fill the table with garbage.
    __builtin_wasm_table_grow(emwgpuTable_RenderPipeline, obj, growSize);
  } else {
    __builtin_wasm_table_set(emwgpuTable_RenderPipeline, tableIndex, obj);
  }

  return reinterpret_cast<WGPURenderPipeline>(static_cast<uintptr_t>(tableIndex));
}

// CommandEncoder

WGPURenderPassEncoder wgpuCommandEncoderBeginRenderPass(WGPUCommandEncoder commandEncoder, WGPURenderPassDescriptor const * descriptor) {
  int tableIndex = 0;
  __externref_t obj = emwgpuCommandEncoderBeginRenderPass(commandEncoder, descriptor, &tableIndex);

  int currentTableSize = __builtin_wasm_table_size(emwgpuTable_RenderPassEncoder);
  if (tableIndex >= currentTableSize) {
    int growSize = tableIndex + 1 - currentTableSize;
    // We don't care what's in any of the other entries in the table so, out of
    // laziness, just fill the table with garbage.
    __builtin_wasm_table_grow(emwgpuTable_RenderPassEncoder, obj, growSize);
  } else {
    __builtin_wasm_table_set(emwgpuTable_RenderPassEncoder, tableIndex, obj);
  }

  return reinterpret_cast<WGPURenderPassEncoder>(static_cast<uintptr_t>(tableIndex));
}

// RenderPassEncoder

void wgpuRenderPassEncoderNoOp_NoJS(WGPURenderPassEncoder renderPassEncoder, uint32_t x) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  emwgpuRenderPassEncoderNoOp_NoJS(pass, x);
}
void wgpuRenderPassEncoderNoOp_JSByExternref(WGPURenderPassEncoder renderPassEncoder, uint32_t x) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  emwgpuRenderPassEncoderNoOp_JSByExternref(pass, x);
}
void wgpuRenderPassEncoderNoOp_JSByIndex(WGPURenderPassEncoder renderPassEncoder, uint32_t x) {
  emwgpuRenderPassEncoderNoOp_JSByIndex(renderPassEncoder, x);
}
void wgpuRenderPassEncoderMultiNoOp_LoopInJS_JSByExternref(WGPURenderPassEncoder renderPassEncoder, uint32_t times, uint32_t x) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  emwgpuRenderPassEncoderMultiNoOp_LoopInJS_JSByExternref(pass, times, x);
}
void wgpuRenderPassEncoderMultiNoOp_LoopInWasmManyLookup_NoJS(WGPURenderPassEncoder renderPassEncoder, uint32_t times, uint32_t x) {
  for (uint32_t i = 0; i < times; ++i) {
    __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
    emwgpuRenderPassEncoderNoOp_NoJS(pass, x);
  }
}
void wgpuRenderPassEncoderMultiNoOp_LoopInWasmManyLookup_JSByExternref(WGPURenderPassEncoder renderPassEncoder, uint32_t times, uint32_t x) {
  for (uint32_t i = 0; i < times; ++i) {
    __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
    emwgpuRenderPassEncoderNoOp_JSByExternref(pass, x);
  }
}
void wgpuRenderPassEncoderMultiNoOp_LoopInWasmSingleLookup_NoJS(WGPURenderPassEncoder renderPassEncoder, uint32_t times, uint32_t x) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  for (uint32_t i = 0; i < times; ++i) {
    emwgpuRenderPassEncoderNoOp_NoJS(pass, x);
  }
}
void wgpuRenderPassEncoderMultiNoOp_LoopInWasmSingleLookup_JSByExternref(WGPURenderPassEncoder renderPassEncoder, uint32_t times, uint32_t x) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  for (uint32_t i = 0; i < times; ++i) {
    emwgpuRenderPassEncoderNoOp_JSByExternref(pass, x);
  }
}

void wgpuRenderPassEncoderDraw(WGPURenderPassEncoder renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  emwgpuRenderPassEncoderDraw(pass, vertexCount, instanceCount, firstVertex, firstInstance);
}

void wgpuRenderPassEncoderSetPipeline(WGPURenderPassEncoder renderPassEncoder, WGPURenderPipeline renderPipeline) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  __externref_t pipeline = emwgpuTable_RenderPipeline_Get(renderPassEncoder);
  emwgpuRenderPassEncoderSetPipeline(pass, pipeline);
}

void wgpuRenderPassEncoderSetBindGroup(WGPURenderPassEncoder renderPassEncoder, uint32_t groupIndex, WGPU_NULLABLE WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  if (group == nullptr) {
    emwgpuRenderPassEncoderSetBindGroupWithoutOffsets(pass, groupIndex, __builtin_wasm_ref_null_extern());
    return;
  }

  __externref_t bg = emwgpuTable_BindGroup_Get(group);
  if (dynamicOffsetCount == 0) {
    emwgpuRenderPassEncoderSetBindGroupWithoutOffsets(pass, groupIndex, bg);
  } else {
    __externref_t heapU32 = emwgpuTable_HEAPU32_Get();
    uintptr_t dynamicOffsetsHeapOffset = reinterpret_cast<uintptr_t>(dynamicOffsets) >> 2;
    static constexpr double MAX_SAFE_INTEGER = 9007199254740991.0;
    assert(dynamicOffsetsHeapOffset < MAX_SAFE_INTEGER);
    emwgpuRenderPassEncoderSetBindGroupWithOffsets(pass, groupIndex, bg, heapU32, dynamicOffsetsHeapOffset, dynamicOffsetCount);
  }
}
