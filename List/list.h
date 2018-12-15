#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

#define INIT_SIZE 10
#define INCREMENT 5

#define OK 0
#define ERROR 1

typedef struct{
    int* data;
    int length;
    int size;
}list;

typedef int Status;

// init a list, with initial length 0
void init(list* p_list);

// get the length of the list
int length(list* p_list);

// make sure the space is staple for later operation
// if current space is used up, more space will be allocated to list
void check_size(list* p_list);

// add a number to the tail of the list
Status add(list* p_list, int num);

// insert a number to the list with given pos and val
Status insert(list* p_list, int index, int num);

// replace a number via index
Status reset(list* p_list, int index, int new_num);

// delete a number via index
Status del(list* p_list, int index);

// find a number, return its smallest index
int find(list* p_list, int num);

// print the list
void print(list* p_list);

void empty(list* p_list);

void destroy(list* p_list);

#endif //DATASTRUCTURE_LIST_H
