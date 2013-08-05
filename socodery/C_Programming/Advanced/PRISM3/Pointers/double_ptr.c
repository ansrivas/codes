/*************************************************************************
*
*  FILE NAME    : double_ptr.c
*
*  DESCRIPTION  : Demonstrates single pointer and  double pointer.
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>

int main()
{ 
 int x = 11, 
     y = 22, 
     *ptr = NULL, 
     *ptr1 = NULL, 
     **pptr = NULL; 
 ptr = &x; /* Assign address of x to ptr */ 
 ptr1 = &y; /* Assign address of y to ptr1 */ 
 pptr = &ptr; /* Assign address of ptr to pptr */ 
 
 printf("Using Single Pointer\n");
 printf("********************\n"); 
 *ptr = 0; /* set x to zero */ 
 printf("x is %d\n", x); /* 0 will be printed here */
 printf("*ptr is %d\n", *ptr); /* again zero will be printed*/

 *ptr += 1; /* increment what p points to */ 
 printf("x is %d\n", x); /* 1 will be printed here*/

 (*ptr)++; /* increment x using single pointer */
 printf("x is %d\n", x); /* 2 will be printed here*/ 

 printf("Using Double Pointer\n");
 printf("********************\n"); 

 **pptr = 100; /* set x to 100 */ 
 printf("x is %d\n", x); /* 100 will be printed here */
 printf("*ptr is %d\n", *ptr); /* again 100 will be printed*/
 printf("**pptr is %d\n", **pptr); /* again 100 will be printed*/

 **pptr += 1; /* increment x using double pointer */ 
 printf("x is %d\n", x); /* 101 will be printed here*/

 (**pptr)++; /* increment what p points to */
 printf("x is %d\n", x); /* 102 will be printed here*/ 

 pptr = &ptr1; /* Now pptr points to ptr1 */
 printf("**pptr is %d\n", **pptr); /* 22 will be printed here */ 

 return 0;
}

