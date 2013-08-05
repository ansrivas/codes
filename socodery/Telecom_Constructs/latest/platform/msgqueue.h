#ifndef MSG_QUE_H
#define MSG_QUE_H

#include <stdio.h>
#include <pthread.h>
#include "prototype.h"
#include "queue.h"

typedef struct 
{
	Queue	        * pQueue;
	pthread_mutex_t   queLock;	
	pthread_cond_t    queCond;
}MessageQue;

extern ReturnType putqueue(MessageQue * pMsgQue, void *pData);

extern void * getqueue(MessageQue * pMsgQue);

extern void initmsgqueue(MessageQue * pMsgQue);

extern MessageQue * createmsgqueue();

extern void deletemsgqueue(MessageQue *pMsgQue);

#endif
