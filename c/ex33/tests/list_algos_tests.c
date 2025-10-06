#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>
#include <sys/time.h>
//char *values[] = {"abc", "shst", "kplm", "xyz", "test", "data", "file", "word", "list", "sort"};
char *values[] = {
    "apple", "banana", "cherry", "date", "elder", "fig", "grape", "honey", "kiwi", "lemon",
    "mango", "nectar", "olive", "peach", "quince", "rasp", "straw", "tango", "ugli", "vanilla",
    "water", "xray", "yam", "zebra", "alpha", "beta", "gamma", "delta", "epsilon", "zeta",
    "eta", "theta", "iota", "kappa", "lambda", "mu", "nu", "xi", "omicron", "pi",
    "rho", "sigma", "tau", "upsilon", "phi", "chi", "psi", "omega", "hello", "world",
    "computer", "keyboard", "mouse", "screen", "monitor", "printer", "router", "switch", "server", "client",
    "network", "internet", "website", "webpage", "browser", "email", "chat", "video", "audio", "image",
    "photo", "camera", "micro", "speaker", "display", "projector", "laptop", "desktop", "tablet", "phone",
    "mobile", "smart", "digital", "analog", "virtual", "real", "cloud", "storage", "memory", "disk",
    "drive", "file", "folder", "document", "spread", "present", "database", "table", "record", "field","apple", "banana", "cherry", "date", "elder", 
    "fig", "grape", "honey", "kiwi", "lemon",
    "mango", "nectar", "olive", "peach", "quince", 
    "rasp", "straw", "tango", "ugli", "vanilla",
    "water", "xray", "yam", "zebra", "alpha", 
    "beta", "gamma", "delta", "epsilon", "zeta",
    "eta", "theta", "iota", "kappa", "lambda", 
    "mu", "nu", "xi", "omicron", "pi",
    "rho", "sigma", "tau", "upsilon", "phi", 
    "chi", "psi", "omega", "hello", "world"
};
#define NUM_VALUES 150

List *create_words()
{
    int i = 0;
    List *words = List_create();

    for(i = 0; i < NUM_VALUES; i++) {
        List_push(words, values[i]);
    }

    return words;
}

int is_sorted(List *words)
{
    LIST_FOREACH(words, first, next, cur) {
        if(cur->next && strcmp(cur->value, cur->next->value) > 0) {
            debug("%s %s", (char *)cur->value, (char *)cur->next->value);
            return 0;
        }
    }

    return 1;
}
static long seconds1, micros1,seconds2, micros2;
char *test_bubble_sort()
{	
	struct timeval start, end;


    List *words = create_words();
    // should work on a list that needs sorting
    gettimeofday(&start, NULL);
    int rc = List_bubble_sort(words, (List_compare)strcmp);
    gettimeofday(&end, NULL);
    List_print(words);
    seconds1  = end.tv_sec  - start.tv_sec;
	micros1   = ((seconds1  * 1000000) + end.tv_usec) - (start.tv_usec);
    mu_assert(rc == 0, "Bubble sort failed.");
    mu_assert(is_sorted(words), "Words are not sorted after bubble sort.");
    // should work on an already sorted list
    rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "Bubble sort of already sorted failed.");
    mu_assert(is_sorted(words), "Words should be sort if already bubble sorted.");

    List_destroy(words);

    // should work on an empty list
    words = List_create();
    rc = List_bubble_sort(words, (List_compare)strcmp);
    mu_assert(rc == 0, "Bubble sort failed on empty list.");
    mu_assert(is_sorted(words), "Words should be sorted if empty.");

    List_destroy(words);

    return NULL;
}

char *test_merge_sort()
{
	struct timeval start, end;
    List *words = create_words();
    // should work on a list that needs sorting
    gettimeofday(&start, NULL);
    List *res = List_merge_sort(words, (List_compare)strcmp);
    gettimeofday(&end, NULL);
    List_print(res);
    seconds2  = end.tv_sec  - start.tv_sec;
	micros2   = ((seconds2  * 1000000) + end.tv_usec) - (start.tv_usec);
    mu_assert(is_sorted(res), "Words are not sorted after merge sort.");
	
    List *res2 = List_merge_sort(res, (List_compare)strcmp);
    mu_assert(is_sorted(res), "Should still be sorted after merge sort.");
    List_destroy(res2);
    List_destroy(res);

    List_destroy(words);
    return NULL;
}


char *all_tests()
{
    mu_suite_start();
    mu_run_test(test_bubble_sort);
    mu_run_test(test_merge_sort);
    printf("Bubble : Time taken = %ld seconds %ld microseconds\n", seconds1, micros1);
    printf("Merge  : Time taken = %ld seconds %ld microseconds\n", seconds2, micros2);
    return NULL;
}

RUN_TESTS(all_tests);
