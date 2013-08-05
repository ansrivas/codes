/*************************************************************************
*
*  FILE NAME    : integral_promotion.c
*
*  DESCRIPTION  : Demonstrates implicit type casting and integral promotion
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
 char ch = 'A';
 signed int num = -10;
 unsigned int u_int = 234;
 float val = 23.76; 
 
 printf("%d\n", ch + num);
 printf("%f\n", val / num);
 printf("%d\n", u_int / num);
 return 0;
}
