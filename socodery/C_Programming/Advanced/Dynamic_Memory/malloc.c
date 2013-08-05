/*************************************************************************
*
*  FILE NAME    : malloc.c
*
*  DESCRIPTION  : Program to demo dynamic memory allocation using malloc
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
#include <stdlib.h> /* required for the malloc and free functions */

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for malloc program
*
* RETURNS: Nothing
**************************************************************************/

int main() 
{
  int number;
  int *ptr;
  int i;

  printf("How many ints would you like store? ");
  scanf("%d", &number);

  ptr = malloc(number*sizeof(int)); /* allocate memory */
 
  if(ptr!=NULL) 
  {
    for(i=0 ; i<number ; i++) 
    {
      *(ptr+i) = i;
    }

    for(i=number ; i>0 ; i--) 
    {
      printf("%d\n", *(ptr+(i-1))); /* print out in reverse order */
    }

    free(ptr); /* free allocated memory */
    return 0;
  }
  else 
  {
    printf("\nMemory allocation failed - not enough memory.\n");
    return 1;
  }
}
