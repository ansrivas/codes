#include<signal.h>

void signal_handler()
  {
     printf("\nchild received signal\n");
  }

main()
  {
    int pid;
    pid=fork();
    
    if(pid==0)
      {
        signal(SIGINT,signal_handler);
        sleep(2);
      }
     else
       {
         kill(pid(),SIGINT);
         sleep(5);
         printf("Parent exiting\n");
       }
   }

     

