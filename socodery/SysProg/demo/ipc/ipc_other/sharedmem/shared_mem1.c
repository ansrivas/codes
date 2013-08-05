/***************************************************************************
*	FILENAME :shared_mem1.c 
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of systemV shared memory object and 2 semaphores are created  
*	which are shared.	
*	Invoke the Executable as a.out
*	 2009  
****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <errno.h>
#include <semaphore.h>
#include<sys/types.h>
#include<pthread.h>


int main()
{
  pid_t childpid;

  key_t key2;
  key_t key1,key3;
  int shmid1;
  int shmid2;
  int shmid3;
  int *data;
  sem_t *psem;
  sem_t *csem;
  int count = 0;

  key1 = ftok("./t1",'R');
  shmid1 = shmget(key1, sizeof(sem_t), 0644 | IPC_CREAT);

  key2 = ftok("./t2",'R');
  shmid2 = shmget(key2, sizeof(sem_t), 0644 | IPC_CREAT);

  key3 = ftok("./t3",'R');
  shmid3 = shmget(key3, sizeof(int), 0644 | IPC_CREAT);
  
  data = shmat(shmid3, (void *)0, 0);
  *data = 0;

  psem = shmat(shmid1, (void *)0, 0);
  csem = shmat(shmid2, (void *)0, 0);

  sem_init(csem,1,1);
  sem_init(psem,1,0);


  if((childpid = fork()) < 0) // error occured

    {
      perror("Fork Failed");
      exit(1);
    }
  else if(childpid == 0) // child process
    {
      /* Write to Shared Memory */
	while (count < 10)
	{
          sem_wait(csem);
          sleep(2);
          printf("Child Process Virtual Address%u  %d\n",data,*data);
	  *data = 1;
          sem_post(psem);
	  count++;
	}
    }
  else // parent process
    {
      /* Write to Shared Memory */
	while (count < 10)
	{
          sem_wait(psem);
          printf("Parent Process Virtual Address%u  %d\n",data,*data);
	  *data = 0;
          sem_post(csem);
	  count++;
	}
        wait(NULL);
    }

  /* Detach Shared Memory */
  shmdt((void *)data);
  shmdt((void *)psem);
  shmdt((void *)csem);


  return 0;
}
