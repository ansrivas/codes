/*************************************************************************
*
*  FILE NAME    : ptr_header.h
*
*  DESCRIPTION  : Header file for structure and pointer demonstration
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/* Avoiding multiple inclusions of header file */
#ifndef PTR_HEADER_H
 #define PTR_HEADER_H

/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <string.h>

/* Note: Header file is the place for user defined variables */

/* Point Structure. */
typedef struct
{
 int x; /* X co-ordinate */
 int y; /* Y co-ordinate */
}point;

#endif

