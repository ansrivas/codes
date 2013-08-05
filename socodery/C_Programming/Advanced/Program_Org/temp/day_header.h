/*************************************************************************
*
*  FILE NAME    : day_header.h
*
*  DESCRIPTION  : Contains header files and function prototypes for day prg
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
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

int leap_year_check(int);
int julian_date_find(int,int,int);
int day_of_the_week(int,int);
void display_day(int);

