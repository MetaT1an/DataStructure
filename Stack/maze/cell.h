#ifndef DATASTRUCTURE_CELL_H
#define DATASTRUCTURE_CELL_H

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
#define BACK 4

#define OK 0
#define ERROR 1

typedef struct {
    int x;
    int y;
    int direction;
}cell;

// find next valid cell via current old one
int next_cell(cell* old, cell* new);

// init cell
void set_cell(cell* c, int x, int y, int direction);
#endif //DATASTRUCTURE_CELL_H
