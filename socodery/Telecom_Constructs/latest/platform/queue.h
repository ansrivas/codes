#ifndef QUE_H
#define QUE_H

#include <stdio.h>
#include "prototype.h"


typedef struct QueNode
{
	void * pObject;
 	struct QueNode *next;
}QueNode;

typedef struct 
{
	struct QueNode	*head;
	struct QueNode	*rear;
}Queue;


extern void initqueue(Queue * lpQue);

extern void deletequeue(Queue * lpQue);

extern unsigned int queueempty(Queue * lpQue);

extern void * dequeue(Queue * lpQue);

extern ReturnType enqueue(Queue * lpQue, void * pdata);

#endif
