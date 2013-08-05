/*
Switch Source Code File
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	"prototype.h"
#include	"basictypes.h"
#include	"connmgr.h"
#include	"callsm.h"


int main(int argc, char *argv[])
{
	ReturnType              retval   = FAILURE;
	CommPoint	 	sockid   = -1;
	CommPoint		connsd  = -1;

	if (argc != 3) {
		LOG_MESSAGE("please provide the ip address and port number\n");
		return retval;
	}

	retval = tcpcreatepassivesocket(argv[1], argv[2], &sockid);
	if(FAILURE == retval)
	{
		LOG_MESSAGE("socket creation failed\n");
		return retval;
	}

	for(;;)
	{
		retval = tcpwaitforconnection(sockid, &connsd);
		if(FAILURE == retval)
		{
			//Raise Error here - code to be written
			break;
		}

		retval = handleoriginatingcall(connsd);

		close(connsd);
		if (FAILURE == retval)
		{
			//Raise Error here - code to be written
		}
	}
	retval = tcpcloseconnection(sockid);
	if (FAILURE == retval)
	{
		return 1;
	}
	return 0;
}
