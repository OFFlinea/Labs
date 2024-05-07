#ifndef MERGE_SORT_H
#define MERGE_SORT_H

enum status
{
    ERROR,
    OK
};

void recursive_merge_sort(int* array, int n);

void iterative_merge_sort(int* array, int n);

#endif