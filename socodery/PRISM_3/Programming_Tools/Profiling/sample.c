/******************************************************************************
keywords                :       gprof

File Name               :       sample.c 

Date of Creation        :       10/09/2007

Owner                   :       Sibu Cyriac

Date of Modification    :

Reason for modification :

Modifier                :

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

int a(void) {
  sleep(1);
  return 0;
}
int b(void) {
  sleep(2);
  return 0;
}

int main(int argc, char** argv)
{
   int iterations;

   if(argc != 2)
   {
      printf("Usage %s <No of Iterations>\n", argv[0]);
      exit(-1);
   }
   else
      iterations = atoi(argv[1]);

   printf("No of iterations = %d\n", iterations);

   while(iterations--)
   {
      a();
      b();
   }
}

