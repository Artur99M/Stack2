#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define STACK_DTOR(p) StackDtor(p, #p, __FILE__, __LINE__, __func__)
#define PUSH(p, num) StackPush(p, num, #p, __FILE__, __LINE__, __func__)
#define POP(p, ERROR) StackPop(p, #p, ERROR, __FILE__, __LINE__, __func__)
#define STACK_CTOR(p, num) StackCtor(p, num, #p, __FILE__, __LINE__, __func__)

typedef int elem_t;

struct stack {
    size_t capacity;
    size_t size;
    elem_t* data;
};

int isFull (struct stack* p);
int isEmpty (struct stack* p);

int StackPush (stack* p, const elem_t number, const char* stackname,
const char* filename, const int numline, const char* func);

elem_t StackPop (stack* p, const char* stackname, int* ERROR,
const char* filename, const int numline, const char* func);

int StackCtor (stack* p, const size_t capacity, const char* stackname,
const char* filename, const int numline, const char* func);

int StackDtor (stack* p, const char* stackname,
const char* filename, const int numline, const char* func);

#endif
