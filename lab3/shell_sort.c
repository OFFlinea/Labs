#include "shell_sort.h"
#include <stdio.h>
#include <assert.h>

void shell_sort(int* array, int n) {

    assert(array);
    
    int gap = 1;

    while (gap < n / 3) {

        gap = gap * 3 + 1;
    }


    while (gap > 0) {

        for (int i = gap; i < n; i++) {

            int temp = array[i];
            int j = 0;

            for (j = i; gap <= j && temp < array[j - gap]; j -= gap) {

                array[j] = array[j - gap];
            }

            array[j] = temp;
        }

        gap = (gap - 1) / 3;
    }
}