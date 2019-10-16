













#include "dawn/dawncpp.h"

namespace dawn {


    static_assert(sizeof(AddressMode) == sizeof(DawnAddressMode), "sizeof mismatch for AddressMode");
    static_assert(alignof(AddressMode) == alignof(DawnAddressMode), "alignof mismatch for AddressMode");

    static_assert(static_cast<uint32_t>(AddressMode::Repeat) == DAWN_ADDRESS_MODE_REPEAT, "value mismatch for AddressMode::Repeat");
    static_assert(static_cast<uint32_t>(AddressMode::MirrorRepeat) == DAWN_ADDRESS_MODE_MIRROR_REPEAT, "value mismatch for AddressMode::MirrorRepeat");
    static_assert(static_cast<uint32_t>(AddressMode::ClampToEdge) == DAWN_ADDRESS_MODE_CLAMP_TO_EDGE, "value mismatch for AddressMode::ClampToEdge");


    static_assert(sizeof(BindingType) == sizeof(DawnBindingType), "sizeof mismatch for BindingType");
    static_assert(alignof(BindingType) == alignof(DawnBindingType), "alignof mismatch for BindingType");

    static_assert(static_cast<uint32_t>(BindingType::UniformBuffer) == DAWN_BINDING_TYPE_UNIFORM_BUFFER, "value mismatch for BindingType::UniformBuffer");
    static_assert(static_cast<uint32_t>(BindingType::StorageBuffer) == DAWN_BINDING_TYPE_STORAGE_BUFFER, "value mismatch for BindingType::StorageBuffer");
    static_assert(static_cast<uint32_t>(BindingType::ReadonlyStorageBuffer) == DAWN_BINDING_TYPE_READONLY_STORAGE_BUFFER, "value mismatch for BindingType::ReadonlyStorageBuffer");
    static_assert(static_cast<uint32_t>(BindingType::Sampler) == DAWN_BINDING_TYPE_SAMPLER, "value mismatch for BindingType::Sampler");
    static_assert(static_cast<uint32_t>(BindingType::SampledTexture) == DAWN_BINDING_TYPE_SAMPLED_TEXTURE, "value mismatch for BindingType::SampledTexture");
    static_assert(static_cast<uint32_t>(BindingType::StorageTexture) == DAWN_BINDING_TYPE_STORAGE_TEXTURE, "value mismatch for BindingType::StorageTexture");


    static_assert(sizeof(BlendFactor) == sizeof(DawnBlendFactor), "sizeof mismatch for BlendFactor");
    static_assert(alignof(BlendFactor) == alignof(DawnBlendFactor), "alignof mismatch for BlendFactor");

    static_assert(static_cast<uint32_t>(BlendFactor::Zero) == DAWN_BLEND_FACTOR_ZERO, "value mismatch for BlendFactor::Zero");
    static_assert(static_cast<uint32_t>(BlendFactor::One) == DAWN_BLEND_FACTOR_ONE, "value mismatch for BlendFactor::One");
    static_assert(static_cast<uint32_t>(BlendFactor::SrcColor) == DAWN_BLEND_FACTOR_SRC_COLOR, "value mismatch for BlendFactor::SrcColor");
    static_assert(static_cast<uint32_t>(BlendFactor::OneMinusSrcColor) == DAWN_BLEND_FACTOR_ONE_MINUS_SRC_COLOR, "value mismatch for BlendFactor::OneMinusSrcColor");
    static_assert(static_cast<uint32_t>(BlendFactor::SrcAlpha) == DAWN_BLEND_FACTOR_SRC_ALPHA, "value mismatch for BlendFactor::SrcAlpha");
    static_assert(static_cast<uint32_t>(BlendFactor::OneMinusSrcAlpha) == DAWN_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA, "value mismatch for BlendFactor::OneMinusSrcAlpha");
    static_assert(static_cast<uint32_t>(BlendFactor::DstColor) == DAWN_BLEND_FACTOR_DST_COLOR, "value mismatch for BlendFactor::DstColor");
    static_assert(static_cast<uint32_t>(BlendFactor::OneMinusDstColor) == DAWN_BLEND_FACTOR_ONE_MINUS_DST_COLOR, "value mismatch for BlendFactor::OneMinusDstColor");
    static_assert(static_cast<uint32_t>(BlendFactor::DstAlpha) == DAWN_BLEND_FACTOR_DST_ALPHA, "value mismatch for BlendFactor::DstAlpha");
    static_assert(static_cast<uint32_t>(BlendFactor::OneMinusDstAlpha) == DAWN_BLEND_FACTOR_ONE_MINUS_DST_ALPHA, "value mismatch for BlendFactor::OneMinusDstAlpha");
    static_assert(static_cast<uint32_t>(BlendFactor::SrcAlphaSaturated) == DAWN_BLEND_FACTOR_SRC_ALPHA_SATURATED, "value mismatch for BlendFactor::SrcAlphaSaturated");
    static_assert(static_cast<uint32_t>(BlendFactor::BlendColor) == DAWN_BLEND_FACTOR_BLEND_COLOR, "value mismatch for BlendFactor::BlendColor");
    static_assert(static_cast<uint32_t>(BlendFactor::OneMinusBlendColor) == DAWN_BLEND_FACTOR_ONE_MINUS_BLEND_COLOR, "value mismatch for BlendFactor::OneMinusBlendColor");


    static_assert(sizeof(BlendOperation) == sizeof(DawnBlendOperation), "sizeof mismatch for BlendOperation");
    static_assert(alignof(BlendOperation) == alignof(DawnBlendOperation), "alignof mismatch for BlendOperation");

    static_assert(static_cast<uint32_t>(BlendOperation::Add) == DAWN_BLEND_OPERATION_ADD, "value mismatch for BlendOperation::Add");
    static_assert(static_cast<uint32_t>(BlendOperation::Subtract) == DAWN_BLEND_OPERATION_SUBTRACT, "value mismatch for BlendOperation::Subtract");
    static_assert(static_cast<uint32_t>(BlendOperation::ReverseSubtract) == DAWN_BLEND_OPERATION_REVERSE_SUBTRACT, "value mismatch for BlendOperation::ReverseSubtract");
    static_assert(static_cast<uint32_t>(BlendOperation::Min) == DAWN_BLEND_OPERATION_MIN, "value mismatch for BlendOperation::Min");
    static_assert(static_cast<uint32_t>(BlendOperation::Max) == DAWN_BLEND_OPERATION_MAX, "value mismatch for BlendOperation::Max");


    static_assert(sizeof(BufferMapAsyncStatus) == sizeof(DawnBufferMapAsyncStatus), "sizeof mismatch for BufferMapAsyncStatus");
    static_assert(alignof(BufferMapAsyncStatus) == alignof(DawnBufferMapAsyncStatus), "alignof mismatch for BufferMapAsyncStatus");

    static_assert(static_cast<uint32_t>(BufferMapAsyncStatus::Success) == DAWN_BUFFER_MAP_ASYNC_STATUS_SUCCESS, "value mismatch for BufferMapAsyncStatus::Success");
    static_assert(static_cast<uint32_t>(BufferMapAsyncStatus::Error) == DAWN_BUFFER_MAP_ASYNC_STATUS_ERROR, "value mismatch for BufferMapAsyncStatus::Error");
    static_assert(static_cast<uint32_t>(BufferMapAsyncStatus::Unknown) == DAWN_BUFFER_MAP_ASYNC_STATUS_UNKNOWN, "value mismatch for BufferMapAsyncStatus::Unknown");
    static_assert(static_cast<uint32_t>(BufferMapAsyncStatus::DeviceLost) == DAWN_BUFFER_MAP_ASYNC_STATUS_DEVICE_LOST, "value mismatch for BufferMapAsyncStatus::DeviceLost");


    static_assert(sizeof(CompareFunction) == sizeof(DawnCompareFunction), "sizeof mismatch for CompareFunction");
    static_assert(alignof(CompareFunction) == alignof(DawnCompareFunction), "alignof mismatch for CompareFunction");

    static_assert(static_cast<uint32_t>(CompareFunction::Never) == DAWN_COMPARE_FUNCTION_NEVER, "value mismatch for CompareFunction::Never");
    static_assert(static_cast<uint32_t>(CompareFunction::Less) == DAWN_COMPARE_FUNCTION_LESS, "value mismatch for CompareFunction::Less");
    static_assert(static_cast<uint32_t>(CompareFunction::LessEqual) == DAWN_COMPARE_FUNCTION_LESS_EQUAL, "value mismatch for CompareFunction::LessEqual");
    static_assert(static_cast<uint32_t>(CompareFunction::Greater) == DAWN_COMPARE_FUNCTION_GREATER, "value mismatch for CompareFunction::Greater");
    static_assert(static_cast<uint32_t>(CompareFunction::GreaterEqual) == DAWN_COMPARE_FUNCTION_GREATER_EQUAL, "value mismatch for CompareFunction::GreaterEqual");
    static_assert(static_cast<uint32_t>(CompareFunction::Equal) == DAWN_COMPARE_FUNCTION_EQUAL, "value mismatch for CompareFunction::Equal");
    static_assert(static_cast<uint32_t>(CompareFunction::NotEqual) == DAWN_COMPARE_FUNCTION_NOT_EQUAL, "value mismatch for CompareFunction::NotEqual");
    static_assert(static_cast<uint32_t>(CompareFunction::Always) == DAWN_COMPARE_FUNCTION_ALWAYS, "value mismatch for CompareFunction::Always");


    static_assert(sizeof(CullMode) == sizeof(DawnCullMode), "sizeof mismatch for CullMode");
    static_assert(alignof(CullMode) == alignof(DawnCullMode), "alignof mismatch for CullMode");

    static_assert(static_cast<uint32_t>(CullMode::None) == DAWN_CULL_MODE_NONE, "value mismatch for CullMode::None");
    static_assert(static_cast<uint32_t>(CullMode::Front) == DAWN_CULL_MODE_FRONT, "value mismatch for CullMode::Front");
    static_assert(static_cast<uint32_t>(CullMode::Back) == DAWN_CULL_MODE_BACK, "value mismatch for CullMode::Back");


    static_assert(sizeof(ErrorFilter) == sizeof(DawnErrorFilter), "sizeof mismatch for ErrorFilter");
    static_assert(alignof(ErrorFilter) == alignof(DawnErrorFilter), "alignof mismatch for ErrorFilter");

    static_assert(static_cast<uint32_t>(ErrorFilter::None) == DAWN_ERROR_FILTER_NONE, "value mismatch for ErrorFilter::None");
    static_assert(static_cast<uint32_t>(ErrorFilter::Validation) == DAWN_ERROR_FILTER_VALIDATION, "value mismatch for ErrorFilter::Validation");
    static_assert(static_cast<uint32_t>(ErrorFilter::OutOfMemory) == DAWN_ERROR_FILTER_OUT_OF_MEMORY, "value mismatch for ErrorFilter::OutOfMemory");


    static_assert(sizeof(ErrorType) == sizeof(DawnErrorType), "sizeof mismatch for ErrorType");
    static_assert(alignof(ErrorType) == alignof(DawnErrorType), "alignof mismatch for ErrorType");

    static_assert(static_cast<uint32_t>(ErrorType::NoError) == DAWN_ERROR_TYPE_NO_ERROR, "value mismatch for ErrorType::NoError");
    static_assert(static_cast<uint32_t>(ErrorType::Validation) == DAWN_ERROR_TYPE_VALIDATION, "value mismatch for ErrorType::Validation");
    static_assert(static_cast<uint32_t>(ErrorType::OutOfMemory) == DAWN_ERROR_TYPE_OUT_OF_MEMORY, "value mismatch for ErrorType::OutOfMemory");
    static_assert(static_cast<uint32_t>(ErrorType::Unknown) == DAWN_ERROR_TYPE_UNKNOWN, "value mismatch for ErrorType::Unknown");
    static_assert(static_cast<uint32_t>(ErrorType::DeviceLost) == DAWN_ERROR_TYPE_DEVICE_LOST, "value mismatch for ErrorType::DeviceLost");


    static_assert(sizeof(FenceCompletionStatus) == sizeof(DawnFenceCompletionStatus), "sizeof mismatch for FenceCompletionStatus");
    static_assert(alignof(FenceCompletionStatus) == alignof(DawnFenceCompletionStatus), "alignof mismatch for FenceCompletionStatus");

    static_assert(static_cast<uint32_t>(FenceCompletionStatus::Success) == DAWN_FENCE_COMPLETION_STATUS_SUCCESS, "value mismatch for FenceCompletionStatus::Success");
    static_assert(static_cast<uint32_t>(FenceCompletionStatus::Error) == DAWN_FENCE_COMPLETION_STATUS_ERROR, "value mismatch for FenceCompletionStatus::Error");
    static_assert(static_cast<uint32_t>(FenceCompletionStatus::Unknown) == DAWN_FENCE_COMPLETION_STATUS_UNKNOWN, "value mismatch for FenceCompletionStatus::Unknown");
    static_assert(static_cast<uint32_t>(FenceCompletionStatus::DeviceLost) == DAWN_FENCE_COMPLETION_STATUS_DEVICE_LOST, "value mismatch for FenceCompletionStatus::DeviceLost");


    static_assert(sizeof(FilterMode) == sizeof(DawnFilterMode), "sizeof mismatch for FilterMode");
    static_assert(alignof(FilterMode) == alignof(DawnFilterMode), "alignof mismatch for FilterMode");

    static_assert(static_cast<uint32_t>(FilterMode::Nearest) == DAWN_FILTER_MODE_NEAREST, "value mismatch for FilterMode::Nearest");
    static_assert(static_cast<uint32_t>(FilterMode::Linear) == DAWN_FILTER_MODE_LINEAR, "value mismatch for FilterMode::Linear");


    static_assert(sizeof(FrontFace) == sizeof(DawnFrontFace), "sizeof mismatch for FrontFace");
    static_assert(alignof(FrontFace) == alignof(DawnFrontFace), "alignof mismatch for FrontFace");

    static_assert(static_cast<uint32_t>(FrontFace::CCW) == DAWN_FRONT_FACE_CCW, "value mismatch for FrontFace::CCW");
    static_assert(static_cast<uint32_t>(FrontFace::CW) == DAWN_FRONT_FACE_CW, "value mismatch for FrontFace::CW");


    static_assert(sizeof(IndexFormat) == sizeof(DawnIndexFormat), "sizeof mismatch for IndexFormat");
    static_assert(alignof(IndexFormat) == alignof(DawnIndexFormat), "alignof mismatch for IndexFormat");

    static_assert(static_cast<uint32_t>(IndexFormat::Uint16) == DAWN_INDEX_FORMAT_UINT16, "value mismatch for IndexFormat::Uint16");
    static_assert(static_cast<uint32_t>(IndexFormat::Uint32) == DAWN_INDEX_FORMAT_UINT32, "value mismatch for IndexFormat::Uint32");


    static_assert(sizeof(InputStepMode) == sizeof(DawnInputStepMode), "sizeof mismatch for InputStepMode");
    static_assert(alignof(InputStepMode) == alignof(DawnInputStepMode), "alignof mismatch for InputStepMode");

    static_assert(static_cast<uint32_t>(InputStepMode::Vertex) == DAWN_INPUT_STEP_MODE_VERTEX, "value mismatch for InputStepMode::Vertex");
    static_assert(static_cast<uint32_t>(InputStepMode::Instance) == DAWN_INPUT_STEP_MODE_INSTANCE, "value mismatch for InputStepMode::Instance");


    static_assert(sizeof(LoadOp) == sizeof(DawnLoadOp), "sizeof mismatch for LoadOp");
    static_assert(alignof(LoadOp) == alignof(DawnLoadOp), "alignof mismatch for LoadOp");

    static_assert(static_cast<uint32_t>(LoadOp::Clear) == DAWN_LOAD_OP_CLEAR, "value mismatch for LoadOp::Clear");
    static_assert(static_cast<uint32_t>(LoadOp::Load) == DAWN_LOAD_OP_LOAD, "value mismatch for LoadOp::Load");


    static_assert(sizeof(PrimitiveTopology) == sizeof(DawnPrimitiveTopology), "sizeof mismatch for PrimitiveTopology");
    static_assert(alignof(PrimitiveTopology) == alignof(DawnPrimitiveTopology), "alignof mismatch for PrimitiveTopology");

    static_assert(static_cast<uint32_t>(PrimitiveTopology::PointList) == DAWN_PRIMITIVE_TOPOLOGY_POINT_LIST, "value mismatch for PrimitiveTopology::PointList");
    static_assert(static_cast<uint32_t>(PrimitiveTopology::LineList) == DAWN_PRIMITIVE_TOPOLOGY_LINE_LIST, "value mismatch for PrimitiveTopology::LineList");
    static_assert(static_cast<uint32_t>(PrimitiveTopology::LineStrip) == DAWN_PRIMITIVE_TOPOLOGY_LINE_STRIP, "value mismatch for PrimitiveTopology::LineStrip");
    static_assert(static_cast<uint32_t>(PrimitiveTopology::TriangleList) == DAWN_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, "value mismatch for PrimitiveTopology::TriangleList");
    static_assert(static_cast<uint32_t>(PrimitiveTopology::TriangleStrip) == DAWN_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP, "value mismatch for PrimitiveTopology::TriangleStrip");


    static_assert(sizeof(StencilOperation) == sizeof(DawnStencilOperation), "sizeof mismatch for StencilOperation");
    static_assert(alignof(StencilOperation) == alignof(DawnStencilOperation), "alignof mismatch for StencilOperation");

    static_assert(static_cast<uint32_t>(StencilOperation::Keep) == DAWN_STENCIL_OPERATION_KEEP, "value mismatch for StencilOperation::Keep");
    static_assert(static_cast<uint32_t>(StencilOperation::Zero) == DAWN_STENCIL_OPERATION_ZERO, "value mismatch for StencilOperation::Zero");
    static_assert(static_cast<uint32_t>(StencilOperation::Replace) == DAWN_STENCIL_OPERATION_REPLACE, "value mismatch for StencilOperation::Replace");
    static_assert(static_cast<uint32_t>(StencilOperation::Invert) == DAWN_STENCIL_OPERATION_INVERT, "value mismatch for StencilOperation::Invert");
    static_assert(static_cast<uint32_t>(StencilOperation::IncrementClamp) == DAWN_STENCIL_OPERATION_INCREMENT_CLAMP, "value mismatch for StencilOperation::IncrementClamp");
    static_assert(static_cast<uint32_t>(StencilOperation::DecrementClamp) == DAWN_STENCIL_OPERATION_DECREMENT_CLAMP, "value mismatch for StencilOperation::DecrementClamp");
    static_assert(static_cast<uint32_t>(StencilOperation::IncrementWrap) == DAWN_STENCIL_OPERATION_INCREMENT_WRAP, "value mismatch for StencilOperation::IncrementWrap");
    static_assert(static_cast<uint32_t>(StencilOperation::DecrementWrap) == DAWN_STENCIL_OPERATION_DECREMENT_WRAP, "value mismatch for StencilOperation::DecrementWrap");


    static_assert(sizeof(StoreOp) == sizeof(DawnStoreOp), "sizeof mismatch for StoreOp");
    static_assert(alignof(StoreOp) == alignof(DawnStoreOp), "alignof mismatch for StoreOp");

    static_assert(static_cast<uint32_t>(StoreOp::Store) == DAWN_STORE_OP_STORE, "value mismatch for StoreOp::Store");
    static_assert(static_cast<uint32_t>(StoreOp::Clear) == DAWN_STORE_OP_CLEAR, "value mismatch for StoreOp::Clear");


    static_assert(sizeof(TextureAspect) == sizeof(DawnTextureAspect), "sizeof mismatch for TextureAspect");
    static_assert(alignof(TextureAspect) == alignof(DawnTextureAspect), "alignof mismatch for TextureAspect");

    static_assert(static_cast<uint32_t>(TextureAspect::All) == DAWN_TEXTURE_ASPECT_ALL, "value mismatch for TextureAspect::All");
    static_assert(static_cast<uint32_t>(TextureAspect::StencilOnly) == DAWN_TEXTURE_ASPECT_STENCIL_ONLY, "value mismatch for TextureAspect::StencilOnly");
    static_assert(static_cast<uint32_t>(TextureAspect::DepthOnly) == DAWN_TEXTURE_ASPECT_DEPTH_ONLY, "value mismatch for TextureAspect::DepthOnly");


    static_assert(sizeof(TextureComponentType) == sizeof(DawnTextureComponentType), "sizeof mismatch for TextureComponentType");
    static_assert(alignof(TextureComponentType) == alignof(DawnTextureComponentType), "alignof mismatch for TextureComponentType");

    static_assert(static_cast<uint32_t>(TextureComponentType::Float) == DAWN_TEXTURE_COMPONENT_TYPE_FLOAT, "value mismatch for TextureComponentType::Float");
    static_assert(static_cast<uint32_t>(TextureComponentType::Sint) == DAWN_TEXTURE_COMPONENT_TYPE_SINT, "value mismatch for TextureComponentType::Sint");
    static_assert(static_cast<uint32_t>(TextureComponentType::Uint) == DAWN_TEXTURE_COMPONENT_TYPE_UINT, "value mismatch for TextureComponentType::Uint");


    static_assert(sizeof(TextureDimension) == sizeof(DawnTextureDimension), "sizeof mismatch for TextureDimension");
    static_assert(alignof(TextureDimension) == alignof(DawnTextureDimension), "alignof mismatch for TextureDimension");

    static_assert(static_cast<uint32_t>(TextureDimension::e1D) == DAWN_TEXTURE_DIMENSION_1D, "value mismatch for TextureDimension::e1D");
    static_assert(static_cast<uint32_t>(TextureDimension::e2D) == DAWN_TEXTURE_DIMENSION_2D, "value mismatch for TextureDimension::e2D");
    static_assert(static_cast<uint32_t>(TextureDimension::e3D) == DAWN_TEXTURE_DIMENSION_3D, "value mismatch for TextureDimension::e3D");


    static_assert(sizeof(TextureFormat) == sizeof(DawnTextureFormat), "sizeof mismatch for TextureFormat");
    static_assert(alignof(TextureFormat) == alignof(DawnTextureFormat), "alignof mismatch for TextureFormat");

    static_assert(static_cast<uint32_t>(TextureFormat::Undefined) == DAWN_TEXTURE_FORMAT_UNDEFINED, "value mismatch for TextureFormat::Undefined");
    static_assert(static_cast<uint32_t>(TextureFormat::R8Unorm) == DAWN_TEXTURE_FORMAT_R8_UNORM, "value mismatch for TextureFormat::R8Unorm");
    static_assert(static_cast<uint32_t>(TextureFormat::R8Snorm) == DAWN_TEXTURE_FORMAT_R8_SNORM, "value mismatch for TextureFormat::R8Snorm");
    static_assert(static_cast<uint32_t>(TextureFormat::R8Uint) == DAWN_TEXTURE_FORMAT_R8_UINT, "value mismatch for TextureFormat::R8Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::R8Sint) == DAWN_TEXTURE_FORMAT_R8_SINT, "value mismatch for TextureFormat::R8Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::R16Uint) == DAWN_TEXTURE_FORMAT_R16_UINT, "value mismatch for TextureFormat::R16Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::R16Sint) == DAWN_TEXTURE_FORMAT_R16_SINT, "value mismatch for TextureFormat::R16Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::R16Float) == DAWN_TEXTURE_FORMAT_R16_FLOAT, "value mismatch for TextureFormat::R16Float");
    static_assert(static_cast<uint32_t>(TextureFormat::RG8Unorm) == DAWN_TEXTURE_FORMAT_RG8_UNORM, "value mismatch for TextureFormat::RG8Unorm");
    static_assert(static_cast<uint32_t>(TextureFormat::RG8Snorm) == DAWN_TEXTURE_FORMAT_RG8_SNORM, "value mismatch for TextureFormat::RG8Snorm");
    static_assert(static_cast<uint32_t>(TextureFormat::RG8Uint) == DAWN_TEXTURE_FORMAT_RG8_UINT, "value mismatch for TextureFormat::RG8Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::RG8Sint) == DAWN_TEXTURE_FORMAT_RG8_SINT, "value mismatch for TextureFormat::RG8Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::R32Float) == DAWN_TEXTURE_FORMAT_R32_FLOAT, "value mismatch for TextureFormat::R32Float");
    static_assert(static_cast<uint32_t>(TextureFormat::R32Uint) == DAWN_TEXTURE_FORMAT_R32_UINT, "value mismatch for TextureFormat::R32Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::R32Sint) == DAWN_TEXTURE_FORMAT_R32_SINT, "value mismatch for TextureFormat::R32Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::RG16Uint) == DAWN_TEXTURE_FORMAT_RG16_UINT, "value mismatch for TextureFormat::RG16Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::RG16Sint) == DAWN_TEXTURE_FORMAT_RG16_SINT, "value mismatch for TextureFormat::RG16Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::RG16Float) == DAWN_TEXTURE_FORMAT_RG16_FLOAT, "value mismatch for TextureFormat::RG16Float");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA8Unorm) == DAWN_TEXTURE_FORMAT_RGBA8_UNORM, "value mismatch for TextureFormat::RGBA8Unorm");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA8UnormSrgb) == DAWN_TEXTURE_FORMAT_RGBA8_UNORM_SRGB, "value mismatch for TextureFormat::RGBA8UnormSrgb");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA8Snorm) == DAWN_TEXTURE_FORMAT_RGBA8_SNORM, "value mismatch for TextureFormat::RGBA8Snorm");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA8Uint) == DAWN_TEXTURE_FORMAT_RGBA8_UINT, "value mismatch for TextureFormat::RGBA8Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA8Sint) == DAWN_TEXTURE_FORMAT_RGBA8_SINT, "value mismatch for TextureFormat::RGBA8Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::BGRA8Unorm) == DAWN_TEXTURE_FORMAT_BGRA8_UNORM, "value mismatch for TextureFormat::BGRA8Unorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BGRA8UnormSrgb) == DAWN_TEXTURE_FORMAT_BGRA8_UNORM_SRGB, "value mismatch for TextureFormat::BGRA8UnormSrgb");
    static_assert(static_cast<uint32_t>(TextureFormat::RGB10A2Unorm) == DAWN_TEXTURE_FORMAT_RGB10_A2_UNORM, "value mismatch for TextureFormat::RGB10A2Unorm");
    static_assert(static_cast<uint32_t>(TextureFormat::RG11B10Float) == DAWN_TEXTURE_FORMAT_RG11_B10_FLOAT, "value mismatch for TextureFormat::RG11B10Float");
    static_assert(static_cast<uint32_t>(TextureFormat::RG32Float) == DAWN_TEXTURE_FORMAT_RG32_FLOAT, "value mismatch for TextureFormat::RG32Float");
    static_assert(static_cast<uint32_t>(TextureFormat::RG32Uint) == DAWN_TEXTURE_FORMAT_RG32_UINT, "value mismatch for TextureFormat::RG32Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::RG32Sint) == DAWN_TEXTURE_FORMAT_RG32_SINT, "value mismatch for TextureFormat::RG32Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA16Uint) == DAWN_TEXTURE_FORMAT_RGBA16_UINT, "value mismatch for TextureFormat::RGBA16Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA16Sint) == DAWN_TEXTURE_FORMAT_RGBA16_SINT, "value mismatch for TextureFormat::RGBA16Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA16Float) == DAWN_TEXTURE_FORMAT_RGBA16_FLOAT, "value mismatch for TextureFormat::RGBA16Float");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA32Float) == DAWN_TEXTURE_FORMAT_RGBA32_FLOAT, "value mismatch for TextureFormat::RGBA32Float");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA32Uint) == DAWN_TEXTURE_FORMAT_RGBA32_UINT, "value mismatch for TextureFormat::RGBA32Uint");
    static_assert(static_cast<uint32_t>(TextureFormat::RGBA32Sint) == DAWN_TEXTURE_FORMAT_RGBA32_SINT, "value mismatch for TextureFormat::RGBA32Sint");
    static_assert(static_cast<uint32_t>(TextureFormat::Depth32Float) == DAWN_TEXTURE_FORMAT_DEPTH32_FLOAT, "value mismatch for TextureFormat::Depth32Float");
    static_assert(static_cast<uint32_t>(TextureFormat::Depth24Plus) == DAWN_TEXTURE_FORMAT_DEPTH24_PLUS, "value mismatch for TextureFormat::Depth24Plus");
    static_assert(static_cast<uint32_t>(TextureFormat::Depth24PlusStencil8) == DAWN_TEXTURE_FORMAT_DEPTH24_PLUS_STENCIL8, "value mismatch for TextureFormat::Depth24PlusStencil8");
    static_assert(static_cast<uint32_t>(TextureFormat::BC1RGBAUnorm) == DAWN_TEXTURE_FORMAT_BC1_RGBA_UNORM, "value mismatch for TextureFormat::BC1RGBAUnorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BC1RGBAUnormSrgb) == DAWN_TEXTURE_FORMAT_BC1_RGBA_UNORM_SRGB, "value mismatch for TextureFormat::BC1RGBAUnormSrgb");
    static_assert(static_cast<uint32_t>(TextureFormat::BC2RGBAUnorm) == DAWN_TEXTURE_FORMAT_BC2_RGBA_UNORM, "value mismatch for TextureFormat::BC2RGBAUnorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BC2RGBAUnormSrgb) == DAWN_TEXTURE_FORMAT_BC2_RGBA_UNORM_SRGB, "value mismatch for TextureFormat::BC2RGBAUnormSrgb");
    static_assert(static_cast<uint32_t>(TextureFormat::BC3RGBAUnorm) == DAWN_TEXTURE_FORMAT_BC3_RGBA_UNORM, "value mismatch for TextureFormat::BC3RGBAUnorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BC3RGBAUnormSrgb) == DAWN_TEXTURE_FORMAT_BC3_RGBA_UNORM_SRGB, "value mismatch for TextureFormat::BC3RGBAUnormSrgb");
    static_assert(static_cast<uint32_t>(TextureFormat::BC4RUnorm) == DAWN_TEXTURE_FORMAT_BC4_R_UNORM, "value mismatch for TextureFormat::BC4RUnorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BC4RSnorm) == DAWN_TEXTURE_FORMAT_BC4_R_SNORM, "value mismatch for TextureFormat::BC4RSnorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BC5RGUnorm) == DAWN_TEXTURE_FORMAT_BC5_RG_UNORM, "value mismatch for TextureFormat::BC5RGUnorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BC5RGSnorm) == DAWN_TEXTURE_FORMAT_BC5_RG_SNORM, "value mismatch for TextureFormat::BC5RGSnorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BC6HRGBUfloat) == DAWN_TEXTURE_FORMAT_BC6H_RGB_UFLOAT, "value mismatch for TextureFormat::BC6HRGBUfloat");
    static_assert(static_cast<uint32_t>(TextureFormat::BC6HRGBSfloat) == DAWN_TEXTURE_FORMAT_BC6H_RGB_SFLOAT, "value mismatch for TextureFormat::BC6HRGBSfloat");
    static_assert(static_cast<uint32_t>(TextureFormat::BC7RGBAUnorm) == DAWN_TEXTURE_FORMAT_BC7_RGBA_UNORM, "value mismatch for TextureFormat::BC7RGBAUnorm");
    static_assert(static_cast<uint32_t>(TextureFormat::BC7RGBAUnormSrgb) == DAWN_TEXTURE_FORMAT_BC7_RGBA_UNORM_SRGB, "value mismatch for TextureFormat::BC7RGBAUnormSrgb");


    static_assert(sizeof(TextureViewDimension) == sizeof(DawnTextureViewDimension), "sizeof mismatch for TextureViewDimension");
    static_assert(alignof(TextureViewDimension) == alignof(DawnTextureViewDimension), "alignof mismatch for TextureViewDimension");

    static_assert(static_cast<uint32_t>(TextureViewDimension::Undefined) == DAWN_TEXTURE_VIEW_DIMENSION_UNDEFINED, "value mismatch for TextureViewDimension::Undefined");
    static_assert(static_cast<uint32_t>(TextureViewDimension::e1D) == DAWN_TEXTURE_VIEW_DIMENSION_1D, "value mismatch for TextureViewDimension::e1D");
    static_assert(static_cast<uint32_t>(TextureViewDimension::e2D) == DAWN_TEXTURE_VIEW_DIMENSION_2D, "value mismatch for TextureViewDimension::e2D");
    static_assert(static_cast<uint32_t>(TextureViewDimension::e2DArray) == DAWN_TEXTURE_VIEW_DIMENSION_2D_ARRAY, "value mismatch for TextureViewDimension::e2DArray");
    static_assert(static_cast<uint32_t>(TextureViewDimension::Cube) == DAWN_TEXTURE_VIEW_DIMENSION_CUBE, "value mismatch for TextureViewDimension::Cube");
    static_assert(static_cast<uint32_t>(TextureViewDimension::CubeArray) == DAWN_TEXTURE_VIEW_DIMENSION_CUBE_ARRAY, "value mismatch for TextureViewDimension::CubeArray");
    static_assert(static_cast<uint32_t>(TextureViewDimension::e3D) == DAWN_TEXTURE_VIEW_DIMENSION_3D, "value mismatch for TextureViewDimension::e3D");


    static_assert(sizeof(VertexFormat) == sizeof(DawnVertexFormat), "sizeof mismatch for VertexFormat");
    static_assert(alignof(VertexFormat) == alignof(DawnVertexFormat), "alignof mismatch for VertexFormat");

    static_assert(static_cast<uint32_t>(VertexFormat::UChar2) == DAWN_VERTEX_FORMAT_UCHAR2, "value mismatch for VertexFormat::UChar2");
    static_assert(static_cast<uint32_t>(VertexFormat::UChar4) == DAWN_VERTEX_FORMAT_UCHAR4, "value mismatch for VertexFormat::UChar4");
    static_assert(static_cast<uint32_t>(VertexFormat::Char2) == DAWN_VERTEX_FORMAT_CHAR2, "value mismatch for VertexFormat::Char2");
    static_assert(static_cast<uint32_t>(VertexFormat::Char4) == DAWN_VERTEX_FORMAT_CHAR4, "value mismatch for VertexFormat::Char4");
    static_assert(static_cast<uint32_t>(VertexFormat::UChar2Norm) == DAWN_VERTEX_FORMAT_UCHAR2_NORM, "value mismatch for VertexFormat::UChar2Norm");
    static_assert(static_cast<uint32_t>(VertexFormat::UChar4Norm) == DAWN_VERTEX_FORMAT_UCHAR4_NORM, "value mismatch for VertexFormat::UChar4Norm");
    static_assert(static_cast<uint32_t>(VertexFormat::Char2Norm) == DAWN_VERTEX_FORMAT_CHAR2_NORM, "value mismatch for VertexFormat::Char2Norm");
    static_assert(static_cast<uint32_t>(VertexFormat::Char4Norm) == DAWN_VERTEX_FORMAT_CHAR4_NORM, "value mismatch for VertexFormat::Char4Norm");
    static_assert(static_cast<uint32_t>(VertexFormat::UShort2) == DAWN_VERTEX_FORMAT_USHORT2, "value mismatch for VertexFormat::UShort2");
    static_assert(static_cast<uint32_t>(VertexFormat::UShort4) == DAWN_VERTEX_FORMAT_USHORT4, "value mismatch for VertexFormat::UShort4");
    static_assert(static_cast<uint32_t>(VertexFormat::Short2) == DAWN_VERTEX_FORMAT_SHORT2, "value mismatch for VertexFormat::Short2");
    static_assert(static_cast<uint32_t>(VertexFormat::Short4) == DAWN_VERTEX_FORMAT_SHORT4, "value mismatch for VertexFormat::Short4");
    static_assert(static_cast<uint32_t>(VertexFormat::UShort2Norm) == DAWN_VERTEX_FORMAT_USHORT2_NORM, "value mismatch for VertexFormat::UShort2Norm");
    static_assert(static_cast<uint32_t>(VertexFormat::UShort4Norm) == DAWN_VERTEX_FORMAT_USHORT4_NORM, "value mismatch for VertexFormat::UShort4Norm");
    static_assert(static_cast<uint32_t>(VertexFormat::Short2Norm) == DAWN_VERTEX_FORMAT_SHORT2_NORM, "value mismatch for VertexFormat::Short2Norm");
    static_assert(static_cast<uint32_t>(VertexFormat::Short4Norm) == DAWN_VERTEX_FORMAT_SHORT4_NORM, "value mismatch for VertexFormat::Short4Norm");
    static_assert(static_cast<uint32_t>(VertexFormat::Half2) == DAWN_VERTEX_FORMAT_HALF2, "value mismatch for VertexFormat::Half2");
    static_assert(static_cast<uint32_t>(VertexFormat::Half4) == DAWN_VERTEX_FORMAT_HALF4, "value mismatch for VertexFormat::Half4");
    static_assert(static_cast<uint32_t>(VertexFormat::Float) == DAWN_VERTEX_FORMAT_FLOAT, "value mismatch for VertexFormat::Float");
    static_assert(static_cast<uint32_t>(VertexFormat::Float2) == DAWN_VERTEX_FORMAT_FLOAT2, "value mismatch for VertexFormat::Float2");
    static_assert(static_cast<uint32_t>(VertexFormat::Float3) == DAWN_VERTEX_FORMAT_FLOAT3, "value mismatch for VertexFormat::Float3");
    static_assert(static_cast<uint32_t>(VertexFormat::Float4) == DAWN_VERTEX_FORMAT_FLOAT4, "value mismatch for VertexFormat::Float4");
    static_assert(static_cast<uint32_t>(VertexFormat::UInt) == DAWN_VERTEX_FORMAT_UINT, "value mismatch for VertexFormat::UInt");
    static_assert(static_cast<uint32_t>(VertexFormat::UInt2) == DAWN_VERTEX_FORMAT_UINT2, "value mismatch for VertexFormat::UInt2");
    static_assert(static_cast<uint32_t>(VertexFormat::UInt3) == DAWN_VERTEX_FORMAT_UINT3, "value mismatch for VertexFormat::UInt3");
    static_assert(static_cast<uint32_t>(VertexFormat::UInt4) == DAWN_VERTEX_FORMAT_UINT4, "value mismatch for VertexFormat::UInt4");
    static_assert(static_cast<uint32_t>(VertexFormat::Int) == DAWN_VERTEX_FORMAT_INT, "value mismatch for VertexFormat::Int");
    static_assert(static_cast<uint32_t>(VertexFormat::Int2) == DAWN_VERTEX_FORMAT_INT2, "value mismatch for VertexFormat::Int2");
    static_assert(static_cast<uint32_t>(VertexFormat::Int3) == DAWN_VERTEX_FORMAT_INT3, "value mismatch for VertexFormat::Int3");
    static_assert(static_cast<uint32_t>(VertexFormat::Int4) == DAWN_VERTEX_FORMAT_INT4, "value mismatch for VertexFormat::Int4");


    static_assert(sizeof(BufferUsage) == sizeof(DawnBufferUsage), "sizeof mismatch for BufferUsage");
    static_assert(alignof(BufferUsage) == alignof(DawnBufferUsage), "alignof mismatch for BufferUsage");

    static_assert(static_cast<uint32_t>(BufferUsage::None) == DAWN_BUFFER_USAGE_NONE, "value mismatch for BufferUsage::None");
    static_assert(static_cast<uint32_t>(BufferUsage::MapRead) == DAWN_BUFFER_USAGE_MAP_READ, "value mismatch for BufferUsage::MapRead");
    static_assert(static_cast<uint32_t>(BufferUsage::MapWrite) == DAWN_BUFFER_USAGE_MAP_WRITE, "value mismatch for BufferUsage::MapWrite");
    static_assert(static_cast<uint32_t>(BufferUsage::CopySrc) == DAWN_BUFFER_USAGE_COPY_SRC, "value mismatch for BufferUsage::CopySrc");
    static_assert(static_cast<uint32_t>(BufferUsage::CopyDst) == DAWN_BUFFER_USAGE_COPY_DST, "value mismatch for BufferUsage::CopyDst");
    static_assert(static_cast<uint32_t>(BufferUsage::Index) == DAWN_BUFFER_USAGE_INDEX, "value mismatch for BufferUsage::Index");
    static_assert(static_cast<uint32_t>(BufferUsage::Vertex) == DAWN_BUFFER_USAGE_VERTEX, "value mismatch for BufferUsage::Vertex");
    static_assert(static_cast<uint32_t>(BufferUsage::Uniform) == DAWN_BUFFER_USAGE_UNIFORM, "value mismatch for BufferUsage::Uniform");
    static_assert(static_cast<uint32_t>(BufferUsage::Storage) == DAWN_BUFFER_USAGE_STORAGE, "value mismatch for BufferUsage::Storage");
    static_assert(static_cast<uint32_t>(BufferUsage::Indirect) == DAWN_BUFFER_USAGE_INDIRECT, "value mismatch for BufferUsage::Indirect");


    static_assert(sizeof(ColorWriteMask) == sizeof(DawnColorWriteMask), "sizeof mismatch for ColorWriteMask");
    static_assert(alignof(ColorWriteMask) == alignof(DawnColorWriteMask), "alignof mismatch for ColorWriteMask");

    static_assert(static_cast<uint32_t>(ColorWriteMask::None) == DAWN_COLOR_WRITE_MASK_NONE, "value mismatch for ColorWriteMask::None");
    static_assert(static_cast<uint32_t>(ColorWriteMask::Red) == DAWN_COLOR_WRITE_MASK_RED, "value mismatch for ColorWriteMask::Red");
    static_assert(static_cast<uint32_t>(ColorWriteMask::Green) == DAWN_COLOR_WRITE_MASK_GREEN, "value mismatch for ColorWriteMask::Green");
    static_assert(static_cast<uint32_t>(ColorWriteMask::Blue) == DAWN_COLOR_WRITE_MASK_BLUE, "value mismatch for ColorWriteMask::Blue");
    static_assert(static_cast<uint32_t>(ColorWriteMask::Alpha) == DAWN_COLOR_WRITE_MASK_ALPHA, "value mismatch for ColorWriteMask::Alpha");
    static_assert(static_cast<uint32_t>(ColorWriteMask::All) == DAWN_COLOR_WRITE_MASK_ALL, "value mismatch for ColorWriteMask::All");


    static_assert(sizeof(ShaderStage) == sizeof(DawnShaderStage), "sizeof mismatch for ShaderStage");
    static_assert(alignof(ShaderStage) == alignof(DawnShaderStage), "alignof mismatch for ShaderStage");

    static_assert(static_cast<uint32_t>(ShaderStage::None) == DAWN_SHADER_STAGE_NONE, "value mismatch for ShaderStage::None");
    static_assert(static_cast<uint32_t>(ShaderStage::Vertex) == DAWN_SHADER_STAGE_VERTEX, "value mismatch for ShaderStage::Vertex");
    static_assert(static_cast<uint32_t>(ShaderStage::Fragment) == DAWN_SHADER_STAGE_FRAGMENT, "value mismatch for ShaderStage::Fragment");
    static_assert(static_cast<uint32_t>(ShaderStage::Compute) == DAWN_SHADER_STAGE_COMPUTE, "value mismatch for ShaderStage::Compute");


    static_assert(sizeof(TextureUsage) == sizeof(DawnTextureUsage), "sizeof mismatch for TextureUsage");
    static_assert(alignof(TextureUsage) == alignof(DawnTextureUsage), "alignof mismatch for TextureUsage");

    static_assert(static_cast<uint32_t>(TextureUsage::None) == DAWN_TEXTURE_USAGE_NONE, "value mismatch for TextureUsage::None");
    static_assert(static_cast<uint32_t>(TextureUsage::CopySrc) == DAWN_TEXTURE_USAGE_COPY_SRC, "value mismatch for TextureUsage::CopySrc");
    static_assert(static_cast<uint32_t>(TextureUsage::CopyDst) == DAWN_TEXTURE_USAGE_COPY_DST, "value mismatch for TextureUsage::CopyDst");
    static_assert(static_cast<uint32_t>(TextureUsage::Sampled) == DAWN_TEXTURE_USAGE_SAMPLED, "value mismatch for TextureUsage::Sampled");
    static_assert(static_cast<uint32_t>(TextureUsage::Storage) == DAWN_TEXTURE_USAGE_STORAGE, "value mismatch for TextureUsage::Storage");
    static_assert(static_cast<uint32_t>(TextureUsage::OutputAttachment) == DAWN_TEXTURE_USAGE_OUTPUT_ATTACHMENT, "value mismatch for TextureUsage::OutputAttachment");
    static_assert(static_cast<uint32_t>(TextureUsage::Present) == DAWN_TEXTURE_USAGE_PRESENT, "value mismatch for TextureUsage::Present");




    static_assert(sizeof(BindGroupBinding) == sizeof(DawnBindGroupBinding), "sizeof mismatch for BindGroupBinding");
    static_assert(alignof(BindGroupBinding) == alignof(DawnBindGroupBinding), "alignof mismatch for BindGroupBinding");

    static_assert(offsetof(BindGroupBinding, binding) == offsetof(DawnBindGroupBinding, binding),
            "offsetof mismatch for BindGroupBinding::binding");
    static_assert(offsetof(BindGroupBinding, buffer) == offsetof(DawnBindGroupBinding, buffer),
            "offsetof mismatch for BindGroupBinding::buffer");
    static_assert(offsetof(BindGroupBinding, offset) == offsetof(DawnBindGroupBinding, offset),
            "offsetof mismatch for BindGroupBinding::offset");
    static_assert(offsetof(BindGroupBinding, size) == offsetof(DawnBindGroupBinding, size),
            "offsetof mismatch for BindGroupBinding::size");
    static_assert(offsetof(BindGroupBinding, sampler) == offsetof(DawnBindGroupBinding, sampler),
            "offsetof mismatch for BindGroupBinding::sampler");
    static_assert(offsetof(BindGroupBinding, textureView) == offsetof(DawnBindGroupBinding, textureView),
            "offsetof mismatch for BindGroupBinding::textureView");


    static_assert(sizeof(BindGroupLayoutBinding) == sizeof(DawnBindGroupLayoutBinding), "sizeof mismatch for BindGroupLayoutBinding");
    static_assert(alignof(BindGroupLayoutBinding) == alignof(DawnBindGroupLayoutBinding), "alignof mismatch for BindGroupLayoutBinding");

    static_assert(offsetof(BindGroupLayoutBinding, binding) == offsetof(DawnBindGroupLayoutBinding, binding),
            "offsetof mismatch for BindGroupLayoutBinding::binding");
    static_assert(offsetof(BindGroupLayoutBinding, visibility) == offsetof(DawnBindGroupLayoutBinding, visibility),
            "offsetof mismatch for BindGroupLayoutBinding::visibility");
    static_assert(offsetof(BindGroupLayoutBinding, type) == offsetof(DawnBindGroupLayoutBinding, type),
            "offsetof mismatch for BindGroupLayoutBinding::type");
    static_assert(offsetof(BindGroupLayoutBinding, hasDynamicOffset) == offsetof(DawnBindGroupLayoutBinding, hasDynamicOffset),
            "offsetof mismatch for BindGroupLayoutBinding::hasDynamicOffset");
    static_assert(offsetof(BindGroupLayoutBinding, multisampled) == offsetof(DawnBindGroupLayoutBinding, multisampled),
            "offsetof mismatch for BindGroupLayoutBinding::multisampled");
    static_assert(offsetof(BindGroupLayoutBinding, textureDimension) == offsetof(DawnBindGroupLayoutBinding, textureDimension),
            "offsetof mismatch for BindGroupLayoutBinding::textureDimension");
    static_assert(offsetof(BindGroupLayoutBinding, textureComponentType) == offsetof(DawnBindGroupLayoutBinding, textureComponentType),
            "offsetof mismatch for BindGroupLayoutBinding::textureComponentType");


    static_assert(sizeof(BlendDescriptor) == sizeof(DawnBlendDescriptor), "sizeof mismatch for BlendDescriptor");
    static_assert(alignof(BlendDescriptor) == alignof(DawnBlendDescriptor), "alignof mismatch for BlendDescriptor");

    static_assert(offsetof(BlendDescriptor, operation) == offsetof(DawnBlendDescriptor, operation),
            "offsetof mismatch for BlendDescriptor::operation");
    static_assert(offsetof(BlendDescriptor, srcFactor) == offsetof(DawnBlendDescriptor, srcFactor),
            "offsetof mismatch for BlendDescriptor::srcFactor");
    static_assert(offsetof(BlendDescriptor, dstFactor) == offsetof(DawnBlendDescriptor, dstFactor),
            "offsetof mismatch for BlendDescriptor::dstFactor");


    static_assert(sizeof(BufferCopyView) == sizeof(DawnBufferCopyView), "sizeof mismatch for BufferCopyView");
    static_assert(alignof(BufferCopyView) == alignof(DawnBufferCopyView), "alignof mismatch for BufferCopyView");

    static_assert(offsetof(BufferCopyView, nextInChain) == offsetof(DawnBufferCopyView, nextInChain),
            "offsetof mismatch for BufferCopyView::nextInChain");
    static_assert(offsetof(BufferCopyView, buffer) == offsetof(DawnBufferCopyView, buffer),
            "offsetof mismatch for BufferCopyView::buffer");
    static_assert(offsetof(BufferCopyView, offset) == offsetof(DawnBufferCopyView, offset),
            "offsetof mismatch for BufferCopyView::offset");
    static_assert(offsetof(BufferCopyView, rowPitch) == offsetof(DawnBufferCopyView, rowPitch),
            "offsetof mismatch for BufferCopyView::rowPitch");
    static_assert(offsetof(BufferCopyView, imageHeight) == offsetof(DawnBufferCopyView, imageHeight),
            "offsetof mismatch for BufferCopyView::imageHeight");


    static_assert(sizeof(BufferDescriptor) == sizeof(DawnBufferDescriptor), "sizeof mismatch for BufferDescriptor");
    static_assert(alignof(BufferDescriptor) == alignof(DawnBufferDescriptor), "alignof mismatch for BufferDescriptor");

    static_assert(offsetof(BufferDescriptor, nextInChain) == offsetof(DawnBufferDescriptor, nextInChain),
            "offsetof mismatch for BufferDescriptor::nextInChain");
    static_assert(offsetof(BufferDescriptor, label) == offsetof(DawnBufferDescriptor, label),
            "offsetof mismatch for BufferDescriptor::label");
    static_assert(offsetof(BufferDescriptor, usage) == offsetof(DawnBufferDescriptor, usage),
            "offsetof mismatch for BufferDescriptor::usage");
    static_assert(offsetof(BufferDescriptor, size) == offsetof(DawnBufferDescriptor, size),
            "offsetof mismatch for BufferDescriptor::size");


    static_assert(sizeof(Color) == sizeof(DawnColor), "sizeof mismatch for Color");
    static_assert(alignof(Color) == alignof(DawnColor), "alignof mismatch for Color");

    static_assert(offsetof(Color, r) == offsetof(DawnColor, r),
            "offsetof mismatch for Color::r");
    static_assert(offsetof(Color, g) == offsetof(DawnColor, g),
            "offsetof mismatch for Color::g");
    static_assert(offsetof(Color, b) == offsetof(DawnColor, b),
            "offsetof mismatch for Color::b");
    static_assert(offsetof(Color, a) == offsetof(DawnColor, a),
            "offsetof mismatch for Color::a");


    static_assert(sizeof(CommandBufferDescriptor) == sizeof(DawnCommandBufferDescriptor), "sizeof mismatch for CommandBufferDescriptor");
    static_assert(alignof(CommandBufferDescriptor) == alignof(DawnCommandBufferDescriptor), "alignof mismatch for CommandBufferDescriptor");

    static_assert(offsetof(CommandBufferDescriptor, nextInChain) == offsetof(DawnCommandBufferDescriptor, nextInChain),
            "offsetof mismatch for CommandBufferDescriptor::nextInChain");
    static_assert(offsetof(CommandBufferDescriptor, label) == offsetof(DawnCommandBufferDescriptor, label),
            "offsetof mismatch for CommandBufferDescriptor::label");


    static_assert(sizeof(CommandEncoderDescriptor) == sizeof(DawnCommandEncoderDescriptor), "sizeof mismatch for CommandEncoderDescriptor");
    static_assert(alignof(CommandEncoderDescriptor) == alignof(DawnCommandEncoderDescriptor), "alignof mismatch for CommandEncoderDescriptor");

    static_assert(offsetof(CommandEncoderDescriptor, nextInChain) == offsetof(DawnCommandEncoderDescriptor, nextInChain),
            "offsetof mismatch for CommandEncoderDescriptor::nextInChain");
    static_assert(offsetof(CommandEncoderDescriptor, label) == offsetof(DawnCommandEncoderDescriptor, label),
            "offsetof mismatch for CommandEncoderDescriptor::label");


    static_assert(sizeof(ComputePassDescriptor) == sizeof(DawnComputePassDescriptor), "sizeof mismatch for ComputePassDescriptor");
    static_assert(alignof(ComputePassDescriptor) == alignof(DawnComputePassDescriptor), "alignof mismatch for ComputePassDescriptor");

    static_assert(offsetof(ComputePassDescriptor, nextInChain) == offsetof(DawnComputePassDescriptor, nextInChain),
            "offsetof mismatch for ComputePassDescriptor::nextInChain");
    static_assert(offsetof(ComputePassDescriptor, label) == offsetof(DawnComputePassDescriptor, label),
            "offsetof mismatch for ComputePassDescriptor::label");


    static_assert(sizeof(CreateBufferMappedResult) == sizeof(DawnCreateBufferMappedResult), "sizeof mismatch for CreateBufferMappedResult");
    static_assert(alignof(CreateBufferMappedResult) == alignof(DawnCreateBufferMappedResult), "alignof mismatch for CreateBufferMappedResult");

    static_assert(offsetof(CreateBufferMappedResult, buffer) == offsetof(DawnCreateBufferMappedResult, buffer),
            "offsetof mismatch for CreateBufferMappedResult::buffer");
    static_assert(offsetof(CreateBufferMappedResult, dataLength) == offsetof(DawnCreateBufferMappedResult, dataLength),
            "offsetof mismatch for CreateBufferMappedResult::dataLength");
    static_assert(offsetof(CreateBufferMappedResult, data) == offsetof(DawnCreateBufferMappedResult, data),
            "offsetof mismatch for CreateBufferMappedResult::data");


    static_assert(sizeof(Extent3D) == sizeof(DawnExtent3D), "sizeof mismatch for Extent3D");
    static_assert(alignof(Extent3D) == alignof(DawnExtent3D), "alignof mismatch for Extent3D");

    static_assert(offsetof(Extent3D, width) == offsetof(DawnExtent3D, width),
            "offsetof mismatch for Extent3D::width");
    static_assert(offsetof(Extent3D, height) == offsetof(DawnExtent3D, height),
            "offsetof mismatch for Extent3D::height");
    static_assert(offsetof(Extent3D, depth) == offsetof(DawnExtent3D, depth),
            "offsetof mismatch for Extent3D::depth");


    static_assert(sizeof(FenceDescriptor) == sizeof(DawnFenceDescriptor), "sizeof mismatch for FenceDescriptor");
    static_assert(alignof(FenceDescriptor) == alignof(DawnFenceDescriptor), "alignof mismatch for FenceDescriptor");

    static_assert(offsetof(FenceDescriptor, nextInChain) == offsetof(DawnFenceDescriptor, nextInChain),
            "offsetof mismatch for FenceDescriptor::nextInChain");
    static_assert(offsetof(FenceDescriptor, label) == offsetof(DawnFenceDescriptor, label),
            "offsetof mismatch for FenceDescriptor::label");
    static_assert(offsetof(FenceDescriptor, initialValue) == offsetof(DawnFenceDescriptor, initialValue),
            "offsetof mismatch for FenceDescriptor::initialValue");


    static_assert(sizeof(Origin3D) == sizeof(DawnOrigin3D), "sizeof mismatch for Origin3D");
    static_assert(alignof(Origin3D) == alignof(DawnOrigin3D), "alignof mismatch for Origin3D");

    static_assert(offsetof(Origin3D, x) == offsetof(DawnOrigin3D, x),
            "offsetof mismatch for Origin3D::x");
    static_assert(offsetof(Origin3D, y) == offsetof(DawnOrigin3D, y),
            "offsetof mismatch for Origin3D::y");
    static_assert(offsetof(Origin3D, z) == offsetof(DawnOrigin3D, z),
            "offsetof mismatch for Origin3D::z");


    static_assert(sizeof(PipelineLayoutDescriptor) == sizeof(DawnPipelineLayoutDescriptor), "sizeof mismatch for PipelineLayoutDescriptor");
    static_assert(alignof(PipelineLayoutDescriptor) == alignof(DawnPipelineLayoutDescriptor), "alignof mismatch for PipelineLayoutDescriptor");

    static_assert(offsetof(PipelineLayoutDescriptor, nextInChain) == offsetof(DawnPipelineLayoutDescriptor, nextInChain),
            "offsetof mismatch for PipelineLayoutDescriptor::nextInChain");
    static_assert(offsetof(PipelineLayoutDescriptor, label) == offsetof(DawnPipelineLayoutDescriptor, label),
            "offsetof mismatch for PipelineLayoutDescriptor::label");
    static_assert(offsetof(PipelineLayoutDescriptor, bindGroupLayoutCount) == offsetof(DawnPipelineLayoutDescriptor, bindGroupLayoutCount),
            "offsetof mismatch for PipelineLayoutDescriptor::bindGroupLayoutCount");
    static_assert(offsetof(PipelineLayoutDescriptor, bindGroupLayouts) == offsetof(DawnPipelineLayoutDescriptor, bindGroupLayouts),
            "offsetof mismatch for PipelineLayoutDescriptor::bindGroupLayouts");


    static_assert(sizeof(PipelineStageDescriptor) == sizeof(DawnPipelineStageDescriptor), "sizeof mismatch for PipelineStageDescriptor");
    static_assert(alignof(PipelineStageDescriptor) == alignof(DawnPipelineStageDescriptor), "alignof mismatch for PipelineStageDescriptor");

    static_assert(offsetof(PipelineStageDescriptor, nextInChain) == offsetof(DawnPipelineStageDescriptor, nextInChain),
            "offsetof mismatch for PipelineStageDescriptor::nextInChain");
    static_assert(offsetof(PipelineStageDescriptor, module) == offsetof(DawnPipelineStageDescriptor, module),
            "offsetof mismatch for PipelineStageDescriptor::module");
    static_assert(offsetof(PipelineStageDescriptor, entryPoint) == offsetof(DawnPipelineStageDescriptor, entryPoint),
            "offsetof mismatch for PipelineStageDescriptor::entryPoint");


    static_assert(sizeof(RasterizationStateDescriptor) == sizeof(DawnRasterizationStateDescriptor), "sizeof mismatch for RasterizationStateDescriptor");
    static_assert(alignof(RasterizationStateDescriptor) == alignof(DawnRasterizationStateDescriptor), "alignof mismatch for RasterizationStateDescriptor");

    static_assert(offsetof(RasterizationStateDescriptor, nextInChain) == offsetof(DawnRasterizationStateDescriptor, nextInChain),
            "offsetof mismatch for RasterizationStateDescriptor::nextInChain");
    static_assert(offsetof(RasterizationStateDescriptor, frontFace) == offsetof(DawnRasterizationStateDescriptor, frontFace),
            "offsetof mismatch for RasterizationStateDescriptor::frontFace");
    static_assert(offsetof(RasterizationStateDescriptor, cullMode) == offsetof(DawnRasterizationStateDescriptor, cullMode),
            "offsetof mismatch for RasterizationStateDescriptor::cullMode");
    static_assert(offsetof(RasterizationStateDescriptor, depthBias) == offsetof(DawnRasterizationStateDescriptor, depthBias),
            "offsetof mismatch for RasterizationStateDescriptor::depthBias");
    static_assert(offsetof(RasterizationStateDescriptor, depthBiasSlopeScale) == offsetof(DawnRasterizationStateDescriptor, depthBiasSlopeScale),
            "offsetof mismatch for RasterizationStateDescriptor::depthBiasSlopeScale");
    static_assert(offsetof(RasterizationStateDescriptor, depthBiasClamp) == offsetof(DawnRasterizationStateDescriptor, depthBiasClamp),
            "offsetof mismatch for RasterizationStateDescriptor::depthBiasClamp");


    static_assert(sizeof(RenderBundleDescriptor) == sizeof(DawnRenderBundleDescriptor), "sizeof mismatch for RenderBundleDescriptor");
    static_assert(alignof(RenderBundleDescriptor) == alignof(DawnRenderBundleDescriptor), "alignof mismatch for RenderBundleDescriptor");

    static_assert(offsetof(RenderBundleDescriptor, nextInChain) == offsetof(DawnRenderBundleDescriptor, nextInChain),
            "offsetof mismatch for RenderBundleDescriptor::nextInChain");
    static_assert(offsetof(RenderBundleDescriptor, label) == offsetof(DawnRenderBundleDescriptor, label),
            "offsetof mismatch for RenderBundleDescriptor::label");


    static_assert(sizeof(RenderBundleEncoderDescriptor) == sizeof(DawnRenderBundleEncoderDescriptor), "sizeof mismatch for RenderBundleEncoderDescriptor");
    static_assert(alignof(RenderBundleEncoderDescriptor) == alignof(DawnRenderBundleEncoderDescriptor), "alignof mismatch for RenderBundleEncoderDescriptor");

    static_assert(offsetof(RenderBundleEncoderDescriptor, nextInChain) == offsetof(DawnRenderBundleEncoderDescriptor, nextInChain),
            "offsetof mismatch for RenderBundleEncoderDescriptor::nextInChain");
    static_assert(offsetof(RenderBundleEncoderDescriptor, label) == offsetof(DawnRenderBundleEncoderDescriptor, label),
            "offsetof mismatch for RenderBundleEncoderDescriptor::label");
    static_assert(offsetof(RenderBundleEncoderDescriptor, colorFormatsCount) == offsetof(DawnRenderBundleEncoderDescriptor, colorFormatsCount),
            "offsetof mismatch for RenderBundleEncoderDescriptor::colorFormatsCount");
    static_assert(offsetof(RenderBundleEncoderDescriptor, colorFormats) == offsetof(DawnRenderBundleEncoderDescriptor, colorFormats),
            "offsetof mismatch for RenderBundleEncoderDescriptor::colorFormats");
    static_assert(offsetof(RenderBundleEncoderDescriptor, depthStencilFormat) == offsetof(DawnRenderBundleEncoderDescriptor, depthStencilFormat),
            "offsetof mismatch for RenderBundleEncoderDescriptor::depthStencilFormat");
    static_assert(offsetof(RenderBundleEncoderDescriptor, sampleCount) == offsetof(DawnRenderBundleEncoderDescriptor, sampleCount),
            "offsetof mismatch for RenderBundleEncoderDescriptor::sampleCount");


    static_assert(sizeof(RenderPassDepthStencilAttachmentDescriptor) == sizeof(DawnRenderPassDepthStencilAttachmentDescriptor), "sizeof mismatch for RenderPassDepthStencilAttachmentDescriptor");
    static_assert(alignof(RenderPassDepthStencilAttachmentDescriptor) == alignof(DawnRenderPassDepthStencilAttachmentDescriptor), "alignof mismatch for RenderPassDepthStencilAttachmentDescriptor");

    static_assert(offsetof(RenderPassDepthStencilAttachmentDescriptor, attachment) == offsetof(DawnRenderPassDepthStencilAttachmentDescriptor, attachment),
            "offsetof mismatch for RenderPassDepthStencilAttachmentDescriptor::attachment");
    static_assert(offsetof(RenderPassDepthStencilAttachmentDescriptor, depthLoadOp) == offsetof(DawnRenderPassDepthStencilAttachmentDescriptor, depthLoadOp),
            "offsetof mismatch for RenderPassDepthStencilAttachmentDescriptor::depthLoadOp");
    static_assert(offsetof(RenderPassDepthStencilAttachmentDescriptor, depthStoreOp) == offsetof(DawnRenderPassDepthStencilAttachmentDescriptor, depthStoreOp),
            "offsetof mismatch for RenderPassDepthStencilAttachmentDescriptor::depthStoreOp");
    static_assert(offsetof(RenderPassDepthStencilAttachmentDescriptor, clearDepth) == offsetof(DawnRenderPassDepthStencilAttachmentDescriptor, clearDepth),
            "offsetof mismatch for RenderPassDepthStencilAttachmentDescriptor::clearDepth");
    static_assert(offsetof(RenderPassDepthStencilAttachmentDescriptor, stencilLoadOp) == offsetof(DawnRenderPassDepthStencilAttachmentDescriptor, stencilLoadOp),
            "offsetof mismatch for RenderPassDepthStencilAttachmentDescriptor::stencilLoadOp");
    static_assert(offsetof(RenderPassDepthStencilAttachmentDescriptor, stencilStoreOp) == offsetof(DawnRenderPassDepthStencilAttachmentDescriptor, stencilStoreOp),
            "offsetof mismatch for RenderPassDepthStencilAttachmentDescriptor::stencilStoreOp");
    static_assert(offsetof(RenderPassDepthStencilAttachmentDescriptor, clearStencil) == offsetof(DawnRenderPassDepthStencilAttachmentDescriptor, clearStencil),
            "offsetof mismatch for RenderPassDepthStencilAttachmentDescriptor::clearStencil");


    static_assert(sizeof(SamplerDescriptor) == sizeof(DawnSamplerDescriptor), "sizeof mismatch for SamplerDescriptor");
    static_assert(alignof(SamplerDescriptor) == alignof(DawnSamplerDescriptor), "alignof mismatch for SamplerDescriptor");

    static_assert(offsetof(SamplerDescriptor, nextInChain) == offsetof(DawnSamplerDescriptor, nextInChain),
            "offsetof mismatch for SamplerDescriptor::nextInChain");
    static_assert(offsetof(SamplerDescriptor, label) == offsetof(DawnSamplerDescriptor, label),
            "offsetof mismatch for SamplerDescriptor::label");
    static_assert(offsetof(SamplerDescriptor, addressModeU) == offsetof(DawnSamplerDescriptor, addressModeU),
            "offsetof mismatch for SamplerDescriptor::addressModeU");
    static_assert(offsetof(SamplerDescriptor, addressModeV) == offsetof(DawnSamplerDescriptor, addressModeV),
            "offsetof mismatch for SamplerDescriptor::addressModeV");
    static_assert(offsetof(SamplerDescriptor, addressModeW) == offsetof(DawnSamplerDescriptor, addressModeW),
            "offsetof mismatch for SamplerDescriptor::addressModeW");
    static_assert(offsetof(SamplerDescriptor, magFilter) == offsetof(DawnSamplerDescriptor, magFilter),
            "offsetof mismatch for SamplerDescriptor::magFilter");
    static_assert(offsetof(SamplerDescriptor, minFilter) == offsetof(DawnSamplerDescriptor, minFilter),
            "offsetof mismatch for SamplerDescriptor::minFilter");
    static_assert(offsetof(SamplerDescriptor, mipmapFilter) == offsetof(DawnSamplerDescriptor, mipmapFilter),
            "offsetof mismatch for SamplerDescriptor::mipmapFilter");
    static_assert(offsetof(SamplerDescriptor, lodMinClamp) == offsetof(DawnSamplerDescriptor, lodMinClamp),
            "offsetof mismatch for SamplerDescriptor::lodMinClamp");
    static_assert(offsetof(SamplerDescriptor, lodMaxClamp) == offsetof(DawnSamplerDescriptor, lodMaxClamp),
            "offsetof mismatch for SamplerDescriptor::lodMaxClamp");
    static_assert(offsetof(SamplerDescriptor, compare) == offsetof(DawnSamplerDescriptor, compare),
            "offsetof mismatch for SamplerDescriptor::compare");


    static_assert(sizeof(ShaderModuleDescriptor) == sizeof(DawnShaderModuleDescriptor), "sizeof mismatch for ShaderModuleDescriptor");
    static_assert(alignof(ShaderModuleDescriptor) == alignof(DawnShaderModuleDescriptor), "alignof mismatch for ShaderModuleDescriptor");

    static_assert(offsetof(ShaderModuleDescriptor, nextInChain) == offsetof(DawnShaderModuleDescriptor, nextInChain),
            "offsetof mismatch for ShaderModuleDescriptor::nextInChain");
    static_assert(offsetof(ShaderModuleDescriptor, label) == offsetof(DawnShaderModuleDescriptor, label),
            "offsetof mismatch for ShaderModuleDescriptor::label");
    static_assert(offsetof(ShaderModuleDescriptor, codeSize) == offsetof(DawnShaderModuleDescriptor, codeSize),
            "offsetof mismatch for ShaderModuleDescriptor::codeSize");
    static_assert(offsetof(ShaderModuleDescriptor, code) == offsetof(DawnShaderModuleDescriptor, code),
            "offsetof mismatch for ShaderModuleDescriptor::code");


    static_assert(sizeof(StencilStateFaceDescriptor) == sizeof(DawnStencilStateFaceDescriptor), "sizeof mismatch for StencilStateFaceDescriptor");
    static_assert(alignof(StencilStateFaceDescriptor) == alignof(DawnStencilStateFaceDescriptor), "alignof mismatch for StencilStateFaceDescriptor");

    static_assert(offsetof(StencilStateFaceDescriptor, compare) == offsetof(DawnStencilStateFaceDescriptor, compare),
            "offsetof mismatch for StencilStateFaceDescriptor::compare");
    static_assert(offsetof(StencilStateFaceDescriptor, failOp) == offsetof(DawnStencilStateFaceDescriptor, failOp),
            "offsetof mismatch for StencilStateFaceDescriptor::failOp");
    static_assert(offsetof(StencilStateFaceDescriptor, depthFailOp) == offsetof(DawnStencilStateFaceDescriptor, depthFailOp),
            "offsetof mismatch for StencilStateFaceDescriptor::depthFailOp");
    static_assert(offsetof(StencilStateFaceDescriptor, passOp) == offsetof(DawnStencilStateFaceDescriptor, passOp),
            "offsetof mismatch for StencilStateFaceDescriptor::passOp");


    static_assert(sizeof(SwapChainDescriptor) == sizeof(DawnSwapChainDescriptor), "sizeof mismatch for SwapChainDescriptor");
    static_assert(alignof(SwapChainDescriptor) == alignof(DawnSwapChainDescriptor), "alignof mismatch for SwapChainDescriptor");

    static_assert(offsetof(SwapChainDescriptor, nextInChain) == offsetof(DawnSwapChainDescriptor, nextInChain),
            "offsetof mismatch for SwapChainDescriptor::nextInChain");
    static_assert(offsetof(SwapChainDescriptor, label) == offsetof(DawnSwapChainDescriptor, label),
            "offsetof mismatch for SwapChainDescriptor::label");
    static_assert(offsetof(SwapChainDescriptor, implementation) == offsetof(DawnSwapChainDescriptor, implementation),
            "offsetof mismatch for SwapChainDescriptor::implementation");


    static_assert(sizeof(TextureViewDescriptor) == sizeof(DawnTextureViewDescriptor), "sizeof mismatch for TextureViewDescriptor");
    static_assert(alignof(TextureViewDescriptor) == alignof(DawnTextureViewDescriptor), "alignof mismatch for TextureViewDescriptor");

    static_assert(offsetof(TextureViewDescriptor, nextInChain) == offsetof(DawnTextureViewDescriptor, nextInChain),
            "offsetof mismatch for TextureViewDescriptor::nextInChain");
    static_assert(offsetof(TextureViewDescriptor, label) == offsetof(DawnTextureViewDescriptor, label),
            "offsetof mismatch for TextureViewDescriptor::label");
    static_assert(offsetof(TextureViewDescriptor, format) == offsetof(DawnTextureViewDescriptor, format),
            "offsetof mismatch for TextureViewDescriptor::format");
    static_assert(offsetof(TextureViewDescriptor, dimension) == offsetof(DawnTextureViewDescriptor, dimension),
            "offsetof mismatch for TextureViewDescriptor::dimension");
    static_assert(offsetof(TextureViewDescriptor, baseMipLevel) == offsetof(DawnTextureViewDescriptor, baseMipLevel),
            "offsetof mismatch for TextureViewDescriptor::baseMipLevel");
    static_assert(offsetof(TextureViewDescriptor, mipLevelCount) == offsetof(DawnTextureViewDescriptor, mipLevelCount),
            "offsetof mismatch for TextureViewDescriptor::mipLevelCount");
    static_assert(offsetof(TextureViewDescriptor, baseArrayLayer) == offsetof(DawnTextureViewDescriptor, baseArrayLayer),
            "offsetof mismatch for TextureViewDescriptor::baseArrayLayer");
    static_assert(offsetof(TextureViewDescriptor, arrayLayerCount) == offsetof(DawnTextureViewDescriptor, arrayLayerCount),
            "offsetof mismatch for TextureViewDescriptor::arrayLayerCount");
    static_assert(offsetof(TextureViewDescriptor, aspect) == offsetof(DawnTextureViewDescriptor, aspect),
            "offsetof mismatch for TextureViewDescriptor::aspect");


    static_assert(sizeof(VertexAttributeDescriptor) == sizeof(DawnVertexAttributeDescriptor), "sizeof mismatch for VertexAttributeDescriptor");
    static_assert(alignof(VertexAttributeDescriptor) == alignof(DawnVertexAttributeDescriptor), "alignof mismatch for VertexAttributeDescriptor");

    static_assert(offsetof(VertexAttributeDescriptor, shaderLocation) == offsetof(DawnVertexAttributeDescriptor, shaderLocation),
            "offsetof mismatch for VertexAttributeDescriptor::shaderLocation");
    static_assert(offsetof(VertexAttributeDescriptor, offset) == offsetof(DawnVertexAttributeDescriptor, offset),
            "offsetof mismatch for VertexAttributeDescriptor::offset");
    static_assert(offsetof(VertexAttributeDescriptor, format) == offsetof(DawnVertexAttributeDescriptor, format),
            "offsetof mismatch for VertexAttributeDescriptor::format");


    static_assert(sizeof(BindGroupDescriptor) == sizeof(DawnBindGroupDescriptor), "sizeof mismatch for BindGroupDescriptor");
    static_assert(alignof(BindGroupDescriptor) == alignof(DawnBindGroupDescriptor), "alignof mismatch for BindGroupDescriptor");

    static_assert(offsetof(BindGroupDescriptor, nextInChain) == offsetof(DawnBindGroupDescriptor, nextInChain),
            "offsetof mismatch for BindGroupDescriptor::nextInChain");
    static_assert(offsetof(BindGroupDescriptor, label) == offsetof(DawnBindGroupDescriptor, label),
            "offsetof mismatch for BindGroupDescriptor::label");
    static_assert(offsetof(BindGroupDescriptor, layout) == offsetof(DawnBindGroupDescriptor, layout),
            "offsetof mismatch for BindGroupDescriptor::layout");
    static_assert(offsetof(BindGroupDescriptor, bindingCount) == offsetof(DawnBindGroupDescriptor, bindingCount),
            "offsetof mismatch for BindGroupDescriptor::bindingCount");
    static_assert(offsetof(BindGroupDescriptor, bindings) == offsetof(DawnBindGroupDescriptor, bindings),
            "offsetof mismatch for BindGroupDescriptor::bindings");


    static_assert(sizeof(BindGroupLayoutDescriptor) == sizeof(DawnBindGroupLayoutDescriptor), "sizeof mismatch for BindGroupLayoutDescriptor");
    static_assert(alignof(BindGroupLayoutDescriptor) == alignof(DawnBindGroupLayoutDescriptor), "alignof mismatch for BindGroupLayoutDescriptor");

    static_assert(offsetof(BindGroupLayoutDescriptor, nextInChain) == offsetof(DawnBindGroupLayoutDescriptor, nextInChain),
            "offsetof mismatch for BindGroupLayoutDescriptor::nextInChain");
    static_assert(offsetof(BindGroupLayoutDescriptor, label) == offsetof(DawnBindGroupLayoutDescriptor, label),
            "offsetof mismatch for BindGroupLayoutDescriptor::label");
    static_assert(offsetof(BindGroupLayoutDescriptor, bindingCount) == offsetof(DawnBindGroupLayoutDescriptor, bindingCount),
            "offsetof mismatch for BindGroupLayoutDescriptor::bindingCount");
    static_assert(offsetof(BindGroupLayoutDescriptor, bindings) == offsetof(DawnBindGroupLayoutDescriptor, bindings),
            "offsetof mismatch for BindGroupLayoutDescriptor::bindings");


    static_assert(sizeof(ColorStateDescriptor) == sizeof(DawnColorStateDescriptor), "sizeof mismatch for ColorStateDescriptor");
    static_assert(alignof(ColorStateDescriptor) == alignof(DawnColorStateDescriptor), "alignof mismatch for ColorStateDescriptor");

    static_assert(offsetof(ColorStateDescriptor, nextInChain) == offsetof(DawnColorStateDescriptor, nextInChain),
            "offsetof mismatch for ColorStateDescriptor::nextInChain");
    static_assert(offsetof(ColorStateDescriptor, format) == offsetof(DawnColorStateDescriptor, format),
            "offsetof mismatch for ColorStateDescriptor::format");
    static_assert(offsetof(ColorStateDescriptor, alphaBlend) == offsetof(DawnColorStateDescriptor, alphaBlend),
            "offsetof mismatch for ColorStateDescriptor::alphaBlend");
    static_assert(offsetof(ColorStateDescriptor, colorBlend) == offsetof(DawnColorStateDescriptor, colorBlend),
            "offsetof mismatch for ColorStateDescriptor::colorBlend");
    static_assert(offsetof(ColorStateDescriptor, writeMask) == offsetof(DawnColorStateDescriptor, writeMask),
            "offsetof mismatch for ColorStateDescriptor::writeMask");


    static_assert(sizeof(ComputePipelineDescriptor) == sizeof(DawnComputePipelineDescriptor), "sizeof mismatch for ComputePipelineDescriptor");
    static_assert(alignof(ComputePipelineDescriptor) == alignof(DawnComputePipelineDescriptor), "alignof mismatch for ComputePipelineDescriptor");

    static_assert(offsetof(ComputePipelineDescriptor, nextInChain) == offsetof(DawnComputePipelineDescriptor, nextInChain),
            "offsetof mismatch for ComputePipelineDescriptor::nextInChain");
    static_assert(offsetof(ComputePipelineDescriptor, label) == offsetof(DawnComputePipelineDescriptor, label),
            "offsetof mismatch for ComputePipelineDescriptor::label");
    static_assert(offsetof(ComputePipelineDescriptor, layout) == offsetof(DawnComputePipelineDescriptor, layout),
            "offsetof mismatch for ComputePipelineDescriptor::layout");
    static_assert(offsetof(ComputePipelineDescriptor, computeStage) == offsetof(DawnComputePipelineDescriptor, computeStage),
            "offsetof mismatch for ComputePipelineDescriptor::computeStage");


    static_assert(sizeof(DepthStencilStateDescriptor) == sizeof(DawnDepthStencilStateDescriptor), "sizeof mismatch for DepthStencilStateDescriptor");
    static_assert(alignof(DepthStencilStateDescriptor) == alignof(DawnDepthStencilStateDescriptor), "alignof mismatch for DepthStencilStateDescriptor");

    static_assert(offsetof(DepthStencilStateDescriptor, nextInChain) == offsetof(DawnDepthStencilStateDescriptor, nextInChain),
            "offsetof mismatch for DepthStencilStateDescriptor::nextInChain");
    static_assert(offsetof(DepthStencilStateDescriptor, format) == offsetof(DawnDepthStencilStateDescriptor, format),
            "offsetof mismatch for DepthStencilStateDescriptor::format");
    static_assert(offsetof(DepthStencilStateDescriptor, depthWriteEnabled) == offsetof(DawnDepthStencilStateDescriptor, depthWriteEnabled),
            "offsetof mismatch for DepthStencilStateDescriptor::depthWriteEnabled");
    static_assert(offsetof(DepthStencilStateDescriptor, depthCompare) == offsetof(DawnDepthStencilStateDescriptor, depthCompare),
            "offsetof mismatch for DepthStencilStateDescriptor::depthCompare");
    static_assert(offsetof(DepthStencilStateDescriptor, stencilFront) == offsetof(DawnDepthStencilStateDescriptor, stencilFront),
            "offsetof mismatch for DepthStencilStateDescriptor::stencilFront");
    static_assert(offsetof(DepthStencilStateDescriptor, stencilBack) == offsetof(DawnDepthStencilStateDescriptor, stencilBack),
            "offsetof mismatch for DepthStencilStateDescriptor::stencilBack");
    static_assert(offsetof(DepthStencilStateDescriptor, stencilReadMask) == offsetof(DawnDepthStencilStateDescriptor, stencilReadMask),
            "offsetof mismatch for DepthStencilStateDescriptor::stencilReadMask");
    static_assert(offsetof(DepthStencilStateDescriptor, stencilWriteMask) == offsetof(DawnDepthStencilStateDescriptor, stencilWriteMask),
            "offsetof mismatch for DepthStencilStateDescriptor::stencilWriteMask");


    static_assert(sizeof(RenderPassColorAttachmentDescriptor) == sizeof(DawnRenderPassColorAttachmentDescriptor), "sizeof mismatch for RenderPassColorAttachmentDescriptor");
    static_assert(alignof(RenderPassColorAttachmentDescriptor) == alignof(DawnRenderPassColorAttachmentDescriptor), "alignof mismatch for RenderPassColorAttachmentDescriptor");

    static_assert(offsetof(RenderPassColorAttachmentDescriptor, attachment) == offsetof(DawnRenderPassColorAttachmentDescriptor, attachment),
            "offsetof mismatch for RenderPassColorAttachmentDescriptor::attachment");
    static_assert(offsetof(RenderPassColorAttachmentDescriptor, resolveTarget) == offsetof(DawnRenderPassColorAttachmentDescriptor, resolveTarget),
            "offsetof mismatch for RenderPassColorAttachmentDescriptor::resolveTarget");
    static_assert(offsetof(RenderPassColorAttachmentDescriptor, loadOp) == offsetof(DawnRenderPassColorAttachmentDescriptor, loadOp),
            "offsetof mismatch for RenderPassColorAttachmentDescriptor::loadOp");
    static_assert(offsetof(RenderPassColorAttachmentDescriptor, storeOp) == offsetof(DawnRenderPassColorAttachmentDescriptor, storeOp),
            "offsetof mismatch for RenderPassColorAttachmentDescriptor::storeOp");
    static_assert(offsetof(RenderPassColorAttachmentDescriptor, clearColor) == offsetof(DawnRenderPassColorAttachmentDescriptor, clearColor),
            "offsetof mismatch for RenderPassColorAttachmentDescriptor::clearColor");


    static_assert(sizeof(TextureCopyView) == sizeof(DawnTextureCopyView), "sizeof mismatch for TextureCopyView");
    static_assert(alignof(TextureCopyView) == alignof(DawnTextureCopyView), "alignof mismatch for TextureCopyView");

    static_assert(offsetof(TextureCopyView, nextInChain) == offsetof(DawnTextureCopyView, nextInChain),
            "offsetof mismatch for TextureCopyView::nextInChain");
    static_assert(offsetof(TextureCopyView, texture) == offsetof(DawnTextureCopyView, texture),
            "offsetof mismatch for TextureCopyView::texture");
    static_assert(offsetof(TextureCopyView, mipLevel) == offsetof(DawnTextureCopyView, mipLevel),
            "offsetof mismatch for TextureCopyView::mipLevel");
    static_assert(offsetof(TextureCopyView, arrayLayer) == offsetof(DawnTextureCopyView, arrayLayer),
            "offsetof mismatch for TextureCopyView::arrayLayer");
    static_assert(offsetof(TextureCopyView, origin) == offsetof(DawnTextureCopyView, origin),
            "offsetof mismatch for TextureCopyView::origin");


    static_assert(sizeof(TextureDescriptor) == sizeof(DawnTextureDescriptor), "sizeof mismatch for TextureDescriptor");
    static_assert(alignof(TextureDescriptor) == alignof(DawnTextureDescriptor), "alignof mismatch for TextureDescriptor");

    static_assert(offsetof(TextureDescriptor, nextInChain) == offsetof(DawnTextureDescriptor, nextInChain),
            "offsetof mismatch for TextureDescriptor::nextInChain");
    static_assert(offsetof(TextureDescriptor, label) == offsetof(DawnTextureDescriptor, label),
            "offsetof mismatch for TextureDescriptor::label");
    static_assert(offsetof(TextureDescriptor, usage) == offsetof(DawnTextureDescriptor, usage),
            "offsetof mismatch for TextureDescriptor::usage");
    static_assert(offsetof(TextureDescriptor, dimension) == offsetof(DawnTextureDescriptor, dimension),
            "offsetof mismatch for TextureDescriptor::dimension");
    static_assert(offsetof(TextureDescriptor, size) == offsetof(DawnTextureDescriptor, size),
            "offsetof mismatch for TextureDescriptor::size");
    static_assert(offsetof(TextureDescriptor, arrayLayerCount) == offsetof(DawnTextureDescriptor, arrayLayerCount),
            "offsetof mismatch for TextureDescriptor::arrayLayerCount");
    static_assert(offsetof(TextureDescriptor, format) == offsetof(DawnTextureDescriptor, format),
            "offsetof mismatch for TextureDescriptor::format");
    static_assert(offsetof(TextureDescriptor, mipLevelCount) == offsetof(DawnTextureDescriptor, mipLevelCount),
            "offsetof mismatch for TextureDescriptor::mipLevelCount");
    static_assert(offsetof(TextureDescriptor, sampleCount) == offsetof(DawnTextureDescriptor, sampleCount),
            "offsetof mismatch for TextureDescriptor::sampleCount");


    static_assert(sizeof(VertexBufferDescriptor) == sizeof(DawnVertexBufferDescriptor), "sizeof mismatch for VertexBufferDescriptor");
    static_assert(alignof(VertexBufferDescriptor) == alignof(DawnVertexBufferDescriptor), "alignof mismatch for VertexBufferDescriptor");

    static_assert(offsetof(VertexBufferDescriptor, stride) == offsetof(DawnVertexBufferDescriptor, stride),
            "offsetof mismatch for VertexBufferDescriptor::stride");
    static_assert(offsetof(VertexBufferDescriptor, stepMode) == offsetof(DawnVertexBufferDescriptor, stepMode),
            "offsetof mismatch for VertexBufferDescriptor::stepMode");
    static_assert(offsetof(VertexBufferDescriptor, attributeCount) == offsetof(DawnVertexBufferDescriptor, attributeCount),
            "offsetof mismatch for VertexBufferDescriptor::attributeCount");
    static_assert(offsetof(VertexBufferDescriptor, attributes) == offsetof(DawnVertexBufferDescriptor, attributes),
            "offsetof mismatch for VertexBufferDescriptor::attributes");


    static_assert(sizeof(RenderPassDescriptor) == sizeof(DawnRenderPassDescriptor), "sizeof mismatch for RenderPassDescriptor");
    static_assert(alignof(RenderPassDescriptor) == alignof(DawnRenderPassDescriptor), "alignof mismatch for RenderPassDescriptor");

    static_assert(offsetof(RenderPassDescriptor, label) == offsetof(DawnRenderPassDescriptor, label),
            "offsetof mismatch for RenderPassDescriptor::label");
    static_assert(offsetof(RenderPassDescriptor, colorAttachmentCount) == offsetof(DawnRenderPassDescriptor, colorAttachmentCount),
            "offsetof mismatch for RenderPassDescriptor::colorAttachmentCount");
    static_assert(offsetof(RenderPassDescriptor, colorAttachments) == offsetof(DawnRenderPassDescriptor, colorAttachments),
            "offsetof mismatch for RenderPassDescriptor::colorAttachments");
    static_assert(offsetof(RenderPassDescriptor, depthStencilAttachment) == offsetof(DawnRenderPassDescriptor, depthStencilAttachment),
            "offsetof mismatch for RenderPassDescriptor::depthStencilAttachment");


    static_assert(sizeof(VertexInputDescriptor) == sizeof(DawnVertexInputDescriptor), "sizeof mismatch for VertexInputDescriptor");
    static_assert(alignof(VertexInputDescriptor) == alignof(DawnVertexInputDescriptor), "alignof mismatch for VertexInputDescriptor");

    static_assert(offsetof(VertexInputDescriptor, nextInChain) == offsetof(DawnVertexInputDescriptor, nextInChain),
            "offsetof mismatch for VertexInputDescriptor::nextInChain");
    static_assert(offsetof(VertexInputDescriptor, indexFormat) == offsetof(DawnVertexInputDescriptor, indexFormat),
            "offsetof mismatch for VertexInputDescriptor::indexFormat");
    static_assert(offsetof(VertexInputDescriptor, bufferCount) == offsetof(DawnVertexInputDescriptor, bufferCount),
            "offsetof mismatch for VertexInputDescriptor::bufferCount");
    static_assert(offsetof(VertexInputDescriptor, buffers) == offsetof(DawnVertexInputDescriptor, buffers),
            "offsetof mismatch for VertexInputDescriptor::buffers");


    static_assert(sizeof(RenderPipelineDescriptor) == sizeof(DawnRenderPipelineDescriptor), "sizeof mismatch for RenderPipelineDescriptor");
    static_assert(alignof(RenderPipelineDescriptor) == alignof(DawnRenderPipelineDescriptor), "alignof mismatch for RenderPipelineDescriptor");

    static_assert(offsetof(RenderPipelineDescriptor, nextInChain) == offsetof(DawnRenderPipelineDescriptor, nextInChain),
            "offsetof mismatch for RenderPipelineDescriptor::nextInChain");
    static_assert(offsetof(RenderPipelineDescriptor, label) == offsetof(DawnRenderPipelineDescriptor, label),
            "offsetof mismatch for RenderPipelineDescriptor::label");
    static_assert(offsetof(RenderPipelineDescriptor, layout) == offsetof(DawnRenderPipelineDescriptor, layout),
            "offsetof mismatch for RenderPipelineDescriptor::layout");
    static_assert(offsetof(RenderPipelineDescriptor, vertexStage) == offsetof(DawnRenderPipelineDescriptor, vertexStage),
            "offsetof mismatch for RenderPipelineDescriptor::vertexStage");
    static_assert(offsetof(RenderPipelineDescriptor, fragmentStage) == offsetof(DawnRenderPipelineDescriptor, fragmentStage),
            "offsetof mismatch for RenderPipelineDescriptor::fragmentStage");
    static_assert(offsetof(RenderPipelineDescriptor, vertexInput) == offsetof(DawnRenderPipelineDescriptor, vertexInput),
            "offsetof mismatch for RenderPipelineDescriptor::vertexInput");
    static_assert(offsetof(RenderPipelineDescriptor, primitiveTopology) == offsetof(DawnRenderPipelineDescriptor, primitiveTopology),
            "offsetof mismatch for RenderPipelineDescriptor::primitiveTopology");
    static_assert(offsetof(RenderPipelineDescriptor, rasterizationState) == offsetof(DawnRenderPipelineDescriptor, rasterizationState),
            "offsetof mismatch for RenderPipelineDescriptor::rasterizationState");
    static_assert(offsetof(RenderPipelineDescriptor, sampleCount) == offsetof(DawnRenderPipelineDescriptor, sampleCount),
            "offsetof mismatch for RenderPipelineDescriptor::sampleCount");
    static_assert(offsetof(RenderPipelineDescriptor, depthStencilState) == offsetof(DawnRenderPipelineDescriptor, depthStencilState),
            "offsetof mismatch for RenderPipelineDescriptor::depthStencilState");
    static_assert(offsetof(RenderPipelineDescriptor, colorStateCount) == offsetof(DawnRenderPipelineDescriptor, colorStateCount),
            "offsetof mismatch for RenderPipelineDescriptor::colorStateCount");
    static_assert(offsetof(RenderPipelineDescriptor, colorStates) == offsetof(DawnRenderPipelineDescriptor, colorStates),
            "offsetof mismatch for RenderPipelineDescriptor::colorStates");
    static_assert(offsetof(RenderPipelineDescriptor, sampleMask) == offsetof(DawnRenderPipelineDescriptor, sampleMask),
            "offsetof mismatch for RenderPipelineDescriptor::sampleMask");
    static_assert(offsetof(RenderPipelineDescriptor, alphaToCoverageEnabled) == offsetof(DawnRenderPipelineDescriptor, alphaToCoverageEnabled),
            "offsetof mismatch for RenderPipelineDescriptor::alphaToCoverageEnabled");



    static_assert(sizeof(BindGroup) == sizeof(DawnBindGroup), "sizeof mismatch for BindGroup");
    static_assert(alignof(BindGroup) == alignof(DawnBindGroup), "alignof mismatch for BindGroup");



    void BindGroup::DawnReference(DawnBindGroup handle) {
        if (handle != nullptr) {
            dawnBindGroupReference(handle);
        }
    }
    void BindGroup::DawnRelease(DawnBindGroup handle) {
        if (handle != nullptr) {
            dawnBindGroupRelease(handle);
        }
    }


    static_assert(sizeof(BindGroupLayout) == sizeof(DawnBindGroupLayout), "sizeof mismatch for BindGroupLayout");
    static_assert(alignof(BindGroupLayout) == alignof(DawnBindGroupLayout), "alignof mismatch for BindGroupLayout");



    void BindGroupLayout::DawnReference(DawnBindGroupLayout handle) {
        if (handle != nullptr) {
            dawnBindGroupLayoutReference(handle);
        }
    }
    void BindGroupLayout::DawnRelease(DawnBindGroupLayout handle) {
        if (handle != nullptr) {
            dawnBindGroupLayoutRelease(handle);
        }
    }


    static_assert(sizeof(Buffer) == sizeof(DawnBuffer), "sizeof mismatch for Buffer");
    static_assert(alignof(Buffer) == alignof(DawnBuffer), "alignof mismatch for Buffer");



        void Buffer::SetSubData(uint64_t start, uint64_t count, void const * data) const {
        dawnBufferSetSubData(Get(), start, count, reinterpret_cast<void const * >(data));
    }
        void Buffer::Unmap() const {
        dawnBufferUnmap(Get());
    }
        void Buffer::Destroy() const {
        dawnBufferDestroy(Get());
    }
        void Buffer::MapReadAsync(BufferMapReadCallback callback, void * userdata) const {
        dawnBufferMapReadAsync(Get(), callback, reinterpret_cast<void * >(userdata));
    }
        void Buffer::MapWriteAsync(BufferMapWriteCallback callback, void * userdata) const {
        dawnBufferMapWriteAsync(Get(), callback, reinterpret_cast<void * >(userdata));
    }
    void Buffer::DawnReference(DawnBuffer handle) {
        if (handle != nullptr) {
            dawnBufferReference(handle);
        }
    }
    void Buffer::DawnRelease(DawnBuffer handle) {
        if (handle != nullptr) {
            dawnBufferRelease(handle);
        }
    }


    static_assert(sizeof(CommandBuffer) == sizeof(DawnCommandBuffer), "sizeof mismatch for CommandBuffer");
    static_assert(alignof(CommandBuffer) == alignof(DawnCommandBuffer), "alignof mismatch for CommandBuffer");



    void CommandBuffer::DawnReference(DawnCommandBuffer handle) {
        if (handle != nullptr) {
            dawnCommandBufferReference(handle);
        }
    }
    void CommandBuffer::DawnRelease(DawnCommandBuffer handle) {
        if (handle != nullptr) {
            dawnCommandBufferRelease(handle);
        }
    }


    static_assert(sizeof(CommandEncoder) == sizeof(DawnCommandEncoder), "sizeof mismatch for CommandEncoder");
    static_assert(alignof(CommandEncoder) == alignof(DawnCommandEncoder), "alignof mismatch for CommandEncoder");



        CommandBuffer CommandEncoder::Finish(CommandBufferDescriptor const * descriptor) const {
        auto result = dawnCommandEncoderFinish(Get(), reinterpret_cast<DawnCommandBufferDescriptor const * >(descriptor));
        return CommandBuffer::Acquire(result);
    }
        ComputePassEncoder CommandEncoder::BeginComputePass(ComputePassDescriptor const * descriptor) const {
        auto result = dawnCommandEncoderBeginComputePass(Get(), reinterpret_cast<DawnComputePassDescriptor const * >(descriptor));
        return ComputePassEncoder::Acquire(result);
    }
        RenderPassEncoder CommandEncoder::BeginRenderPass(RenderPassDescriptor const * descriptor) const {
        auto result = dawnCommandEncoderBeginRenderPass(Get(), reinterpret_cast<DawnRenderPassDescriptor const * >(descriptor));
        return RenderPassEncoder::Acquire(result);
    }
        void CommandEncoder::CopyBufferToBuffer(Buffer const& source, uint64_t sourceOffset, Buffer const& destination, uint64_t destinationOffset, uint64_t size) const {
        dawnCommandEncoderCopyBufferToBuffer(Get(), source.Get(), sourceOffset, destination.Get(), destinationOffset, size);
    }
        void CommandEncoder::CopyBufferToTexture(BufferCopyView const * source, TextureCopyView const * destination, Extent3D const * copySize) const {
        dawnCommandEncoderCopyBufferToTexture(Get(), reinterpret_cast<DawnBufferCopyView const * >(source), reinterpret_cast<DawnTextureCopyView const * >(destination), reinterpret_cast<DawnExtent3D const * >(copySize));
    }
        void CommandEncoder::CopyTextureToBuffer(TextureCopyView const * source, BufferCopyView const * destination, Extent3D const * copySize) const {
        dawnCommandEncoderCopyTextureToBuffer(Get(), reinterpret_cast<DawnTextureCopyView const * >(source), reinterpret_cast<DawnBufferCopyView const * >(destination), reinterpret_cast<DawnExtent3D const * >(copySize));
    }
        void CommandEncoder::CopyTextureToTexture(TextureCopyView const * source, TextureCopyView const * destination, Extent3D const * copySize) const {
        dawnCommandEncoderCopyTextureToTexture(Get(), reinterpret_cast<DawnTextureCopyView const * >(source), reinterpret_cast<DawnTextureCopyView const * >(destination), reinterpret_cast<DawnExtent3D const * >(copySize));
    }
        void CommandEncoder::InsertDebugMarker(char const * groupLabel) const {
        dawnCommandEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(groupLabel));
    }
        void CommandEncoder::PopDebugGroup() const {
        dawnCommandEncoderPopDebugGroup(Get());
    }
        void CommandEncoder::PushDebugGroup(char const * groupLabel) const {
        dawnCommandEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
    }
    void CommandEncoder::DawnReference(DawnCommandEncoder handle) {
        if (handle != nullptr) {
            dawnCommandEncoderReference(handle);
        }
    }
    void CommandEncoder::DawnRelease(DawnCommandEncoder handle) {
        if (handle != nullptr) {
            dawnCommandEncoderRelease(handle);
        }
    }


    static_assert(sizeof(ComputePassEncoder) == sizeof(DawnComputePassEncoder), "sizeof mismatch for ComputePassEncoder");
    static_assert(alignof(ComputePassEncoder) == alignof(DawnComputePassEncoder), "alignof mismatch for ComputePassEncoder");



        void ComputePassEncoder::InsertDebugMarker(char const * groupLabel) const {
        dawnComputePassEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(groupLabel));
    }
        void ComputePassEncoder::PopDebugGroup() const {
        dawnComputePassEncoderPopDebugGroup(Get());
    }
        void ComputePassEncoder::PushDebugGroup(char const * groupLabel) const {
        dawnComputePassEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
    }
        void ComputePassEncoder::SetPipeline(ComputePipeline const& pipeline) const {
        dawnComputePassEncoderSetPipeline(Get(), pipeline.Get());
    }
        void ComputePassEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets) const {
        dawnComputePassEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint64_t const * >(dynamicOffsets));
    }
        void ComputePassEncoder::Dispatch(uint32_t x, uint32_t y, uint32_t z) const {
        dawnComputePassEncoderDispatch(Get(), x, y, z);
    }
        void ComputePassEncoder::DispatchIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
        dawnComputePassEncoderDispatchIndirect(Get(), indirectBuffer.Get(), indirectOffset);
    }
        void ComputePassEncoder::EndPass() const {
        dawnComputePassEncoderEndPass(Get());
    }
    void ComputePassEncoder::DawnReference(DawnComputePassEncoder handle) {
        if (handle != nullptr) {
            dawnComputePassEncoderReference(handle);
        }
    }
    void ComputePassEncoder::DawnRelease(DawnComputePassEncoder handle) {
        if (handle != nullptr) {
            dawnComputePassEncoderRelease(handle);
        }
    }


    static_assert(sizeof(ComputePipeline) == sizeof(DawnComputePipeline), "sizeof mismatch for ComputePipeline");
    static_assert(alignof(ComputePipeline) == alignof(DawnComputePipeline), "alignof mismatch for ComputePipeline");



    void ComputePipeline::DawnReference(DawnComputePipeline handle) {
        if (handle != nullptr) {
            dawnComputePipelineReference(handle);
        }
    }
    void ComputePipeline::DawnRelease(DawnComputePipeline handle) {
        if (handle != nullptr) {
            dawnComputePipelineRelease(handle);
        }
    }


    static_assert(sizeof(Device) == sizeof(DawnDevice), "sizeof mismatch for Device");
    static_assert(alignof(Device) == alignof(DawnDevice), "alignof mismatch for Device");



        BindGroup Device::CreateBindGroup(BindGroupDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateBindGroup(Get(), reinterpret_cast<DawnBindGroupDescriptor const * >(descriptor));
        return BindGroup::Acquire(result);
    }
        BindGroupLayout Device::CreateBindGroupLayout(BindGroupLayoutDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateBindGroupLayout(Get(), reinterpret_cast<DawnBindGroupLayoutDescriptor const * >(descriptor));
        return BindGroupLayout::Acquire(result);
    }
        Buffer Device::CreateBuffer(BufferDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateBuffer(Get(), reinterpret_cast<DawnBufferDescriptor const * >(descriptor));
        return Buffer::Acquire(result);
    }
        CreateBufferMappedResult Device::CreateBufferMapped(BufferDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateBufferMapped(Get(), reinterpret_cast<DawnBufferDescriptor const * >(descriptor));
        return CreateBufferMappedResult {
            Buffer::Acquire(result.buffer),
            result.dataLength,
            result.data
        };
    }
        CommandEncoder Device::CreateCommandEncoder(CommandEncoderDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateCommandEncoder(Get(), reinterpret_cast<DawnCommandEncoderDescriptor const * >(descriptor));
        return CommandEncoder::Acquire(result);
    }
        ComputePipeline Device::CreateComputePipeline(ComputePipelineDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateComputePipeline(Get(), reinterpret_cast<DawnComputePipelineDescriptor const * >(descriptor));
        return ComputePipeline::Acquire(result);
    }
        RenderPipeline Device::CreateRenderPipeline(RenderPipelineDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateRenderPipeline(Get(), reinterpret_cast<DawnRenderPipelineDescriptor const * >(descriptor));
        return RenderPipeline::Acquire(result);
    }
        PipelineLayout Device::CreatePipelineLayout(PipelineLayoutDescriptor const * descriptor) const {
        auto result = dawnDeviceCreatePipelineLayout(Get(), reinterpret_cast<DawnPipelineLayoutDescriptor const * >(descriptor));
        return PipelineLayout::Acquire(result);
    }
        Queue Device::CreateQueue() const {
        auto result = dawnDeviceCreateQueue(Get());
        return Queue::Acquire(result);
    }
        RenderBundleEncoder Device::CreateRenderBundleEncoder(RenderBundleEncoderDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateRenderBundleEncoder(Get(), reinterpret_cast<DawnRenderBundleEncoderDescriptor const * >(descriptor));
        return RenderBundleEncoder::Acquire(result);
    }
        Sampler Device::CreateSampler(SamplerDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateSampler(Get(), reinterpret_cast<DawnSamplerDescriptor const * >(descriptor));
        return Sampler::Acquire(result);
    }
        ShaderModule Device::CreateShaderModule(ShaderModuleDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateShaderModule(Get(), reinterpret_cast<DawnShaderModuleDescriptor const * >(descriptor));
        return ShaderModule::Acquire(result);
    }
        SwapChain Device::CreateSwapChain(SwapChainDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateSwapChain(Get(), reinterpret_cast<DawnSwapChainDescriptor const * >(descriptor));
        return SwapChain::Acquire(result);
    }
        Texture Device::CreateTexture(TextureDescriptor const * descriptor) const {
        auto result = dawnDeviceCreateTexture(Get(), reinterpret_cast<DawnTextureDescriptor const * >(descriptor));
        return Texture::Acquire(result);
    }
        void Device::InjectError(ErrorType type, char const * message) const {
        dawnDeviceInjectError(Get(), static_cast<DawnErrorType>(type), reinterpret_cast<char const * >(message));
    }
        void Device::Tick() const {
        dawnDeviceTick(Get());
    }
        void Device::PushErrorScope(ErrorFilter filter) const {
        dawnDevicePushErrorScope(Get(), static_cast<DawnErrorFilter>(filter));
    }
        void Device::CreateBufferMappedAsync(BufferDescriptor const * descriptor, BufferCreateMappedCallback callback, void * userdata) const {
        dawnDeviceCreateBufferMappedAsync(Get(), reinterpret_cast<DawnBufferDescriptor const * >(descriptor), callback, reinterpret_cast<void * >(userdata));
    }
        void Device::SetUncapturedErrorCallback(ErrorCallback callback, void * userdata) const {
        dawnDeviceSetUncapturedErrorCallback(Get(), callback, reinterpret_cast<void * >(userdata));
    }
        bool Device::PopErrorScope(ErrorCallback callback, void * userdata) const {
        auto result = dawnDevicePopErrorScope(Get(), callback, reinterpret_cast<void * >(userdata));
        return result;
    }
    void Device::DawnReference(DawnDevice handle) {
        if (handle != nullptr) {
            dawnDeviceReference(handle);
        }
    }
    void Device::DawnRelease(DawnDevice handle) {
        if (handle != nullptr) {
            dawnDeviceRelease(handle);
        }
    }


    static_assert(sizeof(Fence) == sizeof(DawnFence), "sizeof mismatch for Fence");
    static_assert(alignof(Fence) == alignof(DawnFence), "alignof mismatch for Fence");



        uint64_t Fence::GetCompletedValue() const {
        auto result = dawnFenceGetCompletedValue(Get());
        return result;
    }
        void Fence::OnCompletion(uint64_t value, FenceOnCompletionCallback callback, void * userdata) const {
        dawnFenceOnCompletion(Get(), value, callback, reinterpret_cast<void * >(userdata));
    }
    void Fence::DawnReference(DawnFence handle) {
        if (handle != nullptr) {
            dawnFenceReference(handle);
        }
    }
    void Fence::DawnRelease(DawnFence handle) {
        if (handle != nullptr) {
            dawnFenceRelease(handle);
        }
    }


    static_assert(sizeof(PipelineLayout) == sizeof(DawnPipelineLayout), "sizeof mismatch for PipelineLayout");
    static_assert(alignof(PipelineLayout) == alignof(DawnPipelineLayout), "alignof mismatch for PipelineLayout");



    void PipelineLayout::DawnReference(DawnPipelineLayout handle) {
        if (handle != nullptr) {
            dawnPipelineLayoutReference(handle);
        }
    }
    void PipelineLayout::DawnRelease(DawnPipelineLayout handle) {
        if (handle != nullptr) {
            dawnPipelineLayoutRelease(handle);
        }
    }


    static_assert(sizeof(Queue) == sizeof(DawnQueue), "sizeof mismatch for Queue");
    static_assert(alignof(Queue) == alignof(DawnQueue), "alignof mismatch for Queue");



        void Queue::Submit(uint32_t commandCount, CommandBuffer const * commands) const {
        dawnQueueSubmit(Get(), commandCount, reinterpret_cast<DawnCommandBuffer const * >(commands));
    }
        void Queue::Signal(Fence const& fence, uint64_t signalValue) const {
        dawnQueueSignal(Get(), fence.Get(), signalValue);
    }
        Fence Queue::CreateFence(FenceDescriptor const * descriptor) const {
        auto result = dawnQueueCreateFence(Get(), reinterpret_cast<DawnFenceDescriptor const * >(descriptor));
        return Fence::Acquire(result);
    }
    void Queue::DawnReference(DawnQueue handle) {
        if (handle != nullptr) {
            dawnQueueReference(handle);
        }
    }
    void Queue::DawnRelease(DawnQueue handle) {
        if (handle != nullptr) {
            dawnQueueRelease(handle);
        }
    }


    static_assert(sizeof(RenderBundle) == sizeof(DawnRenderBundle), "sizeof mismatch for RenderBundle");
    static_assert(alignof(RenderBundle) == alignof(DawnRenderBundle), "alignof mismatch for RenderBundle");



    void RenderBundle::DawnReference(DawnRenderBundle handle) {
        if (handle != nullptr) {
            dawnRenderBundleReference(handle);
        }
    }
    void RenderBundle::DawnRelease(DawnRenderBundle handle) {
        if (handle != nullptr) {
            dawnRenderBundleRelease(handle);
        }
    }


    static_assert(sizeof(RenderBundleEncoder) == sizeof(DawnRenderBundleEncoder), "sizeof mismatch for RenderBundleEncoder");
    static_assert(alignof(RenderBundleEncoder) == alignof(DawnRenderBundleEncoder), "alignof mismatch for RenderBundleEncoder");



        void RenderBundleEncoder::SetPipeline(RenderPipeline const& pipeline) const {
        dawnRenderBundleEncoderSetPipeline(Get(), pipeline.Get());
    }
        void RenderBundleEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets) const {
        dawnRenderBundleEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint64_t const * >(dynamicOffsets));
    }
        void RenderBundleEncoder::Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
        dawnRenderBundleEncoderDraw(Get(), vertexCount, instanceCount, firstVertex, firstInstance);
    }
        void RenderBundleEncoder::DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) const {
        dawnRenderBundleEncoderDrawIndexed(Get(), indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
    }
        void RenderBundleEncoder::DrawIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
        dawnRenderBundleEncoderDrawIndirect(Get(), indirectBuffer.Get(), indirectOffset);
    }
        void RenderBundleEncoder::DrawIndexedIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
        dawnRenderBundleEncoderDrawIndexedIndirect(Get(), indirectBuffer.Get(), indirectOffset);
    }
        void RenderBundleEncoder::InsertDebugMarker(char const * groupLabel) const {
        dawnRenderBundleEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(groupLabel));
    }
        void RenderBundleEncoder::PopDebugGroup() const {
        dawnRenderBundleEncoderPopDebugGroup(Get());
    }
        void RenderBundleEncoder::PushDebugGroup(char const * groupLabel) const {
        dawnRenderBundleEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
    }
        void RenderBundleEncoder::SetVertexBuffers(uint32_t startSlot, uint32_t count, Buffer const * buffers, uint64_t const * offsets) const {
        dawnRenderBundleEncoderSetVertexBuffers(Get(), startSlot, count, reinterpret_cast<DawnBuffer const * >(buffers), reinterpret_cast<uint64_t const * >(offsets));
    }
        void RenderBundleEncoder::SetIndexBuffer(Buffer const& buffer, uint64_t offset) const {
        dawnRenderBundleEncoderSetIndexBuffer(Get(), buffer.Get(), offset);
    }
        RenderBundle RenderBundleEncoder::Finish(RenderBundleDescriptor const * descriptor) const {
        auto result = dawnRenderBundleEncoderFinish(Get(), reinterpret_cast<DawnRenderBundleDescriptor const * >(descriptor));
        return RenderBundle::Acquire(result);
    }
    void RenderBundleEncoder::DawnReference(DawnRenderBundleEncoder handle) {
        if (handle != nullptr) {
            dawnRenderBundleEncoderReference(handle);
        }
    }
    void RenderBundleEncoder::DawnRelease(DawnRenderBundleEncoder handle) {
        if (handle != nullptr) {
            dawnRenderBundleEncoderRelease(handle);
        }
    }


    static_assert(sizeof(RenderPassEncoder) == sizeof(DawnRenderPassEncoder), "sizeof mismatch for RenderPassEncoder");
    static_assert(alignof(RenderPassEncoder) == alignof(DawnRenderPassEncoder), "alignof mismatch for RenderPassEncoder");



        void RenderPassEncoder::SetPipeline(RenderPipeline const& pipeline) const {
        dawnRenderPassEncoderSetPipeline(Get(), pipeline.Get());
    }
        void RenderPassEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, uint32_t dynamicOffsetCount, uint64_t const * dynamicOffsets) const {
        dawnRenderPassEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint64_t const * >(dynamicOffsets));
    }
        void RenderPassEncoder::Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
        dawnRenderPassEncoderDraw(Get(), vertexCount, instanceCount, firstVertex, firstInstance);
    }
        void RenderPassEncoder::DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) const {
        dawnRenderPassEncoderDrawIndexed(Get(), indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
    }
        void RenderPassEncoder::DrawIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
        dawnRenderPassEncoderDrawIndirect(Get(), indirectBuffer.Get(), indirectOffset);
    }
        void RenderPassEncoder::DrawIndexedIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
        dawnRenderPassEncoderDrawIndexedIndirect(Get(), indirectBuffer.Get(), indirectOffset);
    }
        void RenderPassEncoder::ExecuteBundles(uint32_t bundlesCount, RenderBundle const * bundles) const {
        dawnRenderPassEncoderExecuteBundles(Get(), bundlesCount, reinterpret_cast<DawnRenderBundle const * >(bundles));
    }
        void RenderPassEncoder::InsertDebugMarker(char const * groupLabel) const {
        dawnRenderPassEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(groupLabel));
    }
        void RenderPassEncoder::PopDebugGroup() const {
        dawnRenderPassEncoderPopDebugGroup(Get());
    }
        void RenderPassEncoder::PushDebugGroup(char const * groupLabel) const {
        dawnRenderPassEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
    }
        void RenderPassEncoder::SetStencilReference(uint32_t reference) const {
        dawnRenderPassEncoderSetStencilReference(Get(), reference);
    }
        void RenderPassEncoder::SetBlendColor(Color const * color) const {
        dawnRenderPassEncoderSetBlendColor(Get(), reinterpret_cast<DawnColor const * >(color));
    }
        void RenderPassEncoder::SetViewport(float x, float y, float width, float height, float minDepth, float maxDepth) const {
        dawnRenderPassEncoderSetViewport(Get(), x, y, width, height, minDepth, maxDepth);
    }
        void RenderPassEncoder::SetScissorRect(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const {
        dawnRenderPassEncoderSetScissorRect(Get(), x, y, width, height);
    }
        void RenderPassEncoder::SetVertexBuffers(uint32_t startSlot, uint32_t count, Buffer const * buffers, uint64_t const * offsets) const {
        dawnRenderPassEncoderSetVertexBuffers(Get(), startSlot, count, reinterpret_cast<DawnBuffer const * >(buffers), reinterpret_cast<uint64_t const * >(offsets));
    }
        void RenderPassEncoder::SetIndexBuffer(Buffer const& buffer, uint64_t offset) const {
        dawnRenderPassEncoderSetIndexBuffer(Get(), buffer.Get(), offset);
    }
        void RenderPassEncoder::EndPass() const {
        dawnRenderPassEncoderEndPass(Get());
    }
    void RenderPassEncoder::DawnReference(DawnRenderPassEncoder handle) {
        if (handle != nullptr) {
            dawnRenderPassEncoderReference(handle);
        }
    }
    void RenderPassEncoder::DawnRelease(DawnRenderPassEncoder handle) {
        if (handle != nullptr) {
            dawnRenderPassEncoderRelease(handle);
        }
    }


    static_assert(sizeof(RenderPipeline) == sizeof(DawnRenderPipeline), "sizeof mismatch for RenderPipeline");
    static_assert(alignof(RenderPipeline) == alignof(DawnRenderPipeline), "alignof mismatch for RenderPipeline");



    void RenderPipeline::DawnReference(DawnRenderPipeline handle) {
        if (handle != nullptr) {
            dawnRenderPipelineReference(handle);
        }
    }
    void RenderPipeline::DawnRelease(DawnRenderPipeline handle) {
        if (handle != nullptr) {
            dawnRenderPipelineRelease(handle);
        }
    }


    static_assert(sizeof(Sampler) == sizeof(DawnSampler), "sizeof mismatch for Sampler");
    static_assert(alignof(Sampler) == alignof(DawnSampler), "alignof mismatch for Sampler");



    void Sampler::DawnReference(DawnSampler handle) {
        if (handle != nullptr) {
            dawnSamplerReference(handle);
        }
    }
    void Sampler::DawnRelease(DawnSampler handle) {
        if (handle != nullptr) {
            dawnSamplerRelease(handle);
        }
    }


    static_assert(sizeof(ShaderModule) == sizeof(DawnShaderModule), "sizeof mismatch for ShaderModule");
    static_assert(alignof(ShaderModule) == alignof(DawnShaderModule), "alignof mismatch for ShaderModule");



    void ShaderModule::DawnReference(DawnShaderModule handle) {
        if (handle != nullptr) {
            dawnShaderModuleReference(handle);
        }
    }
    void ShaderModule::DawnRelease(DawnShaderModule handle) {
        if (handle != nullptr) {
            dawnShaderModuleRelease(handle);
        }
    }


    static_assert(sizeof(SwapChain) == sizeof(DawnSwapChain), "sizeof mismatch for SwapChain");
    static_assert(alignof(SwapChain) == alignof(DawnSwapChain), "alignof mismatch for SwapChain");



        void SwapChain::Configure(TextureFormat format, TextureUsage allowedUsage, uint32_t width, uint32_t height) const {
        dawnSwapChainConfigure(Get(), static_cast<DawnTextureFormat>(format), static_cast<DawnTextureUsage>(allowedUsage), width, height);
    }
        Texture SwapChain::GetNextTexture() const {
        auto result = dawnSwapChainGetNextTexture(Get());
        return Texture::Acquire(result);
    }
        void SwapChain::Present(Texture const& texture) const {
        dawnSwapChainPresent(Get(), texture.Get());
    }
    void SwapChain::DawnReference(DawnSwapChain handle) {
        if (handle != nullptr) {
            dawnSwapChainReference(handle);
        }
    }
    void SwapChain::DawnRelease(DawnSwapChain handle) {
        if (handle != nullptr) {
            dawnSwapChainRelease(handle);
        }
    }


    static_assert(sizeof(Texture) == sizeof(DawnTexture), "sizeof mismatch for Texture");
    static_assert(alignof(Texture) == alignof(DawnTexture), "alignof mismatch for Texture");



        TextureView Texture::CreateView(TextureViewDescriptor const * descriptor) const {
        auto result = dawnTextureCreateView(Get(), reinterpret_cast<DawnTextureViewDescriptor const * >(descriptor));
        return TextureView::Acquire(result);
    }
        void Texture::Destroy() const {
        dawnTextureDestroy(Get());
    }
    void Texture::DawnReference(DawnTexture handle) {
        if (handle != nullptr) {
            dawnTextureReference(handle);
        }
    }
    void Texture::DawnRelease(DawnTexture handle) {
        if (handle != nullptr) {
            dawnTextureRelease(handle);
        }
    }


    static_assert(sizeof(TextureView) == sizeof(DawnTextureView), "sizeof mismatch for TextureView");
    static_assert(alignof(TextureView) == alignof(DawnTextureView), "alignof mismatch for TextureView");



    void TextureView::DawnReference(DawnTextureView handle) {
        if (handle != nullptr) {
            dawnTextureViewReference(handle);
        }
    }
    void TextureView::DawnRelease(DawnTextureView handle) {
        if (handle != nullptr) {
            dawnTextureViewRelease(handle);
        }
    }


}
