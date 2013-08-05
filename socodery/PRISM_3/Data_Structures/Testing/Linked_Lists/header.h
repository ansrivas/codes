/*******************************************************************************
*
*     FILENAME       :    header.h
*
*     DESCRIPTION    :    This file defines the macros and the structure of the *   			node used for the list.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     14 May 2010  Rashi Arora                          New code for linked list
*
*      @ 2010  Inc  All Rights Reserved
*
*******************************************************************************/

/********************** Header File Inclusions ********************************/
#include <stdio.h>
#include<stdlib.h>

/********************** Macro definitions *************************************/
# define SUCCESS 1
# define FAILURE 0
           
/********************** Structure Definition **********************************/
typedef  struct node_list
{      
    int data;
    struct node_list *next;
}node;

/********************** Function Declaration **********************************/
int isempty(node * head);
node * insert_first(node *head,int number);
node * insert_last(node *head, int number);
node * insert_after(node *head, int node_no, int number);
int delete_first(node **head);
int delete_last(node **head);
node * delete_node(node *head, int number);
int delete_even(node **head);
void display(node *head);
int count(node *head);
int list_free(node *head);
