/*************************************************************************
*
*  FILE NAME    : file2.c
*
*  DESCRIPTION  : Demonstrates extern and static Scope
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
extern int x;
void display_x(void)
{
  printf("Value of x is %d", x);
}

