#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

main() {
	pid_t pid      = 0;
	int   retval   = 0;
	int   status   = 0;

	printf("process id: %u, parent process id: %u\n", getpid(), getppid());
	pid = fork();
	if (0 == pid)
	{
		printf("child process %d\n", getpid());
		
		execl("/bin/ls", "ls", NULL);
		//sleep(2);
		//execl("./child", "child", NULL);
		printf("child process %d\n", getpid());
//		sleep(2);
		exit(0);
	}
	else
       	{
		printf("parent process %d\n", getpid());
		retval = wait(&status);	
       	}
}














