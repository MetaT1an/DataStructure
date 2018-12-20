#ifndef DATASTRUCTURE_CELLSTACK_H
#define DATASTRUCTURE_CELLSTACK_H

#include "cell.h"

#define SIZE 100
#define INC 30

#define DONE 0
#define WRONG 1

typedef struct {
    cell* base;
    cell* top;
    int size;
}cellstack;

void init_stk(cellstack* cstk);

void destroy(cellstack* cstk);

void push(cellstack* cstk, cell c);

int pop(cellstack* cstk, cell* p_c);

int is_empty(cellstack* cstk);

#endif //DATASTRUCTURE_CELLSTACK_H
