#include "stack.h"
#include <stdio.h>
#include <assert.h>

static const int changesize = 2;

int isFull(struct stack* p){
    assert(p != nullptr);
    return p->size == p->capacity - 1;
}

int isEmpty(struct stack* p) {
    assert(p != nullptr);
    return p->size == 0;
}

int StackPush(stack* p, const elem_t number, const char* stackname,
const char* filename, const int numline, const char* func)
{

    if (p == nullptr)
        return 1;
    if (p->data == nullptr)
        return 2;


    if (isFull (p))
    {
        elem_t* data = (elem_t*) realloc (p->data, p->capacity * sizeof(elem_t) * changesize);

        if (data == nullptr)
            return 4;

        p->capacity *= changesize;
        //free (p->data);
        p->data = data;
    }

    p->data[p->size] = number;
    p->size++;

    return 0;
}

elem_t StackPop(stack* p, const char* stackname, int* ERROR, const char* filename,
const int numline, const char* func)
{
    *ERROR = 0;
    if (p == nullptr)
    {
        *ERROR += 1;
        return 0;
    }

    elem_t answer = 0;

    if (isEmpty (p))
    {
        *ERROR += 2;
        return 0;
    }

    p->size--;
    answer = p->data[p->size];
    p->data[p->size] = NULL;


    if (p->size < p->capacity / changesize) {
        p->capacity /= changesize;
        elem_t* data = nullptr;
        if ((data = (elem_t*) malloc(p->capacity * sizeof(elem_t))) == nullptr) {
            *ERROR += 4;
            return 0;
        } else
        {
            for (size_t i = 0; i < p->size; i++)
                data[i] = p->data[i];
            free(p->data);
            p->data = data;
        }
    }


    return answer;
}

int StackCtor (stack* p, const size_t capacity, const char* stackname,
const char* filename, const int numline, const char* func)
{
    if (p == nullptr)
        return 1;

    p->capacity = capacity;
    p->size = 0;
    if ((p->data = (elem_t*) calloc (capacity, sizeof(elem_t))) == nullptr)
        return 2;

    return 0;
}

int StackDtor (stack* p, const char* stackname,
const char* filename, const int numline, const char* func)
{
    if (p == nullptr)
        return 1;

    free (p->data);
    p->capacity = 0;
    p->size = 0;
    p->data = nullptr;
    return 0;
}
