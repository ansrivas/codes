/*************************************************************************
*
*  FILE NAME    : recursive.c
*
*  DESCRIPTION  : Demonstrates recursive functions
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
void fun(int arg)
{
  printf("%d ", arg);
  if( arg < 4)
  {
    fun( arg + 1 );
    printf("%d ", arg);
  }
}

int main(void)
{
  int index = 0;
  for(index = 0; index < 4; index++)
  {
    fun(index);
    printf("\n");
  }
  return 0;
}
