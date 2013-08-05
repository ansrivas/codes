/***************************************************************************
*	FILENAME :signal.c 
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of signal function
*	Invoke the Executable as a.out (Execute it in the Background) 
*	Use the command kill -USR1 or -USR2 Processid , to see the output
*	After execution termination the process by kill -9 processid
*	 2009  
****************************************************************************/
#include<stdio.h>
#include<signal.h>

static void sig_usr(int);

int main(void)
{
	
	/*Registering Handler for SIGUSR1 and SIGUSR2*/
	if (signal(SIGUSR1,sig_usr)==SIG_ERR)
		printf("Cant catch SIGUSR1");
	if (signal(SIGUSR2,sig_usr)==SIG_ERR)
		printf("Cant catch SIGUSR1");
	
	/*Waiting indefinitely for the receipt of signal*/
	for(;;) 
		pause();


}

/************************************************************************
*	FUNCTION NAME:sig_usr
*	DESCRIPTION: A standard signal Handler 
*	NOTES : No Error Checking is done .
*	RETURNS :void 
************************************************************************/
static void sig_usr(int signo)
{

	if (signo == SIGUSR1)
		printf("Received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("Received SIGUSR2\n");
}

