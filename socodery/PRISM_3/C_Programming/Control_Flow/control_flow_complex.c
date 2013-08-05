/*************************************************************************
*
*  FILE NAME    : control_flow_complex.c
*
*  DESCRIPTION  : Demonstrates the need for simplified expressions in decision
		  making statements
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>

int main()
{
 int x = 2, y = 3;
 
 /* Refer to the warning when you compile with "gcc -Wall" */
 if( ((x += 1) == 3) || ((y += 1) == 4) && (x + y == 1))
 {
  printf("%d %d\n", x , y);
 }
 else
 { 
  printf("%d %d\n", x , y);
 }
 return 0;
}
