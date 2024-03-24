#ifndef LSD_SORT_H
#define LSD_SORT_H

#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 256  


void LSD_sort(int* array, int* result, const int n) {

    assert(array);
    assert(result);

    for (int mask = 0xff, shift = 0; mask > 0; mask <<= 8, shift += 8) {

        size_t pref_cnt[BYTE_SIZE];
        memset(pref_cnt, 0, sizeof(pref_cnt));

        for (int i = 0; i < n; ++i) {

            ++pref_cnt[(array[i] & mask) >> shift];
        }

        for (int i = 1; i < BYTE_SIZE; ++i) {

            pref_cnt[i] += pref_cnt[i - 1];
        }

        for (int i = n - 1; i >= 0; --i) {

            result[--pref_cnt[(array[i] & mask) >> shift]] = array[i];
        }

        memcpy(array, result, sizeof(int) * n);
    }
}

void lsd_sort(int* array, int n) {

    assert(array);

    int* result = (int*) calloc(n, sizeof(int));

    if (!result) {

        printf("No memory\n");
        return;
    }

    LSD_sort(array, result, n);

    free(result);
}

#endif