/******************************************************************************
File Name               :       binary_search_tree.c

Date of Creation        :       15/10/2009

Owner                           :       Rashi Arora

Date of Modification            :08/07/2010

Reason for modification         : Added some functions

Modifier                        : Rashi Arora

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

/*******************STRUCTURE DECLARATION****************************/
typedef struct node_s
{
        int data;
        struct node_s *left;
        struct node_s *right;
}node;

/******************FUNCTION DEFINITIONS ****************************/

/* Function to allocate a new node */
node* newnode(int value)
{
        node * newn;
        newn = (node *)malloc(sizeof(node));
        if(NULL == newn)
        {
                printf("\n Memory not available");
                exit(1);
        }
        newn->data = value;
        newn->left = NULL;
        newn->right = NULL;
        return newn;
}

/* Function to insert a node in the tree */
void insert(node **rootptr,int item)
{
        node * current,*parent;
        if(NULL == *rootptr)
        {
                *rootptr=newnode(item);
                printf("\nElement inserted at the root");
                return ;
        }
        else
        {
                parent = *rootptr;
                current = *rootptr;
                while(current!=NULL)
                {
                        parent = current;
                        if(item < current->data)
                                current = current->left;
                        else if(item > current->data)
                                current = current->right;
                        else
                        {
                                printf("\nCannot insert duplicate element ");
                                return;
                        }
                }
                if(item < parent->data)
                {
                        parent->left = newnode(item);
                        printf("\nElement inserted at the left");
                }
                else
                {
                        parent->right = newnode(item);
                        printf("\n Element inserted at the right");
                }
        }
        return;
}

/* Function to display the tree using inorder traversal */
void inorder(node * tree)
{
        if (NULL == tree)
                return;
        inorder(tree->left);
        printf("\n%d",tree->data);
        inorder(tree->right);
}

/*  Main function */
int main()
{
        node *root =NULL;
        int choice;
        do
        {
                printf("\n\n1: Insert an element in the tree");
                printf("\n2: Display inorder traversal ");
                printf("\n3: exit\n");
                scanf("\n%d",&choice);
                switch(choice)
                {
                        case 1: {
                                   int item;
                                   printf("\nEnter a node to be inserted ");
                                   scanf("%d",&item);
                                   insert(&root,item);
                                   break;
                                }
                        case 2: {
                                  inorder(root);
                                  break;
                                }
                }
        }while(choice!=3);
        return 0;
}

