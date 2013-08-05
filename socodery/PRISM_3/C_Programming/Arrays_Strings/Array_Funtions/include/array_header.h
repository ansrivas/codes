/*************************************************************************
*
*  FILE NAME    : array_header.h
*
*  DESCRIPTION  : Contains macros and function definitions for array program
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

/*******************************************************************************
*                       MACROS
*******************************************************************************/

#define IN
#define OUT
#define MODI

#define MAX 5
#define ROW 2
#define COL 3

/*******************************************************************************
*                       FUNCTION PROTOTYPES
*******************************************************************************/
extern void update_1d_array(int [], int);
extern void update_1d_ptr(int *, int);
extern void reverse_1d_ptr(int *, int);
extern void display_1d(int [], int);
extern void display_2d_array(int [][COL]);
extern void display_2d_ptr(int (*ptr)[COL]);
extern void display_2d_dbl_ptr(int **ptr);
