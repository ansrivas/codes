/*************************************************************************
*
*  FILE NAME    : day_header.h
*
*  DESCRIPTION  : Contains header files and function prototypes for day prg
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
*                       FUCNTION PROTOTYPES
*******************************************************************************/

extern int leap_year_check(int);
extern int julian_date_find(int,int,int);
extern int day_of_the_week(int,int);
extern void display_day(int);

