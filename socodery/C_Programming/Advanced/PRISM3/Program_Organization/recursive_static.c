/*************************************************************************
*
*  FILE NAME    : recursive_static.c
*
*  DESCRIPTION  : Demonstrates the behaviour of static variables in recursive
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
int func(int arg)
{
 static int sum = 0;
 sum = sum + arg;
 printf("%d\n", sum);
 if(sum > 2)
   return sum;
 else
   return func(arg + 4);
}

int main()
{
 int res;
 int index;
 for(index = 0; index < 3; index++)
 {
  res = func(index);
  printf("%d\n", res);
 }
 return 0;
}
