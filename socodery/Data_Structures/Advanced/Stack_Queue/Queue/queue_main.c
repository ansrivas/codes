/*******************************************************************************
*
*
*  FILE NAME    : queue_main.c
*
*  DESCRIPTION: To implement a queue using linked list
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/

/*****************************************************************************
*		HEADER FILES
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue_prototypes.h"

/*******************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Accepts the input from user and make calls to different functions*		for implementing a queue 
*
* RETURNS: Returns SUCCESS or FAILURE
*******************************************************************************/

int main()
{
   struct node *front=NULL,*rear = NULL;
   int n,value;
   int i =1,j=0;
   while(i==1)
   {
          printf("\nEnter your choice : \n   \
		Press 1 to insert in Queue\n   \
		Press 2 to delete from Queue\n  \
		Press 3 display Queue\n\t");
          scanf("%d",&j);
          switch(j)
          {
                 case 1:
                                printf("\nEnter the value to be inserted : ");
                                scanf("%d",&value);
                                insert(&front,&rear,value);
                                i =0;
                                break;
                 case 2:
                                delete(&front,&rear,&value);
                                printf("The value deleted is %d\n",value);
                                i = 0;
                                break;
                  case 3:
                                display(front);
                                i = 0;
                                break;
                  default:
                                printf("\n Invalid option ");
                }
                printf("\n Press 1 to continue \n Press 2 to exit");
                scanf("%d",&i);
                system("clear");
        }
        return 0;
}

