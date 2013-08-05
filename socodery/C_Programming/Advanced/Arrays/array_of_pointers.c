/*************************************************************************
*
*  FILE NAME    : array_of_pointers.c
*
*  DESCRIPTION  : Sample program to demonstrate array of pointers
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for array of pointers program
*
* RETURNS: Nothing
**************************************************************************/
int main() 
{
  int int_array[3] = {1,2,3};  /* an array of ints */
    
  int *ptr1 = &int_array[0];   /* ptr1 stores address 
                                of int_array[0] */
  int *ptr2 = &int_array[1];   /* ptr2 stores address 
                                of int_array[1] */

  int *ptrs[3] = {ptr1, ptr2, &int_array[2]};

  /* ptrs is an array that stores the addresses of 
     int_array[0], int_array[1] and int_array[2]  
     respectively - notice the type of ptr_array is int * */

  printf("The value of variable stored at 0x%p is %d\n", 
          ptrs[0], *ptrs[0]);
  printf("The value of variable stored at 0x%p is %d\n", 
          ptrs[1], *ptrs[1]);
  printf("The value of variable stored at 0x%p is %d\n", 
          ptrs[2], *ptrs[2]);
  return 0;
}


