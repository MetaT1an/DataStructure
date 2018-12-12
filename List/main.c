#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void show_menu();
void fun_add(list* p_list);
void fun_insert(list* p_list);
void fun_reset(list* p_list);
void fun_del(list* p_list);
void fun_find(list* p_list);
void fun_print(list* p_list);
void fun_len(list* p_list);
void fun_empty(list* p_list);

int main()
{
    list li;
    init(&li);

    // function array
    void (*f[])(list* p_list) = {fun_add, fun_insert, fun_reset, fun_del, fun_find, fun_print, fun_len, fun_empty};
    show_menu();

    int choice;
    scanf("%d", &choice);

    while(choice != sizeof(f)/sizeof(f[0])){

        if(choice > 0 && choice <= sizeof(f)/sizeof(f[0]) - 1){
            f[choice-1](&li);   // call the relevant function
            printf("\npress [m] to return menu\n");
            while(getchar() != 'm'){};
        }

        show_menu();
        scanf("%d", &choice);
    }

    return 0;
}

void show_menu()
{
    system("clear");
    printf("=========Test for list==========\n");
    printf("1. add a number\n");
    printf("2. insert a number\n");
    printf("3. reset a number\n");
    printf("4. delete a number\n");
    printf("5. find a number\n");
    printf("6. print the list\n");
    printf("7. get length of the list\n");
    printf("8. quit\n");
    printf("================================\n");

}

void fun_add(list* p_list)
{
    int num, status;
    printf("Please input an integer: ");
    scanf("%d", &num);

    status = add(p_list, num);
    if(status == OK)
        printf("[add OK]:Number has been added!\n");
}

void fun_insert(list* p_list)
{
    int index, num, status;

    printf("Please input the position to insert(0 is 1st): ");
    scanf("%d", &index);

    printf("Input the Integer: ");
    scanf("%d", &num);

    status = insert(p_list, index, num);

    if(status == OK){
        printf("[insert OK]:Number has been inserted!\n");
    } else {
        printf("[insert ERROR]:Fail to insert! (Invalid position %d)\n", index);
    }
}

void fun_reset(list* p_list)
{
    int index, num, status;

    printf("Please input the position to reset(0 is 1st): ");
    scanf("%d", &index);

    printf("Input the new Integer: ");
    scanf("%d", &num);

    status = reset(p_list, index, num);

    if(status == OK){
        printf("[insert OK]:Number has been reset!\n");
    } else {
        printf("[reset ERROR]:Fail to reset number! (Invalid position %d)\n", index);
    }
}

void fun_del(list* p_list)
{
    int index, status;

    printf("Please input the position to reset(0 is 1st): ");
    scanf("%d", &index);

    status = del(p_list, index);

    if(status == OK){
        printf("[delete OK]:Number has been deleted!\n");
    } else {
        printf("[delete ERROR]:Fail to delete number! (Invalid position %d)\n", index);
    }
}

void fun_find(list* p_list)
{
    int num, pos;

    printf("Please input the integer to find: ");
    scanf("%d", &num);

    pos = find(p_list, num);

    if(pos == -1){
        printf("[find]:Fail to find the number! (Number %d dose not exist)\n", num);
    } else {
        printf("[find OK]:Number has been found! (pos: %d)", pos);
    }
}

void fun_print(list* p_list)
{
    print(p_list);
}

void fun_len(list* p_list)
{
    int len = length(p_list);
    printf("[length]:Length of the list: %d", len);
}

void fun_empty(list* p_list)
{
    empty(p_list);
}