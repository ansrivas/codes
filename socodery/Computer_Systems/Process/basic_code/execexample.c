#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

main()
{
	int pid;
	pid =fork();
	if(pid==0)
	{
		printf("\nexec starts\n");
		execl("/bin/ls","ls","-l",(char *)0);
		printf("exit\n");
	}
	else
	{		
		wait(0);
		printf("parent\n");
	}
}
