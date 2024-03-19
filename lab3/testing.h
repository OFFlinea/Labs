#ifndef TESTING_H
#define TESTING_H

void test_sortings(const char* test_folder, void (*sort) (int*, int), const char* result_path, int from, int to, int step);

#endif