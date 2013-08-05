/***************************************************************************
*	FILENAME :pipedemo.c 
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of pipe call.A client process gets a filename from the user
*	,sends the filename over pipe1 to the server , the server reads
*	the file name from the same pipe and transfers the contents 
*	to the client over another pipe , which  the client reads and 
*	displays on the screen.
*	Invoke the Executable as a.out
*	 2009  
****************************************************************************/
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<fcntl.h>

#define MAXBUFF 1024

void client(int,int);
void server(int,int);
main()
{
	int exitstatus ,childpid;
	int pipe1[2],pipe2[2];
	pid_t pid;
	if (pipe(pipe1) || pipe(pipe2) < 0)
	{
		printf("Error in Creating Pipe\n");
		exit(1);
	}
	
	/*Two Pipes are , created Pipe1 and Pipe2*/
	/*The client uses Read End of Pipe1 , and
	Write End of Pipe 2 */
	if ((pid = fork())<0)
	{
		printf("Error in Forking \n");
		exit(1);
	}
	else if (pid == 0) /*Child Executing*/
	{
		/*Need to Run the server in the Child*/
		close(pipe1[1]);
		close(pipe2[0]);
		server(pipe1[0],pipe2[1]);
		close(pipe1[0]);
		close(pipe2[1]);
		exit(0);
	}
	else /*Parent Executing*/
	{
		/*The client Runs in the Parent */
	
		close(pipe1[0]);	
		close(pipe2[1]);	
		client(pipe2[0],pipe1[1]);
		childpid = wait(&exitstatus);
		close(pipe1[1]);
		close(pipe2[0]);
		if (-1 == childpid)
		{
			printf("Error in Executing Wait Function\n");
			exit(1);
		}
		exit(0);
	}
}

/********************************************************************
*	FUNCTION NAME:client
*	DESCRIPTION:Reads a file name from the stdin , and writes the 
*	filename to pipe (Pipe1) and then reads the contents , which 
*	Were sent by the server from the read end of pipe 2 and 
*	displays it in the stdout.
*	NOTES : No Error Checking is done .
*	RETURNS :void 
*********************************************************************/

void client(
	int readfd ,/*Read Descritor*/
	int writefd /*Write Descriptor*/)		 
/********************************************************************/
{	
	char databuff[MAXBUFF];
	int status;
	
	/*Read the file name from stdin and write to the IPC*/
	printf("Enter a valid file name for the server\n");
	if (fgets(databuff,MAXBUFF,stdin)==NULL)
	{
		printf("Error in reading data from Stdin\n");
		exit(1);
	}
	status = strlen(databuff);
	/*Discard New Line Character from the file name */
	if (databuff[status-1] == '\n')
		status--;
	if ( write(writefd,databuff,status) != status)
	{
		printf("Client:Error in Writing to the pipe\n");
		exit(1);
	}
	/*Read data from IPC and write to Stdout*/
	while ((status = read(readfd,databuff,MAXBUFF)) > 0)
	{
		if (write(1,databuff,status) != status)
		{
			printf("Client:Data Write Error\n");
			exit(1);
		}
	}
	if (status < 0)
	{
		printf("Client : Data Read Error\n");
		exit(1);
	}	

	 
}


/********************************************************************
*	FUNCTION NAME:server
*	DESCRIPTION:Reads the file name from the pipe (pipe1) Reads 
*	the file from the file system and writes the file's data 
*	on pipe2 , which is then read by the client.
*	NOTES : No Error Checking is done .
*	RETURNS :void 
*********************************************************************/

void server(
	int readfd ,/*Read Descritor*/
	int writefd /*Write Descriptor*/)		 
/********************************************************************/
{	
	char databuff[MAXBUFF],errmesg[256];
	int status,fd;

	/*Read the file name from the IPC descriptor*/
	if ((status=read(readfd,databuff,MAXBUFF))<=0)
		printf("Server:File Name Read Error\n");
	databuff[status] = '\0';
	if ((fd = open(databuff , O_RDONLY)) < 0)
	{
		sprintf(errmesg , "From Server:Can't Open %s",databuff);
		strcpy(databuff,errmesg);
		status = strlen(databuff);
		if (write(writefd,databuff,status) != status)
		{
			printf("Server:Error Mesg Write Error\n");
			exit(1);
		}
	}
	else
	{
		/*Read data from the file and write to the IPC 
		descriptor*/
		while ((status = read(fd,databuff,MAXBUFF)) > 0)
		{
			if (write(writefd,databuff,status) != status)
			{
				printf("Server:Error in data write\n");
				exit(1);
			}
		}
		if (status < 0 )
		{
			printf("Server:Read Error from file \n");
			exit(1);
		}
	}	

}
