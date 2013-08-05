/*************************************************************************
*
*  FILE NAME    : ptr_const.c
*
*  DESCRIPTION  : Demonstrated pointer to constant and constant pointer
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/*******

Note: Please uncomment different statements and observer what happens 

*******/

#include <stdio.h>
#include <stdlib.h>

int main()
{
 const int num = 10;
 int dummy = 11; 

 int *ptr;
 int *ptr2;

// const int *ptr3 = &num;
 int *ptr3 = &num;
/* 
 ptr = &dummy;

 printf("Num is %d\n", num);
 printf("Dummy is %d\n", *ptr);

 ptr2 = &num;
 *ptr2 = 100;
 printf("Num through ptr is %d\n", *ptr2);
 printf("Num now is %d\n", num);
*/

 printf("Ptr3 is %d\n", *ptr3);
 *ptr3 = 50;
 printf("Ptr3 after change is %d\n", *ptr3);


 return 0;
}

