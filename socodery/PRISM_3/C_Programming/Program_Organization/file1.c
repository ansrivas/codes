/*************************************************************************
*
*  FILE NAME    : file1.c
*
*  DESCRIPTION  : Demonstrates extern and static Scope
*
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>

extern void display_x(void);
extern int x;

int main()
{
 printf("%d\n", x);
 x = 10;
 display_x();
 return 0;
}

