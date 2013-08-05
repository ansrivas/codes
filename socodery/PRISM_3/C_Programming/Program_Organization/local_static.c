/*************************************************************************
*
*  FILE NAME    : local_static.c
*
*  DESCRIPTION  : Demonstrates scope of static variables
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>

int static x;

static void display_x()
{
 printf("Global static = %d\n", x);
 /* Uncomment the following line to emphasize the fact that local static scope is limited to the block */
// printf("Local static = %d\n", s);
}

static void sample_fun(int arg)
{
 static int s = 10; /* local static variable */
 s = s + arg; /* Argument gets added */
 printf("%d\n", s);
}

int main()
{
 int index = 0; /* for loop index */
 display_x(); /* Displays global static variable */
 for(index = 0; index < 5; index += 1)
 {
  printf("index = %d\n", index);
  sample_fun(index);
 }
 return 0;
}
 
