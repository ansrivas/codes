/*
Switch Source Code File
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	"prototype.h"
#include	"basictypes.h"
#include	"threadmgr.h"
#include	"connmgr.h"
#include	"callsm.h"


int main(int argc, char *argv[])
{
	ReturnType              retval    = FAILURE;
	CommPoint	 	sockid    = -1;
	OriginatingCall 	*pcallobj = NULL;
	ThreadData 		threadobj;

	if (argc != 3) {
		LOG_MESSAGE("please provide the ip address and port number\n");
		return retval;
	}

	initializecalltable();
	
	retval = tcpcreatepassivesocket(argv[1], argv[2], &sockid);
	if(FAILURE == retval)
	{
		LOG_MESSAGE("socket creation failed\n");
		return retval;
	}

	for(;;)
	{
		pcallobj = (OriginatingCall *) malloc(sizeof(OriginatingCall));
		retval   = tcpwaitforconnection(sockid, &pcallobj->oComPoint);
		if(FAILURE == retval)
		{
			//Raise Error here - code to be written
			break;
		}

		/*threadobj will be overwritten however since we do not need 
		the threadobjs so it is ok.*/

		threadobj.state     = INACTIVE;
		threadobj.available = FREE;
		threadobj.type      = STANDALONE;
		threadobj.execEnv.fcnObj.pFptr = handleoriginatingcall;
		threadobj.execEnv.fcnObj.pArg  = pcallobj;

		retval = createthread(&threadobj);
		if (FAILURE == retval)
		{
			//Raise Error here - code to be written
			continue;
		}
	}
	retval = tcpcloseconnection(sockid);
	if (FAILURE == retval)
	{
		return 1;
	}
	return 0;
}
