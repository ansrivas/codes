#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#define MAX 100
main()
{
	int fd[2],n;
	pid_t pid;
	char *message="Hello World";
	char line[MAX];
	if(pipe(fd)<0){
		printf("PIPE ERROR");
		exit(0);
	}
	if((pid=fork())<0){
		printf("FORK ERROR");
		exit(0);
	}
	else if (pid > 0){ /*PARENT*/
		close(fd[0]);
		write (fd[1], message, strlen(message));
		exit(0);

	}
	else {
		close(fd[1]);
		while((n=read(fd[0],line,MAX))>0)
			write(1,line,n);
		printf("\n%d",n);
		exit(0);
	}
}
	
