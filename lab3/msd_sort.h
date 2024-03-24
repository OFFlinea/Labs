#ifndef MSD_SORT_H
#define MSD_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE_SIZE 256  

void msd_sort_rec(int* array, size_t n, int* result, int shift) {

    if (n <= 1 || shift < 0) {
        
        return;
    } 
    
    int count[BYTE_SIZE + 1] = {};
    int mask = 0xff;
    
    for (size_t i = 0; i < n; ++i) {

        int byteValue = ((array[i] >> shift) & mask) + 1;
        count[byteValue]++;
    }
    
    for (int i = 1; i < BYTE_SIZE + 1; ++i) {

        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; --i) {

        int byteValue = ((array[i] >> shift) & mask) + 1;
        result[--count[byteValue]] = array[i];
    }
    
    for (size_t i = 0; i < n; ++i) {

        array[i] = result[i];
    }
    
    size_t start = 0;

    for (int i = 1; i < BYTE_SIZE + 1; ++i) {

        if (count[i] > start) {
            
            msd_sort_rec(array + start, count[i] - start, result, shift - 8);
            start = count[i];
        }
    }
}

void msd_sort(int* array, int n) {

    int* result = (int*) calloc(n, sizeof(int));
    
    if (!result) {
        
        return; 
    } 
    
    msd_sort_rec(array, n, result, 8);
    
    free(result);
}

#endif