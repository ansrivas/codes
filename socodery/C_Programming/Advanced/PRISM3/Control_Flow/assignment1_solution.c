#include <stdio.h> 
/*Not the complete solution. Just demonstrating how to get repeate the process 
if a non-integer value is not enterer */

int main(void)
{
  int num;
  printf ("Input your number: ");
  while (scanf("%d", &num) != 1)
  {
    while (getchar() != '\n');

    printf ("Wrong Input , Please re-enter: ");
  }
  printf ("You entered %d\n", num);
  return(0);
}


