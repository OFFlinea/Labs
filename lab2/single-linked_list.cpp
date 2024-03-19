#include "list_functions.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


int main() {

    struct Stack* st = stack_ctr();

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


struct Stack* stack_ctr() {

    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));

    if (!st) {

        printf("No memory\n");

        return NULL;
    }

    return st;
}


int push(struct Stack* st, void* buffer) {

    assert(st);
    assert(buffer);

    struct Node* new_elem = (struct Node*) calloc(1, sizeof(struct Node));

    if (!new_elem) {

        printf("No memory\n");

        return 0;
    }

    new_elem->data = *((elem_t*) buffer);
    new_elem->prev = st->head;

    st->head = new_elem;

    return 1;
}


int top(struct Stack* st, void* buffer) {

    assert(st);
    assert(st->head);
    assert(buffer);

    *((elem_t*) buffer) = st->head->data;

    return 1;
}


int pop(struct Stack* st) {

    assert(st);
    assert(st->head);

    struct Node* prev = st->head->prev;

    free(st->head);

    st->head = prev;

    return 1;
}


struct Stack* stack_dtr(struct Stack* st) {

    assert(st);
    assert(st->head);

    struct Node* prev = st->head->prev;

    while (st->head != NULL) {

        prev = st->head->prev;

        free(st->head);

        st->head = prev;
    }

    free(st);

    return NULL;
}


void print_stack(struct Stack* st) {

    assert(st);
    assert(st->head);

    struct Node* element = st->head;

    while(element) {

        printf("%d ", element->data);

        element = element->prev;
    }

    putchar('\n');
}
