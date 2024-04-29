#include "insertion_sort.h"
#include <stdio.h>
#include <assert.h>


void insertion_sort(int* arr, int n) {

    int i = 0, key = 0, j = 0;

    for (i = 1; i < n; i++) {

        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}


int rec_binarySearch(int* a, int item, int low, int high) {

    if (high <= low) {

        return (item > a[low]) ? (low + 1) : low;
    }
 
    int mid = (low + high) / 2;
 
    if (item == a[mid]) {

        return mid + 1;
    }
 
    if (item > a[mid]) {

        return rec_binarySearch(a, item, mid + 1, high);
    }

    return rec_binarySearch(a, item, low, mid - 1);
}
 

void bin1_insertion_sort(int* a, int n) {
 
    for (int i = 1; i < n; ++i) {

        int j = i - 1;
        int selected = a[i];
 
        int loc = rec_binarySearch(a, selected, 0, j);
 
        while (j >= loc) {

            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = selected;
    }
}


int it_binarySearch(int* a, int item, int low, int high) {
    
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (item == a[mid]) {

            return mid + 1;
        }

        if (item > a[mid]) {

            low = mid + 1;
        }

        else {

            high = mid - 1;
        }
    }

    return low;
}

void bin2_insertion_sort(int* a, int n) {
 
    for (int i = 1; i < n; ++i) {
        
        int j = i - 1;
        int selected = a[i];
 
        int loc = it_binarySearch(a, selected, 0, j);
 
        while (j >= loc) {

            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = selected;
    }
}
