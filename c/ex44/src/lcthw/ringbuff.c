#undef NDEBUG
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lcthw/dbg.h>
#include <lcthw/ringbuffer.h>

RingBuffer *RingBuffer_create(int length)
{
    RingBuffer *buffer = calloc(1, sizeof(RingBuffer));
    check_mem(buffer);
    buffer->length  = length + 1;
    buffer->start = 0;
    buffer->end = 0;
    buffer->buffer = calloc(buffer->length, 1);
    check_mem(buffer->buffer);
    return buffer;
error:
    if (buffer) free(buffer);
    return NULL;
}

void RingBuffer_destroy(RingBuffer *buffer)
{
    if(buffer) {
        free(buffer->buffer);
        free(buffer);
    }
}

int RingBuffer_write(RingBuffer *buffer, char *data, int length)
{
    if(RingBuffer_available_data(buffer) == 0) {
        buffer->start = buffer->end = 0;
    }

    check(length <= RingBuffer_available_space(buffer),
            "Not enough space: %d request, %d available",
             length,RingBuffer_available_space(buffer));
    int space_to_end=buffer->length-buffer->end;
    if(space_to_end<length) {
        void *result1 = memcpy(RingBuffer_ends_at(buffer), data, space_to_end);
        check(result1 != NULL, "Failed to write data into buffer_end.");
        void *result2 = memcpy(buffer->buffer, data+space_to_end, length-space_to_end);
        check(result2 != NULL, "Failed to write data into buffer_start.");
    }
    else{
        void *result = memcpy(RingBuffer_ends_at(buffer), data, length);
        check(result != NULL, "Failed to write data into buffer.");
    }

    RingBuffer_commit_write(buffer, length);

    return length;
error:
    return -1;
}

int RingBuffer_read(RingBuffer *buffer, char *target, int amount)
{
    check_debug(amount <= RingBuffer_available_data(buffer),
            "Not enough in the buffer: has %d, needs %d",
            RingBuffer_available_data(buffer), amount);
    int available_to_end=buffer->length-buffer->start;
    if(amount>available_to_end){
        void *result1 = memcpy(target, RingBuffer_starts_at(buffer), available_to_end);
        check(result1 != NULL, "Failed to write buffer_end into data.");
        void *result2 = memcpy(target+available_to_end, buffer->buffer, amount-available_to_end);
        check(result2 != NULL, "Failed to write buffer_start into data.");
    }
    else{
        void *result = memcpy(target, RingBuffer_starts_at(buffer), amount);
        check(result != NULL, "Failed to write buffer into data.");
    }

    RingBuffer_commit_read(buffer, amount);

    if(buffer->end == buffer->start) {
        buffer->start = buffer->end = 0;
    }

    return amount;
error:
    return -1;
}

bstring RingBuffer_gets(RingBuffer *buffer, int amount)
{
    check(amount > 0, "Need more than 0 for gets, you gave: %d ", amount);
    check_debug(amount <= RingBuffer_available_data(buffer),
            "Not enough in the buffer.");
    char *temp_buf=malloc(amount);
    check(temp_buf!=NULL,"failed to allocate temporary buffer.");
    int rc=RingBuffer_read(buffer,temp_buf,amount);
    check(rc==amount,"Failed to read from buffer.");

    bstring result = blk2bstr(temp_buf, amount);
    check(result != NULL, "Failed to create gets result.");
    check(blength(result) == amount, "Wrong result length.");
    
    RingBuffer_commit_read(buffer, amount);
    assert(RingBuffer_available_data(buffer) >= 0 && "Error in read commit.");
    
    free(temp_buf);
    return result;
error:
    return NULL;
}

void RingBuffer_print(RingBuffer *buffer)
{
    int i;
    int totlen=RingBuffer_available_data(buffer);
    int available_to_end=buffer->length-buffer->start;
    if(totlen==0){
        printf("NULL\n");
    }
    else if(buffer->end>=buffer->start){
        for(i=0;i<totlen;i++)
            printf("%c",*(buffer->buffer+buffer->start+i));
        printf("\n");
    }
    else {
        for(i=0;i<available_to_end;i++)
            printf("%c",*(buffer->buffer+buffer->start+i));
        for(i=0;i<buffer->end;i++)
            printf("%c",*(buffer->buffer+i));
        printf("\n");
    }
}