/*************************************************************************
*
*  FILE NAME    : stdin_flush.c
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

#include<stdio.h>
#include<string.h>
/**************************************************************************
*
* FUNCTION NAME: dump_line
*
* DESCRIPTION: Reads characters from file till EOF or new line
*
* RETURNS: Nothing
**************************************************************************/
void dump_line( FILE * fp )
{
  int ch;

  while( (ch = fgetc(fp)) != EOF && ch != '\n' )
    /* null body */;
}

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
 int x;
 char st[31];

 printf("Enter an integer: ");
 scanf("%d", &x);
 //getchar();
 //dump_line(stdin);

 printf("Enter a line of text: ");
 fgets(st, 30, stdin);

 printf("\n\n\n%d\n",x);

 printf("\n\n\n%s",st);
}

















