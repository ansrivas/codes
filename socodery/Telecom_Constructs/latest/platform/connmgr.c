/*
Connection Manager Source Code File

*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	"prototype.h"
#include	"connmgr.h"

ReturnType tcpcreatepassivesocket(char * ipaddress, char * portno, CommPoint * opsd)
{
	int                     retval = -1;
	struct sockaddr_in 	serveraddress;

	*opsd = socket( AF_INET, SOCK_STREAM, 0);
	if( *opsd < 0 )
	{
		SYS_LOG_ERROR_MESSAGE("socket creation failed");
		return FAILURE;
	}
	memset(&serveraddress, 0, sizeof(serveraddress));
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(atoi(portno));
	serveraddress.sin_addr.s_addr = inet_addr(ipaddress);

	retval = bind(*opsd,(struct sockaddr*)&serveraddress,sizeof(serveraddress));
	if( retval < 0 )
	{
		SYS_LOG_ERROR_MESSAGE("socket bind failed");
		return FAILURE;
	}

	retval = listen(*opsd,SERVER_CONN_QUEUE);
	if( retval < 0 ) 
	{
		SYS_LOG_ERROR_MESSAGE("socket listen failed");
		return FAILURE;
	}
	return SUCCESS;
}

ReturnType tcpcreateactivesocketwobind(CommPoint * opsd)
{
	*opsd = socket( AF_INET, SOCK_STREAM, 0);
	if( *opsd < 0 )
	{
		SYS_LOG_ERROR_MESSAGE("socket creation failed");
		return FAILURE;
	}
	return SUCCESS;
}

ReturnType tcpcreateactivesocket(char * ipaddress, char * portno, CommPoint * opsd)
{
	int                     retval = -1;
	struct sockaddr_in 	serveraddress;

	*opsd = socket( AF_INET, SOCK_STREAM, 0);
	if( *opsd < 0 )
	{
		SYS_LOG_ERROR_MESSAGE("socket creation failed");
		return FAILURE;
	}
	memset(&serveraddress, 0, sizeof(serveraddress));
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(atoi(portno));
	serveraddress.sin_addr.s_addr = inet_addr(ipaddress);

	retval = bind(*opsd,(struct sockaddr*)&serveraddress,sizeof(serveraddress));
	if( retval < 0 )
	{
		SYS_LOG_ERROR_MESSAGE("socket bind failed");
		return FAILURE;
	}
	return SUCCESS;
}


ReturnType tcpwaitforconnection(CommPoint sd, CommPoint * opsd)
{
	CommPoint	connsd = -1;

	/*This cliaddr is not being used right now. we will have to define a 
	  type to return this structure to the caller later
	  The prototype of the function will change at that time
	*/
	struct sockaddr_in 	cliaddr;
	socklen_t 		len;

	len=sizeof(cliaddr);
	connsd=accept(sd,(struct sockaddr*)&cliaddr,&len);
	if (connsd < 0)
	{
		return FAILURE;
	}
	*opsd = connsd;
	return SUCCESS;
}


ReturnType tcpconnect(CommPoint sockid, char *destip, char *destport)
{
	struct sockaddr_in destination;

	memset(&destination,0,sizeof(destination));

	if(NULL == destip)
	{
		SYS_LOG_ERROR_MESSAGE("PEER IP ADDRESS MISSING\n");
			
		return FAILURE;
	}
	if(NULL == destport)
	{
		SYS_LOG_ERROR_MESSAGE("PEER PORT NUMBER MISSING\n");	
		return FAILURE;
	}
 	destination.sin_family = AF_INET;
	destination.sin_port = htons(atoi(destport));
	destination.sin_addr.s_addr = inet_addr(destip);

	if(0 < connect(sockid,(struct sockaddr *)&destination,sizeof(destination)))
	{
		SYS_LOG_ERROR_MESSAGE("CANNOT CONNECT TO SERVER\n");
		return FAILURE;
	}
	return SUCCESS;
}



ReturnType tcpreceivedata(CommPoint  channelid, char *precvbuffer, unsigned int   datalength)
{
	int bytesrecved = 0;
	int retread     = 0;

	if(NULL == precvbuffer)
	{
		SYS_LOG_ERROR_MESSAGE("buffer reference invalid");
		return FAILURE;
	}
	while(bytesrecved < datalength)
	{
		retread = read(channelid,precvbuffer+bytesrecved,datalength-bytesrecved);
		if(0 > retread)
		{
			SYS_LOG_ERROR_MESSAGE("Unable to Read data");
			return FAILURE;
		}
		bytesrecved += retread;
	}
	return SUCCESS;
}



ReturnType tcpsenddata(CommPoint channelid, char *psendbuffer, unsigned int datalength)
{
	int byteswritten = 0;
	int retwrite = 0;

	if(NULL == psendbuffer)
	{
		SYS_LOG_ERROR_MESSAGE("buffer empty");
		return FAILURE;
	}

        while(byteswritten < datalength)
        {
		retwrite = write(channelid,psendbuffer+byteswritten,(datalength-byteswritten));
		if(0 > retwrite)
		{
			SYS_LOG_ERROR_MESSAGE("Write error");
			return FAILURE;
		}
		byteswritten += retwrite;
	}
	return SUCCESS;
}


ReturnType tcpreceivedatamultiplechannel(CommPoint *pdescriptorlist, unsigned int  ndescriptor, char *precvbuffer, unsigned int datalength)
{
	int      retsyscall = 0;
	int      index      = 0;
	int      bytesrecv  = 0;
	fd_set   readfds;

	if(NULL == precvbuffer)
	{
		SYS_LOG_ERROR_MESSAGE("no buffer");
		return FAILURE;
	}

	if(NULL == pdescriptorlist)
	{
		SYS_LOG_ERROR_MESSAGE("no socket descriptors");
		return FAILURE;
	}

	FD_ZERO(&readfds);
	index = ndescriptor - 1;
	while (0 <= index)
	{
       	 	FD_SET(pdescriptorlist[index],&readfds);
        	index = index - 1;
	}

	retsyscall = select(FD_SETSIZE,&readfds,NULL,NULL,NULL);
	if(-1 == retsyscall)
	{
        	SYS_LOG_ERROR_MESSAGE("Select failed\n");	
        	return FAILURE;
	}

	index = ndescriptor - 1;
	while (0 <= index)
	{
        	if((FD_ISSET(pdescriptorlist[index], &readfds)))
        	{
                	while(bytesrecv < datalength)
                	{
                        	retsyscall=read(pdescriptorlist[index],precvbuffer+bytesrecv,(datalength-bytesrecv));
				if(-1 == retsyscall)
                        	{                               		
        				SYS_LOG_ERROR_MESSAGE("read failed");
					return FAILURE;
                        	}
                        	bytesrecv += retsyscall;
                	}
                	break;
        	}
        	index -= 1;
	}
	return SUCCESS;
}


ReturnType tcpcloseconnection(CommPoint channelid)
{
	int retval = 0;
	retval = close(channelid);
	if(-1 == retval)
	{                               		
       		SYS_LOG_ERROR_MESSAGE("close failed");
		return FAILURE;
	}
	return SUCCESS;
}
