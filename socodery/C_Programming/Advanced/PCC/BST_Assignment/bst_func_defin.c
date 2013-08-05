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


int height(struct node * root)
{
	if( root == NULL)
	{
		return 0;
	}	
	else
	return 1 + (height(root->left)>height(root->right)?height(root->left):height(root->right));
}


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
 newNode = (struct node *) malloc(sizeof(struct node));
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
void deleteName(struct node ** root, char * item) 
{
	struct node *temp;
	struct node * parent;
	struct node * parent1;
	struct node *delete;
	struct node *child;
	if(*root == NULL)
	printf("underflow\n");
	else
	{
		temp = *root;
		while(1)
		{
			if(NULL == temp)
			{
				break;
			}
			if(strcmp(temp->data,item)==0)
			{
				
				delete = temp;
				break;
			}
			else if(strcmp(temp->data,item)<0)
			{
				parent = temp;
				temp =temp->right;
			}
			else 
			{
				parent = temp;
				temp =temp->left;
			}

		}

		if( NULL != temp)
		{
			if(delete->left == NULL && delete->right == NULL)
			{
				if(parent->left == delete)
				{
					parent->left = NULL;
					free(delete);

				}

				if(parent->right == delete)
				{
					parent->right = NULL;
					free(delete);
				}

			}
			if((delete->left !=NULL && delete->right == NULL )|| delete->left ==NULL && delete->right !=NULL)
			{
				if(parent->left == delete)
				{
					if(delete->right ==NULL)
					{
						parent->left = delete->left;
						free(delete);
					}
					if(delete->left ==NULL)
					{
						parent->left = delete->right;
						free(delete);
					}
				}

				if(parent->right == delete)
				{
					if(delete->right ==NULL)
					{
						parent->right = delete->left;
						free(delete);
					}
					if(delete->left ==NULL)
					{
						parent->right = delete->right;
						free(delete);
					}
				}

			}

			if(delete->left != NULL && delete->right != NULL)
			{
				child = delete->right;
				while(child != NULL)
				{
					parent1 = child;	
					child = child->left;
				}	
				if(parent->left == child)
				{
					parent1->left = NULL;
				}
				if(parent->right == child)
				{
					parent1->right = NULL;
				}
				strcpy(delete->data,child->data);
				free(child);	

			}


		}
		

	}
 
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






void push(struct node* abc, int a)
{
	stack * newnode;
	newnode = (stack*)malloc(sizeof(stack));
	newnode->nod = abc;
	newnode->dat= a;
	newnode->next = NULL;	
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
}

stack* pop()
{
	stack *temp;
	if(head != NULL)
	{
		temp = head;
		head = head->next;
		return(temp);
	}
	else
	{
		return NULL;
	}

}
/******************************************************************************
*
* FUNCTION NAME: print
*
* DESCRIPTION: Prints the tree pointed by root using in-order traversal
*
* RETURNS: Returns nothing
*******************************************************************************/
void print(struct node * root) 
{ 
 int i;
 stack *temp;	
 push(root,1); 
 while( (temp = pop()) != NULL) 
 {
	 if(temp->dat == 0)
	 printf("%s",temp->nod->data);
	 else
	 {
		
		if(temp->nod->right != NULL)
		{
			push(temp->nod->right,1);
		}
		push(temp->nod,0);
	
		if(temp->nod->left != NULL)
		{
			push(temp->nod->left,1);
		}
	 }
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
