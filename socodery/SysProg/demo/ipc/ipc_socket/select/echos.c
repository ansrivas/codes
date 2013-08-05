/***************************************************************************
*	FILENAME : echos.c
*	DESCRIPTION:Contains Code for a echo  server , that will , read 
*	data from an client process , and send it back over the connected 
*	socket.
*	Invoke the Executable as a.out     
*	 2007  
***************************************************************************/




#include	<stdio.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/wait.h>
#include	<fcntl.h>
#include	<signal.h>
#include	<unistd.h>
#define LISTENQ 5
#define MYPORT 11710

void server_echo(int);
void zombiehandler(int);


int main(int C, char **V )

{
	int	sd,connfd,mylen;
	struct	sockaddr_in
		serveraddress,cliaddr , myaddr;
	socklen_t len;
	char buf[100];

	sd = socket( AF_INET, SOCK_STREAM, 0 );
	if( sd < 0 ) {
		perror( "socket" );
		exit( 1 );
	}
	signal(SIGCHLD , zombiehandler);

	memset( &serveraddress, 0, sizeof(serveraddress) );
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(MYPORT);//PORT NO
	serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);//ADDRESS
	bind(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress));
	
	listen(sd,LISTENQ);

	for(;;){
		printf("I am waiting\n");
		len=sizeof(cliaddr);
		connfd=accept(sd,(struct sockaddr*)&cliaddr,&len);
		if ( connfd < 0)
		{
			if (errno == EINTR) 
			printf("Interrupted system call ??");
			continue;
		}

		printf("Connection from %s\n",
		        inet_ntop(AF_INET,&cliaddr.sin_addr,buf,sizeof(buf)));

		if (fork() ==0)
		{
			printf("Opened a New server\n");
			close(sd);

			/*Added the following 4 lines  after using Wild card IP Address */
			printf("SERVER CHILD:Printing my Own IP Address\n");

			mylen=sizeof(myaddr);
			getsockname(connfd,(struct sockaddr*)&myaddr, &mylen);

			printf("SERVVER CHILD:My Own Address is %s\n",
				    inet_ntop(AF_INET,&myaddr.sin_addr,buf,sizeof(buf)));
			
			server_echo(connfd);
			close(connfd);
			exit(0);
		}
		close(connfd);
	}
}


/************************************************************************
*	FUNCTION NAME:server_echo
*	DESCRIPTION: Reads data from the socket and echoes it back.
*	NOTES : No Error Checking is done .
*	RETURNS :void 
************************************************************************/
void server_echo(
	int sockfd /*Connection Socket*/
)
{

	char buf[1024];
	int n;

	while ((n=read(sockfd,buf,1024))>0)
	{
		write(1, buf, n);
		write(sockfd, buf, n);
	}
}

/************************************************************************
*	FUNCTION NAME:zombiehandler
*	DESCRIPTION: Standard Zombie Handler.
*	NOTES : No Error Checking is done .
*	RETURNS :void 
************************************************************************/
void zombiehandler
	(int signo
	)
/************************************************************************/
{
	int status ;
	pid_t pid;
	while ((pid=waitpid (-1,&status , WNOHANG))>0)
		printf("Child with pid =%d exited \n" , pid);
}
/************************************************************************/


