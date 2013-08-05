#include <stdio.h>
#include <pthread.h>
#include "prototype.h"
#include "platform.h"
#include "queue.h"
#include "msgqueue.h"
#include "threadmgr.h"
#include "timerutility.h"
#include "connmgr.h"
#include "msgmgr.h"

ThreadData timerthread;


ReturnType initializeplatform()
{
	ReturnType retval = FAILURE;

	timerthread.state             = INACTIVE;
	timerthread.type              = STANDALONE;
	timerthread.execEnv.fcnObj.pFptr     = maintimerloop;
	timerthread.execEnv.fcnObj.pArg      = NULL;

	retval = createthread(&timerthread);
	return retval;
}
