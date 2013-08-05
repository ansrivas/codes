/*************************************************************************
*
*  FILE NAME    : realloc.c
*
*  DESCRIPTION  : Program to demo dynamic memory allocation using realloc
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
#include<stdio.h>
#include <stdlib.h>
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for realloc program
*
* RETURNS: Nothing
**************************************************************************/

int main() 
{
  int *ptr;
  int i;

  ptr = calloc(5, sizeof(int));

  if(ptr!=NULL) 
  {
    *ptr = 1;
    *(ptr+1) = 2;
    ptr[2] = 4;
    ptr[3] = 8;
    ptr[4] = 16;
    //  ptr[5] = 32; wouldn't assign anything 

    ptr = realloc(ptr, 7*sizeof(int));

    if(ptr!=NULL) 
    {
      printf("Now allocating more memory... \n");
      ptr[5] = 32; /* now it's legal! */
      ptr[6] = 64;

      for(i=0 ; i<7 ; i++) 
      {
        printf("ptr[%d] holds %d\n", i, ptr[i]);
      }
      realloc(ptr,0); /* same as free(ptr); - just fancier! */
      return 0;
    }
    else 
    {
      printf("Not enough memory - realloc failed.\n");
      return 1;
    }
  }
  else 
  {
    printf("Not enough memory - calloc failed.\n");
    return 1;
  }
}

