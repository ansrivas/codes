/*******************************************************************************
*
*     FILENAME       :    main.c
*
*     DESCRIPTION    :    This file defines the main function.
*       It is used for performing different operations on a queue.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     21 May 2010  Rashi Arora                          New code for a queue
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
*                       a queue.
*
*     RETURNS         : SUCCESS
*
*******************************************************************************/
int main(void)
{
    node *front= NULL; /* Pointer for the front of the queue */
    node *rear=NULL; /* Pointer for the rear of the queue */
    int status; /* Variable to check the return status */
    int choice;  /* variable to take the user choice */

    /*
    * Take the user's choice and invoke the function to perform an operation on
    *  the queue
    */
    do
    {
        printf( "\n1.Insert \n");
        printf("2.Remove \n");
        printf("3.Display\n");
        printf("4.Exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {
                        /* Perform insertion in the queue */
                        printf("\n enter the value to be inserted ");
                        int num; /* variable to take the input from user */
                        scanf("%d",&num);
                        insert(&front , &rear , num);
                        break;
                    }
            case 2: {
                         /* Perform deletion on the queue */
                        status = delete(&front , &rear);

                        /* Check the value returned from the function */
                        if (FAILURE == status)
                            printf("\n You cannot delete");
                        else
                            printf("\n Element deleted successfully");
                        break;
                    }
            case 3: {
                         /* Display the queue contents */
                        display(front);
                        break;
                    }
            default: break;
        }
    }while(choice !=4);

    /* Free the memory allocated to the queue */
    status = free_queue(front,rear);
    if (SUCCESS == status)
        printf("\nMemory freed");
    else
        printf("\n Memory not freed ");

    return SUCCESS;
}
