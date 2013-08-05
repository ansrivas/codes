/******************************************************************************
keywords                :       dsa, hash table, list

File Name               :       dsa_hash_table_list_1_0.c

Date of Creation        :       12/11/2007

Owner                   :       Sibu Cyriac

Date of Modification    :

Reason for modification :

Modifier                :

*******************************************************************************/

/******************************************************************************
This program creates a hash table as a set of linked lists
Here 10 pointers are used to address 10 linked lists which form a hash table
******************************************************************************/


#include<stdio.h>
#include<malloc.h>

int main()
{
	int i,k,num;
	struct node
	{
		int n;
		struct node* next;
	};

	struct node *temp,*p1,*AOP[10];

	for(i=0;i<10;i++)
		AOP[i]= NULL;
	for( i=0;i<20;i++)
	{
		scanf("%d", &num);
		k=num%10;
		p1=( struct node*) malloc ( sizeof(struct node));

		p1->n=num;
		p1->next=NULL;

		if(AOP[k]==NULL)
			AOP[k]=p1;
		else
		{
			p1->next=AOP[k];
			AOP[k]=p1;
		}
	}

	for(i=0;i<10;i++)
	{
		temp=AOP[i];
		printf("List number   %d :", i);
		
		while(temp!=NULL)
		{
			printf("%5d",temp->n);
			temp=temp->next;
		}
		printf("\n");
	}
}


