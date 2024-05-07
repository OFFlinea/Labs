#include "selection_sort.h"
#include <stdio.h>
#include <assert.h>


void swap(int* first, int* second) {

    assert(first);
    assert(second);

    int temp = *first;
    *first = *second;
    *second = temp;
}


void selection_sort(int* array, int n) {

    assert(array);

    int i = 0, j = 0, min_idx = 0, temp = 0;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;

        for (j = i + 1; j < n; j++) {

            if (array[j] < array[min_idx]) {

                min_idx = j;
            }
        }

        swap(array + i, array + min_idx);
    }
}