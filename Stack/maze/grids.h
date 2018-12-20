#ifndef DATASTRUCTURE_GRIDS_H
#define DATASTRUCTURE_GRIDS_H

#include "cell.h"

#define N 15

#define NO_WAY 0
#define AVAIL 1
#define ROUTE 2
#define WALL 3
#define START 4
#define END 5

#define YELLOW "\x1b[33m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET   "\x1b[0m"

// generate maze with various state of cells
void init_grids(int grids[N][N]);

// generate START cell
void set_start(int grids[N][N], cell* c);

// generate END cell
void set_end(int grids[N][N], cell* c);

// display the maze
void show(int grids[N][N]);

/*
 * WALL: '#'   white
 * ROUTE: '+'   yellow
 * START: '@'   yellow
 * END: '$'     green
 * NO_WAY: 'o'  red
 * AVAIL: ' '   null
 */
void prt_ch(int status);

#endif //DATASTRUCTURE_GRIDS_H
