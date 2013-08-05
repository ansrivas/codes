/*
producer consumer problem using a message queue

*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include "msgqueue.h"

/*
producer thread puts a data object into a message queue and waits for the consumer to remove it. Once the consumer removes the item, producer repeats the process.
*/

void * producer(void *parg)
{	
	char * pbuffer = NULL;
	MessageQue *pMsgQue = (MessageQue*)parg;
	while(1)
	{
		pbuffer = (char *) malloc(32);
		printf("please enter the string\n");
		scanf("%s", pbuffer);
		putQueue(pMsgQue, pbuffer);
	}
	return NULL;
	
}

/*
consumer function waits for the producer to put an object in the queue
after removing the object from the queue the consumer waits for some more item
This process is repeated again and again
*/

void * consumer(void *parg)
{
	char * pbuffer = NULL;
	MessageQue *pMsgQue = (MessageQue*)parg;
	while(1)
	{
		pbuffer = getQueue(pMsgQue);
		printf("the string entered by user : %s \n", pbuffer);
		free(pbuffer);
	}
	return NULL;
}

	
int main(void)
{
	pthread_t tid1,tid2;
	int rv1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	MessageQue * gpMq = createMsgQueue();
	if (NULL == gpMq)
	{
		printf("\n Cannot allocate queue");
		exit(0);
	}
	initMsgQueue(gpMq);
	rv1 = pthread_create(&tid1,&attr,(void *)producer,gpMq);
	if(rv1 != 0)
	{
		printf("\n Cannot create thread");
		exit(0);
	}
	rv1 = pthread_create(&tid2,&attr,(void *)consumer,gpMq);
	if(rv1 != 0)
	{
		printf("\n Cannot create thread");
		exit(0);
	}
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return(0);
}
