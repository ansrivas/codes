/******************************************************************************
  Add the functions 1) To insert a node at the end
		    2) To delete a node after searching 
******************************************************************************/

/******************************************************************************
keywords                :       linked list, data structures,insertion at beginning

File Name               :       dsa_linklist_creation.c

Date of Creation        :       25/01/2008

Owner                           :       Rashi Arora

Date of Modification            :

Reason for modification         :

Modifier                        :

*******************************************************************************/
#include<stdio.h>

/********************Structure Declaration *************************/
typedef struct node_s
{
        int data;
        struct node_s * next;
}node;

/********************Function Declarations ***************************/
node * create_beg(node *h,int val);
void printlist(node * h);

/***************Function Definitions ******************/
node * create_beg(node *h,int val)

{
        node *q,*newnode;
        newnode=(node*)malloc(sizeof(node));
	if(NULL ==newnode)
	{
		printf("Memory not available");
		exit(0);
	}
        newnode->data=val;
        if(NULL == h)
        {
        	newnode->next =NULL;
	        h=newnode;
        }
        else
        {
                newnode->next=h;
                h=newnode;
        }
        return h;
}

void printlist(node * h)
{
        node *p;
        if(NULL == h)
                printf("list is empty");
        else
        {
                for(p=h;p!=NULL;p=p->next)
                printf("%d\n",p->data);
        }
}


/*********************Main Function *********************************/
int main()
{
        node *head;
        head=NULL;
        int a,b,i;
        printf("\nEnter how many nodes");
        scanf("%d",&b);
        for(i=1;i<=b;i++)
        {
                printf("\nEnter the value to be inserted\t");
                scanf("%d",&a);
                head=create_beg(head,a);
        }
        printf("\nList is\n");
        printlist(head);
        free(head);
}

