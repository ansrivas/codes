/***************************************************************************
*	FILENAME :msgclient.c 
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of msgqueue functions . This is the client which sends a
*	message (Type =1 , Data = Own Pid ) to the server process via 
*	a message Queue.This message is being retrieved by the server
*	and it sends the message (Type = Client's Pid , Data = Server's
*	Pid). This message is being retrieved by the client and it exits. 
*	Invoke the Executable as client (gcc -o client msgclient)
*	 2009  
****************************************************************************/
#include "mq_defines.h"

int main()
{
	key_t k;
	msgbuf msg;
	int msgid,retval;
	/*Generating the Key*/
	k=ftok(KEYPATH,'B');
	if (k < 0)
	{
		printf("Error  in Key Generation\n");
		exit(1);
	}
	/*Getting the Message Queue Descriptor*/
	msgid = msgget(k,0644);
	if (msgid < 0)
	{
		printf("Error in accessing Message Queue\n");
		exit(1);
	}
	/*Generating the Message*/
	msg.mtype=1;
	msg.pid=getpid();
	/*Sending the Message*/
	retval = msgsnd(msgid,&msg,(sizeof(msg)-sizeof(long)),0);
	if(retval<0)
	{
		printf("Could not send.\n");
		exit(1);
	}
	/*Waiting for Reply from the server*/
	retval = msgrcv(msgid,&msg,(sizeof(msg)-sizeof(long)),getpid(),0);
	if(retval<0)
	{
		printf("Could not receive from queue.\n");
		exit(1);
	}
	printf("Client :Received response from server whose Pid=  %d\n"
			,msg.pid);
}
