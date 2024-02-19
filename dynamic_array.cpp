#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


typedef int elem_t;

struct Stack
{
    elem_t* array;
    size_t size;
    size_t capacity;
};

struct Stack* stack_ctr(size_t size, size_t element_size);

int push(struct Stack* st, void* buffer);

int top(struct Stack* st, void* buffer);

int pop(struct Stack* st);

struct Stack* stack_dtr(struct Stack* st);

void print_stack(struct Stack* st);

void test1(struct Stack* st, int start);

void test2(struct Stack* st, int start);

void test3(struct Stack* st, int start);


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


struct Stack* stack_ctr(size_t size, size_t element_size) {

    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));

    if (!st) {

        printf("No memory\n");
        return NULL;
    }

    st->array = (elem_t*) calloc(size, element_size);

    if (!st->array) {

        printf("No memory\n");
        return NULL;
    }

    st->size = 0;
    st->capacity = size;

    return st;
}


int push(struct Stack* st, void* buffer) {

    assert(st);
    assert(st->array);
    assert(buffer);

    const int COEF_EXPANSION = 2;

    if (st->size + 1 == st->capacity) {

        st->array = (elem_t*) realloc(st->array, sizeof(elem_t) * st->capacity * COEF_EXPANSION);

        if (!st->array) {

            printf("No memory\n");

            return 0;
        }

        st->capacity *= COEF_EXPANSION;
    }

    st->array[st->size++] = *((elem_t*) buffer);

    return 1;
}


int top(struct Stack* st, void* buffer) {

    assert(st);
    assert(st->array);
    assert(buffer);

    if (st->size == 0) {

        return 0;
    }

    *((elem_t*) buffer) = st->array[st->size - 1];

    return 1;
}


int pop(struct Stack* st) {

    assert(st);
    assert(st->array);

    const int COEF_DECREASE = 2;

    if (st->size == 0) {

        return 0;
    }

    --st->size;

    if (st->size * COEF_DECREASE * COEF_DECREASE == st->capacity) {

        st->array = (elem_t*) realloc(st->array,
                     sizeof(elem_t) * ((size_t) (st->capacity / COEF_DECREASE)));

        if (!st->array) {

            printf("No memory\n");

            return 0;
        }

        st->capacity = (size_t) (st->capacity / COEF_DECREASE);
    }

    return 1;
}


struct Stack* stack_dtr(struct Stack* st) {

    assert(st);
    assert(st->array);

    free(st->array);
    free(st);

    return NULL;
}


void print_stack(struct Stack* st) {

    assert(st);
    assert(st->array);

    for (size_t i = 0; i < st->size; i++) {

        printf("%d ", st->array[i]);
    }

    putchar('\n');

    printf("size = %u\ncapacity = %u\n", st->size, st->capacity);
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