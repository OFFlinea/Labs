#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void swap(int* a, int* b);

int partitionLomuto(int* array, int low, int high);

void lomuto_quick_sort(int* array, int low, int high);

void Lomuto_quick_sort(int* array, int n);

int median_of_three_random(int* array, int low, int high);

int partitionHoare(int* array, int low, int high);

void hoare_qsort(int* array, int left, int right);

void Hoare_quick_sort(int* array, int n);

void partitionThick(int* array, int low, int high, int* left_pointer, int* right_pointer);

void thick_quick_sort(int* array, int low, int high);

void Thick_quick_sort(int* array, int n);

int partition_center(int* array, int low, int high);

void Center_element_quick_sort(int* array, int low, int high);

void center_element_quick_sort(int* array, int n);

int median_of_three(int* array, int low, int high);

int partition_median_of_three(int* array, int low, int high);

void quicksort_median_of_three_sort(int* array, int low, int high);

void median_of_three_quick_sort(int* array, int n);

#endif