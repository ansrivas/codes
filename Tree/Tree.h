#ifndef __TREE__
#define __TREE__



#include <string.h>

struct node 
{
	int iData ;
	struct node *left ;
	struct node *right; 
} ;
typedef struct node node ;

class CTree
{
	static CTree * mySingleton ;
	CTree()
	{
	
	}
	CTree(CTree &)
	{
	
	}

	CTree & operator=(CTree &)
	{
	
	
	}
public :
	static CTree * FnSingletonImplementation();
	

	/***************************************************
	Tree related APIs
	***************************************************/
	node * nFnCreateMinHeightTreeUsingArray(int iArr[],int iLow, int iHigh);
	bool bFnIsIdentical(node *root1, node *root2);
	bool bFnIsSubTree(node *root1, node* root2);
	node* iFnReturnKthSmallestInBST(node *root, int *k);
	void vFnLevelOrderTraversal(node * root);
	int iFnDiameterOfTree(node *root);
	int vFnMinAtKthLevel(node * root,int k);
	void vFnPrintNodesAtKDistance(node *root);
	int iFnHeight(node *root);
	node * nFnCreateNode(int iData);
	void vFnCreateTree(node **root,int iData);
	void vFnInorder(node *root);
	bool bFnIsBalanced(node * root);
	node* nFnConvertTreeToDoublyList(node **root);
	node * nFnFindNode(node *root, int iData) ;
	node * nFnMinValue(node  *root);
	node * inOrderSuccessor( node *root,  node *n);
	node * vFnDeleteNode(node *root,int iData);
	int iFnFindMinInABinaryTree(node *root) ;
	void vFnPrintVerticalNodes(node *root,int **iArr,int iArrLen) ;



};


CTree * CTree::mySingleton  = NULL;

#endif
