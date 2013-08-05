/*************************************************************************
*
*  FILE NAME    : pbv_pbr_main.c
*
*  DESCRIPTION  : Demonstrates pass by value and pass by reference
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

#include "pbv_pbr_header.h"

/******************************************************************************
*
*       Function Name   : main
*       Description     : Gets the data from user and invokes appropriate
*                         functions to demonsrate PBV and PBR
*       Returns         : Success or Failure
*
*******************************************************************************/

int main()
{
 int num_1 = 11, num_2 = 22;
 char ch_1 = 'A', ch_2 = 'Z';

 printf("Before the call of swap function\n");
 printf("********************************\n");
 printf("num_1 = %d , num_2 = %d\n", num_1, num_2);
 /*
  * Function Call to swap two integers
  */ 
 pbv_swap_int(num_1, num_2);
 printf("After the call of swap function\n");
 printf("********************************\n");
 printf("num_1 = %d , num_2 = %d\n", num_1, num_2);


 printf("Before the call of swap function\n");
 printf("********************************\n");
 printf("ch_1 = %c , ch_2 = %c\n", ch_1, ch_2);
 /*
  * Function Call to swap two characters
  */ 
 pbv_swap_char(ch_1, ch_2);
 printf("After the call of swap function\n");
 printf("********************************\n");
 printf("ch_1 = %c , ch_2 = %c\n", ch_1, ch_2);

 printf("Before the call of swap function\n");
 printf("********************************\n");
 printf("num_1 = %d , num_2 = %d\n", num_1, num_2);
 /*
  * Function Call to swap two integers
  */ 
 pbr_swap(&num_1, &num_2, INT); 
 printf("After the call of swap function\n");
 printf("********************************\n");
 printf("num_1 = %d , num_2 = %d\n", num_1, num_2);


 printf("Before the call of swap function\n");
 printf("********************************\n");
 printf("ch_1 = %c , ch_2 = %c\n", ch_1, ch_2);
 /*
  * Function Call to swap two characters
  */ 
 pbr_swap(&ch_1, &ch_2, CHAR); 
 printf("After the call of swap function\n");
 printf("********************************\n");
 printf("ch_1 = %c , ch_2 = %c\n", ch_1, ch_2);

 return 0;
}

