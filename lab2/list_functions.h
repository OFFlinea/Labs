#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H

typedef int elem_t;

struct Node
{
    elem_t data;
    struct Node* prev;
};

struct Stack
{
    struct Node* head;
};

struct Stack* stack_ctr();

int push(struct Stack* st, void* buffer);

int top(struct Stack* st, void* buffer);

int pop(struct Stack* st);

struct Stack* stack_dtr(struct Stack* st);

void print_stack(struct Stack* st);

#endif