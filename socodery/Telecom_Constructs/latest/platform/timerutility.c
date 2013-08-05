/*
Timer Module : Implemented using functions provided by posix thread library
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <errno.h>
#include <pthread.h>
#include "threadmgr.h"
#include "idgenerator.h"
#include "list.h"
#include "timerutility.h"


typedef struct timespec AbsTime;

typedef struct Timer
{
	AbsTime 		timeout;
	RelativeTime 		period;
	callbackFunc		pCallback;
	pArgCallback		pCallbackArg;
	unsigned int		expCounter;
}Timer;

int searchinserttimer(pListNode *pListHead, pListNode lpNode);

#define greater(time1, time2) ((time1.tv_sec < time2.tv_sec) ? 1 : ((time1.tv_sec > time2.tv_sec) ? 0 :((time1.tv_nsec >= time2.tv_sec) ? 0 : 1)))

List			gTimerList = {NULL, searchinserttimer, NULL};
pthread_mutex_t		timerListLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t 		timeoutOrNotEmpty = PTHREAD_COND_INITIALIZER;


int searchinserttimer(pListNode *pListHead, pListNode lpNode)
{
	int         position = 1;
	pListNode   pTemp = *pListHead;

	Timer	    *pObject = NULL;
	Timer       *pTimer  = (Timer*)lpNode->pObject;

	while (NULL != pTemp)
	{
		pObject = (Timer*)(pTemp->pObject);
		if (greater(pTimer->timeout, pObject->timeout))
			break;
		position++;
		pTemp = pTemp->next;
	}

	if (1 == position) 
	{
		lpNode->prev = NULL;
		lpNode->next = *pListHead;
		*pListHead   = lpNode;
	}
	else
	{
		lpNode->prev = pTemp->prev;
		pTemp->prev  = lpNode;
		lpNode->next = pTemp;
	}
	return position;
}


int inserttimer(Timer * pTimer, TimerIdType * pTid)
{
	ReturnType	retval;
	int 		position;

	retval = insert(&gTimerList, pTimer, &position, (KeyType*)pTid);
	if (SUCCESS == retval)
		return position;
	else
		return 0;
}



ReturnType populatetimerobj(Timer * ptimer, RelativeTime period, unsigned int expiryCount, callbackFunc pFptr, pArgCallback pArg)
{
	int 		sysretval;
	struct timeval	tv;
	unsigned int microsec;
	unsigned int sec;

	sysretval = gettimeofday(&tv, NULL);
	if (0 != sysretval)
	{
		return FAILURE;
	}
	sec = tv.tv_sec + period/RELATIVE_TIME_GRANULARITY;
	microsec = tv.tv_usec + (period % RELATIVE_TIME_GRANULARITY) * 1000;
	if(microsec >= 1000000)
	{
		sec++;
		microsec -= 1000000;
	}

	ptimer->timeout.tv_sec  = sec;
	ptimer->timeout.tv_nsec = microsec * 1000;

	ptimer->period          = period;
	ptimer->pCallback       = pFptr;
	ptimer->pCallbackArg    = pArg;
	ptimer->expCounter      = expiryCount;

	return SUCCESS;
}



ReturnType clonetimer(Timer * lptm, KeyType * pTid)
{
	ReturnType  retval;
	Timer	    *pTimer  = NULL;
	int         position = 0;

	pTimer = (Timer *) malloc(sizeof(Timer));

	retval = populatetimerobj(pTimer, lptm->period, lptm->expCounter, lptm->pCallback, lptm->pCallbackArg);
	if (FAILURE == retval)
	{
		return FAILURE;
	}

	retval = insert(&gTimerList, pTimer, &position, pTid);
	return retval;
}


ReturnType createtimer(RelativeTime period, unsigned int expiryCount, callbackFunc pFptr, pArgCallback  pArg, TimerIdType* pTid)
{
	ReturnType  retval;
	Timer	   *pTimer   = NULL;
	int         position = 0;

	*pTid = -1;

	pTimer = (Timer *) malloc(sizeof(Timer));
	retval = populatetimerobj(pTimer, period, expiryCount, pFptr, pArg);
	if (FAILURE == retval)
	{
		return FAILURE;
	}

	pthread_mutex_lock(&timerListLock);
	position = inserttimer(pTimer, pTid);
	if (1 == position)
	{
		pthread_cond_signal(&timeoutOrNotEmpty);
	}
	pthread_mutex_unlock(&timerListLock);
	if (0 == position)
	{
		return FAILURE;
	}
	return SUCCESS;
}


/*
FUNCTION NAME : deleteTimer
DESCRIPTION :   This function deletes the timer from the timer list
*/

ReturnType deletetimer(TimerIdType   tid)
{
	int   position = 0;

	pthread_mutex_lock(&timerListLock);
	delete(&gTimerList, (KeyType)tid, &position);
	if (1 == position)
	{
		pthread_cond_signal(&timeoutOrNotEmpty);
	}
	pthread_mutex_unlock(&timerListLock);
	if (position > 0)
		return SUCCESS;
	else
		return FAILURE;
}



/*
FUNCTION NAME : maintimerloop
DESCRIPTION   :	This function runs in a separate thread. Sleeps on a sorted timer list and calls the callback function on timer expiry.
*/

void* maintimerloop(void* arg)
{
	int 			deleteKeyFlag;
	int 			retcode;
//	pthread_t 		threadId;
//	ThreadID 		threadId;
	Timer			*ptm;
	pListNode		pTemp;
	pListNode		pFront;

	while (1)
	{
		deleteKeyFlag = 1;
		pthread_mutex_lock(&timerListLock);
		pFront = gTimerList.pHead;
		if(NULL == pFront)
		{
			retcode = pthread_cond_wait(&timeoutOrNotEmpty, &timerListLock);
		}
		else
		{
			retcode = pthread_cond_timedwait(&timeoutOrNotEmpty, &timerListLock, &(((Timer*)pFront->pObject)->timeout));
		}
		if (ETIMEDOUT == retcode)
		{
			pTemp = gTimerList.pHead;
			ptm   = (Timer*)pTemp->pObject;
			gTimerList.pHead = gTimerList.pHead->next;

			/*
			periodic timer which has to expire more than ones 
			it includes the timer which has to expire indefinitely 
			till it is deleted explicitely from the list, this one 
			is identified by value 0 in expCounter field
			update the timer object with the next expiry time
			*/
			if (1 != ptm->expCounter)
			{
				deleteKeyFlag = 0;
				if (0 != ptm->expCounter)
					ptm->expCounter--;
				clonetimer(ptm, &pTemp->key);
			}
		}
		pthread_mutex_unlock(&timerListLock);
		if (ETIMEDOUT == retcode)
		{
			/*
			invoke timer expiry callback function in a 
			separate thread
			*/
			//createthread(&threadId, ptm->pCallback, ptm->pCallbackArg);
			//pthread_create(&threadId, NULL, ptm->pCallback, ptm->pCallbackArg);
			ptm->pCallback(ptm->pCallbackArg);
			if (deleteKeyFlag)
				freekey(pTemp->key);
			free(ptm);
			free(pTemp);
		}
	}
}
