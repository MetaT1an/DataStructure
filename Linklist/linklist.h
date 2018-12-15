#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H

#define OK 0
#define ERROR 1

typedef struct node{
    int value;
    struct node* next;
}node;

typedef struct{
    node* head;
    int length;
}linklist;

typedef int Status;

// init the linklist
void init(linklist* link_list);

int length(linklist* link_list);

// add a node to the tail of the list
Status append(linklist* link_list, int num);

// get point of node with given index
node* get(linklist* link_list, int index);

// find a number via index
int find(linklist* link_list, int num);

// reset the value of node
Status reset(linklist* link_list, int index, int num);

// insert a node
Status insert(linklist* link_list, int index, int num);

// delete node via index
Status del(linklist* link_list, int index);

// print the list
void print(linklist* link_list);

void destroy(linklist* link_list);

#endif //DATASTRUCTURE_LINKLIST_H
