/*************************************************************************
*
*  FILE NAME    : file3.c
*
*  DESCRIPTION  : Sample program to demonstrate storage allocation
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
#include<stdio.h>
extern int a1;

/**************************************************************************
*
* FUNCTION NAME: next1
*
* DESCRIPTION: Sample function for storage allocation program
*
* RETURNS: Returns number of bits
**************************************************************************/

void next1(void)
{

	float b1;
	b1 = 20.3;
	printf("%d \n",a1);
	a1 = 15;
}
