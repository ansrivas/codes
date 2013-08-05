/*
Another implementation of message queue where the dequeue function 
returns immediatly and does not do polling
Polling will have to be used in the client (in the user of the dequeue function)

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



void * getQueue(MessageQue * pMsgQue)
{
	void *pTemp = NULL;
	pthread_mutex_lock(&pMsgQue->queLock);
	if(!queueEmpty(pMsgQue->pQueue))
	{
		pTemp = dequeue(pMsgQue->pQueue);
	}
	pthread_mutex_unlock(&pMsgQue->queLock);
	return (pTemp);
}
