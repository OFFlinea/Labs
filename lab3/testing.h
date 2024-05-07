#ifndef TESTING_H
#define TESTING_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/time.h>

double* test_sorts(const char* path, void (*sort_func)(int*, int), const char* result_path, int from, int to, int step);

#endif
