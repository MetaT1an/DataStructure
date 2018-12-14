#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void init(stack* stk)
{
    stk->base = (int*)malloc(INIT_SISE * sizeof(int));
    stk->top = stk->base;
    stk->size = INIT_SISE;
}

void destroy(stack* stk)
{
    free(stk->base);
    stk->base = NULL;
    stk->top = NULL;
    stk->size = 0;
}

int clear(stack* stk)
{
    stk->top = stk->base;
}

int length(stack* stk)
{
    return (int)(stk->top - stk->base);
}

Status get_top(stack* stk, int* p_num)
{
    if(stk->base == stk->top)
        return ERROR;

    *p_num = *(stk->top - 1);
    return OK;
}

Status push(stack* stk, int num)
{
    // in case the stack is full
    if(length(stk) == stk->size){
        int* new_pos = (int*)realloc(stk->base, (stk->size + INCREMENT) * sizeof(int));
        if(new_pos == NULL)
            return ERROR;
    }

    *(stk->top) = num;
    stk->top++;
    return OK;
}

Status pop(stack* stk, int* p_num)
{
    if(stk->base == stk->top)
        return ERROR;

    *p_num = *(stk->top-1);
    stk->top--;
    return OK;
}

void print(stack* stk)
{
    int* p = stk->base;
    printf("[base] ");

    while(p != stk->top){
        printf("%d ", *p);
        p++;
    }

    printf("[top]\n");
}
