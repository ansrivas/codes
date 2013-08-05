/*
Thread Manager source code file
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "prototype.h"
#include "msgqueue.h"
#include "threadmgr.h"

/*Currently this function is staring only the standalone thread*/

ReturnType createthread(ThreadData *pthrobj)
{
	int              retval;
	pthread_attr_t   threadatrr;

	retval = pthread_attr_init(&threadatrr); 
	if (0 != retval)
	{
		return FAILURE;
	}
	if (STANDALONE == pthrobj->type)
	{
		retval = pthread_create(&(pthrobj->tid), &threadatrr, pthrobj->execEnv.fcnObj.pFptr, pthrobj->execEnv.fcnObj.pArg);
		if (0 != retval)
		{
			pthrobj->state        = INACTIVE;
			pthrobj->available    = FREE;
			return FAILURE;
		}
	}
	pthrobj->state        = ACTIVE;
	pthrobj->available    = BUSY;
	return SUCCESS;
}


void stopthread(ThreadData * pthrobj)
{
	pthread_kill(pthrobj->tid, 9);
}


/*This function is starting only a fixed type of pool threads*/

ReturnType startthread(pStartRoutine startroutine, ThreadData * pthrobj)
{
	int              retval;
	pthread_attr_t   threadatrr;

	retval = pthread_attr_init(&threadatrr); 
	if (0 != retval)
	{
		return FAILURE;
	}

	retval = pthread_create(&(pthrobj->tid), &threadatrr, startroutine, pthrobj);
	if (0 != retval)
	{
		return FAILURE;
	}
	return SUCCESS;
}



/*
startup thread routine in which a thread waits on a message queue for executing a function
*/

static void * thrpoolroutine(void *ptarg)
{
	void           	*retp     = NULL;
	Functor 	*pFuncObj = NULL;
	ThreadData	*tpdata   = (ThreadData *)ptarg;
	
	while(1)
	{
		tpdata->available = FREE;
		pFuncObj = (Functor*)getqueue(tpdata->execEnv.pQid);
		tpdata->available = BUSY;
		if(NULL == pFuncObj)
		{
			continue;
		}
		retp = pFuncObj->pFptr(pFuncObj->pArg);
	}
}


/*
it creates a pool of threads and all these threads wait for messages on a single message queue 
*/

ReturnType createanonymousthreadpool(int nthreads, MessageQue **pqid, ThreadPool ** pthrpool)
{
	int             retval;
	int             lindex;
        ThreadData      *temp;

	*pqid = createmsgqueue();
	if (NULL == *pqid)
	{
		return FAILURE;
	}
	initmsgqueue(*pqid);

	*pthrpool = malloc(sizeof(ThreadPool));
	if (NULL == pthrpool)
	{
		deletemsgqueue(*pqid);
		return FAILURE;
	}
	(*pthrpool)->numThreads = 0;
	(*pthrpool)->pThrList = malloc(sizeof(ThreadData)*nthreads);
	if (NULL == (*pthrpool)->pThrList)
	{
		destroythreadpool(*pthrpool);
		deletemsgqueue(*pqid);
		return FAILURE;
	}

	/*
	Initialize the threads in the thread pool 
	*/
	(*pthrpool)->numThreads = nthreads;
	temp = (*pthrpool)->pThrList;
	for(lindex = 0;lindex < nthreads;lindex++)
	{
		temp->state        = INACTIVE;
		temp->available    = FREE;
		temp->type         = THREADPOOL;
		temp->execEnv.pQid = *pqid;
		temp++;
	}

	/*
	start the threads in the pool
	*/
	temp = (*pthrpool)->pThrList;
	for(lindex = 0; lindex < nthreads; lindex++)
	{
		retval=startthread(thrpoolroutine, temp);
       		if(SUCCESS == retval)
		{
			temp->state = ACTIVE;
		}
		temp++;
	}
	return SUCCESS;
}


void destroythreadpool(ThreadPool      *pthrpool)
{
	int           lindex;
	ThreadData  * temp = pthrpool->pThrList;
	for (lindex = 0; lindex < pthrpool->numThreads; lindex++)
	{
		if (ACTIVE == temp->state)
			stopthread(temp);
		free(temp);
		temp++;
	}
	free(pthrpool);
}


/*
it creates a pool of threads 
Every thread has its own message queue where it waits for messages

ReturnType createthreadpool(int nThreads, ThreadData ** pThrData)
{
	int             retval;
	int             lindex;
	MessageQue      *pqid;
        ThreadData      *ptdata;
        ThreadData      *temp;

	ptdata = malloc(sizeof(ThreadData)*nThreads);
	if (NULL == ptdata)
	{
		return FAILURE;
	}
	temp = ptdata;
	for(lindex = 0;lindex < nThreads;lindex++)
	{
		temp->available = FREE;
		temp->state     = INACTIVE;
		temp->qid       = createmsgqueue();
		if (NULL == temp->qid)
		{
			return FAILURE;
		}
		initmsgqueue(temp->qid);

		retval=createthread(&(temp->tid), thrpoolroutine,(void *)temp);
       		if(FAILURE == retval)
		{
			destroythreadpool(ptdata);
			deletemsgqueue(*pqid);
			free(ptdata);
			return FAILURE;
		}
		temp->state     = ACTIVE;
		temp++;
	}
	*pThrData = ptdata;
	return SUCCESS;
}
*/
