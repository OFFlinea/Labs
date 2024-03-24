#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void heapify(int* array, int n, int i, int k) {
    
    assert(array);

    int largest = i;

    for (int j = 1; j <= k; j++) {

        int child = i * k + j;

        if (child < n && array[largest] < array[child]) {

            largest = child;
        }
    }

    if (largest != i) {

        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heapify(array, n, largest, k);
    }
}

void buildHeap(int* array, int n, int k) {

    for (int i = (n - 1) / k; 0 <= i; i--) {

        heapify(array, n, i, k);
    }
}

void heap_sort(int* array, int n, int k) {

    buildHeap(array, n, k);

    for (int i = n - 1; i > 0; i--) {

        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0, k);
    }
}

#endif