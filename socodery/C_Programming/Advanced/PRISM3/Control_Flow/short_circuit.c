/*************************************************************************
*
*  FILE NAME    : short_ciruit.c
*
*  DESCRIPTION  : Demonstates the effect of short circuit.
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

if( ((x += 1) == 3) || (y += 1 == 4)) //  Uncomment this and comment the next line to see another issue with priority of operators 

//if( ((x += 1) == 3) || ((y += 1) == 4)) /* Since the first condition is true, if does not evaluate the 2nd the condition. This is short circuit */
 {
  printf("%d  %d\n", x , y);
 }
 else
 { 
  printf("%d%d\n", x , y);
 }
 return 0;
}
