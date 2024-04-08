#ifndef MERGE_SORT_H
#define MERGE_SORT_H

enum status
{
    ERROR,
    OK
};

enum status merge(int* array, const size_t left, const size_t mid, const size_t right) {

    assert(array);

    size_t left_i = 0;
    size_t right_i = 0;

    int* sorted_array = (int*) calloc(right - left, sizeof(int));

    if (!sorted_array) {

        return ERROR;
    }

    while (left + left_i < mid && mid + right_i < right) {

        if (array[left + left_i] < array[mid + right_i]) {

            sorted_array[left_i++ + right_i] = array[left + left_i];
        }

        else {

            sorted_array[left_i + right_i++] = array[mid + right_i];
        }
    }

    while (left + left_i < mid) {

        sorted_array[left_i++ + right_i] = array[left + left_i];
    }

    while (mid + right_i < right) {

        sorted_array[left_i + right_i++] = array[mid + right_i];
    }

    for (int curr_size = 0; curr_size < left_i + right_i; curr_size++) {

        array[left + curr_size] = sorted_array[curr_size];
    }

    free(sorted_array);

    return OK;
}


void r_merge_sort(int* array, size_t left, size_t right) {

    assert(array);

    if (right - left <= 1) {

        return;
    }

    int mid = left + (right - left) / 2;

    r_merge_sort(array, left, mid);
    r_merge_sort(array, mid, right);
    
    if(!merge(array, left, mid, right)) {

        return;
    }
}


void recursive_merge_sort(int* array, int n) {

    assert(array);

    r_merge_sort(array, 0, n);
}


void iterative_merge_sort(int* array, int n) {

    assert(array);

    for (int curr_size = 1; curr_size < n; curr_size *= 2) {

        for (int left = 0; left < n - curr_size; left += 2 * curr_size) {

            merge(array, left, left + curr_size, (left + 2 * curr_size < n) ? left + 2 * curr_size : n);
        }
    }
}

#endif