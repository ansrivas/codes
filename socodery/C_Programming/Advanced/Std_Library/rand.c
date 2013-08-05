/*************************************************************************
*
*  FILE NAME    : rand.c
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

#include <stdlib.h>
#include <stdio.h> 
#include <time.h>
/**************************************************************************
*
* FUNCTION NAME: dieroll
*
* DESCRIPTION: Created random  numbers
*
* RETURNS: Random Number
**************************************************************************/
int dieroll ()
{   
   return ((rand () % 6) + 1);
} 

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
   int total = 0, die, nd;

   for (nd = 0; nd < 3; nd++)
   {   
      die = dieroll ();
      total += die; 

      printf (" Die roll %d: %d\n", nd + 1, die);
   } 
   printf ("\nThe total of the three dice is %d.\n", total); 
} 

