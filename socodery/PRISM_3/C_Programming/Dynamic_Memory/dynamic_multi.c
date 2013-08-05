/*************************************************************************
*
*  FILE NAME    : dynamic_multi.c
*
*  DESCRIPTION  : Demonstrate how to allocate memory for multi-dimensionally
*		  and for array of pointers
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*************************************************************************
                        MACROS
**************************************************************************/
#define ROW 3
#define MAX 32
/******************************************************************************
*       Function Name   : main
*       Description     : Demonstates dynamic memory allocation
*       Returns         : Success or Failure
*******************************************************************************/
int main()
{
 char *names[ROW]; /* Array of pointers */
 char **cities = NULL; /* Double pointer */
 int index = 0; /* for loop index */

 /* Initialzing array of pointers */
 memset(names, 0 , ROW);
 
 /* Allocating memory for array of pointers and copying some string */
 for(index = 0; index < ROW; index += 1)
 {
  names[index] = (char *)malloc(MAX * sizeof(char));
  if(NULL == names[index])
  {
   printf("malloc failure\n");
   exit(EXIT_FAILURE);
  }
  strncpy(names[index], " Technologies", MAX - 1);
 }
 
 /* Printing values for array of pointers and freeing the memory */
 for(index = 0; index < ROW; index += 1)
 {
  printf("names[%d] = %s\n", index, names[index]);
  free(names[index]);
  names[index] = NULL;
 }
 /* Allocating memory for pointer to make ROW number of pointers */
 cities = (char **)malloc(ROW * sizeof(char *));
 if(NULL == cities)
 {
  printf("malloc failure\n");
  exit(EXIT_FAILURE);
 }

 /* Allocating memory for each pointer */
 for(index = 0; index < ROW; index += 1)
 {
  cities[index] = (char *)malloc(MAX * sizeof(char)); 
  if(NULL == cities[index])
  {
   printf("malloc failure\n");
   exit(EXIT_FAILURE);
  }
  strncpy(cities[index], "Gurgaon Bangalore Chennai", MAX - 1);
 }

 /* Displaying the content of memory pointed by double pointer and freeing it */
 for(index = 0; index < ROW; index += 1)
 {
  printf("cities[%d] = %s\n", index , cities[index]);
  /* freeing the inner pointers */
  free(cities[index]);
  cities[index] = NULL;
 }
 /* We must free the outer pointer as well. Comment the below line and see
    the output with valgrind */
 free(cities);
 cities = NULL;
 return 0;
}
