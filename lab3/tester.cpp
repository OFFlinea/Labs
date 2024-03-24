#include <stdio.h>
#include "testing.h"
#include "msd_sort.h"


int main() {

    const char* test_folder_path = "big_tests";
    const char* result_file_path = "built_in_quick__sort_results.txt";
    int from = 0;
    int to = 1000000;
    int step = 10000;

    srand(time(NULL));

    double* times = test_sorts(test_folder_path, msd_sort, result_file_path, from, to, step);

    free(times);

    return 0;
}