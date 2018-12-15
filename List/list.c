#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void init(list* p_list)
{
    p_list->data = (int*)malloc(INIT_SIZE * sizeof(int));
    p_list->length = 0;
    p_list->size = INIT_SIZE;
}

int length(list* p_list)
{
    return p_list->length;
}

void check_size(list* p_list)
{
    if(p_list->length < p_list->size)
        return;

    int* new_pos = (int*)realloc(p_list->data, (p_list->size + INCREMENT) * sizeof(int));

    if(new_pos == NULL){
        // fail to allocate more space
        printf("[check_size]:No space to be allocated\n");
        exit(1);
    } else {
        p_list->data = new_pos;
        p_list->size += INCREMENT;
    }
}

Status add(list* p_list, int num)
{
    check_size(p_list);

    int* pos;

    pos = p_list->data + p_list->length;
    *pos = num;
    ++p_list->length;

    return OK;
}

Status insert(list* p_list, int index, int num)
{
    check_size(p_list);

    if(index < 0 || index > p_list->length){
        // invalid position
        return ERROR;
    }

    // [head_pos, tail_pos)
    int* idx_pos = p_list->data + index;
    int* tail_pos = p_list->data + p_list->length;

    while(tail_pos != idx_pos){
        *tail_pos = *(tail_pos-1);
        tail_pos--;
    }
    *(idx_pos) = num;
    ++p_list->length;

    return OK;
}

Status reset(list* p_list, int index, int new_num)
{
    if(index < 0 || index >= p_list->length)
        return ERROR;

    int* idx_pos = p_list->data + index;
    *idx_pos = new_num;

    return  OK;
}

Status del(list* p_list, int index)
{
    if(index < 0 || index >= p_list->length)
        return ERROR;

    // [head_pos, tail_pos)
    int* idx_pos = p_list->data + index;
    int* tail_pos = p_list->data + p_list->length;

    while(idx_pos != tail_pos-1){
        *idx_pos = *(idx_pos+1);
        idx_pos++;
    }

    --p_list->length;
    return OK;
}

int find(list* p_list, int num)
{
    int pos = -1;
    int* head_pos = p_list->data;
    int* tail_pos = p_list->data + p_list->length;

    while(head_pos != tail_pos){
        if(*head_pos == num){
            pos = (int)(head_pos - p_list->data);
            break;
        }
        head_pos++;
    }

    return pos;
}

void print(list* p_list)
{
    if(p_list->length > 0){
        int i;
        for(i=0; i<p_list->length; ++i)
            printf("[%d]%d ", i, *(p_list->data+i));
    }

    printf("\n");
}

void empty(list* p_list)
{
    free(p_list->data);
    init(p_list);
}

void destroy(list* p_list)
{
    free(p_list->data);
    p_list->data = NULL;

    p_list->length = 0;
    p_list->size = 0;
}