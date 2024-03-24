#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

void bubble_sort(int* arr, int n) {

    int i = 0, j = 0, temp = 0;

    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

#endif