/*******************************************************************************
*
*
*  FILE NAME    : queue_functions.c
*
*  DESCRIPTION: Function definitions for implementing a queue
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    DSA FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/

/*****************************************************************************
*		HEADER FILES
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************+
*		Structure for Queue
******************************************************************************/
struct node
{
   int data;
   struct node *link;
};

/*******************************************************************************
*
* FUNCTION NAME: insert
*
* DESCRIPTION: Function to implement insertion in a queue
*
* RETURNS: Nothing
*******************************************************************************/
void insert(struct node **front, struct node **rear, int value)
{
   struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   if(temp==NULL)                /* the list is empty */
   {
      printf("No Memory available Error\n");
      exit(0);
   }
   temp->data = value;
   temp->link=NULL;
   if(*rear == NULL)
   {
      *rear = temp;
      *front = *rear;
   }
   else{
         (*rear)->link= temp;
         *rear = temp;
       }
}

/*******************************************************************************
*
* FUNCTION NAME: delete
*
* DESCRIPTION: Function to implement deletion in a queue
*
* RETURNS: Nothing
*******************************************************************************/

void delete(struct node **front, struct node **rear, int *value)
{
   struct node *temp;
   if((*front == *rear) && (*rear == NULL))
   {
      printf(" The queue is empty cannot delete Error\n");
      exit(0);
   }
   *value = (*front)->data;
   temp = *front;
   *front = (*front)->link;
   if(*rear == temp)
   *rear = (*rear)->link;
   free(temp);
}

/*******************************************************************************
*
* FUNCTION NAME: display
*
* DESCRIPTION: Function to implement display a queue
*
* RETURNS: Nothing
*******************************************************************************/

void display(struct node *front)
{
        struct node *q;
        printf("\n the queue in the squencial order is : \n");
        q = front;
        while(q!=NULL)
        {
               printf("%d->",q->data);
                q = q->link;
        }
}

/*******************************************************************************
*
* FUNCTION NAME: search
*
* DESCRIPTION: Function to create a new node for queue
*
* RETURNS: Nothing
*******************************************************************************/
void search(struct node **front, struct node **rear, int value)
{
   struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   if(temp==NULL)
   exit(0);
}

