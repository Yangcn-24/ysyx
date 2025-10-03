#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";
char *test4 = "test4 data";
char *test5 = "test5 data";
char *test6 = "test6 data";

char *test_create()
{
    list = List_create();
    mu_assert(list != NULL, "Failed to create list.");

    return NULL;
}


char *test_destroy()
{
    List_clear_destroy(list);

    return NULL;

}


char *test_push_pop()
{
    List_push(list, test1);
    mu_assert(List_last(list) == test1, "Wrong last value.");
	List_print(list);
	
    List_push(list, test2);
    mu_assert(List_last(list) == test2, "Wrong last value");
	List_print(list);
	
    List_push(list, test3);
    mu_assert(List_last(list) == test3, "Wrong last value.");
    List_print(list);
    mu_assert(List_count(list) == 3, "Wrong count on push.");

    char *val = List_pop(list);
    mu_assert(val == test3, "Wrong value on pop.");
	List_print(list);
	
    val = List_pop(list);
    mu_assert(val == test2, "Wrong value on pop.");
	List_print(list);
	
    val = List_pop(list);
    mu_assert(val == test1, "Wrong value on pop.");
    List_print(list);
    mu_assert(List_count(list) == 0, "Wrong count after pop.");

    return NULL;
}

char *test_unshift()
{
    List_unshift(list, test1);
    mu_assert(List_first(list) == test1, "Wrong first value.");
	List_print(list);
	
    List_unshift(list, test2);
    mu_assert(List_first(list) == test2, "Wrong first value");
	List_print(list);
	
    List_unshift(list, test3);
    mu_assert(List_first(list) == test3, "Wrong last value.");
    List_print(list);
    mu_assert(List_count(list) == 3, "Wrong count on unshift.");

    return NULL;
}

char *test_remove()
{
    // we only need to test the middle remove case since push/shift
    // already tests the other cases

    char *val = List_remove(list, list->first->next);
    mu_assert(val == test2, "Wrong removed element.");
    List_print(list);
    mu_assert(List_count(list) == 2, "Wrong count after remove.");
    mu_assert(List_first(list) == test3, "Wrong first after remove.");
    mu_assert(List_last(list) == test1, "Wrong last after remove.");

    return NULL;
}


char *test_shift()
{
    mu_assert(List_count(list) != 0, "Wrong count before shift.");

    char *val = List_shift(list);
    mu_assert(val == test3, "Wrong value on shift.");
	List_print(list);
	
    val = List_shift(list);
    mu_assert(val == test1, "Wrong value on shift.");
    List_print(list);
    mu_assert(List_count(list) == 0, "Wrong count after shift.");

    return NULL;
}

char *test_link_break()
{
	List *list1 = List_create();
	mu_assert(list1 != NULL, "Failed to create list1.");
	List_push(list1, test1);
	List_push(list1, test2);
	List_push(list1, test3);
	mu_assert(List_count(list1) == 3, "Wrong count after push test3.");
	
	List *list2 = List_create();
	mu_assert(list2 != NULL, "Failed to create list2.");
	List_push(list2, test4);
	List_push(list2, test5);
	List_push(list2, test6);
	mu_assert(List_count(list2) == 3, "Wrong count after push test6.");
	
	List *list3 = List_link(list1,list2);
	mu_assert(list3 != NULL, "Failed to create list3.");
	mu_assert(List_count(list3) == 6, "Wrong count after push linking.");
	List_print(list3);
	
	List *list4 = List_break(list3,4);
	mu_assert(list4 != NULL, "Failed to create list1.");
	List_print(list3);
	List_print(list4);
	List_destroy(list3);
	List_destroy(list4);
	return NULL;
}
char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_push_pop);
    mu_run_test(test_unshift);
    mu_run_test(test_link_break);
    mu_run_test(test_remove);
    mu_run_test(test_shift);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
