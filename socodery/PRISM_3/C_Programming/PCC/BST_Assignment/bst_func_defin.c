/*******************************************************************************
*
*  FILE NAME    : bst_func_defin.c
*
*  DESCRIPTION: Implementation for standard tree functions
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    DSA FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/

/******************************************************************************
*               Header files
******************************************************************************/
#include <stdio.h>
#include <string.h>

#include "bst_node.h"

/******************************************************************************
*
* FUNCTION NAME: addName
*
* DESCRIPTION: Inserts string pointed by name at appropriate postion in the 
*		tree pointed by rootPtr
*
* RETURNS: Returns nothing
*******************************************************************************/
void addName(struct node ** rootPtr, char * name) 
{ 
 struct node * newNode;  
 
 struct node * treePtr;  /* Create and initialize new node */ 
 
 strcpy (newNode->data, name); 
 
 
 /* Insert new node into tree */ 
 /* Check if tree is empty */ 
 if (*rootPtr == NULL) 
 { 
  *rootPtr = newNode; 
  return ; 
 } 
 
 /* For non-empty tree, search down to find the bottom of the tree */
 treePtr = *rootPtr; 
 
 while (1) 
 { 
  /* Move down tree */ 
  if (strcmp (newNode->data, treePtr->data) < 0) 
  { 
   /* move left */ 
   if (treePtr->left) 
   { 
    treePtr = treePtr->left; 
   } 
   else 
   { 
    treePtr->left = newNode; 
    return; 
   } 
  } 
  else 
  { 
   /* move right */ 
   if (treePtr->right) 
   { 
    treePtr = treePtr->right; 
   } 
   else 
   { 
    treePtr->right = newNode; 
    return; 
   } 
  } 
 } 
} 

/******************************************************************************
*
* FUNCTION NAME: countNodes
*
* DESCRIPTION:Counts the number of nodes in the tree pointed by root
*
* RETURNS: Returns number of nodes in the tree
*******************************************************************************/
int countNodes (struct node * root) 
{ 
 if (root) 
  return (1 + countNodes(root->left) + countNodes(root->right)); 
 else 
  return 0; 
} 

/******************************************************************************
*
* FUNCTION NAME: deleteName
*
* DESCRIPTION:Deletes string pointed by item from tree pointed by roottPtr
*
* RETURNS: Returns nothing
*******************************************************************************/
void deleteName(struct node ** roottPtr, char * item) 
{ 
  printf ("Function deleteName is not implemented at present\n\n"); 
} 

/******************************************************************************
*
* FUNCTION NAME: find
*
* DESCRIPTION: Checks whether the string pointed by item is present in the tree
*		pointed by root	
*
* RETURNS: Returns TRUE or FALSE
*******************************************************************************/
int find (struct node * root, char * item) 
{ 
 if (root == NULL) 
  return 0; 
 if (strcmp (item, root->data) == 0) 
  return 1; 
 if (strcmp (item, root->data) < 0) 
  return find(root->left, item); 
 else 
  return find(root->right, item); 
} 

/******************************************************************************
*
* FUNCTION NAME: print
*
* DESCRIPTION: Prints the tree pointed by root using in-order traversal
*
* RETURNS: Returns nothing
*******************************************************************************/
void print(struct node * root, int level) 
{ 
 int i; 
 if (root) 
 { 
  print (root->left, level+1); 
  for (i = 0; i < level; i++) 
   /* indent based on level of node */ 
   printf (" "); 
  printf ("%s\n", root->data); 
  print (root->right, level+1); 
 } 
} 

/******************************************************************************
*
* FUNCTION NAME: printLeaves
*
* DESCRIPTION: Displays the leaf nodes the tree pointed by root
*
* RETURNS: Returns nothing
*******************************************************************************/
void printLeaves (struct node * root) 
{ 
 if (root) 
 { 
  if ((!(root->left))&&(!(root->right))) 
   printf ("%s\n", root->data); 
  else 
  { 
   printLeaves (root->left); 
   printLeaves (root->right); 
  } 
 } 
} 
