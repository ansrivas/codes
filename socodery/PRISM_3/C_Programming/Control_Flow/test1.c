#include <stdio.h> 
/*Not the complete solution. Just demonstrating how to get repeate the process 
if a non-integer value is not enterer */

int main(void)
{
  int num, tot;
  printf ("Enter Number of Integers:");
  scanf ("%d", &tot);
  while (tot > 0)
  {
     printf ("Input your number: ");
     while (scanf("%d", &num) != 1)
     {
       while (getchar() != '\n');
       printf ("Wrong Input , Please re-enter: ");
       continue;
     }
     printf ("You entered %d\n", num);
     tot -= 1;
  }
  return(0);
}


