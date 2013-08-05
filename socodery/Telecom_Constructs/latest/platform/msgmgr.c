/*
Message Manager Source Code File

*/

#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	"msgmgr.h"

ReturnType establishconnection(CommPoint * pchannelid, NodeId * pnexthop)
{
	ReturnType 	retval;
	retval = tcpcreateactivesocketwobind(pchannelid);
	if(FAILURE == retval) 
	{
		SYS_LOG_ERROR_MESSAGE("can't create a communication endpoint");
		return FAILURE;
	}
	retval = tcpconnect(*pchannelid, pnexthop->ipaddress, pnexthop->port);
	if(FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("can't connect");
		return FAILURE;
	}
	return SUCCESS;
}

ReturnType receivepacket(CommPoint  channelid, TrsfrPacket *precvbuffer)
{
	unsigned int bytestoberecvd = 0;
	ReturnType   retval         = FAILURE;

	if(NULL == precvbuffer)
	{
		SYS_LOG_ERROR_MESSAGE("buffer reference invalid");
		return FAILURE;
	}
	bytestoberecvd = sizeof(TrsfrPacket);
	
	retval = tcpreceivedata(channelid, precvbuffer->buffer, bytestoberecvd);
	if (FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("failure in receiving data");
		return FAILURE;
	}	
	return SUCCESS;
}

ReturnType sendpacket(CommPoint  channelid, TrsfrPacket *psendbuffer)
{
	unsigned int bytestobesent = 0;
	ReturnType   retval         = FAILURE;

	if(NULL == psendbuffer)
	{
		SYS_LOG_ERROR_MESSAGE("buffer reference invalid");
		return FAILURE;
	}
	bytestobesent = sizeof(TrsfrPacket);
	
	retval = tcpsenddata(channelid, psendbuffer->buffer, bytestobesent);
	if (FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("failure in receiving data");
		return FAILURE;
	}	
	return SUCCESS;
}

ReturnType waitforpacket(CommPoint  * pdescriptorlist, unsigned int nsd, TrsfrPacket *precvbuffer)
{
	unsigned int bytestoberecvd = 0;
	ReturnType   retval         = FAILURE;

	if(NULL == precvbuffer)
	{
		SYS_LOG_ERROR_MESSAGE("buffer reference invalid");
		return FAILURE;
	}

	if(NULL == pdescriptorlist)
	{
		SYS_LOG_ERROR_MESSAGE("communication point list invalid");
		return FAILURE;
	}

	if(0 == nsd)
	{
		SYS_LOG_ERROR_MESSAGE("there are no descriptors");
		return FAILURE;
	}

	bytestoberecvd = sizeof(TrsfrPacket);

	retval = tcpreceivedatamultiplechannel(pdescriptorlist, nsd, precvbuffer->buffer, bytestoberecvd);
	
	if (FAILURE == retval)
	{
		SYS_LOG_ERROR_MESSAGE("failure in receiving data");
		return FAILURE;
	}	
	return SUCCESS;
}


ReturnType createmessagefrompacket(TrsfrPacket *precvbuffer, Message *pmsg)
{
	if((NULL == precvbuffer) || (NULL == pmsg))
	{
		SYS_LOG_ERROR_MESSAGE("packet/msg references invalid");
		return FAILURE;
	}
	memcpy(pmsg, precvbuffer->buffer, sizeof(Message));
	return SUCCESS;
}

ReturnType createpacketfrommessage(Message *pmsg, TrsfrPacket *precvbuffer)
{
	if((NULL == precvbuffer) || (NULL == pmsg))
	{
		SYS_LOG_ERROR_MESSAGE("packet/msg references invalid");
		return FAILURE;
	}
	memcpy(precvbuffer->buffer, pmsg, sizeof(Message));
	return SUCCESS;
}
