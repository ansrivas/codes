/*************************************************************************
*
*  FILE NAME    : antonym_header.h
*
*  DESCRIPTION  : Contains macros and function definitions for antonym program
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define MAX 32

#define ant_ret int
#define SUCCESS 1
#define FAILURE 0

/*******************************************************************************
*                       FUNCTION DECLARATIONS
*******************************************************************************/
extern ant_ret get_string(char *);
extern ant_ret remove_newline(char *);
extern ant_ret display_string(char *);
extern ant_ret search_antonym (char *, char **);

