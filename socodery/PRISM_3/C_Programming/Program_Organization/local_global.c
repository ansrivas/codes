/*************************************************************************
*
*  FILE NAME    : local_global.c
*
*  DESCRIPTION  : Demonstrates local and global variables
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/


#include <stdio.h>

int x = 100;

static void display_x(void)
{
 printf("%d\n", x);
}
/* Comment the first declaration and uncomment the following to observe the fact that global variable is avialable to functions only from the point of declaration */
// int x = 100;
int main()
{
 int x = 10;
 display_x();
 printf("%d\n", x);
 return 0;
}
