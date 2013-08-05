/*************************************************************************
*
*  FILE NAME    : explicit_typecasting.c
*
*  DESCRIPTION  : Demonstrates the how explicit type casting is done
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
 signed int num = 10;
 unsigned int u_int = 234;
 float val = 23.76; 
 
 printf("%d\n", (int) ch + num);
 printf("%f\n", val /(float) num);
 printf("%u\n", u_int / (unsigned ) num);
 return 0;
}
