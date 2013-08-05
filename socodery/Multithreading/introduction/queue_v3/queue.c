#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"


void initQueue(Queue * lpQue)
{
	lpQue->head = NULL;
	lpQue->rear = NULL;
}

unsigned int queueEmpty(Queue * lpQue)
{
	if (NULL == lpQue->head)
		return 1;
	else
		return 0;
}


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


returntype enqueue(Queue * lpQue, void * pData)
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

