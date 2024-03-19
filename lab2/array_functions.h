#ifndef STACK_FUNCTIONS_H
#define STACK_FUNCTIONS_H

#include <stdio.h>

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

#endif