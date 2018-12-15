#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void show_menu();
void fun_push(stack* stk);
void fun_pop(stack* stk);
void fun_top(stack* stk);
void fun_print(stack* stk);
void fun_len(stack* stk);
void fun_clear(stack* stk);
void fun_destroy(stack* stk);

int main()
{
    stack stk;
    init(&stk);

    void (*f[])(stack*) = {fun_push, fun_pop, fun_top, fun_print, fun_len, fun_clear, fun_destroy};

    show_menu();

    int choice;
    scanf("%d", &choice);

    while(choice != sizeof(f)/sizeof(f[0])){

        if(choice > 0 && choice <= sizeof(f)/sizeof(f[0]) - 1){
            f[choice-1](&stk);   // call the relevant function
            printf("\npress [m] to return menu\n");
            while(getchar() != 'm'){};
        }

        show_menu();
        scanf("%d", &choice);
    }

    // destroy the stack
    f[choice-1](&stk);
    return 0;
}

void show_menu()
{
    system("clear");
    printf("=========Test for stack==========\n");
    printf("1. push a number\n");
    printf("2. pop a number\n");
    printf("3. get the top number\n");
    printf("4. print the stack\n");
    printf("5. get length of the stack\n");
    printf("6. clear the stack\n");
    printf("7. quit\n");
    printf("====================================\n");
}

void fun_push(stack* stk)
{
    int num, status;
    printf("Please input the number: \n");
    scanf("%d", &num);

    status = push(stk, num);

    if(status == ERROR){
        printf("[push ERROR]: Fail to push the number! (No more space)\n");
    } else {
        printf("[push OK] Number has been pushed!\n");
    }
}

void fun_pop(stack* stk)
{
    int pop_num, status;

    status = pop(stk, &pop_num);
    if(status == ERROR){
        printf("[pop ERROR]: Fail to pop number! (empty stack)\n");
    } else {
        printf("[pop OK]: Number %d has been popped!\n", pop_num);
    }
}

void fun_top(stack* stk)
{
    int top_num, status;

    status = get_top(stk, &top_num);
    if(status == ERROR){
        printf("[pop ERROR]: Fail to get the top number! (empty stack)\n");
    } else {
        printf("[pop OK]: Get top number! (%d)\n", top_num);
    }
}

void fun_print(stack* stk)
{
    print(stk);
}

void fun_len(stack* stk)
{
    printf("The length of the stack: %d\n", length(stk));
}

void fun_clear(stack* stk)
{
    clear(stk);
    printf("[empty OK]: The stack is empty now!\n");
}

void fun_destroy(stack* stk)
{
    destroy(stk);
    printf("[destroy OK]: The stack has been destroyed!\n");
}