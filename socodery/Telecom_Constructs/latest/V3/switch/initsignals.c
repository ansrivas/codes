/*
The file instantiates the signal handlers.
*/

#include<stdio.h>
#include<signal.h>
#include<errno.h>
#include"basictypes.h"

void handle_sigpipe(int signum)
{
	printf("Enter signal handler function for : %d\n", signum);
	printf("Exit signal handler function for : %d\n", signum);
}

ReturnType initializesignalhandlers()
{
	signal(SIGPIPE,handle_sigpipe);
    	if (0 != errno)
	{
		SYS_LOG_ERROR_MESSAGE("SIGPIPE signal set failure\n");
		return FAILURE;
	}
	return SUCCESS;
}
