/*************************************************************************
*
*  FILE NAME    : main.c
*
*  DESCRIPTION  : Contains main function and subsequent function calls
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

/*******************************************************************************
*
*  DESCRIPTION  : Calculate the day of the week on which a given date falls
*                 based on the Julian day for that date. The day of the week is
*                 calculated as follows
*
*                       year = year in question (all four digits)
*                       Jul_day = Julian day of date in question (1 to 366)
*                       fours = integer portion of (year- 1) / 4
*                       hundreds = integer portion of (year - 1) /100
*                       four_hund = integer portion of (year - 1) / 400
*                       day = (year + Jul_day + fours - hundreds + four_hun) % 7
*
*                       where
*                       Result  Means
*
*                       0       Saturday
*                       1       Sunday
*                       2       Monday
*                       3       Tuesday
*                       4       Wednesday
*                       5       Thursday
*                       6       Friday
******************************************************************************/

/*****************************************************************************
*			Header Files
******************************************************************************/

#include "day_header.h"

/******************************************************************************
*
*       Function Name   : main
*       Description     : main function for day program
*       Returns         : SUCCESS or FAILURE
*
*******************************************************************************/

int main()
{
        int user_year;
        int user_month;
        int user_day;

        int leap_check;

        int julian_date;

        int index_for_day;


        printf("\nEnter an year:\n");
        scanf("%d",&user_year);

        printf("\nEnter a month:\n");
        scanf("%d",&user_month);

        printf("\nEnter an day:\n");
        scanf("%d",&user_day);

        leap_check = leap_year_check(user_year);
        if(leap_check > 0)
        {
                printf("\n%d is a leap year",user_year);
        }
        else
	{
        printf("\n%d is not a leap year",user_year);

	}

	julian_date = julian_date_find(user_year,user_month,user_day);
	printf("\nJulian Date for %d-%d-%d is %d", user_day,user_month,
        		user_year,julian_date);


	index_for_day = day_of_the_week(user_year,julian_date);
	printf("\nIndex for day is %d",index_for_day);


	printf("\n\n*********************************************************");
	printf("\n\n\t\tTHE DAY IS:\t");
	display_day(index_for_day);
	printf("\n*********************************************************\n");

	return EXIT_SUCCESS;
}

