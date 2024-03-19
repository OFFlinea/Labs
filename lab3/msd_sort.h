#ifndef MSD_SORT.H
#define MSD_SORT.H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE_SIZE 256  

void msd_sort_rec(int* arr, size_t n, int* output, int shift) {

    if (n <= 1 || shift < 0) {
        
        return;
    } 
    
    int count[BYTE_SIZE + 1] = {0};
    int byteMask = 255;
    
    for (size_t i = 0; i < n; ++i) {

        int byteValue = ((arr[i] >> shift) & byteMask) + 1;
        count[byteValue]++;
    }
    
    for (int i = 1; i < BYTE_SIZE + 1; ++i) {

        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; --i) {

        int byteValue = ((arr[i] >> shift) & byteMask) + 1;
        output[--count[byteValue]] = arr[i];
    }
    
    for (size_t i = 0; i < n; ++i) {

        arr[i] = output[i];
    }
    
    size_t start = 0;

    for (int i = 1; i < BYTE_SIZE + 1; ++i) {

        if (count[i] > start) {
            msd_sort_rec(arr + start, count[i] - start, output, shift - 8);
            start = count[i];
        }
    }
}

void msd_sort(int* arr, size_t n) {

    int* output = (int*) calloc(n, sizeof(int));
    
    if (!output) {
        
        return; 
    } 
    
    msd_sort_rec(arr, n, output, 24);
    
    free(output);
}

#endif