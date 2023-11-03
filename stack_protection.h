#ifndef STACK_PROTECTION_H
#define STACK_PROTECTION_H

#include "stack.h"

#define STACK_DUMP(p) StackDump(p, #p, __FILE__, __LINE__, __func__)

void StackDump (stack p, char* stackname, char* file, int numline, const char* func);

#endif
