#include <stdio.h>
#include "stack.h"
#include "stack_protection.h"

int main (int argc, char* argv [])
{
    stack p;
    STACK_CTOR (&p, 5);
    PUSH (&p, 5);
    PUSH (&p, 5);
    PUSH (&p, 5);
    PUSH (&p, 5);
    PUSH (&p, 5);
    PUSH (&p, 5);
    STACK_DUMP (p);
    int q = 0;
    printf ("%d %d\n", POP (&p, &q), q);
    printf ("%d %d\n", POP (&p, &q), q);
    printf ("%d %d\n", POP (&p, &q), q);
    STACK_DTOR (&p);
}

