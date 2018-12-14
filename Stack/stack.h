#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#define INIT_SISE 2
#define INCREMENT 10

#define OK 0
#define ERROR 1

typedef struct {
    int* base;
    int* top;
    int size;
}stack;

typedef int Status;

void init(stack* stk);

// destroy a stack, no longer be used
void destroy(stack* stk);

// clear elements in stack, allow to use again
int clear(stack* stk);

int length(stack* stk);

Status get_top(stack* stk, int* p_num);

Status push(stack* stk, int num);

Status pop(stack* stk, int* p_num);

void print(stack* stk);

#endif //DATASTRUCTURE_STACK_H
