/*************************************************************************
*
*  FILE NAME    : bitwise_multiplication.c
*
*  DESCRIPTION  : Demonstrates multiplication 2 numbers using bitwise operators
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

int main()
{
 unsigned int val = 10, num = 2;
 unsigned int res = 0;
 while ( num != 0)
 {
  if( num & 1)
  {
   res = res + val;
  }
  val = val << 1; /* Shifting left by 1 */
  num = num >> 1; /* Shifting right by 1 */
 }
 printf("%u\n", res);

 return 0;
}
