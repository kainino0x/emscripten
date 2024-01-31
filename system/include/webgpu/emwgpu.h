/**
 * @license
 * Copyright 2024 The Emscripten Authors
 * SPDX-License-Identifier: MIT
 */

// Declarations for JS emwgpu functions (defined in library_webgpu.js).
// This should be included only from `webgpu.cpp` for now.

#include <webgpu/webgpu.h>
#include <emscripten/em_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

void emwgpu_console_log(__externref_t value);
__externref_t emwgpuGetHEAPU32();

__externref_t emwgpuDeviceCreateBindGroup(WGPUDevice device, WGPUBindGroupDescriptor const * descriptor, int * idOutPtr);
__externref_t emwgpuDeviceCreateRenderPipeline(WGPUDevice device, WGPURenderPipelineDescriptor const * descriptor, int * idOutPtr);

__externref_t emwgpuCommandEncoderBeginRenderPass(WGPUCommandEncoder commandEncoder, WGPURenderPassDescriptor const * descriptor, int * idOutPtr);

void emwgpuRenderPassEncoderNoOp_NoJS(__externref_t renderPassEncoder, uint32_t x);
void emwgpuRenderPassEncoderNoOp_JSByExternref(__externref_t renderPassEncoder, uint32_t x);
void emwgpuRenderPassEncoderNoOp_JSByIndex(WGPURenderPassEncoder renderPassEncoder, uint32_t x);
void emwgpuRenderPassEncoderMultiNoOp_LoopInJS_JSByExternref(__externref_t renderPassEncoder, uint32_t times, uint32_t x);
void emwgpuRenderPassEncoderDraw(__externref_t renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
void emwgpuRenderPassEncoderSetPipeline(__externref_t renderPassEncoder, __externref_t renderPipeline);
void emwgpuRenderPassEncoderSetBindGroupWithoutOffsets(__externref_t renderPassEncoder, uint32_t groupIndex, /*nullable*/ __externref_t bindGroup);
void emwgpuRenderPassEncoderSetBindGroupWithOffsets(__externref_t renderPassEncoder, uint32_t groupIndex, /*nullable*/ __externref_t bindGroup, __externref_t heapU32, double dynamicOffsetsDataStart, uint32_t dynamicOffsetsDataLength);

#ifdef __cplusplus
} // extern "C"
#endif
