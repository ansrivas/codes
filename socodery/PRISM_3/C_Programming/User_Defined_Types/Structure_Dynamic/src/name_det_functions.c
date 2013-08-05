/*************************************************************************
*
*  FILE NAME    : string_functions.c
*
*  DESCRIPTION  : Functions for storing name details of persons
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/***************************************************************************
*                       HEADER FILES
***************************************************************************/
#include "name_det_header.h"

/***************************************************************************
*                       LOCAL FUNCTIONS
***************************************************************************/
static name_ret remove_newline(char *);
static name_ret allocate_person(person_name_et **, int, int);

/****************************************************************************
*
*       Function Name   : remove_newline
*       Description     : Removes \n, if any, from the array
*       Returns         : Success or Failure
*
****************************************************************************/
static name_ret remove_newline(
                               char *arg_input /* input string */
                       	      )
{
  if(NULL == arg_input) /* Error handling for argument */
  {
   return FAILURE;
  }

  /* Finds out the length of the string */
  size_t str_len = strlen(arg_input);

  /* Checks whether a '\n' is appended at the end */
  if('\n' == arg_input[str_len - 1])
  {
   arg_input[str_len - 1] = '\0'; /* Replaces '\n' with '\0' */
  }
  return SUCCESS;
}
/****************************************************************************
*
*       Function Name   : allocate_person
*       Description     : Allocates memory for structure and elements
*       Returns         : Success or Failure
*
****************************************************************************/
static name_ret allocate_person(
				person_name_et **person, /* ptr to person */ 
				int len_first, /* Length of first name */
				int len_second /* Length of second name */
			       )
{
 /* Allocating memory for structure pointer */
 *person = (person_name_et *)malloc(sizeof(person_name_et));
 if(NULL == person) /* Error check for malloc */
 {
  printf("Malloc failure\n");
  return FAILURE;
 }
 /* Allocating memory for structure element */
 (*person)->first_name = (char *)malloc(len_first * sizeof(char)); 
 if(NULL == (*person)->first_name) /* Error check for malloc */
 {
  printf("Malloc failure\n");
  return FAILURE;
 }
 /* Allocating memory for structure element */
 (*person)->second_name = (char *)malloc(len_first * sizeof(char)); 
 if(NULL == (*person)->second_name) /* Error check for malloc */
 {
  printf("Malloc failure\n");
  return FAILURE;
 }
 return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : allocate_person
*       Description     : Copies the 1st & 2nd name to each array element
*       Returns         : Success or Failure
*
****************************************************************************/
name_ret update_person(
			person_name_et **person, /* Ptr to structure */
			char *first_arg, /* First name */
			char *second_arg /* Second name */
		      )
{
 /* Implemente this function which update each array element */
}
 
/****************************************************************************
*
*       Function Name   : display_person
*       Description     : Dispay the contents of the person array
*       Returns         : Success or Failure
*
****************************************************************************/
name_ret display_person(
			person_name_et *arg_person[], /* Array of persons */
			int arg_total /* Total number of persons */
		       )
{
 int index = 0; /* for loop index */
 /* Displaying the elements in the array */
 for(index = 0; index < arg_total; index += 1)
 {
  printf("person - %d\t", index + 1);
  printf("First Name - %s\t", arg_person[index]->first_name); 
  printf("Second Name - %s\n", arg_person[index]->second_name); 
 }
 return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : free_person
*       Description     : Deallocates memory allocated for person array
*       Returns         : Success or Failure
*
****************************************************************************/
name_ret free_person(
                      person_name_et *arg_person[], /* Array of persons */
                      int arg_total /* Total number of persons */
                    )
{
 /* Implement this function to deallocate the memory */
}
