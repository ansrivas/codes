/*************************************************************************
*
*  FILE NAME    : bitwise_swap.c
*
*  DESCRIPTION  : Swapping of 2 values using bitwise XOR (^)
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
 unsigned int num1 = 10;
 unsigned int num2 = 20;
 printf("num1 = %d, num2 = %d\n", num1, num2);

 num1 ^= num2;
 num2 ^= num1;
 num1 ^= num2;
 printf("num1 = %d, num2 = %d\n", num1, num2);
 
 return 0;
}
