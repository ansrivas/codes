/*****************************************************************************
*	FILENAME : threadedfs.c
*	DESCRIPTION:Contains Code for a file server , that will accept a filename
*	from a file client process  read that file and sends it over socket  
*	to the client process .(Shows a typical THREADED SERVER )
*	Invoke the Executable as a.out  PORT NO 
*	 2007  
******************************************************************************/


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
#include	<pthread.h>
#include	<unistd.h>
#define MYPORT 16600
#define MYPORT1 16650
void readFileName(int,char *);
void readWriteFile(char * , int);
void *doit(void *);
void *doit1(void *);

int main( int C, char *V[] )
{
	int sd,connfd,retbind;
	int sd1,connfd1,retbind1;
	struct	sockaddr_in
		serveraddress,cliaddr,serveraddress1,cliaddr1;
	socklen_t len,len1;
	pthread_t th1,th2;
	char buf[100];

	sd = socket( AF_INET, SOCK_STREAM, 0 );
	sd1 = socket(AF_INET,SOCK_STREAM,0);
	if( sd < 0 ) 
	{
		perror( "socket" );
		exit( 1 );
	}
	if( sd1 < 0 ) 
	{
		perror( "socket1" );
		exit( 1 );
	}

	memset( &serveraddress, 0, sizeof(serveraddress));
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(MYPORT);//PORT NO
	serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);//ADDRESS
	
	memset( &serveraddress1, 0, sizeof(serveraddress1));
	serveraddress1.sin_family = AF_INET;
	serveraddress1.sin_port = htons(MYPORT1);//PORT NO
	serveraddress1.sin_addr.s_addr = htonl(INADDR_ANY);//ADDRESS
	retbind=bind(sd,(struct sockaddr*)&serveraddress,sizeof(serveraddress));
	retbind1=bind(sd1,(struct sockaddr*)&serveraddress1,sizeof(serveraddress1));
	if(-1==retbind)
	{
		perror("Bind Fails for first socket\n");
		exit(1);
	}
	if(-1==retbind1)
	{
		perror("Bind fails for second socket\n");
		exit(1);
	}
	listen(sd,5);
	/*Beginning of the Main Server Processing Loop*/
	
	listen(sd1,5);
	for(;;)
	{
		printf("I am waiting-----Start of Main Loop\n");
		len=sizeof(cliaddr);
		connfd=accept(sd,(struct sockaddr*)&cliaddr,&len);
		if ( connfd < 0)
		{
			if (errno == EINTR) 
			printf("Interrupted system call ??");
			continue;
		}
			
	
		//printf("I am waiting-----Start of Main Loop\n");
		len1=sizeof(cliaddr1);
		connfd1=accept(sd1,(struct sockaddr*)&cliaddr1,&len1);
		if ( connfd1 < 0)
		{
			if (errno == EINTR) 
			printf("Interrupted system call ??");
			continue;
		}
		printf("Connection from %s\n",
		inet_ntop(AF_INET,&cliaddr.sin_addr,buf,sizeof(buf)));
		pthread_create(&th1,NULL,doit,(void*)connfd);		
		printf("Connection from %s\n",
		inet_ntop(AF_INET,&cliaddr1.sin_addr,buf,sizeof(buf)));
		pthread_create(&th2,NULL,doit,(void*)connfd1);		
			
	}
	
}



/*********************************************************************
*	FUNCTION NAME:doit
*	DESCRIPTION: Reads the filename , opens the file , reads it and 
*	writes it on the socket.
*	NOTES : 
*	RETURNS :void 
********************************************************************/



void * doit(
	void *connfd) /*The connection socket is passed as the argument */

/*********************************************************************/
	

{
	char fname[1024] , sendbuffer[1024];
	int pointer=0,n,fd;
	pthread_detach(pthread_self());
	/*Now Reading the File Name */
	while ((n=read((int)connfd,(fname + pointer),1024))>0){
		pointer=pointer+n;
	}
	fname[pointer]='\0';
	printf("SERVER THREAD %d  :Request to send file  %s\n " ,
		pthread_self(),fname);
	/*Now Opening the file */
	fd = open(fname, O_RDONLY);
	if (fd < 0 )
	{
			printf("SERVER  THREAD %d: ERROR OPENING FILE \n",
				 pthread_self());
			pthread_exit(NULL);
	}
	while ( (n=read( fd , sendbuffer , 1024)) >0)
		write( (int)connfd , sendbuffer , n);
	printf ("File sending successful \n");
	close((int)connfd);
	close(fd);
	pthread_exit(NULL);
}

/*********************************************************************/
//void * doit1(
//	void *connfd1) /*The connection socket is passed as the argument */

/*********************************************************************/
	

/*{
	char fname1[1024] , sendbuffer[1024];
	int pointer=0,n,fd1;
	pthread_detach(pthread_self());*/
	/*Now Reading the File Name */
/*	while ((n=read((int)connfd1,(fname1 + pointer),1024))>0){
		pointer=pointer+n;
	}
	fname1[pointer]='\0';
	printf("SERVER THREAD %d  :Request to send file  %s\n " ,
		pthread_self(),fname1);*/
	/*Now Opening the file */
/*	fd1 = open(fname1, O_RDONLY);
	if (fd1 < 0 )
	{
			printf("SERVER  THREAD %d: ERROR OPENING FILE \n",
				 pthread_self());
			pthread_exit(NULL);
	}
	while ( (n=read( fd1 , sendbuffer , 1024)) >0)
		write( (int)connfd1 , sendbuffer , n);
	printf ("File sending successful \n");
	close((int)connfd1);
	close(fd1);
	pthread_exit(NULL);
}*/
