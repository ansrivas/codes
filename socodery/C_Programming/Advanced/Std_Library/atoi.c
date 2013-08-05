/*************************************************************************
*
*  FILE NAME    : atoi.c
*
*  DESCRIPTION  : Program to demonstrate standard library
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
* DESCRIPTION: main function for std library program
*
* RETURNS: Nothing
**************************************************************************/

int main()
{
    int result;
    char *test1 = "310"; 
    char *test2 = "8434No number";

    result = atoi (test1);
    printf("Test1 is %d\n", result);

    result = atoi(test2);
    printf("Test2 is %d\n", result);
}

