#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

void selection_sort(int* arr, int n) {

    int i = 0, j = 0, min_idx = 0, temp = 0;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;

        for (j = i + 1; j < n; j++) {

            if (arr[j] < arr[min_idx]) {

                min_idx = j;
            }
        }

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

#endif