/*************************************************************************
*
*  FILE NAME    : arguments_display.c
*
*  DESCRIPTION  : Displays variable number of arguments
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
#include <stdio.h>
#include <stdarg.h>
#include<stdlib.h>
void printargs (int arg1, ...) /*print all int type args, finishing with -1 */
{
    va_list s;
   int g;
  
   va_start (s, arg1);   //s will point to first unnamed arg.
			 

// first call to va_arg() will give first unnamed arg

   for (g = arg1;g!= -1;g = va_arg(s,int))//return unnamed arg & points to next

     printf ("%d ", g);

   va_end (s);

   putchar ('\n');
}

int main(void)
{
   
    printargs (5, 14, 84, 97, 15, 24, 48, -1);

    printargs (84, 51, -1);

    printargs (-1);

    printargs (1, -1);

    return 0;
}


















