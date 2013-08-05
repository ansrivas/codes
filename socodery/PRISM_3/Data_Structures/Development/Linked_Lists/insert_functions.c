/*******************************************************************************
*
*     FILENAME       :    insert_functions.c
*
*     DESCRIPTION    :    This file defines the various insertion function.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     14 May 2010  Rashi Arora                          New code for linked list
*
*      @ 2010  Inc  All Rights Reserved
*
*******************************************************************************/

#include <header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    insert_first
*
*     DESCRIPTION     :    This function inserts a new node at the begining of  *			the single linked list.
*
*     RETURNS         : head, the modified node pointer
*
*******************************************************************************/
node * insert_first(
	node *head, /* Parameter for head of the list*/
	int number) /* Parameter for the data to be inserted */
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
        newnode->data = number; /* Assigning data */

        /*
        * The node currently pointed to by head will now be pointer by this 
        * node
        */
        newnode->next = head; 
        head = newnode; /* Head will now point to the new node added */
        return head;
    }
}
/******************************************************************************
*
*     FUNCTION NAME   :    insert_last
*
*     DESCRIPTION     :    This function inserts a new node at the end of       *			the single linked list.
*
*     RETURNS         : head, the modified node pointer
*
*******************************************************************************/

node * insert_last(
	node *head, /* Parameter for head of the list*/
	int number) /* Parameter for the data to be inserted */
{


    /* Write the code for insertion here */
  
}

/******************************************************************************
*
*     FUNCTION NAME   :    insert_after
*
*     DESCRIPTION     :    This function inserts a new node after the given node*			number in the single linked list.
*
*     RETURNS         : head, the modified node pointer
*
*******************************************************************************/
node * insert_after(
	node *head, /* Parameter for head of the list*/
	int node_no, /* Parameter for the node number after which a node has to be inserted */
	int number) /* Parameter for the data to be inserted */
{

    /* Write the code for insertion here */

}

