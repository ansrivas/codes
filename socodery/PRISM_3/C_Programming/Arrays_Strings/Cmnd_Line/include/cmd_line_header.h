/*************************************************************************
*
*  FILE NAME    : cmc_line_header.h
*
*  DESCRIPTION  : Contains header files and function prototypes for command
*		  line arguments program
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/* Avoiding multiple inclusions of header file */
#ifndef CMD_LINE_HEADER_H
  #define CMD_LINE_HEADER_H
/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define cmd_ret int
#define FAILURE 0
#define SUCCESS 1

#define MAX 32

/*******************************************************************************
*                       FUCNTION PROTOTYPES
*******************************************************************************/
extern cmd_ret process_args(char *[], char *);

#endif

