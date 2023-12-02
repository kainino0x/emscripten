/**
 * @license
 * Copyright 2023 The Emscripten Authors
 * SPDX-License-Identifier: MIT
 */

/*
 * WebGPU support.
 * FIXME: WRITE SOME DOCUMENTATION
 */

{{{
  // Constants. Must be in sync with webgpu.h.
  global.WGPU = {
    RequestAdapterStatus: {
      Success: 0,
      Unavailable: 1,
      Error: 2,
    },
  };
  null;
}}}

var LibraryEmWebGPU = {
  $EmWebGPU: {
    PowerPreference: [undefined, 'low-power', 'high-performance'],
    // FIXME: Note I tried to use emval here but this seems not to be done
    // anywhere else. It wouldn't link with $Emval and there are no other
    // examples of doing so. (WebGL and library_webgpu.js have their own
    // tables.) Also note there is library_html5_webgpu.js's JsValStore which is
    // redundant and should probably be replaced with this. Or maybe we can
    // use Emval.
    _tableNextID: 1,
    _table: [],
    tableInsert: value => {
      const id = EmWebGPU._tableNextID++;
      EmWebGPU._table[id] = value;
      return id;
    },
  },

  emwgpuSetLabel: (id, label) => {
    EmWebGPU.table[id]['label'] = UTF8ToString(label);
  },
  emwgpuDestroy: (id) => {
    EmWebGPU.table[id]['destroy']();
  },
  emwgpuDelete: (id) => {
    delete EmWebGPU.table[id];
  },

  emwgpuRequestAdapter__deps: ['emwgpuOnRequestAdapter'],
  emwgpuRequestAdapter: (request, powerPreference, forceFallbackAdapter) => {
    if (!('gpu' in navigator)) {
      _emwgpuOnRequestAdapter(request, 0, {{{ WGPU.RequestAdapterStatus.Unavailable }}});
      return;
    }

    {{{ runtimeKeepalivePush() }}}
    navigator['gpu']['requestAdapter']({
      powerPreference: EmWebGPU.PowerPreference[powerPreference],
      forceFallbackAdapter,
    }).then(adapter => {
        {{{ runtimeKeepalivePop() }}}
        if (adapter) {
          _emwgpuOnRequestAdapter(request, EmWebGPU.tableInsert(adapter), {{{ WGPU.RequestAdapterStatus.Success }}});
        } else {
          _emwgpuOnRequestAdapter(request, 0, {{{ WGPU.RequestAdapterStatus.Unavailable }}});
        }
      }, exception => {
        {{{ runtimeKeepalivePop() }}}
        _emwgpuOnRequestAdapter(request, 0, {{{ WGPU.RequestAdapterStatus.Error }}});
      });
  },
};

autoAddDeps(LibraryEmWebGPU, '$EmWebGPU');
addToLibrary(LibraryEmWebGPU);
