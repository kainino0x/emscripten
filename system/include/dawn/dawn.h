













#ifndef DAWN_DAWN_H_
#define DAWN_DAWN_H_

#include "dawn/dawn_export.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

const uint64_t DAWN_WHOLE_SIZE = 0xffffffffffffffffULL; // UINT64_MAX

typedef struct DawnBindGroupImpl* DawnBindGroup;
typedef struct DawnBindGroupLayoutImpl* DawnBindGroupLayout;
typedef struct DawnBufferImpl* DawnBuffer;
typedef struct DawnCommandBufferImpl* DawnCommandBuffer;
typedef struct DawnCommandEncoderImpl* DawnCommandEncoder;
typedef struct DawnComputePassEncoderImpl* DawnComputePassEncoder;
typedef struct DawnComputePipelineImpl* DawnComputePipeline;
typedef struct DawnDeviceImpl* DawnDevice;
typedef struct DawnFenceImpl* DawnFence;
typedef struct DawnPipelineLayoutImpl* DawnPipelineLayout;
typedef struct DawnQueueImpl* DawnQueue;
typedef struct DawnRenderBundleImpl* DawnRenderBundle;
typedef struct DawnRenderBundleEncoderImpl* DawnRenderBundleEncoder;
typedef struct DawnRenderPassEncoderImpl* DawnRenderPassEncoder;
typedef struct DawnRenderPipelineImpl* DawnRenderPipeline;
typedef struct DawnSamplerImpl* DawnSampler;
typedef struct DawnShaderModuleImpl* DawnShaderModule;
typedef struct DawnSwapChainImpl* DawnSwapChain;
typedef struct DawnTextureImpl* DawnTexture;
typedef struct DawnTextureViewImpl* DawnTextureView;

typedef enum {
    DAWN_ADDRESS_MODE_REPEAT = 0x00000000,
    DAWN_ADDRESS_MODE_MIRROR_REPEAT = 0x00000001,
    DAWN_ADDRESS_MODE_CLAMP_TO_EDGE = 0x00000002,
    DAWN_ADDRESS_MODE_FORCE32 = 0x7FFFFFFF
} DawnAddressMode;

typedef enum {
    DAWN_BINDING_TYPE_UNIFORM_BUFFER = 0x00000000,
    DAWN_BINDING_TYPE_STORAGE_BUFFER = 0x00000001,
    DAWN_BINDING_TYPE_READONLY_STORAGE_BUFFER = 0x00000002,
    DAWN_BINDING_TYPE_SAMPLER = 0x00000003,
    DAWN_BINDING_TYPE_SAMPLED_TEXTURE = 0x00000004,
    DAWN_BINDING_TYPE_STORAGE_TEXTURE = 0x00000005,
    DAWN_BINDING_TYPE_FORCE32 = 0x7FFFFFFF
} DawnBindingType;

typedef enum {
    DAWN_BLEND_FACTOR_ZERO = 0x00000000,
    DAWN_BLEND_FACTOR_ONE = 0x00000001,
    DAWN_BLEND_FACTOR_SRC_COLOR = 0x00000002,
    DAWN_BLEND_FACTOR_ONE_MINUS_SRC_COLOR = 0x00000003,
    DAWN_BLEND_FACTOR_SRC_ALPHA = 0x00000004,
    DAWN_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 0x00000005,
    DAWN_BLEND_FACTOR_DST_COLOR = 0x00000006,
    DAWN_BLEND_FACTOR_ONE_MINUS_DST_COLOR = 0x00000007,
    DAWN_BLEND_FACTOR_DST_ALPHA = 0x00000008,
    DAWN_BLEND_FACTOR_ONE_MINUS_DST_ALPHA = 0x00000009,
    DAWN_BLEND_FACTOR_SRC_ALPHA_SATURATED = 0x0000000A,
    DAWN_BLEND_FACTOR_BLEND_COLOR = 0x0000000B,
    DAWN_BLEND_FACTOR_ONE_MINUS_BLEND_COLOR = 0x0000000C,
    DAWN_BLEND_FACTOR_FORCE32 = 0x7FFFFFFF
} DawnBlendFactor;

typedef enum {
    DAWN_BLEND_OPERATION_ADD = 0x00000000,
    DAWN_BLEND_OPERATION_SUBTRACT = 0x00000001,
    DAWN_BLEND_OPERATION_REVERSE_SUBTRACT = 0x00000002,
    DAWN_BLEND_OPERATION_MIN = 0x00000003,
    DAWN_BLEND_OPERATION_MAX = 0x00000004,
    DAWN_BLEND_OPERATION_FORCE32 = 0x7FFFFFFF
} DawnBlendOperation;

typedef enum {
    DAWN_BUFFER_MAP_ASYNC_STATUS_SUCCESS = 0x00000000,
    DAWN_BUFFER_MAP_ASYNC_STATUS_ERROR = 0x00000001,
    DAWN_BUFFER_MAP_ASYNC_STATUS_UNKNOWN = 0x00000002,
    DAWN_BUFFER_MAP_ASYNC_STATUS_DEVICE_LOST = 0x00000003,
    DAWN_BUFFER_MAP_ASYNC_STATUS_FORCE32 = 0x7FFFFFFF
} DawnBufferMapAsyncStatus;

typedef enum {
    DAWN_COMPARE_FUNCTION_NEVER = 0x00000000,
    DAWN_COMPARE_FUNCTION_LESS = 0x00000001,
    DAWN_COMPARE_FUNCTION_LESS_EQUAL = 0x00000002,
    DAWN_COMPARE_FUNCTION_GREATER = 0x00000003,
    DAWN_COMPARE_FUNCTION_GREATER_EQUAL = 0x00000004,
    DAWN_COMPARE_FUNCTION_EQUAL = 0x00000005,
    DAWN_COMPARE_FUNCTION_NOT_EQUAL = 0x00000006,
    DAWN_COMPARE_FUNCTION_ALWAYS = 0x00000007,
    DAWN_COMPARE_FUNCTION_FORCE32 = 0x7FFFFFFF
} DawnCompareFunction;

typedef enum {
    DAWN_CULL_MODE_NONE = 0x00000000,
    DAWN_CULL_MODE_FRONT = 0x00000001,
    DAWN_CULL_MODE_BACK = 0x00000002,
    DAWN_CULL_MODE_FORCE32 = 0x7FFFFFFF
} DawnCullMode;

typedef enum {
    DAWN_ERROR_FILTER_NONE = 0x00000000,
    DAWN_ERROR_FILTER_VALIDATION = 0x00000001,
    DAWN_ERROR_FILTER_OUT_OF_MEMORY = 0x00000002,
    DAWN_ERROR_FILTER_FORCE32 = 0x7FFFFFFF
} DawnErrorFilter;

typedef enum {
    DAWN_ERROR_TYPE_NO_ERROR = 0x00000000,
    DAWN_ERROR_TYPE_VALIDATION = 0x00000001,
    DAWN_ERROR_TYPE_OUT_OF_MEMORY = 0x00000002,
    DAWN_ERROR_TYPE_UNKNOWN = 0x00000003,
    DAWN_ERROR_TYPE_DEVICE_LOST = 0x00000004,
    DAWN_ERROR_TYPE_FORCE32 = 0x7FFFFFFF
} DawnErrorType;

typedef enum {
    DAWN_FENCE_COMPLETION_STATUS_SUCCESS = 0x00000000,
    DAWN_FENCE_COMPLETION_STATUS_ERROR = 0x00000001,
    DAWN_FENCE_COMPLETION_STATUS_UNKNOWN = 0x00000002,
    DAWN_FENCE_COMPLETION_STATUS_DEVICE_LOST = 0x00000003,
    DAWN_FENCE_COMPLETION_STATUS_FORCE32 = 0x7FFFFFFF
} DawnFenceCompletionStatus;

typedef enum {
    DAWN_FILTER_MODE_NEAREST = 0x00000000,
    DAWN_FILTER_MODE_LINEAR = 0x00000001,
    DAWN_FILTER_MODE_FORCE32 = 0x7FFFFFFF
} DawnFilterMode;

typedef enum {
    DAWN_FRONT_FACE_CCW = 0x00000000,
    DAWN_FRONT_FACE_CW = 0x00000001,
    DAWN_FRONT_FACE_FORCE32 = 0x7FFFFFFF
} DawnFrontFace;

typedef enum {
    DAWN_INDEX_FORMAT_UINT16 = 0x00000000,
    DAWN_INDEX_FORMAT_UINT32 = 0x00000001,
    DAWN_INDEX_FORMAT_FORCE32 = 0x7FFFFFFF
} DawnIndexFormat;

typedef enum {
    DAWN_INPUT_STEP_MODE_VERTEX = 0x00000000,
    DAWN_INPUT_STEP_MODE_INSTANCE = 0x00000001,
    DAWN_INPUT_STEP_MODE_FORCE32 = 0x7FFFFFFF
} DawnInputStepMode;

typedef enum {
    DAWN_LOAD_OP_CLEAR = 0x00000000,
    DAWN_LOAD_OP_LOAD = 0x00000001,
    DAWN_LOAD_OP_FORCE32 = 0x7FFFFFFF
} DawnLoadOp;

typedef enum {
    DAWN_PRIMITIVE_TOPOLOGY_POINT_LIST = 0x00000000,
    DAWN_PRIMITIVE_TOPOLOGY_LINE_LIST = 0x00000001,
    DAWN_PRIMITIVE_TOPOLOGY_LINE_STRIP = 0x00000002,
    DAWN_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST = 0x00000003,
    DAWN_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP = 0x00000004,
    DAWN_PRIMITIVE_TOPOLOGY_FORCE32 = 0x7FFFFFFF
} DawnPrimitiveTopology;

typedef enum {
    DAWN_STENCIL_OPERATION_KEEP = 0x00000000,
    DAWN_STENCIL_OPERATION_ZERO = 0x00000001,
    DAWN_STENCIL_OPERATION_REPLACE = 0x00000002,
    DAWN_STENCIL_OPERATION_INVERT = 0x00000003,
    DAWN_STENCIL_OPERATION_INCREMENT_CLAMP = 0x00000004,
    DAWN_STENCIL_OPERATION_DECREMENT_CLAMP = 0x00000005,
    DAWN_STENCIL_OPERATION_INCREMENT_WRAP = 0x00000006,
    DAWN_STENCIL_OPERATION_DECREMENT_WRAP = 0x00000007,
    DAWN_STENCIL_OPERATION_FORCE32 = 0x7FFFFFFF
} DawnStencilOperation;

typedef enum {
    DAWN_STORE_OP_STORE = 0x00000000,
    DAWN_STORE_OP_CLEAR = 0x00000001,
    DAWN_STORE_OP_FORCE32 = 0x7FFFFFFF
} DawnStoreOp;

typedef enum {
    DAWN_TEXTURE_ASPECT_ALL = 0x00000000,
    DAWN_TEXTURE_ASPECT_STENCIL_ONLY = 0x00000001,
    DAWN_TEXTURE_ASPECT_DEPTH_ONLY = 0x00000002,
    DAWN_TEXTURE_ASPECT_FORCE32 = 0x7FFFFFFF
} DawnTextureAspect;

typedef enum {
    DAWN_TEXTURE_COMPONENT_TYPE_FLOAT = 0x00000000,
    DAWN_TEXTURE_COMPONENT_TYPE_SINT = 0x00000001,
    DAWN_TEXTURE_COMPONENT_TYPE_UINT = 0x00000002,
    DAWN_TEXTURE_COMPONENT_TYPE_FORCE32 = 0x7FFFFFFF
} DawnTextureComponentType;

typedef enum {
    DAWN_TEXTURE_DIMENSION_1D = 0x00000000,
    DAWN_TEXTURE_DIMENSION_2D = 0x00000001,
    DAWN_TEXTURE_DIMENSION_3D = 0x00000002,
    DAWN_TEXTURE_DIMENSION_FORCE32 = 0x7FFFFFFF
} DawnTextureDimension;

typedef enum {
    DAWN_TEXTURE_FORMAT_UNDEFINED = 0x00000000,
    DAWN_TEXTURE_FORMAT_R8_UNORM = 0x00000001,
    DAWN_TEXTURE_FORMAT_R8_SNORM = 0x00000002,
    DAWN_TEXTURE_FORMAT_R8_UINT = 0x00000003,
    DAWN_TEXTURE_FORMAT_R8_SINT = 0x00000004,
    DAWN_TEXTURE_FORMAT_R16_UINT = 0x00000005,
    DAWN_TEXTURE_FORMAT_R16_SINT = 0x00000006,
    DAWN_TEXTURE_FORMAT_R16_FLOAT = 0x00000007,
    DAWN_TEXTURE_FORMAT_RG8_UNORM = 0x00000008,
    DAWN_TEXTURE_FORMAT_RG8_SNORM = 0x00000009,
    DAWN_TEXTURE_FORMAT_RG8_UINT = 0x0000000A,
    DAWN_TEXTURE_FORMAT_RG8_SINT = 0x0000000B,
    DAWN_TEXTURE_FORMAT_R32_FLOAT = 0x0000000C,
    DAWN_TEXTURE_FORMAT_R32_UINT = 0x0000000D,
    DAWN_TEXTURE_FORMAT_R32_SINT = 0x0000000E,
    DAWN_TEXTURE_FORMAT_RG16_UINT = 0x0000000F,
    DAWN_TEXTURE_FORMAT_RG16_SINT = 0x00000010,
    DAWN_TEXTURE_FORMAT_RG16_FLOAT = 0x00000011,
    DAWN_TEXTURE_FORMAT_RGBA8_UNORM = 0x00000012,
    DAWN_TEXTURE_FORMAT_RGBA8_UNORM_SRGB = 0x00000013,
    DAWN_TEXTURE_FORMAT_RGBA8_SNORM = 0x00000014,
    DAWN_TEXTURE_FORMAT_RGBA8_UINT = 0x00000015,
    DAWN_TEXTURE_FORMAT_RGBA8_SINT = 0x00000016,
    DAWN_TEXTURE_FORMAT_BGRA8_UNORM = 0x00000017,
    DAWN_TEXTURE_FORMAT_BGRA8_UNORM_SRGB = 0x00000018,
    DAWN_TEXTURE_FORMAT_RGB10_A2_UNORM = 0x00000019,
    DAWN_TEXTURE_FORMAT_RG11_B10_FLOAT = 0x0000001A,
    DAWN_TEXTURE_FORMAT_RG32_FLOAT = 0x0000001B,
    DAWN_TEXTURE_FORMAT_RG32_UINT = 0x0000001C,
    DAWN_TEXTURE_FORMAT_RG32_SINT = 0x0000001D,
    DAWN_TEXTURE_FORMAT_RGBA16_UINT = 0x0000001E,
    DAWN_TEXTURE_FORMAT_RGBA16_SINT = 0x0000001F,
    DAWN_TEXTURE_FORMAT_RGBA16_FLOAT = 0x00000020,
    DAWN_TEXTURE_FORMAT_RGBA32_FLOAT = 0x00000021,
    DAWN_TEXTURE_FORMAT_RGBA32_UINT = 0x00000022,
    DAWN_TEXTURE_FORMAT_RGBA32_SINT = 0x00000023,
    DAWN_TEXTURE_FORMAT_DEPTH32_FLOAT = 0x00000024,
    DAWN_TEXTURE_FORMAT_DEPTH24_PLUS = 0x00000025,
    DAWN_TEXTURE_FORMAT_DEPTH24_PLUS_STENCIL8 = 0x00000026,
    DAWN_TEXTURE_FORMAT_BC1_RGBA_UNORM = 0x00000027,
    DAWN_TEXTURE_FORMAT_BC1_RGBA_UNORM_SRGB = 0x00000028,
    DAWN_TEXTURE_FORMAT_BC2_RGBA_UNORM = 0x00000029,
    DAWN_TEXTURE_FORMAT_BC2_RGBA_UNORM_SRGB = 0x0000002A,
    DAWN_TEXTURE_FORMAT_BC3_RGBA_UNORM = 0x0000002B,
    DAWN_TEXTURE_FORMAT_BC3_RGBA_UNORM_SRGB = 0x0000002C,
    DAWN_TEXTURE_FORMAT_BC4_R_UNORM = 0x0000002D,
    DAWN_TEXTURE_FORMAT_BC4_R_SNORM = 0x0000002E,
    DAWN_TEXTURE_FORMAT_BC5_RG_UNORM = 0x0000002F,
    DAWN_TEXTURE_FORMAT_BC5_RG_SNORM = 0x00000030,
    DAWN_TEXTURE_FORMAT_BC6H_RGB_UFLOAT = 0x00000031,
    DAWN_TEXTURE_FORMAT_BC6H_RGB_SFLOAT = 0x00000032,
    DAWN_TEXTURE_FORMAT_BC7_RGBA_UNORM = 0x00000033,
    DAWN_TEXTURE_FORMAT_BC7_RGBA_UNORM_SRGB = 0x00000034,
    DAWN_TEXTURE_FORMAT_FORCE32 = 0x7FFFFFFF
} DawnTextureFormat;

typedef enum {
    DAWN_TEXTURE_VIEW_DIMENSION_UNDEFINED = 0x00000000,
    DAWN_TEXTURE_VIEW_DIMENSION_1D = 0x00000001,
    DAWN_TEXTURE_VIEW_DIMENSION_2D = 0x00000002,
    DAWN_TEXTURE_VIEW_DIMENSION_2D_ARRAY = 0x00000003,
    DAWN_TEXTURE_VIEW_DIMENSION_CUBE = 0x00000004,
    DAWN_TEXTURE_VIEW_DIMENSION_CUBE_ARRAY = 0x00000005,
    DAWN_TEXTURE_VIEW_DIMENSION_3D = 0x00000006,
    DAWN_TEXTURE_VIEW_DIMENSION_FORCE32 = 0x7FFFFFFF
} DawnTextureViewDimension;

typedef enum {
    DAWN_VERTEX_FORMAT_UCHAR2 = 0x00000000,
    DAWN_VERTEX_FORMAT_UCHAR4 = 0x00000001,
    DAWN_VERTEX_FORMAT_CHAR2 = 0x00000002,
    DAWN_VERTEX_FORMAT_CHAR4 = 0x00000003,
    DAWN_VERTEX_FORMAT_UCHAR2_NORM = 0x00000004,
    DAWN_VERTEX_FORMAT_UCHAR4_NORM = 0x00000005,
    DAWN_VERTEX_FORMAT_CHAR2_NORM = 0x00000006,
    DAWN_VERTEX_FORMAT_CHAR4_NORM = 0x00000007,
    DAWN_VERTEX_FORMAT_USHORT2 = 0x00000008,
    DAWN_VERTEX_FORMAT_USHORT4 = 0x00000009,
    DAWN_VERTEX_FORMAT_SHORT2 = 0x0000000A,
    DAWN_VERTEX_FORMAT_SHORT4 = 0x0000000B,
    DAWN_VERTEX_FORMAT_USHORT2_NORM = 0x0000000C,
    DAWN_VERTEX_FORMAT_USHORT4_NORM = 0x0000000D,
    DAWN_VERTEX_FORMAT_SHORT2_NORM = 0x0000000E,
    DAWN_VERTEX_FORMAT_SHORT4_NORM = 0x0000000F,
    DAWN_VERTEX_FORMAT_HALF2 = 0x00000010,
    DAWN_VERTEX_FORMAT_HALF4 = 0x00000011,
    DAWN_VERTEX_FORMAT_FLOAT = 0x00000012,
    DAWN_VERTEX_FORMAT_FLOAT2 = 0x00000013,
    DAWN_VERTEX_FORMAT_FLOAT3 = 0x00000014,
    DAWN_VERTEX_FORMAT_FLOAT4 = 0x00000015,
    DAWN_VERTEX_FORMAT_UINT = 0x00000016,
    DAWN_VERTEX_FORMAT_UINT2 = 0x00000017,
    DAWN_VERTEX_FORMAT_UINT3 = 0x00000018,
    DAWN_VERTEX_FORMAT_UINT4 = 0x00000019,
    DAWN_VERTEX_FORMAT_INT = 0x0000001A,
    DAWN_VERTEX_FORMAT_INT2 = 0x0000001B,
    DAWN_VERTEX_FORMAT_INT3 = 0x0000001C,
    DAWN_VERTEX_FORMAT_INT4 = 0x0000001D,
    DAWN_VERTEX_FORMAT_FORCE32 = 0x7FFFFFFF
} DawnVertexFormat;

typedef enum {
    DAWN_BUFFER_USAGE_NONE = 0x00000000,
    DAWN_BUFFER_USAGE_MAP_READ = 0x00000001,
    DAWN_BUFFER_USAGE_MAP_WRITE = 0x00000002,
    DAWN_BUFFER_USAGE_COPY_SRC = 0x00000004,
    DAWN_BUFFER_USAGE_COPY_DST = 0x00000008,
    DAWN_BUFFER_USAGE_INDEX = 0x00000010,
    DAWN_BUFFER_USAGE_VERTEX = 0x00000020,
    DAWN_BUFFER_USAGE_UNIFORM = 0x00000040,
    DAWN_BUFFER_USAGE_STORAGE = 0x00000080,
    DAWN_BUFFER_USAGE_INDIRECT = 0x00000100,
    DAWN_BUFFER_USAGE_FORCE32 = 0x7FFFFFFF
} DawnBufferUsage;

typedef enum {
    DAWN_COLOR_WRITE_MASK_NONE = 0x00000000,
    DAWN_COLOR_WRITE_MASK_RED = 0x00000001,
    DAWN_COLOR_WRITE_MASK_GREEN = 0x00000002,
    DAWN_COLOR_WRITE_MASK_BLUE = 0x00000004,
    DAWN_COLOR_WRITE_MASK_ALPHA = 0x00000008,
    DAWN_COLOR_WRITE_MASK_ALL = 0x0000000F,
    DAWN_COLOR_WRITE_MASK_FORCE32 = 0x7FFFFFFF
} DawnColorWriteMask;

typedef enum {
    DAWN_SHADER_STAGE_NONE = 0x00000000,
    DAWN_SHADER_STAGE_VERTEX = 0x00000001,
    DAWN_SHADER_STAGE_FRAGMENT = 0x00000002,
    DAWN_SHADER_STAGE_COMPUTE = 0x00000004,
    DAWN_SHADER_STAGE_FORCE32 = 0x7FFFFFFF
} DawnShaderStage;

typedef enum {
    DAWN_TEXTURE_USAGE_NONE = 0x00000000,
    DAWN_TEXTURE_USAGE_COPY_SRC = 0x00000001,
    DAWN_TEXTURE_USAGE_COPY_DST = 0x00000002,
    DAWN_TEXTURE_USAGE_SAMPLED = 0x00000004,
    DAWN_TEXTURE_USAGE_STORAGE = 0x00000008,
    DAWN_TEXTURE_USAGE_OUTPUT_ATTACHMENT = 0x00000010,
    DAWN_TEXTURE_USAGE_PRESENT = 0x00000020,
    DAWN_TEXTURE_USAGE_FORCE32 = 0x7FFFFFFF
} DawnTextureUsage;


typedef struct DawnBindGroupBinding {
    uint32_t binding;
    DawnBuffer buffer;
    uint64_t offset;
    uint64_t size;
    DawnSampler sampler;
    DawnTextureView textureView;
} DawnBindGroupBinding;

typedef struct DawnBindGroupLayoutBinding {
    uint32_t binding;
    DawnShaderStage visibility;
    DawnBindingType type;
    bool hasDynamicOffset;
    bool multisampled;
    DawnTextureViewDimension textureDimension;
    DawnTextureComponentType textureComponentType;
} DawnBindGroupLayoutBinding;

typedef struct DawnBlendDescriptor {
    DawnBlendOperation operation;
    DawnBlendFactor srcFactor;
    DawnBlendFactor dstFactor;
} DawnBlendDescriptor;

typedef struct DawnBufferCopyView {
    const void* nextInChain;
    DawnBuffer buffer;
    uint64_t offset;
    uint32_t rowPitch;
    uint32_t imageHeight;
} DawnBufferCopyView;

typedef struct DawnBufferDescriptor {
    const void* nextInChain;
    DawnBufferUsage usage;
    uint64_t size;
} DawnBufferDescriptor;

typedef struct DawnColor {
    float r;
    float g;
    float b;
    float a;
} DawnColor;

typedef struct DawnCommandBufferDescriptor {
    const void* nextInChain;
    char const * label;
} DawnCommandBufferDescriptor;

typedef struct DawnCommandEncoderDescriptor {
    const void* nextInChain;
} DawnCommandEncoderDescriptor;

typedef struct DawnComputePassDescriptor {
    const void* nextInChain;
    char const * label;
} DawnComputePassDescriptor;

typedef struct DawnCreateBufferMappedResult {
    DawnBuffer buffer;
    uint64_t dataLength;
    void * data;
} DawnCreateBufferMappedResult;

typedef struct DawnExtent3D {
    uint32_t width;
    uint32_t height;
    uint32_t depth;
} DawnExtent3D;

typedef struct DawnFenceDescriptor {
    const void* nextInChain;
    uint64_t initialValue;
} DawnFenceDescriptor;

typedef struct DawnOrigin3D {
    uint32_t x;
    uint32_t y;
    uint32_t z;
} DawnOrigin3D;

typedef struct DawnPipelineLayoutDescriptor {
    const void* nextInChain;
    uint32_t bindGroupLayoutCount;
    DawnBindGroupLayout const * bindGroupLayouts;
} DawnPipelineLayoutDescriptor;

typedef struct DawnPipelineStageDescriptor {
    const void* nextInChain;
    DawnShaderModule module;
    char const * entryPoint;
} DawnPipelineStageDescriptor;

typedef struct DawnRasterizationStateDescriptor {
    const void* nextInChain;
    DawnFrontFace frontFace;
    DawnCullMode cullMode;
    int32_t depthBias;
    float depthBiasSlopeScale;
    float depthBiasClamp;
} DawnRasterizationStateDescriptor;

typedef struct DawnRenderBundleDescriptor {
    const void* nextInChain;
} DawnRenderBundleDescriptor;

typedef struct DawnRenderBundleEncoderDescriptor {
    const void* nextInChain;
    uint32_t colorFormatsCount;
    DawnTextureFormat const * colorFormats;
    DawnTextureFormat depthStencilFormat;
    uint32_t sampleCount;
} DawnRenderBundleEncoderDescriptor;

typedef struct DawnRenderPassDepthStencilAttachmentDescriptor {
    DawnTextureView attachment;
    DawnLoadOp depthLoadOp;
    DawnStoreOp depthStoreOp;
    float clearDepth;
    DawnLoadOp stencilLoadOp;
    DawnStoreOp stencilStoreOp;
    uint32_t clearStencil;
} DawnRenderPassDepthStencilAttachmentDescriptor;

typedef struct DawnSamplerDescriptor {
    const void* nextInChain;
    DawnAddressMode addressModeU;
    DawnAddressMode addressModeV;
    DawnAddressMode addressModeW;
    DawnFilterMode magFilter;
    DawnFilterMode minFilter;
    DawnFilterMode mipmapFilter;
    float lodMinClamp;
    float lodMaxClamp;
    DawnCompareFunction compare;
} DawnSamplerDescriptor;

typedef struct DawnShaderModuleDescriptor {
    const void* nextInChain;
    uint32_t codeSize;
    uint32_t const * code;
} DawnShaderModuleDescriptor;

typedef struct DawnStencilStateFaceDescriptor {
    DawnCompareFunction compare;
    DawnStencilOperation failOp;
    DawnStencilOperation depthFailOp;
    DawnStencilOperation passOp;
} DawnStencilStateFaceDescriptor;

typedef struct DawnSwapChainDescriptor {
    const void* nextInChain;
    uint64_t implementation;
} DawnSwapChainDescriptor;

typedef struct DawnTextureViewDescriptor {
    const void* nextInChain;
    DawnTextureFormat format;
    DawnTextureViewDimension dimension;
    uint32_t baseMipLevel;
    uint32_t mipLevelCount;
    uint32_t baseArrayLayer;
    uint32_t arrayLayerCount;
    DawnTextureAspect aspect;
} DawnTextureViewDescriptor;

typedef struct DawnVertexAttributeDescriptor {
    uint32_t shaderLocation;
    uint64_t offset;
    DawnVertexFormat format;
} DawnVertexAttributeDescriptor;

typedef struct DawnBindGroupDescriptor {
    const void* nextInChain;
    DawnBindGroupLayout layout;
    uint32_t bindingCount;
    DawnBindGroupBinding const * bindings;
} DawnBindGroupDescriptor;

typedef struct DawnBindGroupLayoutDescriptor {
    const void* nextInChain;
    uint32_t bindingCount;
    DawnBindGroupLayoutBinding const * bindings;
} DawnBindGroupLayoutDescriptor;

typedef struct DawnColorStateDescriptor {
    const void* nextInChain;
    DawnTextureFormat format;
    DawnBlendDescriptor alphaBlend;
    DawnBlendDescriptor colorBlend;
    DawnColorWriteMask writeMask;
} DawnColorStateDescriptor;

typedef struct DawnComputePipelineDescriptor {
    const void* nextInChain;
    DawnPipelineLayout layout;
    DawnPipelineStageDescriptor computeStage;
} DawnComputePipelineDescriptor;

typedef struct DawnDepthStencilStateDescriptor {
    const void* nextInChain;
    DawnTextureFormat format;
    bool depthWriteEnabled;
    DawnCompareFunction depthCompare;
    DawnStencilStateFaceDescriptor stencilFront;
    DawnStencilStateFaceDescriptor stencilBack;
    uint32_t stencilReadMask;
    uint32_t stencilWriteMask;
} DawnDepthStencilStateDescriptor;

typedef struct DawnRenderPassColorAttachmentDescriptor {
    DawnTextureView attachment;
    DawnTextureView resolveTarget;
    DawnLoadOp loadOp;
    DawnStoreOp storeOp;
    DawnColor clearColor;
} DawnRenderPassColorAttachmentDescriptor;

typedef struct DawnTextureCopyView {
    const void* nextInChain;
    DawnTexture texture;
    uint32_t mipLevel;
    uint32_t arrayLayer;
    DawnOrigin3D origin;
} DawnTextureCopyView;

typedef struct DawnTextureDescriptor {
    const void* nextInChain;
    DawnTextureUsage usage;
    DawnTextureDimension dimension;
    DawnExtent3D size;
    uint32_t arrayLayerCount;
    DawnTextureFormat format;
    uint32_t mipLevelCount;
    uint32_t sampleCount;
} DawnTextureDescriptor;

typedef struct DawnVertexBufferDescriptor {
    uint64_t stride;
    DawnInputStepMode stepMode;
    uint32_t attributeCount;
    DawnVertexAttributeDescriptor const * attributes;
} DawnVertexBufferDescriptor;

typedef struct DawnRenderPassDescriptor {
    uint32_t colorAttachmentCount;
    DawnRenderPassColorAttachmentDescriptor const * colorAttachments;
    DawnRenderPassDepthStencilAttachmentDescriptor const * depthStencilAttachment;
} DawnRenderPassDescriptor;

typedef struct DawnVertexInputDescriptor {
    const void* nextInChain;
    DawnIndexFormat indexFormat;
    uint32_t bufferCount;
    DawnVertexBufferDescriptor const * buffers;
} DawnVertexInputDescriptor;

typedef struct DawnRenderPipelineDescriptor {
    const void* nextInChain;
    DawnPipelineLayout layout;
    DawnPipelineStageDescriptor vertexStage;
    DawnPipelineStageDescriptor const * fragmentStage;
    DawnVertexInputDescriptor const * vertexInput;
    DawnPrimitiveTopology primitiveTopology;
    DawnRasterizationStateDescriptor const * rasterizationState;
    uint32_t sampleCount;
    DawnDepthStencilStateDescriptor const * depthStencilState;
    uint32_t colorStateCount;
    DawnColorStateDescriptor const * colorStates;
    uint32_t sampleMask;
    bool alphaToCoverageEnabled;
} DawnRenderPipelineDescriptor;


// Custom types depending on the target language
typedef void (*DawnErrorCallback)(DawnErrorType type, const char* message, void* userdata);
typedef void (*DawnBufferCreateMappedCallback)(DawnBufferMapAsyncStatus status,
                                               DawnCreateBufferMappedResult result,
                                               void* userdata);
typedef void (*DawnBufferMapReadCallback)(DawnBufferMapAsyncStatus status,
                                          const void* data,
                                          uint64_t dataLength,
                                          void* userdata);
typedef void (*DawnBufferMapWriteCallback)(DawnBufferMapAsyncStatus status,
                                           void* data,
                                           uint64_t dataLength,
                                           void* userdata);
typedef void (*DawnFenceOnCompletionCallback)(DawnFenceCompletionStatus status, void* userdata);

#ifdef __cplusplus
extern "C" {
#endif

// Procs of BindGroup
typedef void (*DawnProcBindGroupReference)(DawnBindGroup bindGroup);
typedef void (*DawnProcBindGroupRelease)(DawnBindGroup bindGroup);

// Procs of BindGroupLayout
typedef void (*DawnProcBindGroupLayoutReference)(DawnBindGroupLayout bindGroupLayout);
typedef void (*DawnProcBindGroupLayoutRelease)(DawnBindGroupLayout bindGroupLayout);

// Procs of Buffer
typedef void (*DawnProcBufferSetSubData)(DawnBuffer buffer, uint64_t start, uint64_t count, void const * data);
typedef void (*DawnProcBufferUnmap)(DawnBuffer buffer);
typedef void (*DawnProcBufferDestroy)(DawnBuffer buffer);
typedef void (*DawnProcBufferMapReadAsync)(DawnBuffer buffer, DawnBufferMapReadCallback callback, void * userdata);
typedef void (*DawnProcBufferMapWriteAsync)(DawnBuffer buffer, DawnBufferMapWriteCallback callback, void * userdata);
typedef void (*DawnProcBufferReference)(DawnBuffer buffer);
typedef void (*DawnProcBufferRelease)(DawnBuffer buffer);

// Procs of CommandBuffer
typedef void (*DawnProcCommandBufferReference)(DawnCommandBuffer commandBuffer);
typedef void (*DawnProcCommandBufferRelease)(DawnCommandBuffer commandBuffer);

// Procs of CommandEncoder
typedef DawnCommandBuffer (*DawnProcCommandEncoderFinish)(DawnCommandEncoder commandEncoder, DawnCommandBufferDescriptor const * descriptor);
typedef DawnComputePassEncoder (*DawnProcCommandEncoderBeginComputePass)(DawnCommandEncoder commandEncoder, DawnComputePassDescriptor const * descriptor);
typedef DawnRenderPassEncoder (*DawnProcCommandEncoderBeginRenderPass)(DawnCommandEncoder commandEncoder, DawnRenderPassDescriptor const * descriptor);
typedef void (*DawnProcCommandEncoderCopyBufferToBuffer)(DawnCommandEncoder commandEncoder, DawnBuffer source, uint64_t sourceOffset, DawnBuffer destination, uint64_t destinationOffset, uint64_t size);
typedef void (*DawnProcCommandEncoderCopyBufferToTexture)(DawnCommandEncoder commandEncoder, DawnBufferCopyView const * source, DawnTextureCopyView const * destination, DawnExtent3D const * copySize);
typedef void (*DawnProcCommandEncoderCopyTextureToBuffer)(DawnCommandEncoder commandEncoder, DawnTextureCopyView const * source, DawnBufferCopyView const * destination, DawnExtent3D const * copySize);
typedef void (*DawnProcCommandEncoderCopyTextureToTexture)(DawnCommandEncoder commandEncoder, DawnTextureCopyView const * source, DawnTextureCopyView const * destination, DawnExtent3D const * copySize);
typedef void (*DawnProcCommandEncoderInsertDebugMarker)(DawnCommandEncoder commandEncoder, char const * groupLabel);
typedef void (*DawnProcCommandEncoderPopDebugGroup)(DawnCommandEncoder commandEncoder);
typedef void (*DawnProcCommandEncoderPushDebugGroup)(DawnCommandEncoder commandEncoder, char const * groupLabel);
typedef void (*DawnProcCommandEncoderReference)(DawnCommandEncoder commandEncoder);
typedef void (*DawnProcCommandEncoderRelease)(DawnCommandEncoder commandEncoder);

// Procs of ComputePassEncoder
typedef void (*DawnProcComputePassEncoderInsertDebugMarker)(DawnComputePassEncoder computePassEncoder, char const * groupLabel);
typedef void (*DawnProcComputePassEncoderPopDebugGroup)(DawnComputePassEncoder computePassEncoder);
typedef void (*DawnProcComputePassEncoderPushDebugGroup)(DawnComputePassEncoder computePassEncoder, char const * groupLabel);
typedef void (*DawnProcComputePassEncoderSetPipeline)(DawnComputePassEncoder computePassEncoder, DawnComputePipeline pipeline);
typedef void (*DawnProcComputePassEncoderSetBindGroup)(DawnComputePassEncoder computePassEncoder, uint32_t groupIndex, DawnBindGroup group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets);
typedef void (*DawnProcComputePassEncoderDispatch)(DawnComputePassEncoder computePassEncoder, uint32_t x, uint32_t y, uint32_t z);
typedef void (*DawnProcComputePassEncoderDispatchIndirect)(DawnComputePassEncoder computePassEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
typedef void (*DawnProcComputePassEncoderEndPass)(DawnComputePassEncoder computePassEncoder);
typedef void (*DawnProcComputePassEncoderReference)(DawnComputePassEncoder computePassEncoder);
typedef void (*DawnProcComputePassEncoderRelease)(DawnComputePassEncoder computePassEncoder);

// Procs of ComputePipeline
typedef void (*DawnProcComputePipelineReference)(DawnComputePipeline computePipeline);
typedef void (*DawnProcComputePipelineRelease)(DawnComputePipeline computePipeline);

// Procs of Device
typedef DawnBindGroup (*DawnProcDeviceCreateBindGroup)(DawnDevice device, DawnBindGroupDescriptor const * descriptor);
typedef DawnBindGroupLayout (*DawnProcDeviceCreateBindGroupLayout)(DawnDevice device, DawnBindGroupLayoutDescriptor const * descriptor);
typedef DawnBuffer (*DawnProcDeviceCreateBuffer)(DawnDevice device, DawnBufferDescriptor const * descriptor);
typedef DawnCreateBufferMappedResult (*DawnProcDeviceCreateBufferMapped)(DawnDevice device, DawnBufferDescriptor const * descriptor);
typedef DawnCommandEncoder (*DawnProcDeviceCreateCommandEncoder)(DawnDevice device, DawnCommandEncoderDescriptor const * descriptor);
typedef DawnComputePipeline (*DawnProcDeviceCreateComputePipeline)(DawnDevice device, DawnComputePipelineDescriptor const * descriptor);
typedef DawnRenderPipeline (*DawnProcDeviceCreateRenderPipeline)(DawnDevice device, DawnRenderPipelineDescriptor const * descriptor);
typedef DawnPipelineLayout (*DawnProcDeviceCreatePipelineLayout)(DawnDevice device, DawnPipelineLayoutDescriptor const * descriptor);
typedef DawnQueue (*DawnProcDeviceCreateQueue)(DawnDevice device);
typedef DawnRenderBundleEncoder (*DawnProcDeviceCreateRenderBundleEncoder)(DawnDevice device, DawnRenderBundleEncoderDescriptor const * descriptor);
typedef DawnSampler (*DawnProcDeviceCreateSampler)(DawnDevice device, DawnSamplerDescriptor const * descriptor);
typedef DawnShaderModule (*DawnProcDeviceCreateShaderModule)(DawnDevice device, DawnShaderModuleDescriptor const * descriptor);
typedef DawnSwapChain (*DawnProcDeviceCreateSwapChain)(DawnDevice device, DawnSwapChainDescriptor const * descriptor);
typedef DawnTexture (*DawnProcDeviceCreateTexture)(DawnDevice device, DawnTextureDescriptor const * descriptor);
typedef void (*DawnProcDeviceTick)(DawnDevice device);
typedef void (*DawnProcDevicePushErrorScope)(DawnDevice device, DawnErrorFilter filter);
typedef void (*DawnProcDeviceCreateBufferMappedAsync)(DawnDevice device, DawnBufferDescriptor const * descriptor, DawnBufferCreateMappedCallback callback, void * userdata);
typedef void (*DawnProcDeviceSetUncapturedErrorCallback)(DawnDevice device, DawnErrorCallback callback, void * userdata);
typedef bool (*DawnProcDevicePopErrorScope)(DawnDevice device, DawnErrorCallback callback, void * userdata);
typedef void (*DawnProcDeviceReference)(DawnDevice device);
typedef void (*DawnProcDeviceRelease)(DawnDevice device);

// Procs of Fence
typedef uint64_t (*DawnProcFenceGetCompletedValue)(DawnFence fence);
typedef void (*DawnProcFenceOnCompletion)(DawnFence fence, uint64_t value, DawnFenceOnCompletionCallback callback, void * userdata);
typedef void (*DawnProcFenceReference)(DawnFence fence);
typedef void (*DawnProcFenceRelease)(DawnFence fence);

// Procs of PipelineLayout
typedef void (*DawnProcPipelineLayoutReference)(DawnPipelineLayout pipelineLayout);
typedef void (*DawnProcPipelineLayoutRelease)(DawnPipelineLayout pipelineLayout);

// Procs of Queue
typedef void (*DawnProcQueueSubmit)(DawnQueue queue, uint32_t commandCount, DawnCommandBuffer const * commands);
typedef void (*DawnProcQueueSignal)(DawnQueue queue, DawnFence fence, uint64_t signalValue);
typedef DawnFence (*DawnProcQueueCreateFence)(DawnQueue queue, DawnFenceDescriptor const * descriptor);
typedef void (*DawnProcQueueReference)(DawnQueue queue);
typedef void (*DawnProcQueueRelease)(DawnQueue queue);

// Procs of RenderBundle
typedef void (*DawnProcRenderBundleReference)(DawnRenderBundle renderBundle);
typedef void (*DawnProcRenderBundleRelease)(DawnRenderBundle renderBundle);

// Procs of RenderBundleEncoder
typedef void (*DawnProcRenderBundleEncoderSetPipeline)(DawnRenderBundleEncoder renderBundleEncoder, DawnRenderPipeline pipeline);
typedef void (*DawnProcRenderBundleEncoderSetBindGroup)(DawnRenderBundleEncoder renderBundleEncoder, uint32_t groupIndex, DawnBindGroup group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets);
typedef void (*DawnProcRenderBundleEncoderDraw)(DawnRenderBundleEncoder renderBundleEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
typedef void (*DawnProcRenderBundleEncoderDrawIndexed)(DawnRenderBundleEncoder renderBundleEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance);
typedef void (*DawnProcRenderBundleEncoderDrawIndirect)(DawnRenderBundleEncoder renderBundleEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
typedef void (*DawnProcRenderBundleEncoderDrawIndexedIndirect)(DawnRenderBundleEncoder renderBundleEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
typedef void (*DawnProcRenderBundleEncoderInsertDebugMarker)(DawnRenderBundleEncoder renderBundleEncoder, char const * groupLabel);
typedef void (*DawnProcRenderBundleEncoderPopDebugGroup)(DawnRenderBundleEncoder renderBundleEncoder);
typedef void (*DawnProcRenderBundleEncoderPushDebugGroup)(DawnRenderBundleEncoder renderBundleEncoder, char const * groupLabel);
typedef void (*DawnProcRenderBundleEncoderSetVertexBuffers)(DawnRenderBundleEncoder renderBundleEncoder, uint32_t startSlot, uint32_t count, DawnBuffer const * buffers, uint64_t const * offsets);
typedef void (*DawnProcRenderBundleEncoderSetIndexBuffer)(DawnRenderBundleEncoder renderBundleEncoder, DawnBuffer buffer, uint64_t offset);
typedef DawnRenderBundle (*DawnProcRenderBundleEncoderFinish)(DawnRenderBundleEncoder renderBundleEncoder, DawnRenderBundleDescriptor const * descriptor);
typedef void (*DawnProcRenderBundleEncoderReference)(DawnRenderBundleEncoder renderBundleEncoder);
typedef void (*DawnProcRenderBundleEncoderRelease)(DawnRenderBundleEncoder renderBundleEncoder);

// Procs of RenderPassEncoder
typedef void (*DawnProcRenderPassEncoderSetPipeline)(DawnRenderPassEncoder renderPassEncoder, DawnRenderPipeline pipeline);
typedef void (*DawnProcRenderPassEncoderSetBindGroup)(DawnRenderPassEncoder renderPassEncoder, uint32_t groupIndex, DawnBindGroup group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets);
typedef void (*DawnProcRenderPassEncoderDraw)(DawnRenderPassEncoder renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
typedef void (*DawnProcRenderPassEncoderDrawIndexed)(DawnRenderPassEncoder renderPassEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance);
typedef void (*DawnProcRenderPassEncoderDrawIndirect)(DawnRenderPassEncoder renderPassEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
typedef void (*DawnProcRenderPassEncoderDrawIndexedIndirect)(DawnRenderPassEncoder renderPassEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
typedef void (*DawnProcRenderPassEncoderExecuteBundles)(DawnRenderPassEncoder renderPassEncoder, uint32_t bundlesCount, DawnRenderBundle const * bundles);
typedef void (*DawnProcRenderPassEncoderInsertDebugMarker)(DawnRenderPassEncoder renderPassEncoder, char const * groupLabel);
typedef void (*DawnProcRenderPassEncoderPopDebugGroup)(DawnRenderPassEncoder renderPassEncoder);
typedef void (*DawnProcRenderPassEncoderPushDebugGroup)(DawnRenderPassEncoder renderPassEncoder, char const * groupLabel);
typedef void (*DawnProcRenderPassEncoderSetStencilReference)(DawnRenderPassEncoder renderPassEncoder, uint32_t reference);
typedef void (*DawnProcRenderPassEncoderSetBlendColor)(DawnRenderPassEncoder renderPassEncoder, DawnColor const * color);
typedef void (*DawnProcRenderPassEncoderSetViewport)(DawnRenderPassEncoder renderPassEncoder, float x, float y, float width, float height, float minDepth, float maxDepth);
typedef void (*DawnProcRenderPassEncoderSetScissorRect)(DawnRenderPassEncoder renderPassEncoder, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
typedef void (*DawnProcRenderPassEncoderSetVertexBuffers)(DawnRenderPassEncoder renderPassEncoder, uint32_t startSlot, uint32_t count, DawnBuffer const * buffers, uint64_t const * offsets);
typedef void (*DawnProcRenderPassEncoderSetIndexBuffer)(DawnRenderPassEncoder renderPassEncoder, DawnBuffer buffer, uint64_t offset);
typedef void (*DawnProcRenderPassEncoderEndPass)(DawnRenderPassEncoder renderPassEncoder);
typedef void (*DawnProcRenderPassEncoderReference)(DawnRenderPassEncoder renderPassEncoder);
typedef void (*DawnProcRenderPassEncoderRelease)(DawnRenderPassEncoder renderPassEncoder);

// Procs of RenderPipeline
typedef void (*DawnProcRenderPipelineReference)(DawnRenderPipeline renderPipeline);
typedef void (*DawnProcRenderPipelineRelease)(DawnRenderPipeline renderPipeline);

// Procs of Sampler
typedef void (*DawnProcSamplerReference)(DawnSampler sampler);
typedef void (*DawnProcSamplerRelease)(DawnSampler sampler);

// Procs of ShaderModule
typedef void (*DawnProcShaderModuleReference)(DawnShaderModule shaderModule);
typedef void (*DawnProcShaderModuleRelease)(DawnShaderModule shaderModule);

// Procs of SwapChain
typedef void (*DawnProcSwapChainConfigure)(DawnSwapChain swapChain, DawnTextureFormat format, DawnTextureUsage allowedUsage, uint32_t width, uint32_t height);
typedef DawnTexture (*DawnProcSwapChainGetNextTexture)(DawnSwapChain swapChain);
typedef void (*DawnProcSwapChainPresent)(DawnSwapChain swapChain, DawnTexture texture);
typedef void (*DawnProcSwapChainReference)(DawnSwapChain swapChain);
typedef void (*DawnProcSwapChainRelease)(DawnSwapChain swapChain);

// Procs of Texture
typedef DawnTextureView (*DawnProcTextureCreateView)(DawnTexture texture, DawnTextureViewDescriptor const * descriptor);
typedef void (*DawnProcTextureDestroy)(DawnTexture texture);
typedef void (*DawnProcTextureReference)(DawnTexture texture);
typedef void (*DawnProcTextureRelease)(DawnTexture texture);

// Procs of TextureView
typedef void (*DawnProcTextureViewReference)(DawnTextureView textureView);
typedef void (*DawnProcTextureViewRelease)(DawnTextureView textureView);


struct DawnProcTable_s {
    DawnProcBindGroupReference bindGroupReference;
    DawnProcBindGroupRelease bindGroupRelease;

    DawnProcBindGroupLayoutReference bindGroupLayoutReference;
    DawnProcBindGroupLayoutRelease bindGroupLayoutRelease;

    DawnProcBufferSetSubData bufferSetSubData;
    DawnProcBufferUnmap bufferUnmap;
    DawnProcBufferDestroy bufferDestroy;
    DawnProcBufferMapReadAsync bufferMapReadAsync;
    DawnProcBufferMapWriteAsync bufferMapWriteAsync;
    DawnProcBufferReference bufferReference;
    DawnProcBufferRelease bufferRelease;

    DawnProcCommandBufferReference commandBufferReference;
    DawnProcCommandBufferRelease commandBufferRelease;

    DawnProcCommandEncoderFinish commandEncoderFinish;
    DawnProcCommandEncoderBeginComputePass commandEncoderBeginComputePass;
    DawnProcCommandEncoderBeginRenderPass commandEncoderBeginRenderPass;
    DawnProcCommandEncoderCopyBufferToBuffer commandEncoderCopyBufferToBuffer;
    DawnProcCommandEncoderCopyBufferToTexture commandEncoderCopyBufferToTexture;
    DawnProcCommandEncoderCopyTextureToBuffer commandEncoderCopyTextureToBuffer;
    DawnProcCommandEncoderCopyTextureToTexture commandEncoderCopyTextureToTexture;
    DawnProcCommandEncoderInsertDebugMarker commandEncoderInsertDebugMarker;
    DawnProcCommandEncoderPopDebugGroup commandEncoderPopDebugGroup;
    DawnProcCommandEncoderPushDebugGroup commandEncoderPushDebugGroup;
    DawnProcCommandEncoderReference commandEncoderReference;
    DawnProcCommandEncoderRelease commandEncoderRelease;

    DawnProcComputePassEncoderInsertDebugMarker computePassEncoderInsertDebugMarker;
    DawnProcComputePassEncoderPopDebugGroup computePassEncoderPopDebugGroup;
    DawnProcComputePassEncoderPushDebugGroup computePassEncoderPushDebugGroup;
    DawnProcComputePassEncoderSetPipeline computePassEncoderSetPipeline;
    DawnProcComputePassEncoderSetBindGroup computePassEncoderSetBindGroup;
    DawnProcComputePassEncoderDispatch computePassEncoderDispatch;
    DawnProcComputePassEncoderDispatchIndirect computePassEncoderDispatchIndirect;
    DawnProcComputePassEncoderEndPass computePassEncoderEndPass;
    DawnProcComputePassEncoderReference computePassEncoderReference;
    DawnProcComputePassEncoderRelease computePassEncoderRelease;

    DawnProcComputePipelineReference computePipelineReference;
    DawnProcComputePipelineRelease computePipelineRelease;

    DawnProcDeviceCreateBindGroup deviceCreateBindGroup;
    DawnProcDeviceCreateBindGroupLayout deviceCreateBindGroupLayout;
    DawnProcDeviceCreateBuffer deviceCreateBuffer;
    DawnProcDeviceCreateBufferMapped deviceCreateBufferMapped;
    DawnProcDeviceCreateCommandEncoder deviceCreateCommandEncoder;
    DawnProcDeviceCreateComputePipeline deviceCreateComputePipeline;
    DawnProcDeviceCreateRenderPipeline deviceCreateRenderPipeline;
    DawnProcDeviceCreatePipelineLayout deviceCreatePipelineLayout;
    DawnProcDeviceCreateQueue deviceCreateQueue;
    DawnProcDeviceCreateRenderBundleEncoder deviceCreateRenderBundleEncoder;
    DawnProcDeviceCreateSampler deviceCreateSampler;
    DawnProcDeviceCreateShaderModule deviceCreateShaderModule;
    DawnProcDeviceCreateSwapChain deviceCreateSwapChain;
    DawnProcDeviceCreateTexture deviceCreateTexture;
    DawnProcDeviceTick deviceTick;
    DawnProcDevicePushErrorScope devicePushErrorScope;
    DawnProcDeviceCreateBufferMappedAsync deviceCreateBufferMappedAsync;
    DawnProcDeviceSetUncapturedErrorCallback deviceSetUncapturedErrorCallback;
    DawnProcDevicePopErrorScope devicePopErrorScope;
    DawnProcDeviceReference deviceReference;
    DawnProcDeviceRelease deviceRelease;

    DawnProcFenceGetCompletedValue fenceGetCompletedValue;
    DawnProcFenceOnCompletion fenceOnCompletion;
    DawnProcFenceReference fenceReference;
    DawnProcFenceRelease fenceRelease;

    DawnProcPipelineLayoutReference pipelineLayoutReference;
    DawnProcPipelineLayoutRelease pipelineLayoutRelease;

    DawnProcQueueSubmit queueSubmit;
    DawnProcQueueSignal queueSignal;
    DawnProcQueueCreateFence queueCreateFence;
    DawnProcQueueReference queueReference;
    DawnProcQueueRelease queueRelease;

    DawnProcRenderBundleReference renderBundleReference;
    DawnProcRenderBundleRelease renderBundleRelease;

    DawnProcRenderBundleEncoderSetPipeline renderBundleEncoderSetPipeline;
    DawnProcRenderBundleEncoderSetBindGroup renderBundleEncoderSetBindGroup;
    DawnProcRenderBundleEncoderDraw renderBundleEncoderDraw;
    DawnProcRenderBundleEncoderDrawIndexed renderBundleEncoderDrawIndexed;
    DawnProcRenderBundleEncoderDrawIndirect renderBundleEncoderDrawIndirect;
    DawnProcRenderBundleEncoderDrawIndexedIndirect renderBundleEncoderDrawIndexedIndirect;
    DawnProcRenderBundleEncoderInsertDebugMarker renderBundleEncoderInsertDebugMarker;
    DawnProcRenderBundleEncoderPopDebugGroup renderBundleEncoderPopDebugGroup;
    DawnProcRenderBundleEncoderPushDebugGroup renderBundleEncoderPushDebugGroup;
    DawnProcRenderBundleEncoderSetVertexBuffers renderBundleEncoderSetVertexBuffers;
    DawnProcRenderBundleEncoderSetIndexBuffer renderBundleEncoderSetIndexBuffer;
    DawnProcRenderBundleEncoderFinish renderBundleEncoderFinish;
    DawnProcRenderBundleEncoderReference renderBundleEncoderReference;
    DawnProcRenderBundleEncoderRelease renderBundleEncoderRelease;

    DawnProcRenderPassEncoderSetPipeline renderPassEncoderSetPipeline;
    DawnProcRenderPassEncoderSetBindGroup renderPassEncoderSetBindGroup;
    DawnProcRenderPassEncoderDraw renderPassEncoderDraw;
    DawnProcRenderPassEncoderDrawIndexed renderPassEncoderDrawIndexed;
    DawnProcRenderPassEncoderDrawIndirect renderPassEncoderDrawIndirect;
    DawnProcRenderPassEncoderDrawIndexedIndirect renderPassEncoderDrawIndexedIndirect;
    DawnProcRenderPassEncoderExecuteBundles renderPassEncoderExecuteBundles;
    DawnProcRenderPassEncoderInsertDebugMarker renderPassEncoderInsertDebugMarker;
    DawnProcRenderPassEncoderPopDebugGroup renderPassEncoderPopDebugGroup;
    DawnProcRenderPassEncoderPushDebugGroup renderPassEncoderPushDebugGroup;
    DawnProcRenderPassEncoderSetStencilReference renderPassEncoderSetStencilReference;
    DawnProcRenderPassEncoderSetBlendColor renderPassEncoderSetBlendColor;
    DawnProcRenderPassEncoderSetViewport renderPassEncoderSetViewport;
    DawnProcRenderPassEncoderSetScissorRect renderPassEncoderSetScissorRect;
    DawnProcRenderPassEncoderSetVertexBuffers renderPassEncoderSetVertexBuffers;
    DawnProcRenderPassEncoderSetIndexBuffer renderPassEncoderSetIndexBuffer;
    DawnProcRenderPassEncoderEndPass renderPassEncoderEndPass;
    DawnProcRenderPassEncoderReference renderPassEncoderReference;
    DawnProcRenderPassEncoderRelease renderPassEncoderRelease;

    DawnProcRenderPipelineReference renderPipelineReference;
    DawnProcRenderPipelineRelease renderPipelineRelease;

    DawnProcSamplerReference samplerReference;
    DawnProcSamplerRelease samplerRelease;

    DawnProcShaderModuleReference shaderModuleReference;
    DawnProcShaderModuleRelease shaderModuleRelease;

    DawnProcSwapChainConfigure swapChainConfigure;
    DawnProcSwapChainGetNextTexture swapChainGetNextTexture;
    DawnProcSwapChainPresent swapChainPresent;
    DawnProcSwapChainReference swapChainReference;
    DawnProcSwapChainRelease swapChainRelease;

    DawnProcTextureCreateView textureCreateView;
    DawnProcTextureDestroy textureDestroy;
    DawnProcTextureReference textureReference;
    DawnProcTextureRelease textureRelease;

    DawnProcTextureViewReference textureViewReference;
    DawnProcTextureViewRelease textureViewRelease;

};
typedef struct DawnProcTable_s DawnProcTable;

// Stuff below is for convenience and will forward calls to a static DawnProcTable.

// Set which DawnProcTable will be used
DAWN_EXPORT void dawnSetProcs(const DawnProcTable* procs);

// Methods of BindGroup
DAWN_EXPORT void dawnBindGroupReference(DawnBindGroup bindGroup);
DAWN_EXPORT void dawnBindGroupRelease(DawnBindGroup bindGroup);

// Methods of BindGroupLayout
DAWN_EXPORT void dawnBindGroupLayoutReference(DawnBindGroupLayout bindGroupLayout);
DAWN_EXPORT void dawnBindGroupLayoutRelease(DawnBindGroupLayout bindGroupLayout);

// Methods of Buffer
DAWN_EXPORT void dawnBufferSetSubData(DawnBuffer buffer, uint64_t start, uint64_t count, void const * data);
DAWN_EXPORT void dawnBufferUnmap(DawnBuffer buffer);
DAWN_EXPORT void dawnBufferDestroy(DawnBuffer buffer);
DAWN_EXPORT void dawnBufferMapReadAsync(DawnBuffer buffer, DawnBufferMapReadCallback callback, void * userdata);
DAWN_EXPORT void dawnBufferMapWriteAsync(DawnBuffer buffer, DawnBufferMapWriteCallback callback, void * userdata);
DAWN_EXPORT void dawnBufferReference(DawnBuffer buffer);
DAWN_EXPORT void dawnBufferRelease(DawnBuffer buffer);

// Methods of CommandBuffer
DAWN_EXPORT void dawnCommandBufferReference(DawnCommandBuffer commandBuffer);
DAWN_EXPORT void dawnCommandBufferRelease(DawnCommandBuffer commandBuffer);

// Methods of CommandEncoder
DAWN_EXPORT DawnCommandBuffer dawnCommandEncoderFinish(DawnCommandEncoder commandEncoder, DawnCommandBufferDescriptor const * descriptor);
DAWN_EXPORT DawnComputePassEncoder dawnCommandEncoderBeginComputePass(DawnCommandEncoder commandEncoder, DawnComputePassDescriptor const * descriptor);
DAWN_EXPORT DawnRenderPassEncoder dawnCommandEncoderBeginRenderPass(DawnCommandEncoder commandEncoder, DawnRenderPassDescriptor const * descriptor);
DAWN_EXPORT void dawnCommandEncoderCopyBufferToBuffer(DawnCommandEncoder commandEncoder, DawnBuffer source, uint64_t sourceOffset, DawnBuffer destination, uint64_t destinationOffset, uint64_t size);
DAWN_EXPORT void dawnCommandEncoderCopyBufferToTexture(DawnCommandEncoder commandEncoder, DawnBufferCopyView const * source, DawnTextureCopyView const * destination, DawnExtent3D const * copySize);
DAWN_EXPORT void dawnCommandEncoderCopyTextureToBuffer(DawnCommandEncoder commandEncoder, DawnTextureCopyView const * source, DawnBufferCopyView const * destination, DawnExtent3D const * copySize);
DAWN_EXPORT void dawnCommandEncoderCopyTextureToTexture(DawnCommandEncoder commandEncoder, DawnTextureCopyView const * source, DawnTextureCopyView const * destination, DawnExtent3D const * copySize);
DAWN_EXPORT void dawnCommandEncoderInsertDebugMarker(DawnCommandEncoder commandEncoder, char const * groupLabel);
DAWN_EXPORT void dawnCommandEncoderPopDebugGroup(DawnCommandEncoder commandEncoder);
DAWN_EXPORT void dawnCommandEncoderPushDebugGroup(DawnCommandEncoder commandEncoder, char const * groupLabel);
DAWN_EXPORT void dawnCommandEncoderReference(DawnCommandEncoder commandEncoder);
DAWN_EXPORT void dawnCommandEncoderRelease(DawnCommandEncoder commandEncoder);

// Methods of ComputePassEncoder
DAWN_EXPORT void dawnComputePassEncoderInsertDebugMarker(DawnComputePassEncoder computePassEncoder, char const * groupLabel);
DAWN_EXPORT void dawnComputePassEncoderPopDebugGroup(DawnComputePassEncoder computePassEncoder);
DAWN_EXPORT void dawnComputePassEncoderPushDebugGroup(DawnComputePassEncoder computePassEncoder, char const * groupLabel);
DAWN_EXPORT void dawnComputePassEncoderSetPipeline(DawnComputePassEncoder computePassEncoder, DawnComputePipeline pipeline);
DAWN_EXPORT void dawnComputePassEncoderSetBindGroup(DawnComputePassEncoder computePassEncoder, uint32_t groupIndex, DawnBindGroup group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets);
DAWN_EXPORT void dawnComputePassEncoderDispatch(DawnComputePassEncoder computePassEncoder, uint32_t x, uint32_t y, uint32_t z);
DAWN_EXPORT void dawnComputePassEncoderDispatchIndirect(DawnComputePassEncoder computePassEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
DAWN_EXPORT void dawnComputePassEncoderEndPass(DawnComputePassEncoder computePassEncoder);
DAWN_EXPORT void dawnComputePassEncoderReference(DawnComputePassEncoder computePassEncoder);
DAWN_EXPORT void dawnComputePassEncoderRelease(DawnComputePassEncoder computePassEncoder);

// Methods of ComputePipeline
DAWN_EXPORT void dawnComputePipelineReference(DawnComputePipeline computePipeline);
DAWN_EXPORT void dawnComputePipelineRelease(DawnComputePipeline computePipeline);

// Methods of Device
DAWN_EXPORT DawnBindGroup dawnDeviceCreateBindGroup(DawnDevice device, DawnBindGroupDescriptor const * descriptor);
DAWN_EXPORT DawnBindGroupLayout dawnDeviceCreateBindGroupLayout(DawnDevice device, DawnBindGroupLayoutDescriptor const * descriptor);
DAWN_EXPORT DawnBuffer dawnDeviceCreateBuffer(DawnDevice device, DawnBufferDescriptor const * descriptor);
DAWN_EXPORT DawnCreateBufferMappedResult dawnDeviceCreateBufferMapped(DawnDevice device, DawnBufferDescriptor const * descriptor);
DAWN_EXPORT DawnCommandEncoder dawnDeviceCreateCommandEncoder(DawnDevice device, DawnCommandEncoderDescriptor const * descriptor);
DAWN_EXPORT DawnComputePipeline dawnDeviceCreateComputePipeline(DawnDevice device, DawnComputePipelineDescriptor const * descriptor);
DAWN_EXPORT DawnRenderPipeline dawnDeviceCreateRenderPipeline(DawnDevice device, DawnRenderPipelineDescriptor const * descriptor);
DAWN_EXPORT DawnPipelineLayout dawnDeviceCreatePipelineLayout(DawnDevice device, DawnPipelineLayoutDescriptor const * descriptor);
DAWN_EXPORT DawnQueue dawnDeviceCreateQueue(DawnDevice device);
DAWN_EXPORT DawnRenderBundleEncoder dawnDeviceCreateRenderBundleEncoder(DawnDevice device, DawnRenderBundleEncoderDescriptor const * descriptor);
DAWN_EXPORT DawnSampler dawnDeviceCreateSampler(DawnDevice device, DawnSamplerDescriptor const * descriptor);
DAWN_EXPORT DawnShaderModule dawnDeviceCreateShaderModule(DawnDevice device, DawnShaderModuleDescriptor const * descriptor);
DAWN_EXPORT DawnSwapChain dawnDeviceCreateSwapChain(DawnDevice device, DawnSwapChainDescriptor const * descriptor);
DAWN_EXPORT DawnTexture dawnDeviceCreateTexture(DawnDevice device, DawnTextureDescriptor const * descriptor);
DAWN_EXPORT void dawnDeviceTick(DawnDevice device);
DAWN_EXPORT void dawnDevicePushErrorScope(DawnDevice device, DawnErrorFilter filter);
DAWN_EXPORT void dawnDeviceCreateBufferMappedAsync(DawnDevice device, DawnBufferDescriptor const * descriptor, DawnBufferCreateMappedCallback callback, void * userdata);
DAWN_EXPORT void dawnDeviceSetUncapturedErrorCallback(DawnDevice device, DawnErrorCallback callback, void * userdata);
DAWN_EXPORT bool dawnDevicePopErrorScope(DawnDevice device, DawnErrorCallback callback, void * userdata);
DAWN_EXPORT void dawnDeviceReference(DawnDevice device);
DAWN_EXPORT void dawnDeviceRelease(DawnDevice device);

// Methods of Fence
DAWN_EXPORT uint64_t dawnFenceGetCompletedValue(DawnFence fence);
DAWN_EXPORT void dawnFenceOnCompletion(DawnFence fence, uint64_t value, DawnFenceOnCompletionCallback callback, void * userdata);
DAWN_EXPORT void dawnFenceReference(DawnFence fence);
DAWN_EXPORT void dawnFenceRelease(DawnFence fence);

// Methods of PipelineLayout
DAWN_EXPORT void dawnPipelineLayoutReference(DawnPipelineLayout pipelineLayout);
DAWN_EXPORT void dawnPipelineLayoutRelease(DawnPipelineLayout pipelineLayout);

// Methods of Queue
DAWN_EXPORT void dawnQueueSubmit(DawnQueue queue, uint32_t commandCount, DawnCommandBuffer const * commands);
DAWN_EXPORT void dawnQueueSignal(DawnQueue queue, DawnFence fence, uint64_t signalValue);
DAWN_EXPORT DawnFence dawnQueueCreateFence(DawnQueue queue, DawnFenceDescriptor const * descriptor);
DAWN_EXPORT void dawnQueueReference(DawnQueue queue);
DAWN_EXPORT void dawnQueueRelease(DawnQueue queue);

// Methods of RenderBundle
DAWN_EXPORT void dawnRenderBundleReference(DawnRenderBundle renderBundle);
DAWN_EXPORT void dawnRenderBundleRelease(DawnRenderBundle renderBundle);

// Methods of RenderBundleEncoder
DAWN_EXPORT void dawnRenderBundleEncoderSetPipeline(DawnRenderBundleEncoder renderBundleEncoder, DawnRenderPipeline pipeline);
DAWN_EXPORT void dawnRenderBundleEncoderSetBindGroup(DawnRenderBundleEncoder renderBundleEncoder, uint32_t groupIndex, DawnBindGroup group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets);
DAWN_EXPORT void dawnRenderBundleEncoderDraw(DawnRenderBundleEncoder renderBundleEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
DAWN_EXPORT void dawnRenderBundleEncoderDrawIndexed(DawnRenderBundleEncoder renderBundleEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance);
DAWN_EXPORT void dawnRenderBundleEncoderDrawIndirect(DawnRenderBundleEncoder renderBundleEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
DAWN_EXPORT void dawnRenderBundleEncoderDrawIndexedIndirect(DawnRenderBundleEncoder renderBundleEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
DAWN_EXPORT void dawnRenderBundleEncoderInsertDebugMarker(DawnRenderBundleEncoder renderBundleEncoder, char const * groupLabel);
DAWN_EXPORT void dawnRenderBundleEncoderPopDebugGroup(DawnRenderBundleEncoder renderBundleEncoder);
DAWN_EXPORT void dawnRenderBundleEncoderPushDebugGroup(DawnRenderBundleEncoder renderBundleEncoder, char const * groupLabel);
DAWN_EXPORT void dawnRenderBundleEncoderSetVertexBuffers(DawnRenderBundleEncoder renderBundleEncoder, uint32_t startSlot, uint32_t count, DawnBuffer const * buffers, uint64_t const * offsets);
DAWN_EXPORT void dawnRenderBundleEncoderSetIndexBuffer(DawnRenderBundleEncoder renderBundleEncoder, DawnBuffer buffer, uint64_t offset);
DAWN_EXPORT DawnRenderBundle dawnRenderBundleEncoderFinish(DawnRenderBundleEncoder renderBundleEncoder, DawnRenderBundleDescriptor const * descriptor);
DAWN_EXPORT void dawnRenderBundleEncoderReference(DawnRenderBundleEncoder renderBundleEncoder);
DAWN_EXPORT void dawnRenderBundleEncoderRelease(DawnRenderBundleEncoder renderBundleEncoder);

// Methods of RenderPassEncoder
DAWN_EXPORT void dawnRenderPassEncoderSetPipeline(DawnRenderPassEncoder renderPassEncoder, DawnRenderPipeline pipeline);
DAWN_EXPORT void dawnRenderPassEncoderSetBindGroup(DawnRenderPassEncoder renderPassEncoder, uint32_t groupIndex, DawnBindGroup group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets);
DAWN_EXPORT void dawnRenderPassEncoderDraw(DawnRenderPassEncoder renderPassEncoder, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
DAWN_EXPORT void dawnRenderPassEncoderDrawIndexed(DawnRenderPassEncoder renderPassEncoder, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance);
DAWN_EXPORT void dawnRenderPassEncoderDrawIndirect(DawnRenderPassEncoder renderPassEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
DAWN_EXPORT void dawnRenderPassEncoderDrawIndexedIndirect(DawnRenderPassEncoder renderPassEncoder, DawnBuffer indirectBuffer, uint64_t indirectOffset);
DAWN_EXPORT void dawnRenderPassEncoderExecuteBundles(DawnRenderPassEncoder renderPassEncoder, uint32_t bundlesCount, DawnRenderBundle const * bundles);
DAWN_EXPORT void dawnRenderPassEncoderInsertDebugMarker(DawnRenderPassEncoder renderPassEncoder, char const * groupLabel);
DAWN_EXPORT void dawnRenderPassEncoderPopDebugGroup(DawnRenderPassEncoder renderPassEncoder);
DAWN_EXPORT void dawnRenderPassEncoderPushDebugGroup(DawnRenderPassEncoder renderPassEncoder, char const * groupLabel);
DAWN_EXPORT void dawnRenderPassEncoderSetStencilReference(DawnRenderPassEncoder renderPassEncoder, uint32_t reference);
DAWN_EXPORT void dawnRenderPassEncoderSetBlendColor(DawnRenderPassEncoder renderPassEncoder, DawnColor const * color);
DAWN_EXPORT void dawnRenderPassEncoderSetViewport(DawnRenderPassEncoder renderPassEncoder, float x, float y, float width, float height, float minDepth, float maxDepth);
DAWN_EXPORT void dawnRenderPassEncoderSetScissorRect(DawnRenderPassEncoder renderPassEncoder, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
DAWN_EXPORT void dawnRenderPassEncoderSetVertexBuffers(DawnRenderPassEncoder renderPassEncoder, uint32_t startSlot, uint32_t count, DawnBuffer const * buffers, uint64_t const * offsets);
DAWN_EXPORT void dawnRenderPassEncoderSetIndexBuffer(DawnRenderPassEncoder renderPassEncoder, DawnBuffer buffer, uint64_t offset);
DAWN_EXPORT void dawnRenderPassEncoderEndPass(DawnRenderPassEncoder renderPassEncoder);
DAWN_EXPORT void dawnRenderPassEncoderReference(DawnRenderPassEncoder renderPassEncoder);
DAWN_EXPORT void dawnRenderPassEncoderRelease(DawnRenderPassEncoder renderPassEncoder);

// Methods of RenderPipeline
DAWN_EXPORT void dawnRenderPipelineReference(DawnRenderPipeline renderPipeline);
DAWN_EXPORT void dawnRenderPipelineRelease(DawnRenderPipeline renderPipeline);

// Methods of Sampler
DAWN_EXPORT void dawnSamplerReference(DawnSampler sampler);
DAWN_EXPORT void dawnSamplerRelease(DawnSampler sampler);

// Methods of ShaderModule
DAWN_EXPORT void dawnShaderModuleReference(DawnShaderModule shaderModule);
DAWN_EXPORT void dawnShaderModuleRelease(DawnShaderModule shaderModule);

// Methods of SwapChain
DAWN_EXPORT void dawnSwapChainConfigure(DawnSwapChain swapChain, DawnTextureFormat format, DawnTextureUsage allowedUsage, uint32_t width, uint32_t height);
DAWN_EXPORT DawnTexture dawnSwapChainGetNextTexture(DawnSwapChain swapChain);
DAWN_EXPORT void dawnSwapChainPresent(DawnSwapChain swapChain, DawnTexture texture);
DAWN_EXPORT void dawnSwapChainReference(DawnSwapChain swapChain);
DAWN_EXPORT void dawnSwapChainRelease(DawnSwapChain swapChain);

// Methods of Texture
DAWN_EXPORT DawnTextureView dawnTextureCreateView(DawnTexture texture, DawnTextureViewDescriptor const * descriptor);
DAWN_EXPORT void dawnTextureDestroy(DawnTexture texture);
DAWN_EXPORT void dawnTextureReference(DawnTexture texture);
DAWN_EXPORT void dawnTextureRelease(DawnTexture texture);

// Methods of TextureView
DAWN_EXPORT void dawnTextureViewReference(DawnTextureView textureView);
DAWN_EXPORT void dawnTextureViewRelease(DawnTextureView textureView);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // DAWN_DAWN_H_
