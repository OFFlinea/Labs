#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(const int argc, const char** argv) {

    int array_size = (int) strtol(argv[1], NULL, 10);
    int value_limit = (int) strtol(argv[2], NULL, 10);
    int* array = (int*) calloc(array_size, sizeof(int));

    if (!array) {

        printf("No memory\n");
        return 1;
    }

    srand((size_t) time(NULL));

    for (int i = 0; i < array_size; i++) {

        array[i] = rand() % value_limit;
    }

    for (int i = 0; i < array_size; i++) {

        printf("%d ", array[i]);
    }

    putchar('\n');

    free(array);

    return 0;
}