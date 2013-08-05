/******************************************************************************
The code is given for queue insertion using linked list implementation.
Extend the existing code by including the delete function in that.
******************************************************************************/

/******************************************************************************
keywords                :       Queue, data structures,linklist

File Name               :       dsa_queue_linklist.c

Date of Creation        :       13/11/2007

Owner                           :       Rashi Arora

Date of Modification            :

Reason for modification         :

Modifier                        :

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/********************Structure Declaration *************************/
                /* structure containing a data part and link part */
struct node
{
   int data;
   struct node *link;
};
/********************Function Declarations ***************************/
void insert(struct node **front, struct node **rear, int value);
void display(struct node *front);

/***************Function Definitions ******************/
    /* insert or filling the elements (value) in the queue list */
void insert(struct node **front, struct node **rear, int value)
{
   struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   if(NULL == temp)                /* the list is empty */
   {
      printf("No Memory available Error\n");
      exit(0);
   }
   temp->data = value;
   temp->link=NULL;
   if(*rear == NULL)
   {
      *rear = temp;
      *front = *rear;
   }
   else
      *rear = temp;
 }



                /* display the elements (value) which are filled in the queue */
void display(struct node *front)
{
        struct node *q;
        printf("\n the queue in the squencial order is : \n");
        q = front;
        while(q!=NULL)
        {
                if(q->link!=NULL)
                        printf("%d - ",q->data);
                else
                        printf("%d",q->data);
                q = q->link;
        }
}

/*********************Main Function *********************************/

int main()
{
   struct node *front=NULL,*rear = NULL;
   int n,value;
   int i =1,j=0;
   while(i==1)
   {
          printf("\nEnter your choice : \n Press 1 to insert in Queue\n Press 2 display Queue\n\t\t\t");
          scanf("%d",&j);
          switch(j)
          {
                 case 1:
                                printf("\nEnter the value to be inserted : ");
                                scanf("%d",&value);
                                insert(&front,&rear,value);
                                i =0;
                                break;
                case 2:
                                display(front);
                                i = 0;
                                break;
                  default:
                                printf("\n Invalid option ");
                }
                printf("\n Press 1 to continue \n Press 2 to exit");
                scanf("%d",&i);
                system("cls");
        }
        return 0;
}
