#ifndef STACK_H
#define STACK_H

#include <stdio.h>

typedef int elem_t;

struct stack {
    size_t capacity;
    size_t size;
    elem_t* data;
};

int isFull (stack*);
int isEmpty (stack*);
int StackPush(stack*, const elem_t);
elem_t StackPop(stack*, int*);
int StackCtor (stack*, const size_t);
int StackDtor (stack*);

#endif
