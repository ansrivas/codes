/*******************************************************************************
*
*  FILE NAME    : queue_prototypes.h
*
*  DESCRIPTION: Header file for implementing a queue
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/

/*******************************************************************************
*		Prototype of structure for queue
*******************************************************************************/
extern struct node
{
   int data;
   struct node *link;
};

/*****************************************************************************
*		Function Prototypes
******************************************************************************/

extern void insert(struct node **front, struct node **rear, int value);
extern void delete(struct node **front, struct node **rear, int *value);
extern void display(struct node *front);
extern void search(struct node **front, struct node **rear, int value);
