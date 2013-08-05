/*******************************************************************************
*
*  FILE NAME    : bst_node.h
*
*  DESCRIPTION: Declaration of standard node structure for trees
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    DSA FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/ 
/* utilize an ifndef/define mechanism, so nodes will be define exactly once */

 #ifndef _BST_NODE_H 
   #define _BST_NODE_H 
  
   /* Maximum length of names */ 
    #define strMax 20 
   
  /* Define the node structure itself */
   struct node 
   { 
     char data [strMax]; 
     struct node * left; 
     struct node * right; 
   };

   typedef struct stack
	{
	struct node *nod;
	int dat;
	struct stack *next;
	}stack;

	stack *head;
			
 
#endif 
