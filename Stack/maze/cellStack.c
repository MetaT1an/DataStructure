#include <malloc.h>
#include "cellStack.h"

void init_stk(cellstack* cstk)
{
    cstk->base = (cell*)malloc(SIZE * sizeof(cell));
    cstk->top = cstk->base;
    cstk->size = SIZE;
}

void destroy(cellstack* cstk)
{
    free(cstk->base);
    cstk->base = NULL;
    cstk->top = NULL;
    cstk->size = 0;
}

void push(cellstack* cstk, cell c)
{
    if(cstk->top - cstk->base == cstk->size){
        cell* new_base = (cell*)realloc(cstk->base, (cstk->size + INC)* sizeof(cell));
        cstk->base = new_base;
        cstk->top = cstk->base + cstk->size;
        cstk->size += INC;
    }
    *(cstk->top) = c;
    cstk->top++;
}

int pop(cellstack* cstk, cell* p_c)
{
    if(cstk->base == cstk->top)
        return WRONG;

    *p_c = *(cstk->top -1);
    cstk->top--;
    return DONE;
}

int is_empty(cellstack* cstk)
{
    return (cstk->top == cstk->base)? 1: 0;
}