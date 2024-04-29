#include "quick_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void swap(int* a, int* b) {

    assert(a);
    assert(b);

    int t = *a;
    *a = *b;
    *b = t;
}


int partitionLomuto(int* array, int low, int high) {

    assert(array);

    int pivot = array[high];  
    int i = low - 1;  

    for (int j = low; j <= high - 1; j++) {

        if (array[j] < pivot) {
  
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return i + 1;
}


void lomuto_quick_sort(int* array, int low, int high) {

    assert(array);

    if (low < high) {

        int mid = partitionLomuto(array, low, high);

        lomuto_quick_sort(array, low, mid - 1);
        lomuto_quick_sort(array, mid + 1, high);
    }
}


void Lomuto_quick_sort(int* array, int n) {

    assert(array);

    lomuto_quick_sort(array, 0, n - 1);
}


int median_of_three_random(int* array, int low, int high) {

    assert(array);

    int random1 = low + rand() % (high - low + 1);
    int random2 = low + rand() % (high - low + 1);
    int random3 = low + rand() % (high - low + 1);

    if (array[random1] <= array[random2] && array[random2] <= array[random3] || 
        array[random3] <= array[random2] && array[random2] <= array[random1]) {

        return array[random2];
    }

    else if (array[random2] <= array[random1] && array[random1] <= array[random3] ||
             array[random3] <= array[random1] && array[random1] <= array[random2]) {

        return array[random1];
    }

    return array[random3];
}


int partitionHoare(int* array, int low, int high) {

    assert(array);

    int pivot = median_of_three_random(array, low, high);

    int left = low - 1;
    int right = high + 1;

    while (left < right) {

        do {
            left++;
        } while (array[left] < pivot);

        do {
            right--;
        } while (array[right] > pivot);

        if (left < right) {
            
            swap(&array[left], &array[right]);
        }
    }

    return right;
}


void hoare_qsort(int* array, int left, int right) {

    assert(array);

    if (left < right) {

        int mid = partitionHoare(array, left, right);

        hoare_qsort(array, left, mid);
        hoare_qsort(array, mid + 1, right);
    }
}


void Hoare_quick_sort(int* array, int n) {

    assert(array);

    hoare_qsort(array, 0, n - 1);
}


void partitionThick(int* array, int low, int high, int* left_pointer, int* right_pointer) {

    assert(array);

    if (high - low <= 1) {

        if (array[high] < array[low]) {
            
            swap(&array[high], &array[low]);
        }

        *left_pointer = low;
        *right_pointer = high;

        return;
    }

    int mid = low;
    int pivot = array[high];

    while (mid <= high) {

        if (array[mid] < pivot) {

            swap(&array[low++], &array[mid++]);
        }

        else if (array[mid] == pivot) {

            mid++;
        }

        else if (array[mid] > pivot) {

            swap(&array[mid], &array[high--]);
        }
    }

    *left_pointer = low - 1;
    *right_pointer = mid;
}


void thick_quick_sort(int* array, int low, int high) {

    assert(array);

    if (low < high) {

        int left_pointer = 0, right_pointer = 0;
        partitionThick(array, low, high, &left_pointer, &right_pointer);

        thick_quick_sort(array, low, left_pointer);
        thick_quick_sort(array, right_pointer, high);
    }
}


void Thick_quick_sort(int* array, int n) {

    assert(array);

    thick_quick_sort(array, 0, n - 1);
}


int partition_center(int* array, int low, int high) {

    assert(array);

    int pivot = array[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {

        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(&array[i], &array[j]);
    }
}

void Center_element_quick_sort(int* array, int low, int high) {

    assert(array);

    if (low < high) {

        int mid = partition_center(array, low, high);
        Center_element_quick_sort(array, low, mid);
        Center_element_quick_sort(array, mid + 1, high);
    }
}

void center_element_quick_sort(int* array, int n) {

    assert(array);

    Center_element_quick_sort(array, 0, n - 1);
}


int median_of_three(int* array, int low, int high) {

    assert(array);

    int mid = low + (high - low) / 2;

    if (array[low] > array[mid]) {

        swap(&array[low], &array[mid]);
    }

    if (array[low] > array[high]) {

        swap(&array[low], &array[high]);
    }

    if (array[mid] > array[high]) {

        swap(&array[mid], &array[high]);
    }

    swap(&array[mid], &array[high - 1]);
    return array[high - 1];
}


int partition_median_of_three(int* array, int low, int high) {

    assert(array);

    int pivot = median_of_three(array, low, high);
    int i = low;
    int j = high - 1;

    while (true) {

        while (array[++i] < pivot);
        while (array[--j] > pivot);

        if (i < j) {

            swap(&array[i], &array[j]);
        }

        else {

            break;
        }
    }

    swap(&array[i], &array[high - 1]);
    return i;
}


void quicksort_median_of_three_sort(int* array, int low, int high) {

    assert(array);

    if (low + 2 <= high) {

        int mid = partition_median_of_three(array, low, high);
        quicksort_median_of_three_sort(array, low, mid - 1);
        quicksort_median_of_three_sort(array, mid + 1, high);
    } 
    
    else if (low < high && array[low] > array[high]) {

        swap(&array[low], &array[high]);
    }
}


void median_of_three_quick_sort(int* array, int n) {
    
    quicksort_median_of_three_sort(array, 0, n - 1);
}