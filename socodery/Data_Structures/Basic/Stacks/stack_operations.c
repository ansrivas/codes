/******************************************************************************
Modify the given code of stacks by including a function to check whether the given infix expression has balanced parenthesis or not. Make use of the given push and pop functions in the code.
******************************************************************************/

/******************************************************************************
keywords                :       stack , push, pop (array implementation)

File Name               :       dsa_stack_operations.c

Date of Creation        :       13/11/2007

Owner                   :       Rashi Arora

Date of Modification    :

Reason for modification :

Modifier                :

*******************************************************************************/
#include<stdio.h>
# define size 20

/********************Structure Declaration *************************/

typedef struct stack_s
{
    int top;
    char item[size];
}stack;

/********************Function Declaration ***************************/

stack *push(stack *ps,char val);
stack *create(stack *ps);
stack *pop(stack *ps);

/***************Function Definition for creating a Stack******************/

stack *create(stack *ps)
{
    ps=(stack*)malloc(sizeof(stack));
    ps->top=-1;
    return ps;
}


stack *push(stack *ps,char val)
{
    int t;
    if(ps->top==size-1)
        printf("stack overflow");
    else
    {
        ++(ps->top);
        ps->item[ps->top]=val;
    }
    return ps;
}

stack *pop(stack *ps)
{
    char d;
    int counter=0;
    if(-1 == ps->top)
    {
        counter++;
    }
    else
    {
        d=ps->item[ps->top];
        ps->top--;

    }
    if(1 == counter)
    {
        printf("\nStack is empty ");
    }
    else
        printf("\n The popped element from the stack is %c ",d);

    return ps;
}


/*********************Main Function *********************************/

int main()
{
    stack *s;
    int ch;
    s=create(s);
    do
    {
    printf("\n1: Push in the stack  ");
    printf("\n2: Pop from the stack  ");
    printf("\n3: Exit  ");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1: {  char a;
                  printf("\n Enter the character to be pushed in the stack ");
                  scanf("%c",&a);
                  s=push(s,a);
                  break;
                }
        case 2: { char b;
                 s=pop(s);
                 break;
                 }
        }
}while(ch!=3);
    return 0;
    free(s);
}
