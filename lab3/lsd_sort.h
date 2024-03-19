#ifndef LSD_SORT.H
#define LSD_SORT.H

#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 256  


void lsd_sort(int* arr, size_t n) {

    int* output = (int*) calloc(n, sizeof(int));

    if (!output) {

        printf("No memory\n");
        return;
    }
    
    int count[BYTE_SIZE];
    int byteMask = 255;

    for (int shift = 0; shift <= 24; shift += 8) {

        for (int i = 0; i < BYTE_SIZE; ++i) {
            
            count[i] = 0;
        }
        
        for (size_t i = 0; i < n; ++i) {

            int byteValue = (arr[i] >> shift) & byteMask;
            count[byteValue]++;
        }
        
        for (int i = 1; i < BYTE_SIZE; ++i) {

            count[i] += count[i - 1];
        }
        
        for (int i = n - 1; i >= 0; --i) {

            int byteValue = (arr[i] >> shift) & byteMask;
            output[--count[byteValue]] = arr[i];
        }
        
        for (size_t i = 0; i < n; ++i) {
            arr[i] = output[i];
        }
    }
    
    free(output);
}

#endif