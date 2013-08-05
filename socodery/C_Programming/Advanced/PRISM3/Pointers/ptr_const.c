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

 /* Intialising the pointer variable */ 
 int *ptr = NULL; 

 /* Observe the error given by compiler */ 
// num = 100; /* Trying to change the const */
 
 /* Uncomment the following and observe the warning given by compiler */ 
 // *ptr = &num;

 /* Uncomment this and appreciate that a const can be changed by a compiler. "const" is an information to compiler, the assigned memmory is not read-only */
 // *ptr = 100;

 /* Correct pointer type to a const */
 const int *ptr2 = &num; // Pointer to a constant

 /* There is no difference between this and the above */
 int const *ptr1 = &dummy; // Pointer to a constant

 /* We can not change the value pointed by ptr1 */ 
 // *ptr1 = 100;
 
 /* We can not change the value pointer by ptr2 as well even though the target
    not a const. */
   *ptr2 = 200;
 // dummy = 300;

 /* Declaring a const pointer. The target value may change, but the pointer will always point to the same object */
 // int * const ptr3 = &num; // Constant pointer to int

 /* We can change the value pointed by a constant pointer */
 //*ptr3 = 300;
 
 /* We can not make the pointer point to another obeject */
 // ptr3 = &dummy;

 /* Neither pointer nor object can be modified */
 // const int * const ptr4 = &num; // const pointer to const int 

 return 0;
}

