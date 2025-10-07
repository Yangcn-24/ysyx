// 创建调试程序检查创建过程
#include <stdio.h>
#include <stdlib.h>
#include "lcthw/ringbuffer.h"

int main() {
    RingBuffer *buffer = RingBuffer_create(200);
    
    printf("=== Debug RingBuffer_create ===\n");
    printf("Buffer pointer: %p\n", buffer);
    printf("Buffer->length: %d\n", buffer->length);
    printf("Buffer->start: %d\n", buffer->start);
    printf("Buffer->end: %d\n", buffer->end);
    printf("Buffer->buffer: %p\n", buffer->buffer);
    
    // 手动计算
    int manual_space = buffer->length - RingBuffer_available_data(buffer) - 1;
    printf("Manual available_space calculation: %d\n", manual_space);
    printf("Macro available_space: %d\n", RingBuffer_available_space(buffer));
    
    RingBuffer_destroy(buffer);
    return 0;
}