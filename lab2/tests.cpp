#include "tests.h"
#include "array_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main() {

    struct Stack* st = stack_ctr(10, sizeof(elem_t));

    clock_t begin = clock();

    for (int i = 0; i < 1e6; i++) {

        push(st, &i);
    }

    // begin = clock(); // Для теста 3 раскомментить

    //функция с тестом

    test2(st, 1);

    stack_dtr(st);

    clock_t end = clock();

    printf("%lf\n", (double) (end - begin) / CLOCKS_PER_SEC);

    return 0;
}


void test1(struct Stack* st, int start) {

    if (start) {
    
        int capacity = 1e6;

        while (capacity < 1e5) {

            for (int i = 0; i < (int) (capacity / 2); i++) {

                pop(st);
            }

            for(int i = 0; i < (int) (capacity / 4); i++) {

                push(st, &i);
            }

            capacity = (int) (capacity * 3 / 4);
        }
    }
}


void test2(struct Stack* st, int start) {

    if (start) {

        for (int i = 0; i < 100; i++) {

            for (int j = 0; j < 10000; j++) {

                pop(st);
            }

            for (int j = 0; j < 10000; j++) {

                push(st, &i);
            }
        }

        test1(st, 1);

        for (int i = 0; i < 100; i++) {

            for (int j = 0; j < 10000; j++) {

                pop(st);
            }

            for (int j = 0; j < 10000; j++) {

                push(st, &i);
            }
        }
    }
}


void test3(struct Stack* st, int start) {

    if (start) {

        int operation = 0;
        srand(start);

        for (int i = 0; i < 1e6; i++) {
            
            operation = rand();

            if (operation % 2 == 0) {

                push(st, &i);
            }

            else {

                pop(st);
            }
        }
    }
}