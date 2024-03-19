#ifndef INTRO_SORT.H
#define INTRO_SORT.H

#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b) {

    int t = *a;
    *a = *b;
    *b = t;
}


int median_of_three(int* arr, int low, int high) {

    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) {

        swap(&arr[low], &arr[mid]);
    }

    if (arr[low] > arr[high]) {

        swap(&arr[low], &arr[high]);
    }

    if (arr[mid] > arr[high]) {

        swap(&arr[mid], &arr[high]);
    }

    swap(&arr[mid], &arr[high - 1]);
    return arr[high - 1];
}


int partition_median_of_three(int* arr, int low, int high) {

    int pivot = median_of_three(arr, low, high);
    int i = low;
    int j = high - 1;

    while (true) {

        while (arr[++i] < pivot);
        while (arr[--j] > pivot);

        if (i < j) {

            swap(&arr[i], &arr[j]);
        }

        else {

            break;
        }
    }

    swap(&arr[i], &arr[high - 1]);
    return i;
}


void insertion_sort(int* arr, unsigned int n) {

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

void heapify(int* arr, int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {

        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {

        largest = right;
    }

    if (largest != i) {

        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int* arr, int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {

        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {

        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void introsort_util(int* arr, int* begin, int* end, int depthLimit) {

    int size = end - begin;

    if (size < 16) {

        insertion_sort(begin, size);
    } 
    
    else if (depthLimit == 0) {

        heapsort(begin, size);
    } 
    
    else {

        int* pivot = partition_median_of_three(begin, end - 1);
        introsort_util(arr, begin, pivot, depthLimit - 1);
        introsort_util(arr, pivot + 1, end, depthLimit - 1);
    }
}

void introsort(int* arr, unsigned int n) {

    int depthLimit = 2 * log(n);
    introsort_util(arr, arr, arr + n, depthLimit);
}


void introspective_sort(int* arr, unsigned int n) {
    introsort(arr, n);
}

#endif