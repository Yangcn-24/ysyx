#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);
typedef int*(*function_name)(int *numbers, int count, compare_cb cmp);
/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));
    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}
// 分区函数
int partition(int *array, int low, int high, compare_cb cmp)
{
    int pivot = array[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (cmp(array[j], pivot) <= 0) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    
    return (i + 1);
}
// 快速排序递归函数
void quicksort(int *array, int low, int high, compare_cb cmp)
{
    if (low < high) {
        int pi = partition(array, low, high, cmp);
        quicksort(array, low, pi - 1, cmp);
        quicksort(array, pi + 1, high, cmp);
    }
}
int *quick_sort(int *numbers, int count, compare_cb cmp)
{
    int *target = malloc(count * sizeof(int));
    if(!target) die("Memory error.");
    
    memcpy(target, numbers, count * sizeof(int));
    
    // 实际的快速排序实现
    quicksort(target, 0, count - 1, cmp);
    
    return target;
}



/*int plus1(int a)
{
	return a+1;
}*/
/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp,function_name sort, const char *name)
{
    int i = 0;
    printf("Testing %s: ", name);
    int *sorted = sort(numbers, count, cmp);

    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
    unsigned char *data = (unsigned char *)cmp;

	for(i = 0; i < 25; i++) {
    	printf("%02x:", data[i]);
	}

	printf("\n");
}


int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    // 测试冒泡排序
    test_sorting(numbers, count, sorted_order, bubble_sort, "Bubble Sort Ascending");
    test_sorting(numbers, count, reverse_order, bubble_sort, "Bubble Sort Descending");
    
    // 测试快速排序
    test_sorting(numbers, count, sorted_order, quick_sort, "Quick Sort Ascending");
    test_sorting(numbers, count, reverse_order, quick_sort, "Quick Sort Descending");
	//test_sorting(numbers, count, NULL);
    free(numbers);

    return 0;
}
