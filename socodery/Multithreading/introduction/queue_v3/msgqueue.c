/*
This file has the code for messagequeue(packet queue) implementation using a mutex variable and a condition variable
A very important point is why have we used the "while statement " in the dequeue function and not an if condition.

while(queueEmpty(pMsgQue->pQueue))
{
	pthread_cond_wait(&(pMsgQue->queCond),&(pMsgQue->queLock));
}

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
	pthread_cond_init(&(pMsgQue->queCond), NULL);
}

MessageQue * createMsgQueue()
{
	MessageQue *pMsgQue = NULL;
	pMsgQue = (MessageQue *) malloc(sizeof(MessageQue));
	if (NULL != pMsgQue)
	{
		pMsgQue->pQueue = (Queue *) malloc(sizeof(Queue));
	}
	return pMsgQue;
}


returntype putQueue(MessageQue * pMsgQue, void *pData)
{
	returntype retval = FAILURE;
	pthread_mutex_lock(&pMsgQue->queLock);
	retval = enqueue(pMsgQue->pQueue, pData);
	if (SUCCESS == retval)
		pthread_cond_signal(&pMsgQue->queCond);
	pthread_mutex_unlock(&pMsgQue->queLock);
 	return retval;
}




void * getQueue(MessageQue * pMsgQue)
{
	void *pTemp;
	pthread_mutex_lock(&pMsgQue->queLock);
	while(queueEmpty(pMsgQue->pQueue))
	{
		pthread_cond_wait(&(pMsgQue->queCond),&(pMsgQue->queLock));
	}
	pTemp = dequeue(pMsgQue->pQueue);
	pthread_mutex_unlock(&pMsgQue->queLock);
	return (pTemp);
}
