#ifndef MERGE_SORT_H
#define MERGE_SORT_H

enum status
{
    ERROR,
    OK
};

enum status merge(int* array, const size_t left, const size_t mid, const size_t right);

void r_merge_sort(int* array, size_t left, size_t right);

void recursive_merge_sort(int* array, int n);

void iterative_merge_sort(int* array, int n);

#endif