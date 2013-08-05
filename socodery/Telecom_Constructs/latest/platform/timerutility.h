#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <pthread.h>
#include "prototype.h"
#include "idgenerator.h"

typedef void * pArgCallback;

typedef void * (*callbackFunc)(void *);

typedef uIdType TimerIdType;

/*
relativetime takes the timeout period in milliseconds
*/

#define RELATIVE_TIME_GRANULARITY	1000

typedef unsigned int RelativeTime;


extern ReturnType createtimer(RelativeTime period, unsigned int expiryCount, callbackFunc pFptr, pArgCallback  pArg, TimerIdType* pTid);

extern ReturnType deletetimer(TimerIdType   tid);

extern void* maintimerloop(void* arg);


#endif
