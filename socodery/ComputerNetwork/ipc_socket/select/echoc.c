/****************************************************************************
*	FILENAME : echoc.c
*	DESCRIPTION:Contains Code for a echo  client , that will accept data
*	from the user(keyboard) and sends  that data  to a echo server process 
*	and prints the received data back on the screen .
*	Invoke the Executable as a.out IPAddress PortNo   
*	 2007  
*****************************************************************************/

#include	<stdio.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<fcntl.h>
#include	<signal.h>
#include	<unistd.h>

#define BUFSIZE 1024
static void sig_usr(int);
void str_cli(FILE *fp , int sockfd);

int main( int C, char *V[] )
{
	int	sd;
	struct	sockaddr_in
		serveraddress;

	if(V[1] == NULL)
	{
		printf("Enter the IP address of the server\n");
		exit(0);
	}
	
	if(V[2] == NULL)
	{
		printf("Enter the port number for the server\n");
		exit(0);
	}

	/*Install a signal Handle for SIGPIPE */
	/*Will get a SIGPIPE When the client tries to a socket that 
	  has received a RST*/
	signal(SIGPIPE,sig_usr);
	
	sd = socket( AF_INET, SOCK_STREAM, 0 );
	if( sd < 0 ) {
		perror( "socket" );
		exit( 1 );
	}
	
	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(atoi(V[2]));//PORT NO
	serveraddress.sin_addr.s_addr = inet_addr(V[1]);//ADDRESS
	if (connect(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress))<0){
		printf("Cannot Connect to server");
		exit(1);}
	printf("Connected to server \n");

	/* Prompt user to enter something */
	printf("Enter something to be echoed\n");

	str_cli(stdin,sd);
}



/************************************************************************
*	FUNCTION NAME:sig_usr
*	DESCRIPTION: Signal Handler for Trapping SIGPIPE
*	NOTES : No Error Checking is done .
*	RETURNS :void 
************************************************************************/
static void sig_usr(
	int signo) /*Signal Number*/
{
	char *str="RECEIVED SIGPIPE";
	if(signo==SIGPIPE)
		write(1,str,strlen(str));
	exit(0);
	
}

/************************************************************************
*	FUNCTION NAME:str_cli
*	DESCRIPTION: Main Client Processing (Select waits for readiness of 
*	connection socket or stdin)
*	NOTES : No Error Checking is done .
*	RETURNS :void 
************************************************************************/

void str_cli(
	FILE *fp,		/*Here to be used as stdin as argument*/
	int sockfd)		/*Connection Socket */
{
	int maxdes,written,byteswritten,n;
	fd_set rset;
	char sendbuf[BUFSIZE] , recvbuf[BUFSIZE];

	/*Clearing the Read Set*/
	FD_ZERO(&rset);

	/*Finding out the maximum descriptor number*/
	/*Note the first argument to select is the number of descriptors
	to be checked*/
	/*Descriptors start from 0 , so a 1 is added*/
	maxdes=(sockfd>fileno(fp)?sockfd+1:fileno(fp)+1);

	for(;;)
	{
		/*Turning on the interested descriptors*/
		FD_SET(fileno(fp) , &rset);
		FD_SET(sockfd , &rset);

		/*Calling Select*/
		select(maxdes,&rset,NULL,NULL,NULL);
	
		/*Socket is ready*/
		if(FD_ISSET(sockfd , & rset))
		{
		
			/*The following loop is having a limitation */
			/*Assuming All the data is read in one shot */
			/*It is not true for TCP Operation */
			while ((n=read(sockfd ,recvbuf , BUFSIZE )) >0 )
			{
				write(1, recvbuf , n );
				break;
			}
	
			/* Prompt user to enter something */	
			printf("Enter something to be echoed\n");
		
		}

		/*The function fileno returns the filedescriptor for the stream*/
		if(FD_ISSET(fileno(fp) , & rset))
		{	
			/*Take I/P from KB*/
			fgets(sendbuf,BUFSIZE,fp);
			n = strlen (sendbuf);
			byteswritten=0;

			/*Write it on the Socket*/
			while (byteswritten<n)
			{
				written=write(sockfd , sendbuf+byteswritten,strlen(sendbuf)-byteswritten);
				byteswritten+=written;
			}
		}
	}

}

/*****************************************************************************/
	
