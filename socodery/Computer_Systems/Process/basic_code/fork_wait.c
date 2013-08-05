#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main() {
	int pid      = 0;
	int retval   = 0;
	int status   = 0;
	int lcounter = 0;
	pid = fork();
	if (pid == 0)
	{
		sleep(10);
		printf("after exec child process id %d \n", getpid());
		exit(4);
	}
	else 
	{	
		printf("Parent\n");
		exit(0);
		retval = wait(&status);	
		printf("retval %d : status %d\n", retval, status);
		printf("child exit status %d\n",WEXITSTATUS(status));
		while (lcounter++<1)
		{
			sleep(1);
			printf("parent process id %d \n", getpid());
		}
	}
	return 1;
}
