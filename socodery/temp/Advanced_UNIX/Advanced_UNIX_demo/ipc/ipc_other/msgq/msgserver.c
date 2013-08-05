/***************************************************************************
*	FILENAME :msgserver.c 
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of msgqueue functions . This is the server  which  creates
*	a message Queue , waits for Client's message . It retrieves the 
*	Client Messages (in any order) and then sends its own message 
*	back to the client .
*	Note : Name the executable as server and start it first , then
*	invoke the clients.
*	 2009  
****************************************************************************/
#include "mq_defines.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
static void sig_usr(int signo);

/*The descriptor for message Q is global so that the Q can be deleted 
from inside the Handler for CTRL-C*/

int msgid;

int main()
{
	key_t k;
	msgbuf msg;
	int error;

	/*Registering a Signal Handler for CTRL-C */	
	if (signal(SIGINT,sig_usr)==SIG_ERR)
	{
		printf("Cant Register Handler for CTRL-C");
	}

	k = ftok(KEYPATH,'B'); /***** Generate a Key ********/
	if (k < 0)
	{
		printf("Failure in Key Generation\n");
		exit(1);
	}
	/*Server Creating the Q ueue*/
	msgid = msgget(k,0644|IPC_CREAT); 
	if (msgid < 0)
	{
		printf("Server : Error in Creating Message Queue\n");
		exit(1);
	}
	for(;;)
	{
		printf(" I am waiting for a client.......\n");
		error = msgrcv(msgid,&msg,(sizeof(msg)-sizeof(long)),1,0);
		if(error<0)
		{
			printf("Failure in Receiving Message\n");
			exit(0);
		}
	
		printf("Server : Received from Client %d\n",msg.pid);
		
		/*Restructuring the Message for Client*/
		msg.mtype=msg.pid;
		msg.pid=getpid();
		/*Sending the Message*/
		error = msgsnd(msgid,&msg,(sizeof(msg)-sizeof(long)),0);
		if(error<0)
		{
			printf("Could not send Message\n");
			exit(0);
		}
		
	}
}
/************************************************************************
*	FUNCTION NAME:sig_usr
*	DESCRIPTION: A standard signal Handler for CTRL-C for deleting the 
*	Message Queue.
*	NOTES : No Error Checking is done .
*	RETURNS :void 
************************************************************************/
static void sig_usr(int signo)
{
	int retval;
	retval = msgctl(msgid , IPC_RMID , NULL);
	if (retval < 0)
	{
		printf("Error in deleting the Message Q \n");
		perror("Msgctl:\n");
		exit(1);
	}
	printf("Server:Q deleted successfully\n");
	exit(0);
}
