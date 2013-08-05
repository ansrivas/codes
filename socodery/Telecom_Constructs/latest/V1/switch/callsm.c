/*
call Manager Source Code File
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"basictypes.h"
#include	"msgmgr.h"
#include	"calllib.h"
#include	"callsm.h"


oCallEventHandler ocallstatetable[NUM_CALLER_STATES][NUM_CALL_EVENTS];

Subscriber_Call_Events getsubscriberevent(Message * pmsg)
{
	return (pmsg->mtype.subscriberEvent);
}

void initializecalltable()
{
	ocallstatetable[0][0] = defaulthandler;
	ocallstatetable[0][1] = defaulthandler;
	ocallstatetable[0][2] = defaulthandler;
	ocallstatetable[0][3] = defaulthandler;
	ocallstatetable[0][4] = defaulthandler;

	ocallstatetable[1][0] = defaulthandler;
	ocallstatetable[1][1] = callanswer;
	ocallstatetable[1][2] = defaulthandler;
	ocallstatetable[1][3] = defaulthandler;
	ocallstatetable[1][4] = defaulthandler;

	ocallstatetable[2][0] = defaulthandler;
	ocallstatetable[2][1] = defaulthandler;
	ocallstatetable[2][2] = defaulthandler;
	ocallstatetable[2][3] = defaulthandler;
	ocallstatetable[2][4] = defaulthandler;

	ocallstatetable[3][0] = defaulthandler;
/*
	callnaswer has been called instead of default handler to handle repeat setup messages
*/
//	ocallstatetable[3][1] = defaulthandler;
	ocallstatetable[3][1] = callanswer;

	ocallstatetable[3][2] = callrelease;
	ocallstatetable[3][3] = defaulthandler;
	ocallstatetable[3][4] = datatransfer;

	ocallstatetable[4][0] = defaulthandler;
	ocallstatetable[4][1] = defaulthandler;
	ocallstatetable[4][2] = defaulthandler;
	ocallstatetable[4][3] = defaulthandler;
	ocallstatetable[4][4] = defaulthandler;

	ocallstatetable[5][0] = defaulthandler;
	ocallstatetable[5][1] = defaulthandler;
	ocallstatetable[5][2] = defaulthandler;
	ocallstatetable[5][3] = defaulthandler;
	ocallstatetable[5][4] = defaulthandler;
}

void * handleoriginatingcall(void * pcobj)
{
	int			retval = FAILURE;
	TrsfrPacket		packet;
	Message			msg;
	Subscriber_Call_Events	event;
	OriginatingCall		*pCallObject = (OriginatingCall*)pcobj;

//	pCallObject->state = OCALL_IDLE_STATE;
	pCallObject->state = OCALL_SETUP_INITIATED;
	/*
	The sleep call below has been put here to test the timer
	functionality on the subscriber side, otherwise it is of no use and
	should be removed.
	*/
	sleep(2);

	while (1)
	{
		retval = receivepacket(pCallObject->oComPoint, &packet);
		if(FAILURE == retval)
		{
			SYS_LOG_ERROR_MESSAGE("packet reading failed");
			break;
		}
		retval = createmessagefrompacket(&packet, &msg);
		if(FAILURE == retval)
		{
			SYS_LOG_ERROR_MESSAGE("message parsing failed");
			break;
		}
		event = getsubscriberevent(&msg);
		if ((event < 0) || (event > 4))
		{
			event = SUBS_EVT_INVALID;
		}
		retval = ocallstatetable[pCallObject->state][event](pCallObject, &msg);
		if(FAILURE == retval)
		{
			SYS_LOG_ERROR_MESSAGE("packet reading failed");
			break;
		}
		if (OCALL_TERMINATED == pCallObject->state)
		{
			break;
		}
	}
	tcpcloseconnection(pCallObject->oComPoint);
	free((OriginatingCall*)pCallObject);
	return NULL;
}
