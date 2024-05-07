#include "testing.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/time.h>

int cmp(const void* num1, const void* num2) {

    const int first = *((const int*) num1);
    const int second = *((const int*) num2);

    return (first > second) - (first < second);
}


double* test_sorts(const char* path, void (*sort_func)(int*, int), const char* result_path, int from, int to, int step) {

    assert(path);
    assert(result_path);

    int num_tests = (to - from) / step + 1;
    double* times = (double*) calloc(num_tests, sizeof(double));

    if (!times) {

        printf("No memory\n");
        exit(1);
    }

    int test_index = 0;
    double sorting_time = 0;
    const int N_SUBTESTS = 5;
    const int MAX_LEN_PATH = 1024;
    struct timeval start = {}, end = {};

    for (int size = from; size <= to; size += step) {

        for (int i_subtest = 1; i_subtest <= N_SUBTESTS; i_subtest++) {

            const int MAX_LEN = 1024;
            char test_file_path[MAX_LEN_PATH] = {};
            snprintf(test_file_path, sizeof(test_file_path), "%s/%d_%d.in", path, size, i_subtest);

            FILE* test_file_in = fopen(test_file_path, "r");

            if (!test_file_in) {

                printf("%s\n", test_file_path);
                printf("File error\n");
                exit(1);
            }

            int* array = (int*) calloc(size, sizeof(int));

            if (!array) {

                printf("No memory\n");
                exit(1);
            }

            for (int i = 0; i < size; i++) {

                fscanf(test_file_in, "%d", &array[i]);
            }

            fclose(test_file_in);

            gettimeofday(&start, NULL);
            sort_func(array, size);
            gettimeofday(&end, NULL);

            sorting_time += (end.tv_sec  - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

            snprintf(test_file_path, sizeof(test_file_path), "%s/%d_%d.out", path, size, i_subtest);

            FILE* test_file_out = fopen(test_file_path, "r");

            int elem = 0;

            for (int i = 0; i < size; i++) {

                fscanf(test_file_out, "%d", &elem);
                assert(elem == array[i]);
            }

            free(array);
            fclose(test_file_out);
        }

        times[test_index++] = sorting_time / N_SUBTESTS;
    }

    FILE* result_file = fopen(result_path, "w");

    if (!result_file) {

        printf("%s\n", result_path);
        printf("File error\n");
        exit(1);
    }

    for (int i = 0; i < num_tests; i++) {

        fprintf(result_file, "%f ", times[i]);
    }

    fclose(result_file);

    return times;
}