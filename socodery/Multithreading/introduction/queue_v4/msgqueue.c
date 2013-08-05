/*
This is a semaphore based implementation of message queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "queue.h"
#include "msgqueue.h"


void initMsgQueue(MessageQue * pMsgQue)
{
	initQueue(pMsgQue->pQueue);
	sem_init(&pMsgQue->consumer, 0, 0);
	sem_init(&pMsgQue->producer, 0, 1);
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
	sem_wait(&pMsgQue->producer);
	retval = enqueue(pMsgQue->pQueue, pData);

	/*
	In case of success the consumer should be woken up, however if 
	enqueue is not successful then the producer semaphore is reset to 
	its original value so that another or the same producer can try to 
	put the item in the queue after some time 
	*/
	if (SUCCESS == retval)
		sem_post(&pMsgQue->consumer);
	else
		//possibly raise an error also
		sem_post(&pMsgQue->producer);
 	return retval;
}




void * getQueue(MessageQue * pMsgQue)
{
	void *pTemp;
	sem_wait(&pMsgQue->consumer);
	pTemp = dequeue(pMsgQue->pQueue);
	sem_post(&pMsgQue->producer);
	return (pTemp);
}
