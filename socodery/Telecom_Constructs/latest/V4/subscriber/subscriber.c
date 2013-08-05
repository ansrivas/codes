#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/time.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	"prototype.h"
#include	"platform.h"
#include	"timerutility.h"

#define 	RESEND_LIMIT	10
#define 	TIMEOUT_PERIOD	200

typedef struct TimerExp
{
	int 		sd;
	int 		resendcount;
	TrsfrPacket	packet;
}TimerExpType;

void * sendData(void * pData)
{
	struct timeval	tv;
	TimerExpType * pTimerExpData = (TimerExpType*)pData;
	gettimeofday(&tv, NULL);
	if (pTimerExpData->resendcount >= 0)
	{
		write(pTimerExpData->sd, &pTimerExpData->packet, sizeof(TrsfrPacket));
		printf("timer expired : %u : %u\n", tv.tv_sec, tv.tv_usec);
	}
	else
	{
		printf("server not responding \n");
//		close(pTimerExpData->sd);
	}
	pTimerExpData->resendcount--;
	return NULL;
}



int main(int argc, char *argv[]) 
{
	int			sd = 0;
	TrsfrPacket		packet;
	Message			sentvalue;
	Message			recvdvalue;
	TimerIdType		tId;
	TimerExpType		timerData;
	ReturnType		retval;

	struct	sockaddr_in 	serveraddress;

	if (argc != 3) {
		printf("please provide following command line arguments\n");
		printf("server IP address\n");
		printf("server port\n");
		exit(1);
	}
	retval = initializeplatform();
	if (FAILURE == retval)
	{
		printf("platform initialization failed ");
		exit(1);
	}
	
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if( sd < 0 ) {
		perror( "socket" );
		exit( 1 );
	}

	//the data to be sent to the server

	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port   = htons(atoi(argv[2]));    //SERVER TCP PORT
	serveraddress.sin_addr.s_addr = inet_addr(argv[1]); //SERVER IP ADDRESS
	if (0 != connect(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress)))
	{
		printf("cannot connect to server");
		close(sd);
		exit(1);
	}
	sentvalue.mtype.subscriberEvent = SUBS_EVT_DIGITS_DIALLED;
	memcpy(&packet, &sentvalue, sizeof(sentvalue));
	write(sd, &packet, sizeof(packet));

	memcpy(&timerData.packet, &packet, sizeof(packet));
	timerData.sd = sd;
	timerData.resendcount = RESEND_LIMIT;
	retval = createtimer(TIMEOUT_PERIOD, 5, sendData, &timerData, &tId);
	if (FAILURE == retval)
	{
		printf("cannot create a timer");
		close(sd);
		exit(1);
	}
	read(sd, &packet, sizeof(packet));

	memcpy(&recvdvalue, &packet, sizeof(recvdvalue));

	if (SWITCH_EVT_ANSWER == recvdvalue.mtype.switchEvent)
	{
		printf("received answer\n");
		retval = deletetimer(tId);
		if (FAILURE == retval)
		{
			printf("cannot delete the timer\n");
		}
		else
		{
			printf("deleted the timer\n");
		}
		sentvalue.mtype.subscriberEvent = SUBS_EVT_DATA;
		memcpy(&packet, &sentvalue, sizeof(sentvalue));
		write(sd, &packet, sizeof(packet));
	}
	while(1)
	{
		read(sd, &packet, sizeof(packet));
		memcpy(&recvdvalue, &packet, sizeof(recvdvalue));
		if (SWITCH_EVT_DATA == recvdvalue.mtype.switchEvent)
		{
			break;
		}
		else
		{
			printf("received proper response for invalid message \n");
		}
	}
	if (SWITCH_EVT_DATA == recvdvalue.mtype.switchEvent)
	{
		printf("received data\n");
		printf("sending out of turn message\n");
		sentvalue.mtype.subscriberEvent = SUBS_EVT_DIGITS_DIALLED;
		memcpy(&packet, &sentvalue, sizeof(sentvalue));
		write(sd, &packet, sizeof(packet));
	}
	read(sd, &packet, sizeof(packet));
	memcpy(&recvdvalue, &packet, sizeof(recvdvalue));
	if (SWITCH_EVT_INVALID == recvdvalue.mtype.switchEvent)
	{
		printf("received proper response for invalid message \n");
		sentvalue.mtype.subscriberEvent = SUBS_EVT_DATA;
		memcpy(&packet, &sentvalue, sizeof(sentvalue));
		write(sd, &packet, sizeof(packet));
	}
	read(sd, &packet, sizeof(packet));
	memcpy(&recvdvalue, &packet, sizeof(recvdvalue));
	if (SWITCH_EVT_DATA == recvdvalue.mtype.switchEvent)
	{
		printf("received data\n");
		sentvalue.mtype.subscriberEvent = SUBS_EVT_RELEASE;
		memcpy(&packet, &sentvalue, sizeof(sentvalue));
		write(sd, &packet, sizeof(packet));
	}
	read(sd, &packet, sizeof(packet));
	memcpy(&recvdvalue, &packet, sizeof(recvdvalue));
	if (SWITCH_EVT_RELEASE_CNF == recvdvalue.mtype.switchEvent)
	{
		printf("received release conf\n");
	}

	printf("exiting \n");
	close(sd);
	return 0;
}
