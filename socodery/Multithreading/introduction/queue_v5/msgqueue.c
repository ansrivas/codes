/*
This is a semaphore based implementation of message queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "queue.h"
#include "msgqueue.h"


void initMsgQueue(MessageQue * pMsgQue, unsigned int sizeOfQue)
{
	initQueue(pMsgQue->pQueue);
	pthread_mutex_init(&pMsgQue->queLock, NULL);
	sem_init(&pMsgQue->consumer, 0, 0);
	if (sizeOfQue > 0)
		sem_init(&pMsgQue->producer, 0, sizeOfQue);
	else
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

	/*Think - why the lock is used*/
	pthread_mutex_lock(&pMsgQue->queLock);
	retval = enqueue(pMsgQue->pQueue, pData);
	pthread_mutex_unlock(&pMsgQue->queLock);
	/*The lock has been used so that there are no conflicts in the queue 
	semaphore is primarily used for synchronization/signaling between 
	producer-consumer*/

	/*
	In case of success the consumer should be woken up, however if
	enqueue is not successful then the producer semaphore is reset to
	its original value so that another or the same producer can try to
	put the item in the queue after some time
	*/
	if (SUCCESS == retval)
		sem_post(&pMsgQue->consumer);
	else
		sem_post(&pMsgQue->producer);
 	return retval;
}




void * getQueue(MessageQue * pMsgQue)
{
	void *pTemp;
	sem_wait(&pMsgQue->consumer);
	pthread_mutex_lock(&pMsgQue->queLock);
	pTemp = dequeue(pMsgQue->pQueue);
	pthread_mutex_unlock(&pMsgQue->queLock);
	sem_post(&pMsgQue->producer);
	return (pTemp);
}
