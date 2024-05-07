#include <stdio.h>
#include "testing.h"
#include "insertion_sort.h"


int main() {

    const char* test_folder_path = "small_tests";
    const char* result_file_path = "insertion_sort_results.txt";
    int from = 0;
    int to = 1000;
    int step = 50;

    srand(time(NULL));

    double* times = test_sorts(test_folder_path, insertion_sort, result_file_path, from, to, step);

    free(times);

    return 0;
}