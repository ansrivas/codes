/*************************************************************************
*
*  FILE NAME    : day_functions.c
*
*  DESCRIPTION  : Function definitios for day from julian program
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
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

int leap_year_check(
			int leap_year /* Input Variable - Year */
		   )
{
        int leap_return = 0; /* Value to be returned from the function */

	/* Checking for leap year */
        if (((0 == leap_year % 4) && (0 != leap_year % 100)) || (0 == leap_year % 400))
        {
                leap_return = 1;
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

int julian_date_find(
			int year,  /* Input - Year */ 
			int month, /* Input - Month */
			int day    /* Input - Day */
		    )
{
        int mon_count = 1; /* To keep track of month count */
        int days_count = day; /* To keep track of day count */

        while(mon_count < month) /* Till the given month */
        {
		/* If there are 31 days in a month */
                if((mon_count == 1) || (mon_count == 3) || (mon_count == 5) ||
                 (mon_count == 7) || (mon_count == 8) || (mon_count == 10) ||
                 (mon_count == 12))
		{
                        days_count = days_count + 31;
		}
		/* If there are only 30 days in a month */
                else if((mon_count == 4) || (mon_count == 6) || (mon_count==
                        9) || (mon_count == 11))
		{
                        days_count = days_count + 30;
		}
		/* If there are 29 days in Feb */
                else if ((mon_count == 2) && (leap_year_check(year)))
		{
                        days_count = days_count + 29;
		}
		/* If there are 28 days in Feb */
                else if((mon_count == 2) && (!leap_year_check(year)))
		{
                        days_count = days_count + 28;
		}

                mon_count++; /* Incrementing month */
        } /* End of While */

        return days_count;
}

/******************************************************************************
*
*       Function Name   : day_of_the week
*       Description     : Finds out the index of the day 
*       Returns         : Day index
*
*******************************************************************************/

int day_of_the_week(
			int year,  /* Input - Year */ 
			int julian /* Input - Julian Date */
		   )
{

        int day_index = 0; /* Stores the index of the day */
	/* Temporary variables*/
        int cal_julian = julian; 
        int cal_year = year; 
        int fours = (cal_year - 1) / 4;
        int hundreds = (cal_year - 1) / 100;
        int four_hund = (cal_year - 1) / 400;

        /* Calculating the day index */
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


void display_day(
		 int day_index /* Input : Index of the day */
		)
{
	/* Switches based on the index */
        switch(day_index)
        {
                case 0:
			{
                         printf("Saturday\n");
                         break;
			}
                case 1:
			{
                         printf("Sunday\n");
                         break;
			}
                case 2:
			{
                         printf("Monday\n");
                         break;
			}
                case 3:
			{
                         printf("Tuesday\n");
                         break;
			}
		case 4:
			{
                         printf("Wednesday\n");
                         break;
			}
                case 5:
			{
                         printf("Thursday\n");
                         break;
			}
                case 6:
			{
                         printf("Friday\n");
                         break;
			}
		default:
			{
			 printf("Invalid Index\n");
			 break;
			}
        }
}

