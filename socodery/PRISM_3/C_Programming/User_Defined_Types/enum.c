/*************************************************************************
*
*  FILE NAME    : enum.c
*
*  DESCRIPTION  : Demonstration of enumerated data types
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
#include <stdio.h>

/*****************************************************************************
*                       User Defined types
******************************************************************************/

/* This is used as an error type from functiosns. The advantage that enum gives
   over macros is that the domain of values is limited. That means the return
   value can be only SUCCESS or FAILURE, in this example. */
typedef enum{
 FAILURE = 0,
 SUCCESS = 1
}ret_type_et;

/******************************************************************************
*
*       Function Name   : my_alloc
*       Description     : Allocates memory
*       Returns         : Success or Failure
*
*******************************************************************************/
ret_type_et my_alloc(
		     char **arg /* Address of pointer */
		    )
{
 *arg = (char *)malloc(sizeof(char));
 if(NULL == *arg)
 {
  return FAILURE;
 }
 return SUCCESS;
}
/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstrates union
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 char *ptr = NULL;
 ret_type_et ret_val = SUCCESS;
 printf("Enum = %d\n", ret_val);
 ret_val = my_alloc(&ptr);
 if(FAILURE == ret_val)
 {
  printf("Memory allocation failed\n");
 }
 else
 {
  free(ptr);
  ptr = NULL;
 }
 
 return 0;
}

