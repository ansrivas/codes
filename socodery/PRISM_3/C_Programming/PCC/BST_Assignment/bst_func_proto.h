/*******************************************************************************
*
*  FILE NAME    : bst_func_proto.h
*
*  DESCRIPTION: Header file for standard tree functions
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    DSA FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/

/******************************************************************************
*		Include files
******************************************************************************/

#include "bst_node.h" 

/******************************************************************************
*	Pre-condition: rootPtr points to the pointer designating the root of a 
*			tree 
*	Post-condition: a name is read and inserted into the binary search tree *******************************************************************************/
void addName(struct node ** rootPtr, char * name); 

/******************************************************************************
*	Pre-condition: root designates the root of the tree 
*
*	Post-condition: the number of items on the list is counted and returned *	the tree itself is unchanged 
******************************************************************************/
int countNodes (struct node * root); 

/****************************************************************************** 
*	Pre-condition: rootPtr points to the pointer designating the root of a 
*			tree
*	Post-condition: a name is read and that name is deleted from the tree 
*******************************************************************************/
void deleteName(struct node ** roottPtr, char * name);

/****************************************************************************** 
*	Pre-condition: root designates the root of the tree item designates a 
*		data element (string) 
*	Post-condition: true is returned if the item is in the tree; false is 
*			returned otherwise the tree itself is unchanged 
*******************************************************************************/
int find (struct node * root, char * item); 

/******************************************************************************
*	Pre-condition: root designates the root of the tree 
*	Post-condition: The items on the list are printed using an in-order 
*			traversal printed items are indented according to their *			level the tree itself is unchanged 
*******************************************************************************/
void print(struct node * root, int level); 

/****************************************************************************** 
*	Pre-condition: root designates the root of the tree 
*	Post-condition: the leaves on the tree are printed; the tree itself is 
*			unchanged 
*******************************************************************************/
void printLeaves (struct node * root); 
