/*
call Manager Source Code File
*/

#include	<stdio.h>
#include	"basictypes.h"
#include	"msgmgr.h"
#include	"calllib.h"
#include	"callsm.h"


Subscriber_Call_Events getsubscriberevent(Message * pmsg)
{
	return (pmsg->mtype.subscriberEvent);
}

ReturnType handleoriginatingcall(CommPoint origpcommpointid)
{
	int	                retval = SUCCESS;
	TrsfrPacket             packet;
	Message                 msg;
	Subscriber_Call_Events  event;
	OriginatingCall         callobject;

//	callobject.state = OCALL_IDLE_STATE;
	callobject.state = OCALL_SETUP_INITIATED;
	callobject.oComPoint = origpcommpointid;
	while (1)
	{
		retval = receivepacket(callobject.oComPoint, &packet);
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

		switch (callobject.state)
		{
			case OCALL_IDLE_STATE :
				switch (event) 
				{
					case SUBS_EVT_OFF_HOOK :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DIGITS_DIALLED :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_RELEASE :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_INVALID :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DATA :
						retval = defaulthandler(&callobject, &msg);
						break;
				}
				break;

			case OCALL_SETUP_INITIATED :
				switch (event) 
				{
					case SUBS_EVT_OFF_HOOK :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DIGITS_DIALLED :
						retval = callanswer(&callobject, &msg);
						break;
					case SUBS_EVT_RELEASE :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_INVALID :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DATA :
						retval = defaulthandler(&callobject, &msg);
						break;
				}
				break;

			case OCALL_INPROGRESS :
				switch (event) 
				{
					case SUBS_EVT_OFF_HOOK :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DIGITS_DIALLED :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_RELEASE :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_INVALID :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DATA :
						retval = defaulthandler(&callobject, &msg);
						break;
				}
				break;

			case OCALL_CONNECTED :
				switch (event) 
				{
					case SUBS_EVT_OFF_HOOK :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DIGITS_DIALLED :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_RELEASE :
						retval = callrelease(&callobject, &msg);
						break;
					case SUBS_EVT_INVALID :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DATA :
						retval = datatransfer(&callobject, &msg);
						break;
				}
				break;

			case OCALL_TERM_INITIATED :
				switch (event) 
				{
					case SUBS_EVT_OFF_HOOK :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DIGITS_DIALLED :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_RELEASE :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_INVALID :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DATA :
						retval = defaulthandler(&callobject, &msg);
						break;
				}
				break;

			case OCALL_TERMINATED :
				switch (event) 
				{
					case SUBS_EVT_OFF_HOOK :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DIGITS_DIALLED :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_RELEASE :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_INVALID :
						retval = defaulthandler(&callobject, &msg);
						break;
					case SUBS_EVT_DATA :
						retval = defaulthandler(&callobject, &msg);
						break;
				}
				break;
		}

		if(FAILURE == retval)
		{
			SYS_LOG_ERROR_MESSAGE("packet reading failed");
			break;
		}
		if (OCALL_TERMINATED == callobject.state)
		{
			break;
		}
	}
	tcpcloseconnection(callobject.oComPoint);
	return retval;
}
