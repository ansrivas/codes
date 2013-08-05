/*************************************************************************
*
*  FILE NAME    : prototypes.h
*
*  DESCRIPTION  : Header file for date converter program
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
/*************************************************************************
*		HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**************************************************************************
*               GLOBAL DECLARATIONS
***************************************************************************/

typedef union month
{
int mth;
char mon[4];
}union_month;
typedef struct date_struct
{
        int day;
        union_month m;
        int year;
}struct_date;
struct_date date;

/*************************************************************************
*		FUNCTION PROTOTYPES
*************************************************************************/

void convert_day(int);
void convert_month(int);
int convert_mon_to_int(char []);
void convert_year(int);
