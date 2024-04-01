#include "array_functions.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


struct Stack* stack_ctr(size_t size, size_t element_size) {

    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));

    if (!st) {

        return NULL;
    }

    st->array = (elem_t*) calloc(size, element_size);

    if (!st->array) {

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

            return ERROR;
        }

        st->capacity *= COEF_EXPANSION;
    }

    st->array[st->size++] = *((elem_t*) buffer);

    return OK;
}


int top(struct Stack* st, void* buffer) {

    assert(st);
    assert(st->array);
    assert(buffer);

    if (st->size == 0) {

        return ERROR;
    }

    *((elem_t*) buffer) = st->array[st->size - 1];

    return OK;
}


int pop(struct Stack* st) {

    assert(st);
    assert(st->array);

    const int COEF_DECREASE = 2;

    if (st->size == 0) {

        return ERROR;
    }

    --st->size;

    if (st->size * COEF_DECREASE * COEF_DECREASE == st->capacity) {

        st->array = (elem_t*) realloc(st->array,
                     sizeof(elem_t) * ((size_t) (st->capacity / COEF_DECREASE)));

        if (!st->array) {

            return ERROR;
        }

        st->capacity = (size_t) (st->capacity / COEF_DECREASE);
    }

    return OK;
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