/*************************************************************************
*
*  FILE NAME    : day_functions.c
*
*  DESCRIPTION  : Function definitios for day from julian program
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*			Header Files
**************************************************************************/

#include "day_header.h"

/******************************************************************************
*
*       Function Name   : leap_year_check
*       Description     : Finds out whether an year is a leap year or not
*       Returns         : 0 if not leap year and 1 if leap year
*
*******************************************************************************/

int leap_year_check(int leap_year)
{
        int leap_return=0;

        if (((leap_year % 4) == 0) && ((leap_year % 100) != 0) || ((leap_year %
                400) == 0))
        {
                leap_return=1;
        }

        return leap_return;
}

/******************************************************************************
*
*       Function Name   : julian_date_find
*       Description     : Finds out the julian date of a date
*       Returns         : Julian date
*
*******************************************************************************/

int julian_date_find(int year, int month, int day)
{
        int mon_count = 1;
        int days_count = day;

        while(mon_count < month)
        {
                if((mon_count == 1) || (mon_count == 3) || (mon_count == 5) ||
                 (mon_count == 7) || (mon_count == 8) || (mon_count == 10) ||
                 (mon_count == 12))
                        days_count = days_count + 31;
                else if((mon_count == 4) || (mon_count == 6) || (mon_count==
                        9) || (mon_count == 11))
                        days_count = days_count + 30;
                else if ((mon_count == 2) && (leap_year_check(year)))
                        days_count = days_count + 29;
                else if((mon_count == 2) && (!leap_year_check(year)))
                        days_count = days_count + 28;

                mon_count++;
        }

        return days_count;
}

/******************************************************************************
*
*       Function Name   : day_of_the week
*       Description     : Finds out the julian date of a date
*       Returns         : Julian date
*
*******************************************************************************/

int day_of_the_week(int year, int julian)
{

        int day_index;
        int cal_julian = julian;

        int cal_year = year;
        int fours = (cal_year - 1) / 4;
        int hundreds = (cal_year -1) / 100;
        int four_hund = (cal_year - 1) / 400;

        day_index = (cal_year + cal_julian + fours - hundreds + four_hund) % 7;

        return day_index;
}

/******************************************************************************
*
*       Function Name   : display_day
*       Description     : Displays the day of the week using the day index
*       Returns         : Nothing
*
*******************************************************************************/


void display_day(int day_index)
{

        switch(day_index)
        {
                case 0:
                        printf("Saturday\n");
                        break;

                case 1:
                        printf("Sunday\n");
                         break;

                case 2:
                        printf("Monday\n");
                        break;

                case 3:
                        printf("Tuesday\n");
                        break;
		                case 4:
                        printf("Wednesday\n");
                        break;

                case 5:
                        printf("Thursday\n");
                        break;

                case 6:
                        printf("Friday\n");
                        break;
        }
}

