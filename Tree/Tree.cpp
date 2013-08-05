// Tree.cpp : Defines the entry point for the console application.
//



/******************************************************************
Author:			Ankur Srivastava
Description :	This file implements the APIs from the class CTree, which 
inturn implements a tree data structure and all its operations
*******************************************************************/


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "Tree.h"
#include <limits.h>




/***************************************************************************************************/

//Singleton Implementation for the class CTree
CTree * CTree::FnSingletonImplementation()
{
	if(NULL == mySingleton)
		mySingleton = new CTree();

	return mySingleton ;


}

/***************************************************************************************************/




node * CTree::nFnCreateMinHeightTreeUsingArray(int iArr[],int iLow, int iHigh)
{
	if(iHigh <= iLow)
		return NULL;
	int iMid = (iLow + iHigh)/2 ;
	node * root = (node *)malloc(sizeof(node));
	root->iData = iArr[iMid] ;
	root->left = nFnCreateMinHeightTreeUsingArray(iArr,iLow,iMid-1);
	root->right = nFnCreateMinHeightTreeUsingArray(iArr,iMid+1, iHigh);

	return root ;
}
/***************************************************************************************************/
bool CTree::bFnIsIdentical(node *root1, node *root2)
{

	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false ;

	return ((root1->iData == root2->iData) && bFnIsIdentical(root1->left,root2->left) && bFnIsIdentical(root1->right, root2->right)) ;

}
/***************************************************************************************************/
bool CTree::bFnIsSubTree( node* root1, node* root2)
{
	if(root2 == NULL )//the NULL subtree is actually a tree
		return true ; 

	if(root1 == NULL)
		return false ;
	if( bFnIsIdentical(root1, root2) )
		return true ;

	return (bFnIsSubTree(root1->left,root2) || bFnIsSubTree(root1->right, root2));
}

/***************************************************************************************************/

node * CTree::iFnReturnKthSmallestInBST(node *root, int *k)
{
	if(NULL == root)
		return NULL ;



	node * nLeftSubtree = iFnReturnKthSmallestInBST(root->left,k);
	if(NULL != nLeftSubtree)
	{
		return nLeftSubtree ;
	}
	(*k)-- ;
	if(!(--(*k)))
		return root ;
	return iFnReturnKthSmallestInBST(root->right,k);

}

/***************************************************************************************************/

void vFnImplementLevelOrder(node *root,int i )
{
	if(NULL == root)
		return ;
	if(i == 1)
		printf("%d ",root->iData) ;
	else
	{
		vFnImplementLevelOrder(root->left,i - 1);
		vFnImplementLevelOrder(root->right,i - 1);

	}
}


void CTree::vFnLevelOrderTraversal(node * root)
{
	int iHeight = iFnHeight(root);
	if(iHeight == 0)
		printf("Empty tree\n");

	for(int i = 1 ; i <= iHeight ;i++)
	{

		vFnImplementLevelOrder(root,i);
		printf("At Level = %d\n   ",i);

	}

}

/***********************************Tree creation code starts here**********************************/

node * CTree::nFnCreateNode(int iData)
{
	node * newNode = NULL ;
	newNode = (node *)malloc(sizeof(node)) ;
	if(NULL == newNode)
	{
		printf("Memory cant be allocated\n");
		return newNode ;
	}
	newNode->iData = iData ;
	newNode->left = NULL ;
	newNode->right	 = NULL ;

	return newNode ;
}


void CTree::vFnCreateTree(node **root,int iData)
{

	if(NULL == *root)
	{
		*root = nFnCreateNode(iData);
	}
	else
		if(iData < (*root)->iData)
			vFnCreateTree(&(*root)->left,iData);
		else
			if(iData > (*root)->iData)
				vFnCreateTree(&(*root)->right,iData);
			else
			{
				printf("Dupe data\n");
				return ;
			}

}



/***********************************Tree creation code ends here**********************************/

node * nFNMergeLists(node ** a, node  ** b)
{
	if(*a == NULL && *b == NULL)
		return NULL ;

	if(*a == NULL)
		return *b ;
	if(*b == NULL)
		return *a;

	node *temp = *a ;

	while(temp->right)
		temp = temp->right ;

	temp->right = *b ;

	return *a ;


}


void joinList(node **a, node **b)
{
	(*a)->right = *b ; 
	(*b)->left = *a ; 
}

node *mergeTree(node *aList, node* bList)
{

	if(aList == NULL)
		return bList;
	if(bList == NULL)
		return aList;

	node *aLast , *bLast ;
	aLast = aList->left;
	bLast = bList->left;

	joinList(&aLast,&bList);
	joinList(&bLast, &aList);

	return aList;
}

node* CTree::nFnConvertTreeToDoublyList(node **root)
{

	if(*root == NULL)
		return NULL;

	node *left = nFnConvertTreeToDoublyList(&(*root)->left);
	node *right = nFnConvertTreeToDoublyList(&(*root)->right);
	(*root)->left = *root;
	(*root)->right = *root;

	left = mergeTree(left, *root);
	left = mergeTree(left, right);

	return left;

}
/*

// This is a modified in-order traversal adapted to this problem.
// prev (init to NULL) is used to keep track of previously traversed node.
// head pointer is updated with the list's head as recursion ends.
void treeToDoublyList(Node *p, Node *& prev, Node *& head) {
  if (!p) return;
  treeToDoublyList(p->left, prev, head);
  // current node's left points to previous node
  p->left = prev;
  if (prev)
    prev->right = p;  // previous node's right points to current node
  else
    head = p; // current node (smallest element) is head of
              // the list if previous node is not available
  // as soon as the recursion ends, the head's left pointer 
  // points to the last node, and the last node's right pointer
  // points to the head pointer.
  Node *right = p->right;
  head->left = p;
  p->right = head;
  // updates previous node
  prev = p;
  treeToDoublyList(right, prev, head);
}
 
// Given an ordered binary tree, returns a sorted circular
// doubly-linked list. The conversion is done in-place.
Node* treeToDoublyList(Node *root) {
  Node *prev = NULL;
  Node *head = NULL;
  treeToDoublyList(root, prev, head);
  return head;
}








*/




/***********************************Tree traversal code starts here**********************************/
void CTree::vFnInorder(node *root)
{
	if(root)
	{
		vFnInorder(root->left);
		printf("%d ",root->iData);
		vFnInorder(root->right);
	}

	return ;
}




/***********************************Tree traversal code ends here**********************************/



int CTree::iFnDiameterOfTree(node *root)
{

	if(NULL == root)
		return 0 ;

	int iLeftHeight = iFnHeight(root->left);
	int iRightHeight = iFnHeight(root->right) ;


	return CUtils::iFnMax((iLeftHeight + iRightHeight +1),CUtils::iFnMax(iFnDiameterOfTree(root->left),iFnDiameterOfTree(root->right)));
}

/***********************************************************************************************************/
int vFnImplementMinAtKthLevel(node *root,int i )
{
	if(NULL == root)
		return INT_MAX;
	if(i == 1)
	{
		printf("%d ",root->iData) ;
		return root->iData ;
	}
	int iLeftData = vFnImplementMinAtKthLevel(root->left,--i);
	int iRightData = vFnImplementMinAtKthLevel(root->right,--i);
	return CUtils::iFnMin(iLeftData,iRightData);
}


int CTree::vFnMinAtKthLevel(node * root,int k)
{
	if(root == NULL)
	{
		printf("Empty tree\n");
		return INT_MAX;
	}

	return vFnImplementMinAtKthLevel(root,k);

}


/***********************************Calculate tree height code starts here**********************************/
int CTree::iFnHeight(node *root)
{
	if(NULL == root)
		return 0 ;

	return CUtils::iFnMax(iFnHeight(root->left) ,iFnHeight(root->right)) + 1;

}



/***********************************Calculate tree height code ends here**********************************/


/***********************************Check if tree is balanced code starts here**********************************/

bool CTree::bFnIsBalanced(node * root)
{
	if(NULL == root)
		return true ;

	int iLeftHeight = iFnHeight(root->left);
	int iRightHeight = iFnHeight(root->right);

	return (CUtils::iFnAbs(iLeftHeight - iRightHeight) <= 1 && bFnIsBalanced(root->left) && bFnIsBalanced(root->right));

}

node * CTree::nFnFindNode(node *root, int iData) 
{

	if(root == NULL)
	{
		printf("Not found\n");
		return NULL ;
	}

	if(iData == root->iData)
		return root ;
	else 
		if(iData < root->iData)
			return nFnFindNode(root->left,iData) ;
		if(iData > root->iData)
			return nFnFindNode(root->right,iData);

}

node * CTree::nFnMinValue(node *root)
{
	if(root == NULL)
		return NULL ;

	while(root->left)
		root = root->left ;

	return root ;

}
node * CTree::inOrderSuccessor(struct node *root, struct node *n)
{
    // step 1 of the above algorithm
    if( n->right != NULL )
        return nFnMinValue(n->right);
 
    struct node *succ = NULL;
 
    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->iData < root->iData)
        {
            succ = root;
            root = root->left;
        }
        else if (n->iData > root->iData)
            root = root->right;
        else
           break;
    }
 
    return succ;
}

node* CTree::vFnDeleteNode(node *root,int iData)
{
	if(NULL == root)
		return NULL;

	if(root->iData == iData)
	{
	
		if(root->left  && root->right )
		{
			node *tempRight = nFnMinValue(root->right);
			root->iData = tempRight->iData ;
			root->right = vFnDeleteNode(root->right,tempRight->iData);
			
		}
		else 
		{
			node *tempRight = root ;
			if(root->left ==NULL)
				root == root->right ;
			else
				if(root->right == NULL)
					root == root->left ;

			free(tempRight);
			tempRight = NULL ;
		
		}

	
	}
	else
		if(iData < root->iData)
			root->left = vFnDeleteNode(root->left,iData);
		else
			root->right =vFnDeleteNode(root->right,iData);

	return root ;
}

int CTree::iFnFindMinInABinaryTree(node *root) 
{
	if(!root)
		return INT_MAX ;

	int iLeft = iFnFindMinInABinaryTree(root->left);
		int iRight = iFnFindMinInABinaryTree(root->right) ;
	
		return CUtils::iFnMin(CUtils::iFnMin(iLeft,iRight),root->iData) ;



}

void CTree::vFnPrintVerticalNodes(node *root,int **iArr,int iArrLen)
{
	if(root)
	{
		*(*iArr+ iArrLen) += root->iData ;
		vFnPrintVerticalNodes(root->left,iArr,iArrLen -1 );
		vFnPrintVerticalNodes(root->left,iArr,iArrLen +1 );
	}




return ;
}



/***********************************Check if tree is balanced code ends here**********************************/

int _tmain(int argc, _TCHAR* argv[])
{
	node *root = NULL;
	//	for(int i = 0 ; i <10 ;i++)
	CTree *treeSingleton = CTree::FnSingletonImplementation();

	node *list1 = NULL ;
	list1 = (node *)malloc(sizeof(list1));
	list1->left = NULL ;
	list1->iData = 4 ;
	list1->right = NULL ;
	node *list2 = NULL ;
	list2 = (node *)malloc(sizeof(list2));
	list2->iData = 5 ;
	list2->left = NULL ;
	list2->right = NULL ;


	list1 = nFNMergeLists(&list1,&list2);

	while(list1)
	{
		//		printf("%d",list1->iData );
		list1 = list1->right ;
	}
	treeSingleton->vFnCreateTree(&root,5);
	treeSingleton->vFnCreateTree(&root,3);
	treeSingleton->vFnCreateTree(&root,8);
	/*treeSingleton->vFnCreateTree(&root,6);
	treeSingleton->vFnCreateTree(&root,10);
	treeSingleton->vFnCreateTree(&root,4);
	treeSingleton->vFnCreateTree(&root,1);*/

//	treeSingleton->vFnInorder(root);
	//	printf("The minimum at Level = 3 is %d",treeSingleton->vFnMinAtKthLevel(root,3));
//	treeSingleton->vFnLevelOrderTraversal(root);
	/*int iHeight = treeSingleton->iFnHeight(root);
	int *iArr =  (int *)malloc(sizeof(int)*(2*iHeight +1));
	memset(iArr,0,iHeight);
	treeSingleton->vFnPrintVerticalNodes(root,&iArr,iHeight);
	for(int i = 0 ; i < (2* iHeight +1) ;i++)
		printf("%d ",iArr[i]); 


	printf("The min is = %d\n",treeSingleton->iFnFindMinInABinaryTree(root));
*/
//	treeSingleton->vFnDeleteNode(root,8);

//	treeSingleton->vFnInorder(root);

	/*
	node *requiredNode = treeSingleton->nFnFindNode(root,15);
	if(requiredNode)
		printf("%d",requiredNode->iData) ;
	else
		printf("Loda\n"); */

	treeSingleton->nFnConvertTreeToDoublyList(&root);
	return 0;
}

