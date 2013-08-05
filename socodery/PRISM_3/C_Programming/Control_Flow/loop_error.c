/*************************************************************************
*
*  FILE NAME    : loop_error.c
*
*  DESCRIPTION  : Demonstrates how invalid value change can lead to crash.
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
 int cnt = 5, num = 1000;
 do 
 { 
  printf ("%d", num);
  num /= cnt;      
 } while (cnt --); /* End of while */
}
