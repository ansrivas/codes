/*************************************************************************
*
*  FILE NAME    : byte_padding.c
*
*  DESCRIPTION  : Demonstration of byte padding
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
#include <string.h>
#include <stdlib.h>

/*****************************************************************************
*                       Macros
******************************************************************************/
#define MAX 6

/*****************************************************************************
*                       User Defined types
******************************************************************************/
typedef struct
{
 int id; 
 char name[MAX];
}sample1;

typedef struct
{
 int id; 
 char ch;
}sample2;

typedef struct
{
 float *f;
 char ch;
}sample3;

typedef struct
{
 long double d;
 int i;
 char ch;
}sample4;

typedef struct
{
 char ch1;
 char ch2;
}sample5;
/******************************************************************************
*
*       Function Name   : main
*       Description     : Displays size of a structure
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{ sample4 s4;

 printf("Size of short: %d\n", sizeof(short));
 printf("Size of int : %d\n", sizeof(int));
 printf("Size of char : %d\n", sizeof(char));
 printf("Size of long  : %d\n", sizeof(long ));
 printf("Size of long double : %d\n\n", sizeof(long double));

 printf("Size of structure is %d\n", sizeof(sample1));
 printf("Size of structure is %d\n", sizeof(sample2));
 printf("Size of structure is %d\n", sizeof(sample3));
 printf("Size of structure is %d\n", sizeof(sample4));
 printf("Size of structure is %d\n", sizeof(sample5));
 return 0;
}
