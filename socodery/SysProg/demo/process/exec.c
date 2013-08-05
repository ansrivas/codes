/***************************************************************************
*	FILENAME : exec.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of exec call
*	Invoke the Executable as a.out
*	 2009  
****************************************************************************/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
#include<string.h>
main()
{
	int status,retval,childid;
	pid_t pid; /*Return Value of fork*/
	
	printf("Before Fork\n");

	if ((pid = fork())<0)
	{
		printf("Fork  Error:%s",strerror(errno));
		exit(1);
	}
	else if (pid == 0) /*Child Executing that will exec the program file*/
	{
		/*Running the program wordcount(wc) on file fork.c*/
		retval = execl("/usr/bin/wc","wc","-l","fork.c",(char*)0);
		if (retval < 0)
		{
			printf("Exec Error:%s",strerror(errno));
			exit(1);
		}
		printf("Cannot come here\n");
	}
	else /*Parent Executing*/
	{
		/*Parent waiting for Child's Termination*/
		childid = wait(&status);
		printf("Parent = %d,Child  =%d  exited with status =%d" ,
			getpid(),childid,WEXITSTATUS(status));
	}
}

