/*************************************************************************
*
*  FILE NAME    : ctype.c
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

#include <ctype.h> 
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

int main () 
{   
   int test; 
   char *ans[2] = {" not ", ""}; 

   for (test = -1; test < 256; test++) 
   {   
      printf ("\n\n\nThe value %d is :\n",  test); 
      printf (" %salphanumeric\n",  ans[(isalnum(test) != 0)]); 
      printf (" %sa letter\n",  ans[(isalpha(test) != 0)]); 
      printf (" %sascii\n",   ans[(__isascii(test) != 0)]); 
      printf (" %sa control\n",  ans[(iscntrl(test) != 0)]); 
      printf (" %sa digit\n",  ans[(isdigit(test) != 0)]); 
      printf (" %sprintable/ not a space\n",  ans[(isgraph(test) != 0)]); 
      printf (" %slower case\n", ans[(islower(test) != 0)]); 
      printf (" %sprintable\n", ans[(isprint(test) != 0)]); 
      printf (" %sa punctuator\n", ans[(ispunct(test) != 0)]); 
      printf (" %swhite space\n", ans[(isspace(test) != 0)]); 
      printf (" %supper case\n", ans[(isupper(test) != 0)]); 
      printf (" %sa hexadecimal digit\n", ans[(isxdigit(test) != 0)]); 
      printf ("\n* Press a key for the next value*\n");
	getchar();
   } 
} 

