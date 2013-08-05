/*
Thread manager Header File
*/
#ifndef THREAD_MGR_H
#define THREAD_MGR_H

#include <pthread.h>
#include "prototype.h"
#include "msgqueue.h"

typedef pthread_t ThreadID;

typedef enum 
{
	INACTIVE = 0,
	ACTIVE
}RunStatus;

typedef enum 
{
	THREADPOOL = 0,
	STANDALONE
}ThreadType;

typedef enum
{
	BUSY = 0,
	FREE
}AvailabilityStatus;

typedef void * (*GenericRoutine)(void *);

typedef GenericRoutine pStartRoutine;

typedef struct Functor
{
	GenericRoutine	pFptr;
	void 		*pArg;
} Functor;

typedef struct ThreadData
{
	ThreadID		tid;
	RunStatus		state;
	AvailabilityStatus	available;
	ThreadType              type;
	union {
		Functor			fcnObj;
		MessageQue		*pQid;
	}execEnv;
}ThreadData;


typedef struct ThreadPool
{
	unsigned int		  numThreads;
	ThreadData		* pThrList;
}ThreadPool;

extern void destroythreadpool(ThreadPool *);

ReturnType createanonymousthreadpool(int, MessageQue **, ThreadPool **);

extern ReturnType createthread(ThreadData *pthrobj);

#endif
