#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void show_menu();
void fun_append(linklist* link_list);
void fun_insert(linklist* link_list);
void fun_reset(linklist* link_list);
void fun_del(linklist* link_list);
void fun_find(linklist* link_list);
void fun_print(linklist* link_list);
void fun_len(linklist* link_list);
void fun_destroy(linklist* link_list);

int main()
{
    linklist lklist;
    init(&lklist);

    void (*f[])(linklist* link_list) = {fun_append, fun_insert, fun_reset, fun_del, fun_find, fun_print, fun_len, fun_destroy};
    show_menu();

    int choice;
    scanf("%d", &choice);

    while(choice != sizeof(f)/sizeof(f[0])){

        if(choice > 0 && choice <= sizeof(f)/sizeof(f[0]) - 1){
            f[choice-1](&lklist);   // call the relevant function
            printf("\npress [m] to return menu\n");
            while(getchar() != 'm'){};
        }

        show_menu();
        scanf("%d", &choice);
    }

    f[choice-1](&lklist);
    return 0;
}

void show_menu()
{
    system("clear");
    printf("=========Test for linklist==========\n");
    printf("1. append a number\n");
    printf("2. insert a number\n");
    printf("3. reset a number\n");
    printf("4. delete a number\n");
    printf("5. find a number\n");
    printf("6. print the list\n");
    printf("7. get length of the list\n");
    printf("8. destroy and quit\n");
    printf("====================================\n");
}

void fun_append(linklist* link_list)
{
    int num, status;
    printf("Please input an integer: ");
    scanf("%d", &num);

    status = append(link_list, num);
    if(status == OK)
        printf("[append OK]:Number has been added!\n");
}

void fun_insert(linklist* link_list)
{
    int index, num, status;
    printf("Please input the position to insert(0 is 1st): ");
    scanf("%d", &index);

    printf("Input the Integer: ");
    scanf("%d", &num);

    status = insert(link_list, index, num);

    if(status == OK){
        printf("[insert OK]:Number has been inserted!\n");
    } else {
        printf("[insert ERROR]:Fail to insert! (Invalid position %d)\n", index);
    }
}

void fun_reset(linklist* link_list)
{
    int index, num, status;

    printf("Please input the position to reset(0 is 1st): ");
    scanf("%d", &index);

    printf("Input the new Integer: ");
    scanf("%d", &num);

    status = reset(link_list, index, num);

    if(status == OK){
        printf("[insert OK]:Number has been reset!\n");
    } else {
        printf("[reset ERROR]:Fail to reset number! (Invalid position %d)\n", index);
    }
}

void fun_del(linklist* link_list)
{
    int index, status;

    printf("Please input the position to reset(0 is 1st): ");
    scanf("%d", &index);

    status = del(link_list, index);

    if(status == OK){
        printf("[delete OK]:Number has been deleted!\n");
    } else {
        printf("[delete ERROR]:Fail to delete number! (Invalid position %d)\n", index);
    }
}

void fun_find(linklist* link_list)
{
    int num, pos;

    printf("Please input the integer to find: ");
    scanf("%d", &num);

    pos = find(link_list, num);

    if(pos == -1){
        printf("[find]:Fail to find the number! (Number %d dose not exist)\n", num);
    } else {
        printf("[find OK]:Number has been found! (pos: %d)\n", pos);
    }
}

void fun_print(linklist* link_list)
{
    print(link_list);
}

void fun_len(linklist* link_list)
{
    int len = length(link_list);
    printf("[length]:Length of the list: %d\n", len);
}

void fun_destroy(linklist* link_list)
{
    destroy(link_list);
    printf("[destroy OK]:list has been destroyed!\n");
}