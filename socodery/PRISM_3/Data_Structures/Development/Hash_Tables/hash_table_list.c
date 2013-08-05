/******************************************************************************
File Name               :       hash_table_list.c

Date of Creation        :       12/11/2007

Owner                   :       Sibu Cyriac

Date of Modification    :	08/07/2010

Reason for modification :	coding guidelines added

Modifier                :	Rashi Arora

*******************************************************************************/

/******************************************************************************
A program to implement hash table of size 10 where collisions are resolved using chaining.
******************************************************************************/


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int n;
	struct node* next;
};

int main()
{
	int i,index,num;
	struct node *temp,*new_node;
	struct node *hash_table_AOP[10]; /* hash table*/

	for(i=0;i<10;i++)
		hash_table_AOP[i]= NULL;
	
	for( i=0;i<20;i++)
	{
		printf("\nEnter the number to be inserted in the hash table ");
		scanf("%d", &num);
		index = num % 10; /* Hash function */

		/* Allocate a new node and insert the data entered in it */
		new_node = ( struct node*) malloc ( sizeof(struct node));
		if( NULL == new_node)
		{
			printf("\nMemory not allocated ");
			exit(1);
		}
		new_node->n = num;
		new_node->next = NULL;

		/* Insert this new node at the index calculated using hash function */
		if(NULL == hash_table_AOP[index])
		{
			/* No collision at the specified index in hash table */
			hash_table_AOP[index] = new_node;
		}
		else
		{
			/*
		        Collision at the index so it is resolved using chaining. 			New node is added at the begining of the list 
			*/
			new_node->next = hash_table_AOP[index];
			hash_table_AOP[index] = new_node;
		}
	}
	/* Print the hash table */
	for(i=0;i<10;i++)
	{
		temp = hash_table_AOP[i];
		printf("List number   %d :", i);
		
		while(temp != NULL)
		{
			printf("%5d",temp->n);
			temp=temp->next;
		}
		printf("\n");
	}
	/* Free the memory */
	for(i=0;i<10;i++)
	{
		struct node * temp1;
		temp = hash_table_AOP[i];
		while(temp != NULL)
		{
			temp1 = temp;
			temp = temp->next;
			free(temp1);
		}
		printf("\n");
	}
	return 0;
}


