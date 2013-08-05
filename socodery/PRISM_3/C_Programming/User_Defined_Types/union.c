/*************************************************************************
*
*  FILE NAME    : union.c
*
*  DESCRIPTION  : Demonstration of union
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/
/*****************************************************************************
*                       Header Files
******************************************************************************/
#include <stdio.h>

/*****************************************************************************
*                       User Defined types
******************************************************************************/
typedef union
{
 int num;
 char ch;
}sample;

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstrates union
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 sample dummy;
 printf("size of union - %d\n", sizeof(sample));
 printf("Enter an integer\n");
 scanf("%d", &dummy.num);

 getchar();
 printf("Enter a character\n");
 scanf("%c", &dummy.ch);

 printf("The entered values are\n");
 printf("%d\t%c\n", dummy.num, dummy.ch);

 return 0;
}

