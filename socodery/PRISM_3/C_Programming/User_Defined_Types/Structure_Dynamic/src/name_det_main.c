/*************************************************************************
*
*  FILE NAME    : name_det_main.c
*
*  DESCRIPTION  : Program for storing first name and second name for
*		  a set of persons.
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/
/*****************************************************************************
*                       HEADER FILES
******************************************************************************/
#include "name_det_header.h"

/*****************************************************************************
*                       LOCAL MACROS
******************************************************************************/
#define SIZE 10

/******************************************************************************
*
*       Function Name   : main
*       Description     : Accepts a first name and second name of a max of 10
*			  persons and stores it in an array of structure.
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 char f_name[MAX], /* First name from user */ 
      s_name[MAX], /* Second name from user */
      input[MAX];  /* Choice from user */
 name_ret ret_val = SUCCESS; /* Return value from functions */
 char *fgets_ret = NULL; /* Return value from fgets */
 int person_index = 0;  /* Keeps track of number of inputs */
 /* Array of structure pointers */
 person_name_et *ptr_person[SIZE];

 memset(f_name,0,MAX);
 memset(s_name,0,MAX);

 /* Gets input from user till the array size is reached */ 
 while(person_index <= SIZE)
 {
  /* Gets user choice */
  printf("Press any key to continue, 'quit' to exist\n");
  fgets_ret = fgets(input,MAX,stdin);
  if(NULL == fgets_ret) /* Error check for fgets */
  {
   printf("fgets failed\n");
   ret_val = FAILURE;
   break;
  } 
  /* Checks whether user want to stop the input */
  if(strncmp(input,"quit",4) == 0)
  {
   ret_val = SUCCESS;
   break;
  }
  else /* User wants to continue */
  {
   /* Gets first name from user */
   printf("Enter the first name - maximum 31 characters\n");
   fgets_ret = fgets(f_name, MAX, stdin);
   if(NULL == fgets_ret) /* Error check for fgets */
   {
    printf("fgets failed\n");
    ret_val = FAILURE;
    break;
   } 
   /* Gets second name from user */
   printf("Enter the second name - maximum 31 characters\n");
   fgets_ret = fgets(s_name, MAX, stdin);
   if(NULL == fgets_ret) /* Error check for fgets */
   {
    printf("fgets failed\n");
    ret_val = FAILURE;
    break;
   } 
   /* Updates the array with user input. The correct index is to
      be passed here */
 
   printf ("First Name: %s\n", f_name);
   printf ("Second Name: %s\n", s_name);

   ret_val = update_person(&ptr_person[person_index],f_name,s_name);
   if(FAILURE == ret_val)
   {
    printf("update_person -failed\n");
    break;
   }
  }
  /* Incrementing the number of elements in the array */
  person_index += 1;
 } /* End of while */
 if(FAILURE == ret_val)
 {
  printf("Updating Details - Failure\n");
  printf("Displaying current output\n");
 }
 else
 {
  printf("Updating Details - Success\n");
  printf("Displaying current output\n");
 }
  
 /* Display the contents of the array */

/*
  for (index_1 = 0; index_1 <= person_index; index_1++)
  {
     printf("Person Number: %d\n", index_1 + 1);
     printf("/t First Name: %s\n", ptr_person[index_1]->first_name);
  }
*/

 ret_val = display_person(ptr_person,person_index);
 if(FAILURE == ret_val)
 {
  printf("Display failed\n");
  /* Deallocating memory from the array */
  free_person(ptr_person,person_index);
 } 
 /* Deallocating memory from the array */
 free_person(ptr_person,person_index);
 return 0;
}
