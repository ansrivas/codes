/*******************************************************************************
*
*     FILENAME       :    delete_functions.c
*
*     DESCRIPTION    :    This file defines the various deletion functions.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     14 May 2010  Rashi Arora                          New code for linked list
*
*      @ 2010  Inc  All Rights Reserved
*
*******************************************************************************/

#include<header.h>

/******************************************************************************
*
*     FUNCTION NAME   :    delete_first
*
*     DESCRIPTION     :    This function deletes a node from the begining of
*                       the single linked list.
*
*     RETURNS         : SUCCESS, if a node is successfully deleted
*			FAILURE, if node is not deleted
*
*******************************************************************************/
int delete_first(
    node **head)/* Parameter for head of the list*/
{

   /* Write the code for deletion here */

}

/******************************************************************************
*
*     FUNCTION NAME   :    delete_last
*
*     DESCRIPTION     :    This function deletes a node from the end of
*                       the single linked list.
*
*     RETURNS         : SUCCESS, if a node is successfully deleted
*			FAILURE, if node is not deleted
*
*******************************************************************************/
int delete_last(
    node **head) /* Parameter for head of the list*/
{
    node *current; /* Temporary node pointer to traverse the list */
    node *temp; /* Temporary node pointer to traverse the list */
    current = *head;

    /* Check if the list is empty */
    if (isempty(*head))
    {
        printf("LIST IS EMPTY");
        return FAILURE;
    }
    else if (NULL == current->next) 
    {
        /* If only one node is in the list it is deleted */
        *head = NULL;
        free(current);
        return SUCCESS;
    }
    else
    {   
        /* Traverse the list to reach the second last node */
        while(NULL != current->next->next)
        {
                current = current->next;
        }
     
        /* Last node is deleted and second last node points to NULL */
        temp = current->next;
        current->next = NULL;
        free(temp);
        return SUCCESS;
    }
}

/******************************************************************************
*
*     FUNCTION NAME   :    delete_node
*
*     DESCRIPTION     :    This function deletes a node after searching the data
*                       in the single linked list.
*
*     RETURNS         : head, the modified node pointer
*
*******************************************************************************/
node * delete_node(
	node *head, /* Parameter for head of the list */
	int number )/* Parameter for the data to be searched */
{

   /* write the code for deletion here */

}


