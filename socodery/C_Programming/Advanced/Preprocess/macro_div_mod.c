/*************************************************************************
*
*  FILE NAME    : macro_div_mod.c
*
*  DESCRIPTION  : Finds out the quotient and remainder of two numbers using
*		  macors
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#define DIV(x, y)  (((y) == 0) ? 0 : (x)/(y))

#define MOD(x,y) (x)-((DIV(x,y))*(y))
# define p 20

#include <stdio.h>

int main()
{
 printf("%d",p);
 int num1, num2, mod;
 printf("\nEnter two integers\n");
 scanf("%d%d",&num1,&num2);
 printf("\nThe result of division is %d\n", DIV(num1,num2));
 mod = MOD(num1,num2);
 printf("\nThe result of modulus is %d\n", mod);
 
}
