/*
 * Copyright 2019 The Emscripten Authors.  All rights reserved.
 * Emscripten is available under two separate licenses, the MIT license and the
 * University of Illinois/NCSA Open Source License.  Both these licenses can be
 * found in the LICENSE file.
 *
 * WebGPU support. (TODO: Add documentation.)
 */

{{{ (function() {
  // Helper functions for code generation
  global.gpu = {
    makeInitManager: function(type) {
      var mgr = 'this.mgr' + type
      return mgr + ' = ' + mgr + ' || makeManager();';
    },

    makeReferenceRelease: function(type) {
      let s = '';
      s += 'dawn' + type + 'Reference: function(id) {\n';
      s += '  WebGPU.mgr' + type + '.reference(id);\n'
      s += '},\n';
      s += 'dawn' + type + 'Release: function(id) {\n';
      s += '  WebGPU.mgr' + type + '.release(id);\n'
      s += '},';
      return s;
    },

    makeGetBool: function(ptr, pos) { return makeGetValue(ptr, pos, 'i32') !== 0; },
    makeGetU32: function(ptr, pos) { return makeGetValue(ptr, pos, 'i32', false, true); },
    makeGetU64: function(ptr, pos) { return makeGetValue(ptr, pos, 'i64', false, true); },

    makeCheck: function(str) {
      if (!ASSERTIONS) return '';
      return 'assert(' + str + ');';
    },
    makeCheckDefined: function(name) {
      return this.makeCheck('typeof ' + name + ' !== "undefined"');
    },
    makeCheckDescriptor: function(descriptor) {
      // Assert descriptor is non-null, then that its nextInChain is null.
      var OffsetOfNextInChainMember = 0;
      return this.makeCheck(descriptor + ' !== 0') + this.makeCheck(makeGetValue(descriptor, OffsetOfNextInChainMember, '*') + ' === 0');
    },
  };
  return null;
})(); }}}

var LibraryWebGPU = {
  $WebGPU: {
    initManagers: function() {
      function makeManager() {
        return {
          objects: [null],
          create: function(object) {
            var id = this.objects.length;
            {{{ gpu.makeCheck("typeof this.objects[id] === 'undefined'") }}}
            this.objects[id] = { refcount: 1, object };
            return id;
          },
          get: function(id) {
            {{{ gpu.makeCheckDefined('this.objects[id]') }}}
            return this.objects[id].object;
          },
          reference: function(id) {
            var o = this.objects[id];
            {{{ gpu.makeCheckDefined('o') }}}
            this.objects[id].refcount++;
          },
          release: function(id) {
            var o = this.objects[id];
            {{{ gpu.makeCheckDefined('o') }}}
            {{{ gpu.makeCheck('o.refCount > 0') }}}
            o.refcount--;
            if (o.refcount <= 0) {
              delete this.objects[id];
            }
          },
        };
      }

      {{{ gpu.makeInitManager('Device') }}}
      {{{ gpu.makeInitManager('Queue') }}}

      {{{ gpu.makeInitManager('CommandBuffer') }}}
      {{{ gpu.makeInitManager('CommandEncoder') }}}
      {{{ gpu.makeInitManager('RenderPassEncoder') }}}

      {{{ gpu.makeInitManager('Buffer') }}}
      {{{ gpu.makeInitManager('Texture') }}}
      {{{ gpu.makeInitManager('TextureView') }}}

      {{{ gpu.makeInitManager('RenderPipeline') }}}
      {{{ gpu.makeInitManager('PipelineLayout') }}}
      {{{ gpu.makeInitManager('ShaderModule') }}}
    },

    getColor: function(ptr) {
      return [
        {{{ makeGetValue('ptr', 0, 'float') }}},
        {{{ makeGetValue('ptr', 4, 'float') }}},
        {{{ makeGetValue('ptr', 8, 'float') }}},
        {{{ makeGetValue('ptr', 12, 'float') }}},
      ];
    },

    AddressMode: [ 'repeat', 'mirror-repeat', 'clamp-to-edge' ],
    BindingType: [ 'uniform-buffer', 'storage-buffer', 'readonly-storage-buffer', 'sampler', 'sampled-texture', 'storage-texture' ],
    BlendFactor: [
      'zero', 'one', 'src-color', 'one-minus-src-color', 'src-alpha', 'one-minus-src-alpha',
      'dst-color', 'one-minus-dst-color', 'dst-alpha', 'one-minus-dst-alpha',
      'src-alpha-saturated', 'blend-color', 'one-minus-blend-color',
    ],
    BlendOperation: [ 'add', 'subtract', 'reverse-subtract', 'min', 'max' ],
    BufferMapAsyncStatus: [ 'success', 'error', 'unknown', 'device-lost' ],
    CompareFunction: [ 'never', 'less', 'less-equal', 'greater', 'greater-equal', 'equal', 'not-equal', 'always' ],
    CullMode: [ 'none', 'front', 'back' ],
    ErrorFilter: [ 'none', 'validation', 'out-of-memory' ],
    ErrorType: [ 'no-error', 'validation', 'out-of-memory', 'unknown', 'device-lost' ],
    FenceCompletionStatus: [ 'success', 'error', 'unknown', 'device-lost' ],
    FilterMode: [ 'nearest', 'linear' ],
    FrontFace: [ 'ccw', 'cw' ],
    IndexFormat: [ 'uint16', 'uint32' ],
    InputStepMode: [ 'vertex', 'instance' ],
    LoadOp: [ 'clear', 'load' ],
    PrimitiveTopology: [ 'point-list', 'line-list', 'line-strip', 'triangle-list', 'triangle-strip' ],
    StencilOperation: [ 'keep', 'zero', 'replace', 'invert', 'increment-clamp', 'decrement-clamp', 'increment-wrap', 'decrement-wrap' ],
    StoreOp: [ 'store' ],
    TextureAspect: [ 'all', 'stencil-only', 'depth-only' ],
    TextureComponentType: [ 'float', 'sint', 'uint' ],
    TextureDimension: [ '1d', '2d', '3d' ],
    TextureFormat: [
      'undefined', 'r8-unorm', 'r8-snorm', 'r8-uint', 'r8-sint', 'r16-uint', 'r16-sint',
      'r16-float', 'rg8-unorm', 'rg8-snorm', 'rg8-uint', 'rg8-sint', 'r32-float', 'r32-uint',
      'r32-sint', 'rg16-uint', 'rg16-sint', 'rg16-float', 'rgba8-unorm', 'rgba8-unorm-srgb',
      'rgba8-snorm', 'rgba8-uint', 'rgba8-sint', 'bgra8-unorm', 'bgra8-unorm-srgb',
      'rgb10-a2-unorm', 'rg11-b10-float', 'rg32-float', 'rg32-uint', 'rg32-sint', 'rgba16-uint',
      'rgba16-sint', 'rgba16-float', 'rgba32-float', 'rgba32-uint', 'rgba32-sint',
      'depth32-float', 'depth24-plus', 'depth24-plus-stencil8', 'bc1-rgba-unorm',
      'bc1-rgba-unorm-srgb', 'bc2-rgba-unorm', 'bc2-rgba-unorm-srgb', 'bc3-rgba-unorm',
      'bc3-rgba-unorm-srgb', 'bc4-r-unorm', 'bc4-r-snorm', 'bc5-rg-unorm', 'bc5-rg-snorm',
      'bc6h-rgb-ufloat', 'bc6h-rgb-sfloat', 'bc7-rgba-unorm', 'bc7-rgba-unorm-srgb',
    ],
    TextureViewDimension: [ 'undefined', '1d', '2d', '2d-array', 'cube', 'cube-array', '3d' ],
    VertexFormat: [
      'uchar2', 'uchar4', 'char2', 'char4', 'uchar2-norm', 'uchar4-norm', 'char2-norm',
      'char4-norm', 'ushort2', 'ushort4', 'short2', 'short4', 'ushort2-norm', 'ushort4-norm',
      'short2-norm', 'short4-norm', 'half2', 'half4', 'float', 'float2', 'float3', 'float4',
      'uint', 'uint2', 'uint3', 'uint4', 'int', 'int2', 'int3', 'int4',
    ],
  },

  // *Reference/*Release

  {{{ gpu.makeReferenceRelease('Device') }}}
  {{{ gpu.makeReferenceRelease('Queue') }}}

  {{{ gpu.makeReferenceRelease('CommandBuffer') }}}
  {{{ gpu.makeReferenceRelease('CommandEncoder') }}}
  {{{ gpu.makeReferenceRelease('RenderPassEncoder') }}}

  {{{ gpu.makeReferenceRelease('Buffer') }}}
  {{{ gpu.makeReferenceRelease('Texture') }}}
  {{{ gpu.makeReferenceRelease('TextureView') }}}

  {{{ gpu.makeReferenceRelease('RenderPipeline') }}}
  {{{ gpu.makeReferenceRelease('PipelineLayout') }}}
  {{{ gpu.makeReferenceRelease('ShaderModule') }}}

  // *Destroy

  dawnBufferDestroy: function(bufferId) { WebGPU.mgrBuffer.get(bufferId).destroy(); },
  dawnTextureDestroy: function(textureId) { WebGPU.mgrTexture.get(textureId).destroy(); },

  // dawnDevice

  // dawnDeviceCreate*

  dawnDeviceCreateQueue: function(deviceId) {
    assert(WebGPU.mgrQueue.objects.length === 1, 'there is only one queue');
    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrQueue.create(device.getQueue());
  },

  dawnDeviceCreateCommandEncoder: function(deviceId, descriptor) {
    if (descriptor) {
      {{{ gpu.makeCheckDescriptor('descriptor') }}}
    }
    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrCommandEncoder.create(device.createCommandEncoder());
  },

  dawnDeviceCreateBuffer: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}
    var desc = {
      usage: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnBufferDescriptor.usage) }}},
      size: {{{ gpu.makeGetU64('descriptor', C_STRUCTS.DawnBufferDescriptor.size) }}},
    };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrBuffer.create(device.createBuffer(desc));
  },

  dawnDeviceCreateTexture: function() {
    console.warn('dawnDeviceCreateTexture: unimplemented');
  },

  dawnDeviceCreatePipelineLayout: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}
    var bglCount = {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnPipelineLayoutDescriptor.bindGroupLayoutCount) }}};
    var bglPtr = {{{ makeGetValue('descriptor', C_STRUCTS.DawnPipelineLayoutDescriptor.bindGroupLayouts, '*') }}};
    var bgls = [];
    for (var i = 0; i < bglCount; ++i) {
      bgls.push(WebGPU.mgrBindGroupLayout.get(
        {{{ makeGetValue('bindGroupLayoutPtr', '4 * i', '*') }}}));
    }
    var desc = { bindGroupLayouts: bgls };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrPipelineLayout.create(device.createPipelineLayout(desc));
  },

  dawnDeviceCreateRenderPipeline: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}

    function makeRasterizationState(rsPtr) {
      if (rsPtr === null) return null;
      {{{ gpu.makeCheckDescriptor('rsPtr') }}}
      return {
        frontFace: WebGPU.FrontFace[
          {{{ gpu.makeGetU32('rsPtr', C_STRUCTS.DawnRasterizationStateDescriptor.frontFace) }}}],
        cullMode: WebGPU.CullMode[
          {{{ gpu.makeGetU32('rsPtr', C_STRUCTS.DawnRasterizationStateDescriptor.frontFace) }}}],
      };
    }

    function makeBlendDescriptor(bdPtr) {
      {{{ gpu.makeCheck('bdPtr !== 0') }}}
      return {
        operation: WebGPU.BlendOperation[
          {{{ gpu.makeGetU32('bdPtr', C_STRUCTS.DawnBlendDescriptor.operation) }}}],
        srcFactor: WebGPU.BlendFactor[
          {{{ gpu.makeGetU32('bdPtr', C_STRUCTS.DawnBlendDescriptor.srcFactor) }}}],
        dstFactor: WebGPU.BlendFactor[
          {{{ gpu.makeGetU32('bdPtr', C_STRUCTS.DawnBlendDescriptor.dstFactor) }}}],
      };
    }

    function makeColorState(csPtr) {
      {{{ gpu.makeCheckDescriptor('csPtr') }}}
      return {
        format: WebGPU.TextureFormat[
          {{{ gpu.makeGetU32('csPtr', C_STRUCTS.DawnColorStateDescriptor.format) }}}],
        alphaBlend: makeBlendDescriptor(
          {{{ makeGetValue('csPtr', C_STRUCTS.DawnColorStateDescriptor.alphaBlend, '*') }}}),
        colorBlend: makeBlendDescriptor(
          {{{ makeGetValue('csPtr', C_STRUCTS.DawnColorStateDescriptor.colorBlend, '*') }}}),
        writeMask: {{{ gpu.makeGetU32('csPtr', C_STRUCTS.DawnColorStateDescriptor.writeMask) }}},
      };
    }

    function makeColorStates(count, csPtrs) {
      if (count === 0) return undefined;

      var states = [];
      for (var i = 0; i < count; ++i) {
        states.push(makeColorState(
          {{{ makeGetValue('csPtrs', 'i * 4', '*') }}}));
      }
      return states;
    }

    function makeStencilStateFace(ssfPtr) {
      {{{ gpu.makeCheck('ssfPtr !== 0') }}}
      return {
        compare: WebGPU.CompareFunction[
          {{{ gpu.makeGetU32('ssfPtr', C_STRUCTS.DawnStencilStateFaceDescriptor.compare) }}}],
        failOp: WebGPU.StencilOperation[
          {{{ gpu.makeGetU32('ssfPtr', C_STRUCTS.DawnStencilStateFaceDescriptor.failOp) }}}],
        depthFailOp: WebGPU.StencilOperation[
          {{{ gpu.makeGetU32('ssfPtr', C_STRUCTS.DawnStencilStateFaceDescriptor.depthFailOp) }}}],
        passOp: WebGPU.StencilOperation[
          {{{ gpu.makeGetU32('ssfPtr', C_STRUCTS.DawnStencilStateFaceDescriptor.passOp) }}}],
      };
    }

    function makeDepthStencilState(dssPtr) {
      {{{ gpu.makeCheck('dssPtr !== 0') }}}
      return {
        format: WebGPU.TextureFormat[
          {{{ gpu.makeGetU32('dssPtr', C_STRUCTS.DawnDepthStencilStateDescriptor.format) }}}],
        depthWriteEnabled: {{{ gpu.makeGetBool('dssPtr', C_STRUCTS.DawnDepthStencilStateDescriptor.depthWriteEnabled) }}},
        depthCompare: WebGPU.CompareFunction[
          {{{ gpu.makeGetU32('dssPtr', C_STRUCTS.DawnDepthStencilStateDescriptor.depthCompare) }}}],
        stencilFront: makeStencilStateFace(
          {{{ makeGetValue('dssPtr', C_STRUCTS.DawnDepthStencilStateDescriptor.stencilFront, '*') }}}),
        stencilBack: makeStencilStateFace(
          {{{ makeGetValue('dssPtr', C_STRUCTS.DawnDepthStencilStateDescriptor.stencilBack, '*') }}}),
        stencilReadMask: {{{ gpu.makeGetU32('dssPtr', C_STRUCTS.DawnDepthStencilStateDescriptor.stencilReadMask) }}},
        stencilWriteMask: {{{ gpu.makeGetU32('dssPtr', C_STRUCTS.DawnDepthStencilStateDescriptor.stencilWriteMask) }}},
      };
    }

    function makeVertexAttribute(vaPtr) {
      {{{ gpu.makeCheck('vaPtr !== 0') }}}
      return {
        offset: {{{ gpu.makeGetU64('vaPtr', C_STRUCTS.DawnVertexAttributeDescriptor.offset) }}},
        format: WebGPU.VertexFormat[
          {{{ gpu.makeGetU32('vaPtr', C_STRUCTS.DawnVertexAttributeDescriptor.format) }}}],
        shaderLocation: {{{ gpu.makeGetU32('vaPtr', C_STRUCTS.DawnVertexAttributeDescriptor.shaderLocation) }}},
      };
    }

    function makeVertexAttributes(count, vaPtrs) {
      var vas = [];
      for (var i = 0; i < count; ++i) {
        vas.push(makeVertexAttribute(
          {{{ makeGetValue('vaPtrs', 'i * 4', '*') }}}));
      }
      return vas;
    }

    function makeVertexBuffer(vbPtr) {
      if (vbPtr === 0) return undefined;

      return {
        stride: {{{ gpu.makeGetU64('vbPtr', C_STRUCTS.DawnVertexBufferDescriptor.stride) }}},
        stepMode: WebGPU.InputStepMode[
          {{{ gpu.makeGetU32('vbPtr', C_STRUCTS.DawnVertexBufferDescriptor.stepMode) }}}],
        attributeSet: makeVertexAttributes(
          {{{ gpu.makeGetU32('vbPtr', C_STRUCTS.DawnVertexBufferDescriptor.attributeCount) }}},
          {{{ makeGetValue('vbPtr', C_STRUCTS.DawnVertexBufferDescriptor.attributes, '*') }}}),
      };
    }

    function makeVertexBuffers(count, vbPtrs) {
      if (count === 0) return undefined;

      var vbs = [];
      for (var i = 0; i < count; ++i) {
        vbs.push(makeVertexBuffer(
          {{{ makeGetValue('vbPtrs', 'i * 4', '*') }}}));
      }
      return vbs;
    }

    function makeVertexInput(viPtr) {
      {{{ gpu.makeCheckDescriptor('viPtr') }}}
      return {
        indexFormat: WebGPU.IndexFormat[
          {{{ gpu.makeGetU32('viPtr', C_STRUCTS.DawnVertexInputDescriptor.indexFormat) }}}],
        vertexBuffers: makeVertexBuffers(
          {{{ gpu.makeGetU32('viPtr', C_STRUCTS.DawnVertexInputDescriptor.bufferCount) }}},
          {{{ makeGetValue('viPtr', C_STRUCTS.DawnVertexInputDescriptor.buffers, '*') }}}),
      };
    }

    var desc = {
      layout: WebGPU.mgrPipelineLayout.get(
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.layout, '*') }}}),
      vertexStage: null,
      fragmentStage: null,
      primitiveTopology: WebGPU.PrimitiveTopology[
        {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.primitiveTopology) }}}],
      rasterizationState: makeRasterizationState(
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.rasterizationState, '*') }}}),
      colorStates: makeColorStates(
        {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.colorStateCount) }}},
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.colorStates, '*') }}}),
      depthStencilState: makeDepthStencilState(
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.depthStencilState, '*') }}}),
      vertexInput: makeVertexInput(
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.vertexInput, '*') }}}),
      sampleCount: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.sampleCount) }}},
      sampleMask: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.sampleMask) }}},
      alphaToCoverageEnabled: {{{ gpu.makeGetBool('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.alphaToCoverageEnabled) }}},
    };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrRenderPipeline.create(device.createRenderPipeline(desc));
  },

  dawnDeviceCreateShaderModule: function(descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}
    var count = {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnShaderModuleDescriptor.codeSize) }}};
    var start = {{{ makeGetValue('descriptor', C_STRUCTS.DawnShaderModuleDescriptor.code, '*') }}};
    var desc = { code: HEAP32.subarray(start, start + count) };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrShaderModule.create(device.createShaderModule(desc));
  },

  dawnDeviceSetUncapturedErrorCallback: function(deviceId, callback, userdata) {
    var device = WebGPU.mgrDevice.get(deviceId);
    device.onuncapturederror = function(ev) {
      // DawnErrorType type, const char* message, void* userdata
      var Validation = 0x00000001;
      var OutOfMemory = 0x00000002;
      var type;
      if (ev.error instanceof GPUValidationError) type = Validation;
      else if (ev.error instanceof GPUOutOfMemoryError) type = OutOfMemory;
      var message = 0; // TODO: copy ev.error.message into memory, pass it, then free it
      dynCall('viii', callback, [type, message, userdata]);
    };
  },

  // dawnQueue

  dawnQueueSubmit: function(queueId, commandCount, commands) {
#if ASSERTIONS
    assert(commands % 4 === 0);
#endif
    var queue = WebGPU.mgrQueue.get(queueId);
    var cmds = Array.from(HEAP32.subarray(commands >> 2, (commands >> 2) + commandCount),
      function(id) { return WebGPU.mgrCommandBuffer.get(id); });
    queue.submit(cmds);
  },

  // dawnCommandEncoder

  dawnCommandEncoderFinish: function(commandEncoderId) {
    var commandEncoder = WebGPU.mgrCommandEncoder.get(commandEncoderId);
    return WebGPU.mgrCommandBuffer.create(commandEncoder.finish());
  },

  dawnCommandEncoderBeginRenderPass: function(commandEncoderId, descriptor) {
    {{{ gpu.makeCheck('descriptor !== 0') }}}

    function makeColorAttachment(caPtr) {
      return {
        attachment: WebGPU.mgrTextureView.get(
          {{{ gpu.makeGetU32('caPtr', C_STRUCTS.DawnRenderPassColorAttachmentDescriptor.attachment) }}}),
        resolveTarget: WebGPU.mgrTextureView.get(
          {{{ gpu.makeGetU32('caPtr', C_STRUCTS.DawnRenderPassColorAttachmentDescriptor.resolveTarget) }}}),
        loadOp: WebGPU.LoadOp[
          {{{ gpu.makeGetU32('caPtr', C_STRUCTS.DawnRenderPassColorAttachmentDescriptor.loadOp) }}}],
        storeOp: WebGPU.StoreOp[
          {{{ gpu.makeGetU32('caPtr', C_STRUCTS.DawnRenderPassColorAttachmentDescriptor.storeOp) }}}],
        clearColor: WebGPU.getColor(caPtr + {{{ C_STRUCTS.DawnRenderPassColorAttachmentDescriptor.clearColor }}}),
      };
    }

    function makeColorAttachments(count, caPtrs) {
      var attachments = [];
      for (var i = 0; i < count; ++i) {
        attachments.push(makeColorAttachment(
          {{{ makeGetValue('caPtrs', 'i * 4', '*') }}}));
      }
      return attachments;
    }

    function makeDepthStencilAttachment(dsaPtr) {
      if (dsaPtr === 0) return undefined;
      return {
        attachment: WebGPU.mgrTextureView.get(
          {{{ gpu.makeGetU32('dsaPtr', C_STRUCTS.DawnRenderPassDepthStencilAttachmentDescriptor.attachment) }}}),
        depthLoadOp: WebGPU.LoadOp[
          {{{ gpu.makeGetU32('dsaPtr', C_STRUCTS.DawnRenderPassDepthStencilAttachmentDescriptor.depthLoadOp) }}}],
        depthStoreOp: WebGPU.StoreOp[
          {{{ gpu.makeGetU32('dsaPtr', C_STRUCTS.DawnRenderPassDepthStencilAttachmentDescriptor.depthStoreOp) }}}],
        clearDepth: {{{ makeGetValue('dsaPtr', C_STRUCTS.DawnRenderPassDepthStencilAttachmentDescriptor.clearDepth, 'float') }}},
        stencilLoadOp: WebGPU.LoadOp[
          {{{ gpu.makeGetU32('dsaPtr', C_STRUCTS.DawnRenderPassDepthStencilAttachmentDescriptor.stencilLoadOp) }}}],
        stencilStoreOp: WebGPU.StoreOp[
          {{{ gpu.makeGetU32('dsaPtr', C_STRUCTS.DawnRenderPassDepthStencilAttachmentDescriptor.stencilStoreOp) }}}],
        clearStencil: {{{ gpu.makeGetU32('dsaPtr', C_STRUCTS.DawnRenderPassDepthStencilAttachmentDescriptor.clearStencil) }}},
      };
    }

    function makeRenderPassDescriptor(descriptor) {
      // required sequence<GPURenderPassColorAttachmentDescriptor> colorAttachments;
      // GPURenderPassDepthStencilAttachmentDescriptor depthStencilAttachment;
      return {
        colorAttachments: makeColorAttachments(
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnRenderPassDescriptor.colorAttachmentCount) }}},
          {{{ makeGetValue('descriptor', C_STRUCTS.DawnRenderPassDescriptor.colorAttachments, '*') }}}),
        depthStencilAttachment: makeDepthStencilAttachment(
          {{{ makeGetValue('descriptor', C_STRUCTS.DawnRenderPassDescriptor.depthStencilAttachment, '*') }}}),
      };
    }

    var commandEncoder = WebGPU.mgrCommandEncoder.get(commandEncoderId);
    commandEncoder.beginRenderPass(makeRenderPassDescriptor(descriptor));
  },

  dawnCommandEncoderCopyBufferToBuffer: function(commandEncoderId, srcId, srcOffset_l, srcOffset_h, dstId, dstOffset_l, dstOffset_h, size_l, size_h) {
    var commandEncoder = WebGPU.mgrCommandEncoder.get(commandEncoderId);
    var src = WebGPU.mgrBuffer.get(srcId);
    var dst = WebGPU.mgrBuffer.get(dstId);
    commandEncoder.copyBufferToBuffer(
      src, {{{ makeU64ToNumber('srcOffset_l', 'srcOffset_h') }}},
      dst, {{{ makeU64ToNumber('dstOffset_l', 'dstOffset_h') }}},
      {{{ makeU64ToNumber('size_l', 'size_h') }}});
  },

  dawnCommandEncoderCopyTextureToBuffer: function() {
    console.warn('dawnCommandEncoderCopyTextureToBuffer: unimplemented');
  },

  // dawnBuffer

  dawnBufferSetSubData: function(bufferId, start_l, start_h, count_l, count_h, data) {
    var buffer = WebGPU.mgrBuffer.get(bufferId);
    var start = {{{ makeU64ToNumber('start_l', 'start_h') }}};
    var count = {{{ makeU64ToNumber('count_l', 'count_h') }}};
    buffer.setSubData(start, HEAPU8, data, count);
  },

  dawnBufferMapReadAsync: function(bufferId, callback, userdata) {
    var bufferEntry = WebGPU.mgrBuffer.objects[bufferId];
    bufferEntry.mapped = 'write';
    var buffer = bufferEntry.object;

    buffer.mapReadAsync().then(function(mapped) {
      var DAWN_BUFFER_MAP_ASYNC_STATUS_SUCCESS = 0;
      var data = _malloc(mapped.byteLength);
      HEAP8.set(new Uint8Array(mapped), data);
      var dataLength_h = (mapped.byteLength / 0x100000000) | 0;
      var dataLength_l = mapped.byteLength | 0;
      // DawnBufferMapAsyncStatus status, const void* data, uint64_t dataLength, void* userdata
      dynCall('viiji', callback, [DAWN_BUFFER_MAP_ASYNC_STATUS_SUCCESS, data, dataLength_l, dataLength_h, userdata]);
    }, function() {
      // TODO(kainino0x): Figure out how to pick other error status values.
      var DAWN_BUFFER_MAP_ASYNC_STATUS_ERROR = 1;
      dynCall('viiji', callback, [DAWN_BUFFER_MAP_ASYNC_STATUS_ERROR, 0, 0, 0, userdata]);
    });
  },

  dawnBufferMapWriteAsync: function(bufferId, callback, userdata) {
    var e = WebGPU.mgrBuffer.objects[bufferId];
    var buffer = e.object;

    buffer.mapWriteAsync().then(function(mapped) {
      var DAWN_BUFFER_MAP_ASYNC_STATUS_SUCCESS = 0;
      var data = _malloc(mapped.byteLength);
      HEAP8.fill(0, data, mapped.byteLength);
      e.mapWriteSrc = data;
      e.mapWriteDst = mapped;

      var dataLength_h = (mapped.byteLength / 0x100000000) | 0;
      var dataLength_l = mapped.byteLength | 0;
      // DawnBufferMapAsyncStatus status, void* data, uint64_t dataLength, void* userdata
      dynCall('viiji', callback, [DAWN_BUFFER_MAP_ASYNC_STATUS_SUCCESS, data, dataLength_l, dataLength_h, userdata]);
    }, function() {
      // TODO(kainino0x): Figure out how to pick other error status values.
      var DAWN_BUFFER_MAP_ASYNC_STATUS_ERROR = 1;
      dynCall('viiji', callback, [DAWN_BUFFER_MAP_ASYNC_STATUS_ERROR, 0, 0, 0, userdata]);
    });
  },

  dawnBufferUnmap: function(bufferId) {
    var e = WebGPU.mgrBuffer.objects[bufferId];
    if (e.mapWriteSrc) {
      new Uint8Array(e.mapWriteDst).set(HEAP8.subarray(e.mapWriteSrc, e.mapWriteSrc + e.mapWriteDst.byteLength));
    }
    e.mapWriteSrc = undefined;
    e.mapWriteDst = undefined;
    e.object.unmap();
  },

  // dawnTexture

  dawnTextureCreateView: function() {
    console.warn('dawnTextureCreateView: unimplemented');
  },

  // dawnRenderPass

  dawnRenderPassEncoderSetPipeline: function() {
    console.warn('dawnRenderPassEncoderSetPipeline: unimplemented');
  },
  dawnRenderPassEncoderDraw: function() {
    console.warn('dawnRenderPassEncoderDraw: unimplemented');
  },
  dawnRenderPassEncoderEndPass: function() {
    console.warn('dawnRenderPassEncoderEndPass: unimplemented');
  },
};

autoAddDeps(LibraryWebGPU, '$WebGPU');
mergeInto(LibraryManager.library, LibraryWebGPU);
