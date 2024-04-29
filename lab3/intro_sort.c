#include "intro_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include "heap_sort.h"
#include <assert.h>
#include <math.h>


void introspective_util(int* array, int low, int high, int depth_limit) {

    assert(array);

    int size = high - low + 1;

    if (size <= 16) {

        shell_sort(array + low, size);
    }
    
    else if (depth_limit == 0)

        heap_sort(array + low, size, 5);

    else {

        if (low + 2 <= high) {

            int mid = partition_median_of_three(array, low, high);
            introspective_util(array, low, mid - 1, depth_limit - 1);
            introspective_util(array, mid + 1, high, depth_limit - 1);
        } 
        
        else if (low < high && array[low] > array[high]) {

            swap(&array[low], &array[high]);
        }
    }
}


void intro_sort(int* array, int n) {

    assert(array);

    int depth_limit = 7 * log(n);

    introspective_util(array, 0, n - 1, depth_limit);
}