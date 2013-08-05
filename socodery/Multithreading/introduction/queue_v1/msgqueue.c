/*
This file has the code for messagequeue(packet queue) implementation using just a mutex variable
The code written here uses a polling mechanism

Why do you need a mutex in the message queue? why not use the simple queue implementation without mutex as provided in the queue.c file

mutex is required because atleast two threads(producer and consumer) will be accessing the queue and it is possible that queue goes in an inconsitent state because of that

for example consider the following lines from the enqueue and dequeue funtions

//sample code from enqueue starts
	if (NULL == lpQue->head)
	{
		lpQue->head = pNode;
		lpQue->rear = pNode;
	}
//sample code from enqueue ends

//sample code from dequeue starts
	if (NULL != lpQue->head)
	{
		pTemp = lpQue->head;
		lpQue->head = lpQue->head->next;
		if (pTemp == lpQue->rear)
			lpQue->rear = NULL;
		pData = pTemp->pObject;
		free(pTemp);
	}
//sample code from dequeue ends

if a producer thread is accessing the enqueue function and a consumer thread 
is accessing the dequeue function smultaneosuly there is a possibility that 
it will end up in race condition.
Consider the scneario when the producer thread is descheduled before executing the statement:
		lpQue->rear = pNode;

*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
#include "msgqueue.h"


void initMsgQueue(MessageQue * pMsgQue)
{
	initQueue(pMsgQue->pQueue);
	pthread_mutex_init(&(pMsgQue->queLock), NULL);
}

MessageQue * createMsgQueue()
{
	MessageQue *pMsgQue = NULL;
	pMsgQue = (MessageQue *) malloc(sizeof(MessageQue));
	pMsgQue->pQueue = (Queue *) malloc(sizeof(Queue));
	return pMsgQue;
}


returntype putQueue(MessageQue * pMsgQue, void *pData)
{
	returntype retval = FAILURE;
	pthread_mutex_lock(&pMsgQue->queLock);
	retval = enqueue(pMsgQue->pQueue, pData);
	pthread_mutex_unlock(&pMsgQue->queLock);
 	return retval;
}


//This implementation has a tight loop and very inefficient polling mechanism
void * getQueue(MessageQue * pMsgQue)
{
	void *pTemp = NULL;
	while(1)
	{
		if (queueEmpty(pMsgQue->pQueue))
			continue;
		pthread_mutex_lock(&pMsgQue->queLock);
		if (!queueEmpty(pMsgQue->pQueue))
		{
			pTemp = dequeue(pMsgQue->pQueue);
			pthread_mutex_unlock(&pMsgQue->queLock);
			return (pTemp);
		}
		pthread_mutex_unlock(&pMsgQue->queLock);
	}
}
