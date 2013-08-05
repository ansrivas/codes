/******************************************************************************
keywords                :       linked list, data structures,insertion at beginn
ing

File Name               :       dsa_linklist_creation.c

Date of Creation        :       25/01/2008

Owner                           :       Rashi Arora

Date of Modification            :

Reason for modification         :

Modifier                        :

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

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
        node *newnode;
        newnode=(node*)malloc(sizeof(node));
        newnode->data=val;
        if(h==NULL)
        {
                h=newnode;
		h->next=NULL;

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
        if(h==NULL)
                printf("list is empty");
        else
        {
                for(p=h;p!=NULL;p=p->next)
                printf("%d\n",p->data);
        }
}
void free_list(node *head)
{
        node * temp;
        while(NULL != head)
        {
                temp=head;
                head=head->next;
                free(temp);
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
        free_list(head);
        return 0;
}

