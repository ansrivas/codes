/*******************************************************************************
*
*  FILE NAME    : bst_main.c
*
*  DESCRIPTION: Program to implement a binary search tree
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
#include <stdlib.h>

#include "bst_node.h" 
#include "bst_func_proto.h" 

/******************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Main for tree implementation
*
* RETURNS: Returns nothing
*******************************************************************************/
int main () 
{ 
 int h = 0;
 struct node * root = NULL; 
 char name[strMax]; 
 char option; 
 printf ("This program performs operations on a binary search tree\n\n"); 
 while (1) 
 { 
  printf ("Menu Options\n"); 
  printf (" C - Count the number of names in the tree\n"); 
  printf (" D - Delete a name from the tree\n"); 
  printf (" F - Determine if a specified name is in the tree\n"); 
  printf (" I - Insert name into tree\n"); 
  printf (" L - Print the leaves in the tree\n"); 
  printf (" P - Print alphabetical listing of names\n"); 
  printf (" H - height of the tree\n"); 
  printf (" Q - Quit\n"); 
  printf ("Enter desired option: "); 
  scanf (" %c", &option); 
  switch (option) 
  { 
   case 'c': 
   case 'C': 
    printf ("The number of nodes in the tree is %d\n\n", countNodes(root)); 
    break; 

   case 'd': 
   case 'D': 
    printf ("Enter name to be deleted from the tree: "); 
    scanf (" %s", name); 
    deleteName (&root, name); 
    printf ("Deletion completed\n\n"); 
    break; 

   case 'f':  
   case 'F': 
    printf ("Search: Enter name to be sought on the tree: "); 
    scanf (" %s", name); 
    if (find(root, name)) 
     printf ("%s found on list\n\n", name); 
    else 
     printf ("%s NOT found on list\n\n", name); 
    break; 

   case 'i': 
   case 'I': 
    printf ("Enter name to be added to the tree: "); 
    scanf (" %s", name); 
    addName (&root, name); 
    printf ("Insertion completed\n\n"); 
    break; 

   case 'l': 
   case 'L': 
    printf ("The following leaves are in the tree:\n"); 
    printLeaves (root); 
    printf ("End of listing\n\n"); 
    break; 

   case 'p': 
   case 'P': 
    printf ("The following nodes are in the tree:\n"); 
    print (root);  
    printf ("End of listing\n\n"); 
    break; 

   case 'q': 
   case 'Q': 
    printf ("Program terminated\n");  
    exit(EXIT_SUCCESS);  
    break; 

	case 'h':
	case 'H':
	h = height(root);
	printf("height is %d\n",h);

   default: 
    printf ("Invalid Option\n\n"); 
  }
 } 
} 
