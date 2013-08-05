/*
call Manager Lib Source Code File
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"basictypes.h"
#include	"msgmgr.h"
#include	"calllib.h"


ReturnType createinprogressmessage(OriginatingCall * pcallobj, Message * pmsg)
{
	pmsg->mtype.switchEvent = SWITCH_EVT_IN_PROGRESS;
	pmsg->data.ctrlData.oSubscriber = pcallobj->oSubscriber;
	pmsg->data.ctrlData.tSubscriber = pcallobj->tSubscriber;
	return SUCCESS;
}


ReturnType createanswermessage(OriginatingCall * pcallobj, Message * pmsg)
{
	pmsg->mtype.switchEvent = SWITCH_EVT_ANSWER;
	pmsg->data.ctrlData.oSubscriber = pcallobj->oSubscriber;
	pmsg->data.ctrlData.tSubscriber = pcallobj->tSubscriber;
	return SUCCESS;
}

ReturnType createeventnothandled(OriginatingCall * pcallobj, Message * pmsg)
{
	pmsg->mtype.switchEvent = SWITCH_EVT_INVALID;
	return SUCCESS;
}

ReturnType createdatapacket(OriginatingCall * pcallobj, Message * pmsg)
{
	pmsg->mtype.switchEvent = SWITCH_EVT_DATA;
	return SUCCESS;
}

ReturnType createreleasemessage(OriginatingCall * pcallobj, Message * pmsg)
{
	pmsg->mtype.switchEvent = SWITCH_EVT_RELEASE_CNF;
	pmsg->data.ctrlData.oSubscriber = pcallobj->oSubscriber;
	pmsg->data.ctrlData.tSubscriber = pcallobj->tSubscriber;
	return SUCCESS;
}


ReturnType datatransfer(OriginatingCall * pcallobj, Message * pmsg)
{
	ReturnType 	retval;
	Message		destmsg;
	TrsfrPacket	destpacket;

	LOG_MESSAGE("Enter datatransfer function\n");

	retval = createdatapacket(pcallobj, &destmsg);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create message");
		return FAILURE;
	}
	retval = createpacketfrommessage(&destmsg, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create a packet");
		return FAILURE;
	}
	sendpacket(pcallobj->oComPoint, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("packet could not be sent");
		return FAILURE;
	}
	return SUCCESS;
}


ReturnType defaulthandler(OriginatingCall * pcallobj, Message * pmsg)
{
	ReturnType 	retval;
	Message		destmsg;
	TrsfrPacket	destpacket;

	LOG_MESSAGE("Enter defaulthandler function\n");

	retval = createeventnothandled(pcallobj, &destmsg);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create message");
		return FAILURE;
	}
	retval = createpacketfrommessage(&destmsg, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create a packet");
		return FAILURE;
	}
	retval = sendpacket(pcallobj->oComPoint, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("packet could not be sent");
		return FAILURE;
	}
	return SUCCESS;
}


ReturnType callrelease(OriginatingCall * pcallobj, Message * pmsg)
{
	ReturnType 	retval;
	Message		destmsg;
	TrsfrPacket	destpacket;

	LOG_MESSAGE("Enter callrelease function\n");

	retval = createreleasemessage(pcallobj, &destmsg);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create setup request message");
		return FAILURE;
	}
	retval = createpacketfrommessage(&destmsg, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create a packet");
		return FAILURE;
	}
	sendpacket(pcallobj->oComPoint, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("packet could not be sent");
		return FAILURE;
	}
	pcallobj->state = OCALL_TERMINATED;
	return SUCCESS;
}

ReturnType callsetup(OriginatingCall * pcallobj, Message * pmsg)
{
	ReturnType 	retval;
	Message		destmsg;
	TrsfrPacket	destpacket;

	LOG_MESSAGE("Enter callsetup function\n");

	retval = createinprogressmessage(pcallobj, &destmsg);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create setup request message");
		return FAILURE;
	}
	retval = createpacketfrommessage(&destmsg, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create a packet");
		return FAILURE;
	}
	sendpacket(pcallobj->oComPoint, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("packet could not be sent");
		return FAILURE;
	}
	pcallobj->state = OCALL_INPROGRESS;
	return SUCCESS;
}

ReturnType callanswer(OriginatingCall * pcallobj, Message * pmsg)
{
	ReturnType 	retval;
	Message		destmsg;
	TrsfrPacket	destpacket;

	LOG_MESSAGE("Enter call answer function\n");

	//sleep(2);

	retval = createanswermessage(pcallobj, &destmsg);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create setup request message");
		return FAILURE;
	}
	retval = createpacketfrommessage(&destmsg, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't create a packet");
		return FAILURE;
	}
	sendpacket(pcallobj->oComPoint, &destpacket);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("packet could not be sent");
		return FAILURE;
	}
	pcallobj->state = OCALL_CONNECTED;
	return SUCCESS;
}

