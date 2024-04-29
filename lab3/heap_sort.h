#ifndef HEAP_SORT_H
#define HEAP_SORT_H

int get_child(int largest, int k, int pos);

void swap(int* first, int* second);

void heapify(int* array, int n, int i, int k);

void buildHeap(int* array, int n, int k);

void heap_sort(int* array, int n, int k);

#endif