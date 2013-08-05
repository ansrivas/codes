/*************************************************************************
*
*  FILE NAME    : array_dbl_pointers.c
*
*  DESCRIPTION  : Program to demonstrate the relatioship between 2D array and 
*		  double pointers
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - double pointer program
*
* RETURNS: Nothing
**************************************************************************/
int main()
{
	long	mat[5][5], **ptr;

	mat[0][0] = 3;
	ptr = (long **) mat;

	printf("  mat          %p \n",  mat);
	printf("  ptr          %p \n",  ptr);
	printf("  mat[0][0]    %ld \n",  mat[0][0]);
	printf(" &mat[0][0]    %p \n", &mat[0][0]);
	printf(" &ptr[0][0]    %p \n", &ptr[0][0]);

        return 0;	
}

