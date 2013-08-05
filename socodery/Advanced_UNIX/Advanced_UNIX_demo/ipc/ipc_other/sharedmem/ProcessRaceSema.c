/***************************************************************************
*	FILENAME : threadrace.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of modification of a global variable by multiple threads.
*	Invoke the Executable as a.out (Link with Linker option -lpthread)
*	 2007  
****************************************************************************/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<unistd.h>
#include<sys/stat.h>
#include<semaphore.h>

void *doit(int,int * );

int main(int argc, char* argv[])
{
	int sharedmem;
	pid_t retfork;
	int *ptr;
	struct stat buf;
	sem_t *semptr;

	if (argc < 3)
	{
		printf ("Usage is : a.out <Mempathname> <Semapathname>");
		exit(1);
	}

	/*Creating a Shared Mem, by taking the path name from user*/
	sharedmem = shm_open(argv[1], O_RDWR|O_CREAT, 0700);

	/*Creating a Posix Named Semaphore with initial value=1*/
	semptr = sem_open(argv[2],O_CREAT, 0600,1);

	if (SEM_FAILED == semptr)
	{
		printf("Semaphore Opening Failed\n");
		perror("Semaphore");
		exit(1);
	}
	if (-1 == sharedmem)
	{
		printf("Unable to Create/Access Shared Mem\n");
		perror("Sharem Mem Create/Access");
		exit(1);
	}
	/*Immediatly Unlink all the ipc, so that the memory will be deleted when
	all the processes that refer the memory exits*/
	shm_unlink(argv[1]);
	sem_unlink(argv[2]);
	
	/*Checking the Initial Size of Shared Mem. It should be 0, if created.*/

	fstat(sharedmem, &buf);
	printf("The size Before Ftruncate is %d", buf.st_size);
	
	/*Specifying the sise of the Shared Mem*/
	ftruncate(sharedmem, sizeof(int));

	fstat(sharedmem, &buf);
	printf("The size After Fruncate is %d", buf.st_size);
	
	/*Now map it in the process address space to use it*/
	ptr=(int*)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE,
		MAP_SHARED, sharedmem,0);
	if ((void*)-1 == ptr)
	{
		printf("Error in Mapping\n");
		perror("Memory Mapping Error\n");
	}
	/*Initialising it to zero*/
	/*Linux Man page says it is automatically initilaised to 0*/
	//*ptr=0;
	
	/*Creating a Child*/

	retfork=fork();
	if (0 == retfork)
	{
		ptr=(int*)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE,
		MAP_SHARED, sharedmem,0);
		if ((void*)-1 == ptr)
		{
			printf("Error in Mapping\n");
			perror("Memory Mapping Error\n");
		}
		/*Protecting the Critical Region*/
		sem_wait(semptr);
		doit(retfork, ptr);
		sem_post(semptr);
		exit(0);
	}
	/*Protecting the Critical Section in Parent*/
	sem_wait(semptr);
	doit(retfork, ptr);
	sem_post(semptr);
	/*Wait for the Termination of its Child*/
	wait(NULL);
	printf("The final Value of the Shared Stuff is %d\n", *ptr);
	exit(0);
}

/********************************************************************
*	FUNCTION NAME:doit
*	DESCRIPTION:Increments a variable in shared mem.
*	NOTES : No Error Checking is done .
*	RETURNS :void * 
*********************************************************************/
void *  doit(int id,int *p)
{
	int localvar, count;
	for(count=0;count<15000;count++)
	{
		localvar = *p;
		printf("%d:%d\n",id, localvar);
		*p= localvar + 1;
	}
	return NULL;
}


