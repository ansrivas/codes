/*************************************************************************
*
*  FILE NAME    : var_header.h
*
*  DESCRIPTION  : Header file variable arguments program
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/* Check for multiple header file inclusion */
#ifndef VAR_HEADER_H
 #define VAR_HEADER_H

/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* Error codes */

#define FILE_ERROR 200
#define MEMORY_ERROR 500

/*******************************************************************************
*                       MACROS
*******************************************************************************/
/* Macros to specify number of arguments */
#define F_ERR_ARG 3
#define M_ERR_ARG 2

/*Return value of functions */
typedef enum {SUCCESS = 0, FAILURE = 1} return_type;

/*******************************************************************************
*                       FUCNTION PROTOTYPES
*******************************************************************************/
extern return_type error_handler(int , ...);
extern return_type remove_newline(char *);

#endif
