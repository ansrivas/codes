/*************************************************************************
*
*  FILE NAME    : array_pointer.c
*
*  DESCRIPTION  : Finds out the maximum in an array and writes 0 there
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*                               HEADER FILES
*************************************************************************/
#include <stdio.h>

/*************************************************************************
*                               MACROS
*************************************************************************/
#define MAX 5
#define ROW 2
#define COL 3

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstration of arrays and pointers
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 int index_1; /* for loop indices */
 int index = 0; /* Stores the index of minimum value */
 int min; /* Variable to keep track of minimum in the array */

 /* 1-d array declaration and initilization */
 int numbers[MAX] = {44,22,11,55,33};

 min = 99; /* Initialized to maximum 2-digit number */ 

 /* Displaying the array */
 for(index_1 = 0; index_1 < MAX; index_1 += 1)
 {
   printf("%d\t", numbers[index_1]);
 }
 printf("\n");

 /* Searching for the minimum and replace thas with 0 */
 for(index_1 = 0; index_1 < MAX; index_1 += 1) 
 {
  if(*(numbers + index_1) < min) /* Checking for minimum */
  {
   min = *(numbers + index_1); /* Replacing min with new less value */
   index = index_1; /* Storing the index */
  }
 }
  *(numbers + index) = 0; /* Replacing minimum value with 0 */
  
 /* Displaying the array */
 for(index_1 = 0; index_1 < MAX; index_1 += 1)
 {
   printf("%d\t", numbers[index_1]);
 }
 printf("\n");
 return 0;
}
