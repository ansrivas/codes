/*******************************************************************************
*
*     FILENAME       :    main.c
*
*     DESCRIPTION    :    This file defines the main function.
*       It is used for performing different operations on a stack.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     26 May 2010  Rashi Arora                          New code for a stack
*
*      @ 2010  Inc  All Rights Reserved
*
*******************************************************************************/

#include<header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    main
*
*     DESCRIPTION     :    This function calls different functions to perform
*                       operations like insertion, deletion, display etc on
*                       a stack.
*
*     RETURNS         : SUCCESS
*
*******************************************************************************/
int main(void)
{
    int choice; /* variable to take the user choice */
    top = -1;
    /* 
    * Take the user's choice and invoke the function to perform an operation on     *  the stack 
    */
    do
    {
        printf("\n1.Push \n");
        printf("2.Pop \n");
        printf("3.Display\n");
        printf("4.Exit   ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {
                        /* Perform insertion in the stack */
                        printf("\n enter the value to be inserted ");
                        int num; /* variable to take the input from user */
                        scanf(" %d",&num);
                        push(num);
                        break;
                    }
            case 2: {
                        /* Perform deletion on the stack */
                        int ret_val; /* Variable to check the return value */
                        ret_val = pop();
                        if (FAILURE != ret_val)
                            printf("\nItem deleted is %d \n",ret_val);
                        break;
                    }
            case 3: {
                        /* Display the stack contents */
                        display();
                        break;
                    }
            default: break;
        }
    }while(choice !=4);
    return SUCCESS;
}
