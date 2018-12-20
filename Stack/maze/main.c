#include <stdio.h>
#include <stdlib.h>
#include "grids.h"
#include "cell.h"
#include "cellStack.h"

int main()
{
    cellstack cstk;     // for path tracking
    int grids[N][N];    // structure of the maze
    int flag;
    cell head, end, tmp;     // start & end cell of the maze

    set_cell(&head, 0, 0, 0);   // init direction of head
    set_cell(&tmp, 0, 0, 0);
    init_stk(&cstk);
    init_grids(grids);

    set_start(grids, &head);
    set_end(grids, &end);

    show(grids);
    while(head.x!=end.x || head.y!=end.y){

        flag = next_cell(&head, &tmp);

        if(flag == ERROR && is_empty(&cstk))    // no solution
            break;
        else if(flag == ERROR && !is_empty(&cstk)){ // no available direction
            grids[head.x][head.y] = NO_WAY;
            pop(&cstk, &head);
            grids[head.x][head.y] = START;
        }
        else if(flag == DONE){                  // potential cell
            flag = grids[tmp.x][tmp.y];
            if(flag != AVAIL && flag != END){   // invalid cell
                continue;
            }
            push(&cstk, head);                  // proceed to the next available cell
            grids[head.x][head.y] = ROUTE;

            head = tmp;
            grids[head.x][head.y] = START;
        }
        system("sleep 0.3");    // linux sleep
        system("clear");
        show(grids);// repaint the maze
    }
    destroy(&cstk);

    return 0;
}