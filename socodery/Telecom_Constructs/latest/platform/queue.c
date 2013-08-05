#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"

/*

Initializes the queue by 
initializing the head and the rear pointers of the queue object

*/
void initqueue(Queue * lpQue)
{
	lpQue->head = NULL;
	lpQue->rear = NULL;
}


void deletequeue(Queue * lpQue)
{
}

/*

Checks if the queue is empty or not
Returns 1 if the queue is empty and 0 when queue is not empty

*/
unsigned int queueempty(Queue * lpQue)
{
	if (NULL == lpQue->head)
		return 1;
	else
		return 0;
}


/*

Returns the data item stored at the head of the queue 
Returns NULL if the queue is empty 

*/
void * dequeue(Queue * lpQue)
{
	void    * pData = NULL;
	QueNode * pTemp;

	if (NULL != lpQue->head)
	{
		pTemp = lpQue->head;
		lpQue->head = lpQue->head->next;
		if (pTemp == lpQue->rear)
			lpQue->rear = NULL;
		pData = pTemp->pObject;
		free(pTemp);
	}
	return (pData);
}


/*

Adds an item at the end/rear of the queue
Returns SUCCESS if the item is added successfully
Returns FAILURE if the item can't be added

*/
ReturnType enqueue(Queue * lpQue, void * pData)
{
	QueNode *pNode;
   	pNode = (QueNode *)malloc(sizeof(QueNode));
	if (NULL == pNode)
	{
		return FAILURE;
	}
        pNode->pObject = pData;
	pNode->next = NULL;

	if (NULL == lpQue->head)
	{
		lpQue->head = pNode;
		lpQue->rear = pNode;
	}
	else
	{
		lpQue->rear->next = pNode;
		lpQue->rear = pNode;
	}
	return SUCCESS;
}
