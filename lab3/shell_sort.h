#ifndef SHELL_SORT_H
#define SHELL_SORT_H

void shell_sort(int* arr, int n) {
    
    int gap = 1;

    while (gap < n / 3) {

        gap = gap * 3 + 1;
    }


    while (gap > 0) {

        for (int i = gap; i < n; i++) {

            int temp = arr[i];
            int j = 0;

            for (j = i; gap <= j && temp < arr[j - gap]; j -= gap) {

                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }

        gap = (gap - 1) / 3;
    }
}

#endif