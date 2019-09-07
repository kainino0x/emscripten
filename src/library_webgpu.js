/*
 * Copyright 2019 The Emscripten Authors.  All rights reserved.
 * Emscripten is available under two separate licenses, the MIT license and the
 * University of Illinois/NCSA Open Source License.  Both these licenses can be
 * found in the LICENSE file.
 *
 * WebGPU support. (TODO: Add documentation.)
 */
var LibraryWebGPU = {
  $WebGPU: {
    buffers: {
      nextId: 1,
      objects: []
    },
  },

  dawnDeviceRelease: function() {
    console.warn("dawnDeviceRelease not implemented");
  },

  dawnDeviceCreateBuffer: function(deviceId, descriptor) {
#if ASSERTIONS
    assert(deviceId === 1);
    assert(descriptor !== 0);
    var nextInChain = {{{ makeGetValue('descriptor', C_STRUCTS.DawnBufferDescriptor.nextInChain, '*') }}};
    assert(nextInChain === 0);
#endif
    var desc = {
      usage: {{{ makeGetValue('descriptor', C_STRUCTS.DawnBufferDescriptor.usage, 'i64') }}},
      size: {{{ makeGetValue('descriptor', C_STRUCTS.DawnBufferDescriptor.size, 'i64') }}},
    };

    var buffer = Module['preinitializedWebGPUDevice'].createBuffer(desc);

    var id = WebGPU.buffers.nextId;
    WebGPU.buffers.nextId++;
    WebGPU.buffers.objects[id] = { refcount: 1, object: buffer };
    return id;
  },

  dawnBufferRelease: function(bufferId) {
    var b = WebGPU.buffers.objects[bufferId];
    b.refcount--;
    if (b.refcount === 0) {
      WebGPU.buffers.objects[bufferId] = undefined;
    }
  },

  dawnBufferSetSubData: function(bufferId, start_l, start_h, count_l, count_h, data) {
    var buffer = WebGPU.buffers.objects[bufferId].object;
#if ASSERTIONS
    assert(buffer);
    assert(start_h < 0x200000);
    assert(count_h < 0x200000);
#endif
    var start = start_h * 0x100000000 + start_l;
    var count = count_h * 0x100000000 + count_l;
    buffer.setSubData(start, HEAPU8, data, count);
  },

  dawnBufferMapReadAsync: function(bufferId, callback, userdata) {
    var buffer = WebGPU.buffers.objects[bufferId].object;
#if ASSERTIONS
    assert(buffer);
    assert(callback);
#endif
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
};

autoAddDeps(LibraryWebGPU, '$WebGPU');

mergeInto(LibraryManager.library, LibraryWebGPU);
