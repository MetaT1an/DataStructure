#include "cell.h"

int next_cell(cell* old, cell* new)
{
    if(old->direction == BACK)
        return ERROR;
    
    switch(old->direction){
        case RIGHT: new->x = old->x; new->y = old->y + 1;
            break;
        case DOWN: new->x = old->x + 1; new->y = old->y;
            break;
        case LEFT: new->x = old->x; new->y = old->y - 1;
            break;
        case UP: new->x = old->x - 1; new->y = old->y;
            break;
        default:
            break;
    }
    new->direction = RIGHT;
    old->direction++;
    return OK;
}

void set_cell(cell* c, int x, int y, int direction)
{
    c->x = x;
    c->y = y;
    c->direction = direction;
}