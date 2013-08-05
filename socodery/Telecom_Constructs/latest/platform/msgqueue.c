/*
This file has the code for messagequeue(packet queue) implementation using a mutex variable and a condition variable
It uses the functions written for the implementation of the queue
A very important point is why have we used the "while statement " in the dequeue function and not an if condition.
while(queueEmpty(pMsgQue->pQueue))
{
	pthread_cond_wait(&(pMsgQue->queCond),&(pMsgQue->queLock));
}

'while' is required if multiple client threads are waiting on the same 
message queue for a message and if more than one of them wake up after a message is inserted in the queue.
Let us assume that one message is inserted in the queue and multiple threads are woken upi after that. signal() call may wake up multiple threads.
One of them will be able to acquire the lock and remove the message and the queue will become empty. 
The second thread will acquire the lock after the first thread releases it and 
the second thread must check again if the queue still has any messages or not. It is necessary to have the 'while' condition to handle this scenario.

'if' condition is suffcient if only one thread is waiting for the messages on a queue since it will wake up only if there is a message in the queue. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
#include "msgqueue.h"


/*
Initializes the message queue data structure
*/ 

void initmsgqueue(MessageQue * pMsgQue)
{
	if (NULL == pMsgQue)
	{	
		initqueue(pMsgQue->pQueue);
		pthread_mutex_init(&(pMsgQue->queLock), NULL);
		pthread_cond_init(&(pMsgQue->queCond), NULL);
	}
}


/*
Creates a new message queue 
*/ 
MessageQue * createmsgqueue()
{
	MessageQue *pMsgQue = NULL;
	pMsgQue = (MessageQue *) malloc(sizeof(MessageQue));
	if (NULL != pMsgQue)
	{
		pMsgQue->pQueue = (Queue *) malloc(sizeof(Queue));
	}
	return pMsgQue;
}


/*
deletes a message queue 
*/ 
void deletemsgqueue(MessageQue *pMsgQue)
{
	deletequeue(pMsgQue->pQueue);
	free(pMsgQue);
	return;
}




/*
Puts a new message in the message queue
After successfully putting the message in the queue it wakes up atleast one of the client threads waiting for the message
It returns success if it is able to enqueue the message successfully else it returns failure
*/ 

ReturnType putqueue(MessageQue * pMsgQue, void *pData)
{
	ReturnType retval = FAILURE;
	int apiretval = 0;
	apiretval = pthread_mutex_lock(&pMsgQue->queLock);
	if (0 != apiretval)
	{
		return retval;
	}
	retval = enqueue(pMsgQue->pQueue, pData);
	if (SUCCESS == retval)
		pthread_cond_signal(&pMsgQue->queCond);
	pthread_mutex_unlock(&pMsgQue->queLock);
 	return retval;
}



/*
Removes a message from the message queue
The function makes the calling thread sleep if the the queue is empty
The function returns the object removed from the queue
*/ 

void * getqueue(MessageQue * pMsgQue)
{
	void *pTemp = NULL;
	int apiretval = 0;
	apiretval = pthread_mutex_lock(&pMsgQue->queLock);
	if (0 != apiretval)
	{
		return pTemp;
	}
	while(queueempty(pMsgQue->pQueue))
	{
		pthread_cond_wait(&(pMsgQue->queCond),&(pMsgQue->queLock));
	}
	pTemp = dequeue(pMsgQue->pQueue);
	pthread_mutex_unlock(&pMsgQue->queLock);
	return (pTemp);
}
