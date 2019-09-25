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
  };
  return '';
})(); }}}

var LibraryWebGPU = {
  $WebGPU: {
    initManagers: function() {
      function makeManager() {
        return {
          objects: [null],
          create: function(object) {
            var id = this.objects.length;
#if ASSERTIONS
            assert(typeof this.objects[id] === 'undefined');
#endif
            this.objects[id] = { refcount: 1, object };
            return id;
          },
          get: function(id) {
#if ASSERTIONS
            assert(typeof this.objects[id] !== 'undefined');
#endif
            return this.objects[id].object;
          },
          reference: function(id) {
            var o = this.objects[id];
#if ASSERTIONS
            assert(typeof o !== 'undefined');
#endif
            this.objects[id].refcount++;
          },
          release: function(id) {
            var o = this.objects[id];
#if ASSERTIONS
            assert(typeof o !== 'undefined');
            assert(o.refcount > 0);
#endif
            o.refcount--;
            if (o.refcount <= 0) {
              delete this.objects[id];
            }
          },
        };
      }

      {{{ gpu.makeInitManager('Device') }}}
      {{{ gpu.makeInitManager('Queue') }}}
      {{{ gpu.makeInitManager('Buffer') }}}
      {{{ gpu.makeInitManager('Texture') }}}
      {{{ gpu.makeInitManager('CommandBuffer') }}}
      {{{ gpu.makeInitManager('CommandEncoder') }}}
    },
  },

  // *Reference/*Release

  {{{ gpu.makeReferenceRelease('Device') }}}
  {{{ gpu.makeReferenceRelease('Queue') }}}
  {{{ gpu.makeReferenceRelease('Buffer') }}}
  {{{ gpu.makeReferenceRelease('Texture') }}}
  {{{ gpu.makeReferenceRelease('CommandBuffer') }}}
  {{{ gpu.makeReferenceRelease('CommandEncoder') }}}

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
#if ASSERTIONS
    if (descriptor) {
      var nextInChain = {{{ makeGetValue('descriptor', C_STRUCTS.DawnCommandEncoderDescriptor.nextInChain, '*') }}};
      assert(nextInChain === nullptr);
    }
#endif
    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrCommandEncoder.create(device.createCommandEncoder());
  },

  dawnDeviceCreateBuffer: function(deviceId, descriptor) {
#if ASSERTIONS
    assert(descriptor !== 0);
    var nextInChain = {{{ makeGetValue('descriptor', C_STRUCTS.DawnBufferDescriptor.nextInChain, '*') }}};
    assert(nextInChain === 0);
#endif
    var desc = {
      usage: {{{ makeGetValue('descriptor', C_STRUCTS.DawnBufferDescriptor.usage, 'i64') }}},
      size: {{{ makeGetValue('descriptor', C_STRUCTS.DawnBufferDescriptor.size, 'i64') }}},
    };

    var device = WebGPU.mgrDevice.get(deviceId);
    return WebGPU.mgrBuffer.create(device.createBuffer(desc));
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

  dawnCommandEncoderCopyBufferToBuffer: function(commandEncoderId, srcId, srcOffset_l, srcOffset_h, dstId, dstOffset_l, dstOffset_h, size_l, size_h) {
    var commandEncoder = WebGPU.mgrCommandEncoder.get(commandEncoderId);
    var src = WebGPU.mgrBuffer.get(srcId);
    var dst = WebGPU.mgrBuffer.get(dstId);
    commandEncoder.copyBufferToBuffer(
      src, {{{ makeU64ToNumber('srcOffset_l', 'srcOffset_h') }}},
      dst, {{{ makeU64ToNumber('dstOffset_l', 'dstOffset_h') }}},
      {{{ makeU64ToNumber('size_l', 'size_h') }}});
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
};

autoAddDeps(LibraryWebGPU, '$WebGPU');
mergeInto(LibraryManager.library, LibraryWebGPU);
