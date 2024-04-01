#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void* num1, const void* num2);


int main(int argc, char** argv) {

    int array_size = strtol(argv[1], NULL, 10);
    int* array = (int*) calloc(array_size, sizeof(int));

    if (!array) {

        printf("No memory\n");
        return 1;
    }

    for (int i = 0; i < array_size; i++) {

        if (!scanf("%d", &array[i])) {

            return 1;
        }
    }

    qsort(array, array_size, sizeof(int), cmp_int);

    for (int i = 0; i < array_size; i++) {

        printf("%d ", array[i]);
    }

    putchar('\n');

    free(array);

    return 0;
}


int cmp_int(const void* num1, const void* num2) {

    return *((const int*) num1) - *((const int*) num2);
}