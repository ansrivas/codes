/*************************************************************************
*
*  FILE NAME    : static.c
*
*  DESCRIPTION  : Sample program to demonstrate static variables
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include<stdio.h>

#define MAX 5

void sum_it(void);

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for storage allocation program
*
* RETURNS: Returns number of bits
**************************************************************************/

int main()
{
	int count;
	
	printf("Please enter 5 numers\n:");
	for(count = 0; count < MAX; count++)
		sum_it();

// printf("%d",sum);

	return 0;
}
/**************************************************************************
*
* FUNCTION NAME: sum_it
*
* DESCRIPTION: Sample function for static demo program
*
* RETURNS: Returns number of bits
**************************************************************************/

void sum_it(void)
{

	static int sum=0;

	int num;

	printf("\n Please enter a number:\n");
	scanf("%d", &num);

	sum += num;

	printf("\nThe current total is %d\n", sum);
} 
