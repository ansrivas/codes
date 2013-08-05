/***************************************************************************
*	FILENAME : attach.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	attaching of a Shared Memory segment in a parent and in the child	
*	Invoke the Executable as a.out
*	 2009  
****************************************************************************/
#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
main()
{
	key_t key;
	int shmid,status ;
	char *virtualaddr1=NULL,*virtualaddr2=NULL;
	
	key =ftok("shared.c",'R');
	shmid=shmget(key,1024,0644|IPC_CREAT);
	if (-1 == shmid)
	{
		printf("Failed to Create Shared Memory\n");
		exit(1);
	}	
	//Attach First Time
	virtualaddr1=shmat(shmid,(void*)0,0);

	if(NULL==virtualaddr1)
	{
		printf("Error in attaching\n");
		exit(1);
	}
	printf("First Time attaching VADDR =%u\n",virtualaddr1);

	//Attach Second Time
	virtualaddr2=shmat(shmid,(void*)0,0);

	if(NULL==virtualaddr2)
	{
		printf("Error in attaching\n");
		exit(1);
	}
	printf("Second Time attching VADDR=%u\n",virtualaddr2);
	
	/*Writing Something from the Parent */
	strcpy(virtualaddr1,"Testing Shared Memory");
	
	/*Now create a Child  and write something*/
	
	if(fork()==0) 
	{   printf("Inside child%u\n",virtualaddr2 + strlen(virtualaddr1));
	strcpy((virtualaddr2 + strlen(virtualaddr1)),"Child has Written This Stuff");
            printf("child=%s",virtualaddr2);
		exit(0);
	}
	/*Parent waits for Child's termination*/
	wait(NULL);
	
	/*Printing The memory contents from the parent*/
	printf("parent=%s",virtualaddr1);
	
	/*Detaching the Two instances*/
	shmdt(virtualaddr1);
	shmdt(virtualaddr2);
	
	/*Finally deleting the shared memory segment*/
	status = shmctl(shmid,IPC_RMID,0);
	if (status < 0)
	{
		printf("Error in Deleting Shared Memory\n");
		perror("Error:Shared Memory Deletion\n");
		exit(1);
	}	
	
}
