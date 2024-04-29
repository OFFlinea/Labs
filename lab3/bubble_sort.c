#include "bubble_sort.h"
#include <stdio.h>
#include <assert.h>


void swap(int* first, int* second) {

    assert(first);
    assert(second);

    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubble_sort(int* arr, int n) {

    int i = 0, j = 0, temp = 0;

    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                swap(arr + j, arr + j + 1);
            }
        }
    }
}