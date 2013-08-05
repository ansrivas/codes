/********************************************************************************
*
*  FILE NAME    : divisibility_check.c
*
*  DESCRIPTION: It takes as an input an array and a parameter N and checks 
*		whether N is divisible by the values in the array or not.
*
*    DATE    NAME    REFERENCE    REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2007,  Technologies (Holdings) Ltd
*******************************************************************************/

#include<stdio.h>
/*******************************************************************************
*
* FUNCTION NAME: check
*
* DESCRIPTION: Checks whether the number N is divisible be the elements of the array or not.
*
* RETURNS: Returns 0
*******************************************************************************/
void check(int array_length,int *array,int number)
{
 int i;
 for(i=0;i<array_length;i++)
 {
  if(number%(*(array+i))==0)
  {
    printf("\nThe number is divisible by %d",*(array+i));
  }
 }
}
/*******************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Takes an array as an input and a number N.
*
* RETURNS: Returns 0
*******************************************************************************/
int main()
{
 int array_num,i,number;
 int array[5];
 printf("Enter the total number of elements in the array\n");
 scanf("%d",&array_num);
 printf("\n Enter the array elements\n");
 for(i=0;i<array_num;i++)
 {
   scanf("%d",&array[i]);
 }
 printf("\n Enter the number which has to be checked for divisibility\n");
 scanf("%d",&number);
 check(array_num,&array,number);
 return 0;
}

