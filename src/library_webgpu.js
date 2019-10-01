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

    makeGetBool: function(ptr, pos) {
      // In an actual build, bool seems to be i8. But on the off-chance it's i32, on little-endian
      // this will still work as long as the value of 'true' isn't zero in the lowest byte.
      return '(' + makeGetValue(ptr, pos, 'i8') + ' !== 0)';
    },
    makeGetU32: function(ptr, pos) { return makeGetValue(ptr, pos, 'i32', false, true); },
    makeGetU64: function(ptr, pos) {
      var l = makeGetValue(ptr, pos, 'i32', false, true);
      var h = makeGetValue('(' + ptr + ' + 4)', pos, 'i32', false, true)
      return h + ' * 0x100000000 + ' + l
    },

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
      if (this.mgrDevice) return;

      function makeManager() {
        return {
          objects: [undefined],
          create: function(object) {
            var id = this.objects.length;
            {{{ gpu.makeCheck("typeof this.objects[id] === 'undefined'") }}}
            this.objects[id] = { refcount: 1, object };
            return id;
          },
          get: function(id) {
            if (id === 0) return undefined;
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
            {{{ gpu.makeCheck('o.refcount > 0') }}}
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

      {{{ gpu.makeInitManager('BindGroup') }}}
      {{{ gpu.makeInitManager('Buffer') }}}
      {{{ gpu.makeInitManager('Sampler') }}}
      {{{ gpu.makeInitManager('Texture') }}}
      {{{ gpu.makeInitManager('TextureView') }}}

      {{{ gpu.makeInitManager('BindGroupLayout') }}}
      {{{ gpu.makeInitManager('PipelineLayout') }}}
      {{{ gpu.makeInitManager('RenderPipeline') }}}
      {{{ gpu.makeInitManager('ShaderModule') }}}
    },

    makeColor: function(ptr) {
      return {
        r: {{{ makeGetValue('ptr', 0, 'float') }}},
        g: {{{ makeGetValue('ptr', 4, 'float') }}},
        b: {{{ makeGetValue('ptr', 8, 'float') }}},
        a: {{{ makeGetValue('ptr', 12, 'float') }}},
      };
    },

    makeExtent3D: function(ptr) {
      return {
        width: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnExtent3D.width) }}},
        height: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnExtent3D.height) }}},
        depth: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnExtent3D.depth) }}},
      };
    },

    makeOrigin3D: function(ptr) {
      return {
        x: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnOrigin3D.x) }}},
        y: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnOrigin3D.y) }}},
        z: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnOrigin3D.z) }}},
      };
    },

    makeTextureCopyView: function(ptr) {
      {{{ gpu.makeCheckDescriptor('ptr') }}}
      return {
        texture: this.mgrTexture.get(
          {{{ makeGetValue('ptr', C_STRUCTS.DawnTextureCopyView.texture, '*') }}}),
        mipLevel: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnTextureCopyView.mipLevel, '*') }}},
        arrayLayer: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnTextureCopyView.arrayLayer, '*') }}},
        origin: WebGPU.makeOrigin3D(ptr + {{{ C_STRUCTS.DawnTextureCopyView.origin }}}),
      };
    },

    makeBufferCopyView: function(ptr) {
      {{{ gpu.makeCheckDescriptor('ptr') }}}
      return {
        buffer: this.mgrBuffer.get(
          {{{ makeGetValue('ptr', C_STRUCTS.DawnBufferCopyView.buffer, '*') }}}),
        offset: {{{ gpu.makeGetU64('ptr', C_STRUCTS.DawnBufferCopyView.offset) }}},
        rowPitch: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnBufferCopyView.rowPitch) }}},
        imageHeight: {{{ gpu.makeGetU32('ptr', C_STRUCTS.DawnBufferCopyView.imageHeight) }}},
      };
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
      undefined, 'r8unorm', 'r8snorm', 'r8uint', 'r8sint', 'r16uint', 'r16sint',
      'r16float', 'rg8unorm', 'rg8snorm', 'rg8uint', 'rg8sint', 'r32float', 'r32uint',
      'r32sint', 'rg16uint', 'rg16sint', 'rg16float', 'rgba8unorm', 'rgba8unorm-srgb',
      'rgba8snorm', 'rgba8uint', 'rgba8sint', 'bgra8unorm', 'bgra8unorm-srgb',
      'rgb10a2unorm', 'rg11b10float', 'rg32float', 'rg32uint', 'rg32sint', 'rgba16uint',
      'rgba16sint', 'rgba16float', 'rgba32float', 'rgba32uint', 'rgba32sint',
      'depth32float', 'depth24plus', 'depth24plus-stencil8', 'bc1rgbaunorm',
      'bc1rgbaunorm-srgb', 'bc2rgbaunorm', 'bc2rgbaunorm-srgb', 'bc3rgbaunorm',
      'bc3rgbaunorm-srgb', 'bc4runorm', 'bc4rsnorm', 'bc5rgunorm', 'bc5rgsnorm',
      'bc6hrgbufloat', 'bc6hrgbsfloat', 'bc7rgbaunorm', 'bc7rgbaunorm-srgb',
    ],
    TextureViewDimension: [ undefined, '1d', '2d', '2darray', 'cube', 'cube-array', '3d' ],
    VertexFormat: [
      'uchar2', 'uchar4', 'char2', 'char4', 'uchar2norm', 'uchar4norm', 'char2norm',
      'char4norm', 'ushort2', 'ushort4', 'short2', 'short4', 'ushort2norm', 'ushort4norm',
      'short2norm', 'short4norm', 'half2', 'half4', 'float', 'float2', 'float3', 'float4',
      'uint', 'uint2', 'uint3', 'uint4', 'int', 'int2', 'int3', 'int4',
    ],
  },

  // *Reference/*Release

  {{{ gpu.makeReferenceRelease('Device') }}}
  {{{ gpu.makeReferenceRelease('Queue') }}}

  {{{ gpu.makeReferenceRelease('CommandBuffer') }}}
  {{{ gpu.makeReferenceRelease('CommandEncoder') }}}
  {{{ gpu.makeReferenceRelease('RenderPassEncoder') }}}

  {{{ gpu.makeReferenceRelease('BindGroup') }}}
  {{{ gpu.makeReferenceRelease('Buffer') }}}
  {{{ gpu.makeReferenceRelease('Sampler') }}}
  {{{ gpu.makeReferenceRelease('Texture') }}}
  {{{ gpu.makeReferenceRelease('TextureView') }}}

  {{{ gpu.makeReferenceRelease('BindGroupLayout') }}}
  {{{ gpu.makeReferenceRelease('PipelineLayout') }}}
  {{{ gpu.makeReferenceRelease('RenderPipeline') }}}
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

  dawnDeviceCreateTexture: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}

    var desc = {
      size: WebGPU.makeExtent3D(descriptor + {{{ C_STRUCTS.DawnTextureDescriptor.size }}}),
      arrayLayerCount: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureDescriptor.arrayLayerCount) }}},
      mipLevelCount: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureDescriptor.mipLevelCount) }}},
      sampleCount: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureDescriptor.sampleCount) }}},
      dimension: WebGPU.TextureDimension[
        {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureDescriptor.dimension) }}}],
      format: WebGPU.TextureFormat[
        {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureDescriptor.format) }}}],
      usage: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureDescriptor.usage) }}},
    };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrTexture.create(device.createTexture(desc));
  },

  dawnDeviceCreateSampler: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}

    var desc = {
      addressModeU: WebGPU.AddressMode[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnSamplerDescriptor.addressModeU) }}}],
      addressModeV: WebGPU.AddressMode[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnSamplerDescriptor.addressModeV) }}}],
      addressModeW: WebGPU.AddressMode[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnSamplerDescriptor.addressModeW) }}}],
      magFilter: WebGPU.FilterMode[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnSamplerDescriptor.magFilter) }}}],
      minFilter: WebGPU.FilterMode[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnSamplerDescriptor.minFilter) }}}],
      mipmapFilter: WebGPU.FilterMode[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnSamplerDescriptor.mipmapFilter) }}}],
      lodMinClamp: {{{ makeGetValue('descriptor', C_STRUCTS.DawnSamplerDescriptor.lodMinClamp, 'float') }}},
      lodMaxClamp: {{{ makeGetValue('descriptor', C_STRUCTS.DawnSamplerDescriptor.lodMaxClamp, 'float') }}},
      compare: WebGPU.CompareFunction[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnSamplerDescriptor.compare) }}}],
    };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrSampler.create(device.createSampler(desc));
  },

  dawnDeviceCreateBindGroupLayout: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}

    function makeBinding(bindingPtr) {
      {{{ gpu.makeCheck('bindingPtr !== 0') }}}

      return {
        binding:
          {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupLayoutBinding.binding) }}},
        visibility:
          {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupLayoutBinding.visibility) }}},
        type: WebGPU.BindingType[
          {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupLayoutBinding.type) }}}],
        textureDimension: WebGPU.TextureViewDimension[
          {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupLayoutBinding.textureDimension) }}}],
        textureComponentType: WebGPU.TextureComponentType[
          {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupLayoutBinding.textureComponentType) }}}],
        multisampled:
          {{{ gpu.makeGetBool('bindingPtr', C_STRUCTS.DawnBindGroupLayoutBinding.multisampled) }}},
        hasDynamicOffset:
          {{{ gpu.makeGetBool('bindingPtr', C_STRUCTS.DawnBindGroupLayoutBinding.hasDynamicOffset) }}},
      };
    }

    function makeBindings(count, bindingsPtrs) {
      var bindings = [];
      for (var i = 0; i < count; ++i) {
        bindings.push(makeBinding(bindingsPtrs +
            {{{ C_STRUCTS.DawnBindGroupLayoutBinding.__size__ }}} * i));
      }
      return bindings;
    }

    var desc = {
      bindings: makeBindings(
        {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnBindGroupLayoutDescriptor.bindingCount) }}},
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnBindGroupLayoutDescriptor.bindings, '*') }}},
      ),
    };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrBindGroupLayout.create(device.createBindGroupLayout(desc));
  },

  dawnDeviceCreateBindGroup: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}

    function makeBinding(bindingPtr) {
      {{{ gpu.makeCheck('bindingPtr !== 0') }}}

      var bufferId = {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupBinding.buffer) }}};
      var samplerId = {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupBinding.sampler) }}};
      var textureViewId = {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupBinding.textureView) }}};
#if ASSERTIONS
      assert((bufferId != 0) + (samplerId != 0) + (textureViewId != 0) == 1);
#endif

      var binding = {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupLayoutBinding.binding) }}};

      if (bufferId != 0) {
        var size = undefined;

        // Handle WGPU_WHOLE_SIZE.
        var sizePart1 = {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupBinding.size) }}};
        var sizePart2 = {{{ gpu.makeGetU32('bindingPtr', C_STRUCTS.DawnBindGroupBinding.size + 4) }}};
        if (sizePart1 != 0xFFFFFFFF || sizePart2 != 0xFFFFFFFF) {
          size = {{{ gpu.makeGetU64('bindingPtr', C_STRUCTS.DawnBindGroupBinding.size) }}};
        }

        return {
          binding,
          resource: {
            buffer: WebGPU.mgrBuffer.get(bufferId),
            offset: {{{ gpu.makeGetU64('bindingPtr', C_STRUCTS.DawnBindGroupBinding.offset) }}},
            size: size,
          },
        };
      } else if (samplerId != 0) {
        return {
          binding,
          resource: WebGPU.mgrSampler.get(samplerId),
        };
      } else {
        return {
          binding,
          resource: WebGPU.mgrTextureView.get(textureViewId),
        };
      }
    }

    function makeBindings(count, bindingsPtrs) {
      var bindings = [];
      for (var i = 0; i < count; ++i) {
        bindings.push(makeBinding(bindingsPtrs +
            {{{C_STRUCTS.DawnBindGroupBinding.__size__}}} * i));
      }
      return bindings;
    }

    var desc = {
      layout: WebGPU.mgrBindGroupLayout.get(
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnBindGroupDescriptor.layout, '*') }}}),
      bindings: makeBindings(
        {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnBindGroupDescriptor.bindingCount) }}},
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnBindGroupDescriptor.bindings, '*') }}},
      ),
    };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrBindGroup.create(device.createBindGroup(desc));
  },

  dawnDeviceCreatePipelineLayout: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}
    var bglCount = {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnPipelineLayoutDescriptor.bindGroupLayoutCount) }}};
    var bglPtr = {{{ makeGetValue('descriptor', C_STRUCTS.DawnPipelineLayoutDescriptor.bindGroupLayouts, '*') }}};
    var bgls = [];
    for (var i = 0; i < bglCount; ++i) {
      bgls.push(WebGPU.mgrBindGroupLayout.get(
        {{{ makeGetValue('bglPtr', '4 * i', '*') }}}));
    }
    var desc = { bindGroupLayouts: bgls };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrPipelineLayout.create(device.createPipelineLayout(desc));
  },

  dawnDeviceCreateRenderPipeline: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}

    function makeStage(ptr) {
      if (ptr === 0) return undefined;
      {{{ gpu.makeCheckDescriptor('ptr') }}}
      return {
        module: WebGPU.mgrShaderModule.get(
          {{{ makeGetValue('ptr', C_STRUCTS.DawnPipelineStageDescriptor.module, '*') }}}),
        entryPoint: UTF8ToString(
          {{{ makeGetValue('ptr', C_STRUCTS.DawnPipelineStageDescriptor.entryPoint, '*') }}}),
      };
    }

    function makeRasterizationState(rsPtr) {
      if (rsPtr === 0) return undefined;
      {{{ gpu.makeCheckDescriptor('rsPtr') }}}
      return {
        frontFace: WebGPU.FrontFace[
          {{{ gpu.makeGetU32('rsPtr', C_STRUCTS.DawnRasterizationStateDescriptor.frontFace) }}}],
        cullMode: WebGPU.CullMode[
          {{{ gpu.makeGetU32('rsPtr', C_STRUCTS.DawnRasterizationStateDescriptor.frontFace) }}}],
      };
    }

    function makeBlendDescriptor(bdPtr) {
      if (bdPtr === 0) return undefined;
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

    function makeColorStates(count, csPtr) {
      if (count === 0) return undefined;

      var states = [];
      for (var i = 0; i < count; ++i) {
        states.push(makeColorState(csPtr + {{{ C_STRUCTS.DawnColorStateDescriptor.__size__ }}} * i));
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
      if (dssPtr === 0) return undefined;

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

    function makeVertexAttributes(count, vaArrayPtr) {
      var vas = [];
      for (var i = 0; i < count; ++i) {
        vas.push(makeVertexAttribute(vaArrayPtr + i * {{{ C_STRUCTS.DawnVertexAttributeDescriptor.__size__ }}}));
      }
      return vas;
    }

    function makeVertexBuffer(vbPtr) {
      if (vbPtr === 0) return undefined;

      return {
        stride: {{{ gpu.makeGetU64('vbPtr', C_STRUCTS.DawnVertexBufferDescriptor.stride) }}},
        stepMode: WebGPU.InputStepMode[
          {{{ gpu.makeGetU32('vbPtr', C_STRUCTS.DawnVertexBufferDescriptor.stepMode) }}}],
        // TODO(kainino0x): Update naming once Dawn matches WebGPU.
        attributeSet: makeVertexAttributes(
          {{{ gpu.makeGetU32('vbPtr', C_STRUCTS.DawnVertexBufferDescriptor.attributeCount) }}},
          {{{ makeGetValue('vbPtr', C_STRUCTS.DawnVertexBufferDescriptor.attributes, '*') }}}),
      };
    }

    function makeVertexBuffers(count, vbArrayPtr) {
      if (count === 0) return undefined;

      var vbs = [];
      for (var i = 0; i < count; ++i) {
        vbs.push(makeVertexBuffer(vbArrayPtr + i * {{{ C_STRUCTS.DawnVertexBufferDescriptor.__size__ }}}));
      }
      return vbs;
    }

    function makeVertexInput(viPtr) {
      if (viPtr === 0) return undefined;
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
      vertexStage: makeStage(
        descriptor + {{{ C_STRUCTS.DawnRenderPipelineDescriptor.vertexStage }}}),
      fragmentStage: makeStage(
        {{{ makeGetValue('descriptor', C_STRUCTS.DawnRenderPipelineDescriptor.fragmentStage, '*') }}}),
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

  dawnDeviceCreateShaderModule: function(deviceId, descriptor) {
    {{{ gpu.makeCheckDescriptor('descriptor') }}}
    var count = {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnShaderModuleDescriptor.codeSize) }}};
    var start = {{{ makeGetValue('descriptor', C_STRUCTS.DawnShaderModuleDescriptor.code, '*') }}};
    var desc = { code: HEAPU32.subarray(start >> 2, (start >> 2) + count) };

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
      var messagePtr = allocateUTF8(ev.error.message);
      dynCall('viii', callback, [type, messagePtr, userdata]);
      _free(messagePtr);
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

  dawnCommandEncoderFinish: function(encoderId) {
    var commandEncoder = WebGPU.mgrCommandEncoder.get(encoderId);
    return WebGPU.mgrCommandBuffer.create(commandEncoder.finish());
  },

  dawnCommandEncoderBeginRenderPass: function(encoderId, descriptor) {
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
        loadValue: WebGPU.makeColor(caPtr + {{{ C_STRUCTS.DawnRenderPassColorAttachmentDescriptor.clearColor }}}),
      };
    }

    function makeColorAttachments(count, caPtr) {
      var attachments = [];
      for (var i = 0; i < count; ++i) {
        attachments.push(makeColorAttachment(caPtr + {{{ C_STRUCTS.DawnRenderPassColorAttachmentDescriptor.__size__ }}} * i));
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

    var commandEncoder = WebGPU.mgrCommandEncoder.get(encoderId);
    return WebGPU.mgrRenderPassEncoder.create(commandEncoder.beginRenderPass(makeRenderPassDescriptor(descriptor)));
  },

  dawnCommandEncoderCopyBufferToBuffer: function(encoderId, srcId, srcOffset_l, srcOffset_h, dstId, dstOffset_l, dstOffset_h, size_l, size_h) {
    var commandEncoder = WebGPU.mgrCommandEncoder.get(encoderId);
    var src = WebGPU.mgrBuffer.get(srcId);
    var dst = WebGPU.mgrBuffer.get(dstId);
    commandEncoder.copyBufferToBuffer(
      src, {{{ makeU64ToNumber('srcOffset_l', 'srcOffset_h') }}},
      dst, {{{ makeU64ToNumber('dstOffset_l', 'dstOffset_h') }}},
      {{{ makeU64ToNumber('size_l', 'size_h') }}});
  },

  dawnCommandEncoderCopyBufferToTexture: function(encoderId, srcPtr, dstPtr, copySizePtr) {
    var commandEncoder = WebGPU.mgrCommandEncoder.get(encoderId);
    var copySize = WebGPU.makeExtent3D(copySizePtr);
    commandEncoder.copyBufferToTexture(
      WebGPU.makeBufferCopyView(srcPtr), WebGPU.makeTextureCopyView(dstPtr), copySize);
  },

  dawnCommandEncoderCopyTextureToBuffer: function(encoderId, srcPtr, dstPtr, copySizePtr) {
    var commandEncoder = WebGPU.mgrCommandEncoder.get(encoderId);
    var copySize = WebGPU.makeExtent3D(copySizePtr);
    commandEncoder.copyTextureToBuffer(
      WebGPU.makeTextureCopyView(srcPtr), WebGPU.makeBufferCopyView(dstPtr), copySize);
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

  dawnTextureCreateView: function(textureId, descriptor) {
    var desc;
    if (descriptor !== 0) {
      {{{ gpu.makeCheckDescriptor('descriptor') }}}

      desc = {
        format: WebGPU.TextureFormat[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureViewDescriptor.format) }}}],
        dimension: WebGPU.TextureViewDimension[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureViewDescriptor.dimension) }}}],
        baseMipLevel: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureViewDescriptor.baseMipLevel) }}},
        mipLevelCount: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureViewDescriptor.mipLevelCount) }}},
        baseArrayLayer: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureViewDescriptor.baseArrayLayer) }}},
        arrayLayerCount: {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureViewDescriptor.arrayLayerCount) }}},
        aspect: WebGPU.TextureAspect[
          {{{ gpu.makeGetU32('descriptor', C_STRUCTS.DawnTextureViewDescriptor.aspect) }}}],
      };
    }

    var texture = WebGPU.mgrTexture.get(textureId);
    return WebGPU.mgrTextureView.create(texture.createView(desc));
  },

  // dawnRenderPass

  dawnRenderPassEncoderSetBindGroup: function(passId, groupIndex, groupId, dynamicOffsetCount, dynamicOffsetsPtr) {
    var pass = WebGPU.mgrRenderPassEncoder.get(passId);
    var group = WebGPU.mgrBindGroup.get(groupId);
    if (dynamicOffsetCount == 0) {
      pass.setBindGroup(groupIndex, group);
    } else {
      var offsets = [];
      for (var i = 0; i < dynamicOffsetCount; i++, dynamicOffsetsPtr += 8) {
        offsets.push({{{ gpu.makeGetU64('dynamicOffsetsPtr', 0) }}});
      }
      pass.setBindGroup(groupIndex, group, offsets);
    }
  },
  dawnRenderPassEncoderSetIndexBuffer: function(passId, bufferId, offset) {
    var pass = WebGPU.mgrRenderPassEncoder.get(passId);
    var buffer = WebGPU.mgrBuffer.get(bufferId);
    pass.setIndexBuffer(buffer, offset);
  },
  dawnRenderPassEncoderSetPipeline: function(passId, pipelineId) {
    var pass = WebGPU.mgrRenderPassEncoder.get(passId);
    var pipeline = WebGPU.mgrRenderPipeline.get(pipelineId);
    pass.setPipeline(pipeline);
  },
  dawnRenderPassEncoderSetScissorRect: function(passId, x, y, w, h) {
    var pass = WebGPU.mgrRenderPassEncoder.get(passId);
    pass.setScissorRect(x, y, w, h);
  },
  dawnRenderPassEncoderSetVertexBuffers: function(passId, startSlot, count, buffersPtr, offsetsPtr) {
    var pass = WebGPU.mgrRenderPassEncoder.get(passId);

#if ASSERTIONS
    assert(buffersPtr % 4 === 0);
#endif
    var buffers = Array.from(HEAP32.subarray(buffersPtr >> 2, (buffersPtr >> 2) + count),
      function(id) { return WebGPU.mgrBuffer.get(id); });

    var offsets = [];
    for (var i = 0; i < count; i++, offsetsPtr += 8) {
        offsets.push({{{ gpu.makeGetU64('offsetsPtr', 0) }}});
    }

    pass.setVertexBuffers(startSlot, buffers, offsets);
  },
  dawnRenderPassEncoderDraw: function(passId, vertexCount, instanceCount, firstVertex, firstInstance) {
    var pass = WebGPU.mgrRenderPassEncoder.get(passId);
    pass.draw(vertexCount, instanceCount, firstVertex, firstInstance);
  },
  dawnRenderPassEncoderDrawIndexed: function(passId, indexCount, instanceCount, firstIndex, baseVertex, firstInstance) {
    var pass = WebGPU.mgrRenderPassEncoder.get(passId);
    pass.drawIndexed(indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
  },
  dawnRenderPassEncoderEndPass: function(passId) {
    var pass = WebGPU.mgrRenderPassEncoder.get(passId);
    pass.endPass();
  },
};

autoAddDeps(LibraryWebGPU, '$WebGPU');
mergeInto(LibraryManager.library, LibraryWebGPU);
