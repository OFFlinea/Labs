#ifndef HEAP_SORT_H
#define HEAP_SORT_H

int get_child(int largest, int k, int pos) {

    return largest * k + pos;
}


void swap(int* first, int* second) {

    assert(first);
    assert(second);

    int temp = *first;
    *first = *second;
    *second = temp;
}


void heapify(int* array, int n, int i, int k) {
    
    assert(array);

    int largest = i;

    for (int j = 1; j <= k; j++) {

        int child =  get_child(i, k, j);

        if (child < n && array[largest] < array[child]) {

            largest = child;
        }
    }

    if (largest != i) {

        swap(array + i, array + largest);
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

        swap(array, array + i);

        heapify(array, i, 0, k);
    }
}

#endif