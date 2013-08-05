/******************************************************************************
keywords		:       linked list, data structures, reversing

File Name		:       dsa_linklist_reversing.c

Date of Creation	:       13/11/2007

Owner                   	:       Rashi Arora

Date of Modification    	:

Reason for modification 	:

Modifier                	:

*******************************************************************************/
#include<stdio.h>

/********************Structure Declaration *************************/
typedef struct node_s
{
        int data;
        struct node_s * next;
}node;

/********************Function Declarations ***************************/
node * create(node *h,int val);
void printlist(node * h);
void del(node *h);
node * reverse(node *h);
node * sort(node *h,int num);


/***************Function Definitions ******************/
node * create(node *h,int val)

{
        node *q,*newnode;
        newnode=(node*)malloc(sizeof(node));
        newnode->data=val;
        if(h==NULL)
        {
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
        if(h==NULL)
                printf("list is empty");
        else
        {
                for(p=h;p!=NULL;p=p->next)
                printf("%d\n",p->data);
        }
}

node * reverse(node * h)
{
        node *curr,*new,*p;
        curr=h;
        new=h->next;
        p=NULL;
        while(new!=NULL)
        {
                curr->next=p;
                p=curr;
                curr=new;
                new=curr->next;
        }
        curr->next=p;
        h=curr;
        return h;
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
                head=create(head,a);
        }
        printf("\nList is\n");
        printlist(head);
        head=reverse(head);
        printf("\n List after reversing is\n");
        printlist(head);
}





