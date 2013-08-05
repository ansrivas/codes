/***************************************************************************
*	FILENAME :shared_across_process.c 
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of posix shared memory object and simple regular file 
*	 which is mmap.	
*	Invoke the Executable as a.out
*	 2009  
****************************************************************************/
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/wait.h>

main()
{
	int fd1,fd2;
	int *ptr1,*ptr2,*buf;
	struct stat stat;
	pid_t childpid;
	fd1=shm_open("/shm",O_CREAT|O_RDWR|O_TRUNC,S_IRUSR|S_IWUSR); 
	ptr1 = (int *)mmap(0,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
	ftruncate(fd1,sizeof(fd1));
	
	fd2=open("datafile",O_RDONLY);
	fstat(fd2,&stat);
	ptr2 = (int *)mmap(0,stat.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);

	*ptr1 =10;	
	
	if((childpid = fork())==0)
	{
	ptr2 = (int *)mmap(0,stat.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);
		
	ptr1 = (int *)mmap(0,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
		printf("Child:shmptr =%p,t2 ptr = %p\n",ptr1,ptr2);
		printf("Shared Memory integer = %d\n",*ptr1);
		sleep(2);
		printf("Shared Memory integer = %d\n",*ptr1);
		exit(0);
	}

	else
	{
	ptr1 = (int *)mmap(0,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);

	ptr2 = (int *)mmap(0,stat.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);
		
		printf("Parent:shmptr =%p,t2 ptr = %p\n",ptr1,ptr2);
		*ptr1 = 7;
	         wait(NULL);
		exit(0);
	}
}
