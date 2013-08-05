#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	"prototype.h"



int main(int argc, char *argv[]) 
{
	int			sd = 0;
	TrsfrPacket		packet;
	Message			sentvalue;
	Message			recvdvalue;

	struct	sockaddr_in 	serveraddress;

	if (argc != 3) {
		printf("please provide following command line arguments\n");
		printf("server IP address\n");
		printf("server port\n");
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
	printf("sending digits \n");
	sentvalue.mtype.subscriberEvent = SUBS_EVT_DIGITS_DIALLED;
	memcpy(&packet, &sentvalue, sizeof(sentvalue));
	write(sd, &packet, sizeof(packet));

	read(sd, &packet, sizeof(packet));
	memcpy(&recvdvalue, &packet, sizeof(recvdvalue));

	if (SWITCH_EVT_ANSWER == recvdvalue.mtype.switchEvent)
	{
		printf("received answer\n");
		printf("sending data \n");
	}
	int index = 0;
	while (index++ < 16)
	{
		sentvalue.mtype.subscriberEvent = SUBS_EVT_DATA;
		memcpy(&packet, &sentvalue, sizeof(sentvalue));
		write(sd, &packet, sizeof(packet));
		read(sd, &packet, sizeof(packet));
		memcpy(&recvdvalue, &packet, sizeof(recvdvalue));
		if (SWITCH_EVT_DATA == recvdvalue.mtype.switchEvent)
		{
			printf("received data\n");
		}

		//why the following lines??
		if (SWITCH_EVT_RELEASE_CNF == recvdvalue.mtype.switchEvent)
		{
			printf("received release conf\n");
			printf("exiting \n");
			close(sd);
			return 0;
		}
	}
	printf("sending release \n");
	sentvalue.mtype.subscriberEvent = SUBS_EVT_RELEASE;
	memcpy(&packet, &sentvalue, sizeof(sentvalue));
	write(sd, &packet, sizeof(packet));
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
