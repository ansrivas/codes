/*******************************************************************************
*
*     FILENAME       :    stack_functions.c
*
*     DESCRIPTION    :    This file defines the various functions on stack.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     26 May 2010  Rashi Arora                          New code for a stack
*
*      @ 2010  Inc  All Rights Reserved
*
*******************************************************************************/

#include <header.h>

/******************************************************************************
*
*     FUNCTION NAME   :   isempty
*
*     DESCRIPTION     :   This function checks whether the stack is empty or not
*
*     RETURNS         : SUCCESS, if stack is empty
*			FAILURE, if stack is not empty
*
*******************************************************************************/
int isempty()
{
    if (-1 == top)
        return SUCCESS; /* Stack is empty */
    else
        return FAILURE; /* Stack is not empty */
}

/******************************************************************************
*
*     FUNCTION NAME   :    overflow
*
*     DESCRIPTION     :    This function checks whether the Stack is full or not
*
*     RETURNS         : SUCCESS if stack is full,
*                       FAILURE if stack is not full
*
*******************************************************************************/
int overflow()
{
    if (STACKSIZE -1 == top)
        return SUCCESS; /* Stack Full */
    else
        return FAILURE; /* Stack not full */
}

/******************************************************************************
*
*     FUNCTION NAME   :    push
*
*     DESCRIPTION     :This function inserts a new item at the top of the stack
*
*     RETURNS         : nothing
*
*******************************************************************************/
void push(int value) /* Parameter for the item to be inserted */
{
    if (overflow())
        printf("\n Stack overflow");
    else
    {
        /* Insert if stack size is not full */
        top++;
        items[top] = value;
    }
}

/******************************************************************************
*
*     FUNCTION NAME   :    pop
*
*     DESCRIPTION     :This function deletes an item from the top of the stack
*
*     RETURNS         : FAILURE, if item is not deleted
*                       temp, the item which is deleted
*
*******************************************************************************/
int pop()
{
    int temp; /* Variable to store the item which is deleted */

    /* Check if stack is empty or not */
    if (isempty())
    {
        printf("\nStack Underflow");
        return FAILURE;
    }
    else
    {
        /* Delete the item from top of the stack */
        temp = items[top];
        top--;
        return temp;
    }
}

/******************************************************************************
*
*     FUNCTION NAME   :    display
*
*     DESCRIPTION     :This function displays the data in the stack
*
*     RETURNS         : nothing
*
*******************************************************************************/
void display()
{
    /* Check if stack is empty or not */
    if (isempty())
        printf("\nThe stack is empty\n");
    else
    {
        /* Display the items in the stack */
        int counter;
        printf("\n The items in stack are \n");
        for (counter = top; counter >= 0; counter--)
            printf("\n%d",items[counter]);
    }
}

