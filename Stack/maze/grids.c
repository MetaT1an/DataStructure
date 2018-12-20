#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grids.h"

void init_grids(int grids[N][N])
{
    int i, j;
    srand((unsigned)time(NULL));

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){

            if(i==0 ||j==0 || i==N-1 || j==N-1) {
                grids[i][j] = WALL;
            } else if(rand() % 10 < 3){
                grids[i][j] = WALL;
            } else {
                grids[i][j] = AVAIL;
            }
        }
    }
}

void show(int grids[N][N])
{
    int i, j;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            prt_ch(grids[i][j]);
        }
        putchar('\n');
    }
}

void set_start(int grids[N][N], cell* c)
{
    srand((unsigned)time(NULL));

    c->x = rand()%(N-2)+1;
    c->y = rand()%(N-2)+1;
    grids[c->x][c->y] = START;
}

void set_end(int grids[N][N], cell* c)
{
    srand((unsigned)time(NULL)>>1);

    c->x = rand()%(N-2)+1;
    c->y = rand()%(N-2)+1;
    grids[c->x][c->y] = END;
}

void prt_ch(int status)
{
    /*
     * 'o' --> no path
     * ' ' --> untried
     * '+' --> on the trial
     * '#' --> wall
     * '@' --> head
     * '$' --> destination
     */
    static char ch[] = {'o', ' ', '+', '#', '@', '$'};

    switch(status){
        case WALL: printf("%c ", ch[status]);
            break;
        case ROUTE: printf(YELLOW "%c " RESET, ch[status]);
            break;
        case NO_WAY: printf(RED "%c " RESET, ch[status]);
            break;
        case START: printf(YELLOW "%c " RESET, ch[status]);
            break;
        case END: printf(GREEN "%c " RESET, ch[status]);
            break;
        case AVAIL: printf("%c ", ch[status]);
            break;
        default:
            break;
    }
}