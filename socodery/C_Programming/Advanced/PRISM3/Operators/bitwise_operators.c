/*************************************************************************
*
*  FILE NAME    : bitwise_operators.c
*
*  DESCRIPTION  : Demonstrates the issues with bitwise operators
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
 int x = 4;
 int y = ~x;
 printf("%d\n", y);

 x = 2147483647;
 y = x << 2; 
 printf("%d\n", y);
 
 x = 2147483647;
 y = x >> 32;  /* Change 32 to 16 after observing the warning */
 printf("%d\n", y);

 x = 2147483647;
 y = x >> -4; /* Change this to +ve */ 
 printf("%d\n", y);
 return 0;
}
