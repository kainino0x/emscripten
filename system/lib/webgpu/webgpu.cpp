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
static __externref_t emwgpuTable_RenderPassEncoder[0];
EMSCRIPTEN_KEEPALIVE
static __externref_t emwgpuTable_RenderPipeline[0];

__externref_t emwgpuTable_RenderPassEncoder_Get(void* ptr_id) {
  uintptr_t id = reinterpret_cast<uintptr_t>(ptr_id);
  return __builtin_wasm_table_get(emwgpuTable_RenderPassEncoder, id);
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
  return reinterpret_cast<WGPUInstance>(1);
}

// Instance

void wgpuInstanceReference(WGPUInstance) { /* no-op for now */ }
void wgpuInstanceRelease(WGPUInstance) { /* no-op for now */ }

// Device

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

void wgpuRenderPassEncoderDraw(WGPURenderPassEncoder renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  emwgpuRenderPassEncoderDraw(pass, vertexCount, instanceCount, firstVertex, firstInstance);
}

void wgpuRenderPassEncoderSetPipeline(WGPURenderPassEncoder renderPassEncoder, WGPURenderPipeline renderPipeline) {
  __externref_t pass = emwgpuTable_RenderPassEncoder_Get(renderPassEncoder);
  __externref_t pipeline = emwgpuTable_RenderPipeline_Get(renderPassEncoder);
  emwgpuRenderPassEncoderSetPipeline(pass, pipeline);
}
