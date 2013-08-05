/*******************************************************************************
*
*     FILENAME       :    header.h
*
*     DESCRIPTION    :    This file defines the macros and the structure of the
*                       node used for the queue.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     21 May 2010  Rashi Arora                          New code for the queue
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
typedef struct node_q
{
    int data;
    struct node_q *next;
}node;

/********************** Function Declaration **********************************/
void insert(node **front,node **rear,int value);
int delete(node **front,node **rear);
int isempty(node *front);
void display(node *front);
int free_queue(node* front,node*rear);

