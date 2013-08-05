/*************************************************************************
*
*  FILE NAME    : file1.c
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

#include "prototype.h"

/* Global Variable*/

int a1=0;
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main for storage allocation program
*
* RETURNS: Returns nothing
**************************************************************************/
int main()
{
	a1 = 2;
	printf("\na1 = %d\n", a1);
	next();
	printf("\na1 = %d\n", a1);
	next1();
	printf("\na1 = %d\n", a1);

	return 0;
}




















