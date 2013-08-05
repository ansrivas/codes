/*******************************************************************************
*
*     FILENAME       :    queue_functions.c
*
*     DESCRIPTION    :    This file defines the various functions on queue.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     21 May 2010  Rashi Arora                          New code for a queue
*
*      @ 2010  Inc  All Rights Reserved
*
*******************************************************************************/

#include <header.h>

/******************************************************************************
*
*     FUNCTION NAME   :   isempty
*
*     DESCRIPTION     :   This function checks whether the queue is empty or not
*
*     RETURNS         : SUCCESS, if queue is empty
*                       FAILURE, if queue is not empty
*
*******************************************************************************/
int isempty(node *front) /* Parameter for the front end of the Queue */
{
    if (NULL == front)
        return SUCCESS;
    else
        return FAILURE;
}

/******************************************************************************
*
*     FUNCTION NAME   : insert
*
*     DESCRIPTION     :This function inserts a new node at the rear end of the  *		       queue
*
*     RETURNS         : nothing
*
*******************************************************************************/
void insert(node **front, /* Parameter for the front end of the queue */
	node ** rear, /* Parameter for the rear end of the queue */
	int value) /* Parameter for the data to be inserted in the queue */
{
    node *newnode;/* Node pointer for the new node which needs to be inserted */

    /* Allocate memory to the new node */
    newnode = (node*) malloc (sizeof(node));

    /* Check if memory is allocated or not */
    if (NULL ==newnode)
    {
        printf("Memory not available");
        exit(FAILURE);
    }
    else
    {
        /* Insert the new node in the queue */
        newnode->data = value;
        newnode->next = NULL;

       /* Check whether queue is empty or not */
	if (isempty(*front))
	{
            /* This is the first node */
            *front = newnode;
            *rear = newnode;
        }
        else
        {
            /* Node's exist in the queue so insert at the rear end */
            (*rear)->next = newnode;
            *rear = newnode;
        }
    }
}

/******************************************************************************
*
*     FUNCTION NAME   : delete
*
*     DESCRIPTION     :  This function deletes a node from the front end of the *			queue
*
*     RETURNS         : SUCCESS, if element is deleted
*			FAILURE, if queue is empty
*
*******************************************************************************/
int delete(node **front, /* Parameter for the front end of the queue */
  	node **rear) /* Parameter for the rear end of the queue */
{
    node *temp_node; /* Temporary node pointer */
    int value; /* Variable to represent the data which is deleted */
    
    /* Check if the queue is empty or not */     
    if (isempty(*front))
    {
        printf("\nQueue Underflow");
        return FAILURE;
    }
    else if (*rear == *front)
    {
        /* Only one node is available in the queue */
        temp_node = *front;
        *front = NULL;
        *rear =NULL;
        value = temp_node->data;
        free (temp_node);
    }        
    else
    {
        /* Delete the node from the front end of the queue */
        temp_node = *front;
        *front = (*front)->next;
        value = temp_node->data;
        free (temp_node);
    }
    printf("\nElement deleted is %d",value);
    return SUCCESS;
}

/******************************************************************************
*
*     FUNCTION NAME   :    display
*
*     DESCRIPTION     :This function displays the data in the queue
*
*     RETURNS         : nothing
*
*******************************************************************************/
void display(node * front) /* Parameter for the front end of the queue */
{
    node *current; /* Temporary node pointer to traverse the queue */

    /* Check if the queue is empty or not */
    if (isempty(front))
        printf("\nThe Queue is empty") ;
    else
    {
        printf("\nQueue is \n");
  
        /* Traverse the queue and display the elements */
        for( current = front ; current != NULL ; current = current->next)
            printf("\n %d",current->data);
    }
}

/******************************************************************************
*
*     FUNCTION NAME   :    free_queue
*
*     DESCRIPTION     :    This function frees the memory which is allocated to
*                       the nodes of the queue.
*
*     RETURNS         : SUCCESS if memory is freed,
*                       FAILURE if queue is already empty
*
*******************************************************************************/
int free_queue(node *front, /* Parameter for the front end of the queue */
	node *rear)/* Parameter for the rear end of the queue */
{
    node *current; /* Temporary node pointer to traverse the queue */

    /* Check if the queue is already empty i.e. does not exist */
    if (isempty(front))
        return FAILURE;

    /* Traverse the queue to free each node */
    while (NULL != front)
    {
        current = front->next;
        free(front);
        front = current;
    }
    
    rear= NULL;
    return SUCCESS;
}

