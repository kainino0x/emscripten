#include <webgpu/webgpu.h>
#include <cstdio>

void OnRequestAdapter(WGPURequestAdapterStatus status, WGPUAdapter adapter, const char* message, void*) {
    printf("Got! status=%d adapter=%p message=%s\n", status, adapter, message);
}

int main() {
    WGPUInstance instance = wgpuCreateInstance(nullptr);
    wgpuInstanceRequestAdapter(instance, nullptr, OnRequestAdapter, nullptr);
}
