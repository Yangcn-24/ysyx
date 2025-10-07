#include "minunit.h"
#include <lcthw/ringbuffer.h>
#include <assert.h>

static RingBuffer *buffer = NULL;
static char *tests[] = {"test1 data", "test2 data", "test3 data"};
#define NUM_TESTS 3

char *test_create()
{
    buffer = RingBuffer_create(200);
    RingBuffer_print(buffer);
    mu_assert(buffer!=NULL,"Failed to create buffer.");
    printf("%d \n",RingBuffer_available_data(buffer));
    mu_assert(RingBuffer_available_data(buffer)==0, "New buffer should be empty.");
    return NULL;
}

char *test_destroy(){
    mu_assert(buffer!=NULL,"Failed to make buffer");
    RingBuffer_destroy(buffer);
    return NULL;
}

char *test_write()
{
    for(int i=0;i<NUM_TESTS;i++){
        int length=strlen(tests[i]);
        int available_before = RingBuffer_available_space(buffer);
        int res=RingBuffer_write(buffer,tests[i],length);
        RingBuffer_print(buffer);
        mu_assert(res==length,"return length is error.");
        mu_assert(RingBuffer_available_space(buffer) == available_before - length, 
                 "Available space should decrease after write.");
    }
    return NULL;
}

char *test_read()
{
    char result[1024];
    for(int i = 0; i < NUM_TESTS; i++){
        int length = strlen(tests[i]); 
        int available_data_before = RingBuffer_available_data(buffer);
        int res = RingBuffer_read(buffer, result, length);
        RingBuffer_print(buffer);
        mu_assert(res == length, "return amount is error.");
        mu_assert(RingBuffer_available_data(buffer) == available_data_before - length,
                 "Available data should decrease after read.");
        result[length] = '\0';
        mu_assert(memcmp(result, tests[i], length) == 0, "read data doesn't match");
    }
    mu_assert(RingBuffer_available_data(buffer) == 0, 
             "Buffer should be empty after reading all data.");
    return NULL;
}

char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_write);
    mu_run_test(test_read);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
