/*
Switch Source Code File
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	"prototype.h"
#include	"basictypes.h"
#include	"platform.h"
#include	"threadmgr.h"
#include	"connmgr.h"
#include	"callsm.h"

#define NUM_THREADS	10


int main(int argc, char *argv[])
{
	ReturnType              retval    = FAILURE;
	CommPoint	 	sockid    = -1;
	OriginatingCall		*pcallobj = NULL;
	ThreadPool		*pthrpool = NULL;
	Functor			*pFuncObj = NULL;
	MessageQue		*pqid;

	if (argc != 3) {
		LOG_MESSAGE("please provide the ip address and port number\n");
		return retval;
	}

	retval = initializeplatform();
	if(FAILURE == retval)
	{
		LOG_MESSAGE("platform initilization failed\n");
		return retval;
	}
	initializecalltable();
	
	retval = tcpcreatepassivesocket(argv[1], argv[2], &sockid);
	if(FAILURE == retval)
	{
		LOG_MESSAGE("socket creation failed\n");
		return retval;
	}
	retval = createanonymousthreadpool(NUM_THREADS, &pqid, &pthrpool);
	if(FAILURE == retval)
	{
		LOG_MESSAGE("thread pool creation failed\n");
		return retval;
	}

	for(;;)
	{
		/*socket connection id is being dynamically allocated to 
		keep no limit on socket connections*/
		pcallobj = (OriginatingCall *) malloc(sizeof(OriginatingCall));
		retval = tcpwaitforconnection(sockid, &pcallobj->oComPoint);
		if(FAILURE == retval)
		{
			//Raise Error here - code to be written
			break;
		}

		pFuncObj = malloc(sizeof(Functor));
		pFuncObj->pFptr = handleoriginatingcall;
		pFuncObj->pArg  = pcallobj;

		retval = putqueue(pqid, pFuncObj);
		if (FAILURE == retval)
		{
			//Raise Error here - code to be written
			continue;
		}
	}
	close(sockid);
	return 1;
}
