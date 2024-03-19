#ifndef MERGE_SORT.H
#define MERGE_SORT.H

void merge(int* arr, int l, int m, int r) {

    int i = 0, j = 0, k = 0;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1] = {}, R[n2] = {};

    for (i = 0; i < n1; i++) {

        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {

        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {

            arr[k] = L[i];
            i++;
        } 
        
        else {

            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {

        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {

        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_recursive_sort(int* arr, int l, int r) {

    if (l < r) {

        int m = l + (r - l) / 2;

        merge_recursive_sort(arr, l, m);
        merge_recursive_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void recursive_merge_sort(int* arr, unsigned int n) {

    merge_recursive_sort(arr, 0, n);
}


void iterative_merge_sort(int* arr, unsigned int n) {

    int curr_size = 0;
    int left_start = 0;
    
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {

        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {

            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}


int min(int x, int y) {
    
    return (x < y) ? x : y;
}

#endif