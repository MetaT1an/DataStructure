#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"

void init(linklist* link_list)
{
    link_list->head = NULL;
    link_list->length = 0;
}

int length(linklist* link_list)
{
    return link_list->length;
}

int append(linklist* link_list, int num)
{
    // generate a new node
    node* block = (node*)malloc(sizeof(int));
    block->value = num;
    block->next = NULL;

    node* tail = link_list->head;

    if(tail == NULL){
        link_list->head = block;
    } else {
        while(tail->next != NULL)
            tail = tail->next;

        tail->next = block;
    }
    link_list->length++;
    return OK;
}

node* get(linklist* link_list, int index)
{
    if(index < 0 || index >= link_list->length)
        return NULL;

    node* p = link_list->head;
    int cnt;

    for(cnt=0; cnt<index; ++cnt)
        p = p->next;

    return p;
}

int find(linklist* link_list, int num)
{
    int index = -1, cnt = 0;
    node* p = link_list->head;

    while(p != NULL){
        if(p->value == num){
            index = cnt;
            break;
        }
        p = p->next;
        cnt++;
    }
    return index;
}

int insert(linklist* link_list, int index, int num)
{
    // to insert a node in to index n (n>0)
    // we need to find (n-1) node
    if(index < 0 || index >= link_list->length)
        return ERROR;

    node* block = (node*)malloc(sizeof(int));
    block->value = num;
    block->next = NULL;

    if(index == 0){
        block->next = link_list->head;
        link_list->head = block;
    } else {
        node* pre = get(link_list, index-1);
        block->next = pre->next;
        pre->next = block;
    }

    link_list->length++;
    return OK;
}

int reset(linklist* link_list, int index, int num)
{
    node* pos = get(link_list, index);
    if(pos == NULL)
        return ERROR;

    pos->value = num;
    return OK;
}

int del(linklist* link_list, int index)
{
    if(index < 0 || index >= link_list->length)
        return ERROR;

    node* target;
    if(index == 0){
        target = link_list->head;
        link_list->head = target->next;
        free(target);
    } else {
        node* pre = get(link_list, index-1);
        target = pre->next;
        pre->next = target->next;
    }
    free(target);

    link_list->length--;
    return OK;
}


void print(linklist* link_list)
{
    node* p = link_list->head;
    int cnt = 0;

    while(p != NULL){
        printf("[%d]%d", cnt, p->value);

        if(p->next != NULL)
            printf("-->");

        p = p->next;
        ++cnt;
    }
    putchar('\n');
}

void empty(linklist* link_list)
{
    node* p = link_list->head;
    node* q = p;
    link_list->head = NULL;

    while(p != NULL){
        p = p->next;
        free(q);
        q = p;
    }
    link_list->length = 0;
}