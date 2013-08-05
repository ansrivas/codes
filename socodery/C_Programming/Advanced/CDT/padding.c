/*************************************************************************
*
*  FILE NAME    : padding.c
*
*  DESCRIPTION  : Simple program to demonstrate structure padding
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
*		GLOBAL DECLARATIONS
**************************************************************************/
struct sample1
{
 int *ptr;
 int i;
}s1;

struct sample2
{
 int *ptr;
 int i;
 char ch;
}s2;

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for padding demo
*
* RETURNS: Nothing
**************************************************************************/
int main()
{
 printf("%d\n",sizeof(s1));
 printf("%d\n",sizeof(s2));

 return EXIT_SUCCESS;
}
