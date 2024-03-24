#ifndef INSERTION_SORT.H
#define INSERTION_SORT.H


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

#endif