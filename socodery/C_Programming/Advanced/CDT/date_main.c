/*************************************************************************
*
*  FILE NAME    : date_functions.c
*  
*   DESCRIPTION  : To accept the date in any one of the following format
*     dd-mm-yy   (eg 12-04-07 assuming all the yrs are from 2000 onwards)
*     dd-Mon-yy  (eg 01-Jan-06 assuming all the yrs are from 2000 onwards)
*     dd-Mon-yyyy (eg 11-Feb-2007)
*     dd-mm-yyyy  (eg 12-05-2007)
*     dd-mm   (with default year as 2007)
*     After accepting, display the date in a sentence format
*     E.g the date 12-04-07 can be displayed as
*     The 12th day of the month April of the year 2007
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

#include "date_prototype.h"


/*****************************************************************************
* FUNCTION NAME: main
*
* DESCRIPTION: Takes the input in any of the format and calls appropriate functi
ons to display the date in resultant format
*
* RETURNS: Returns 0
*****************************************************************************/
int main()
{
        int choice;
        printf("Select The format for entering the date\n");
        printf("1. dd-mm-yy \n");
        printf("2. dd-mon-yy \n");
        printf("3. dd-mon-yyyy \n");
        printf("4. dd-mm-yyyy \n");
        printf("5. dd-mm \n");
        printf("6. Exit \n");
        printf("Enter your choice  ");
        scanf("%d",&choice);
        switch(choice)
        {
		 case 1:     
			printf("\n Enter the date ");
                 	scanf("%d",&date.day);
                	printf("\n Enter the month  ");
                 	scanf("%d",&date.m.mth);
                 	printf("\n Enter the year  ");
                 	scanf("%d",&date.year);
                 	convert_day(date.day);
                 	convert_month(date.m.mth);
                 	convert_year(date.year);
                 	break;
		 
		case 2:     
			printf("\n Enter the date ");
                 	scanf("%d",&date.day);
                 	printf("\n Enter the month  ");
                 	scanf("%s",&date.m.mon);
                 	printf("\n Enter the year  ");
                 	scanf("%d",&date.year);
                 	convert_day(date.day);
                 	convert_month(convert_mon_to_int(date.m.mon));
                 	convert_year(date.year);
                 	break;

		case 3:     
			printf("\n Enter the date ");
                	scanf("%d",&date.day);
                	printf("\n Enter the month  ");
                	scanf("%s",&date.m.mon);
                	printf("\n Enter the year  ");
                	scanf("%d",&date.year);
                	convert_day(date.day);
                	convert_month(convert_mon_to_int(date.m.mon));
                	convert_year(date.year);
                	break;

		case 4:     
			printf("\n Enter the date ");
                	scanf("%d",&date.day);
               	 	printf("\n Enter the month  ");
                	scanf("%d",&date.m.mth);
                	printf("\n Enter the year  ");
                	scanf("%d",&date.year);
                	convert_day(date.day);
                	convert_month(date.m.mth);
                	convert_year(date.year);
                	break;

		case 5:      
			printf("\n Enter the date ");
                	scanf("%d",&date.day);
                	printf("\n Enter the month  ");
                	scanf("%d",&date.m.mth);
                	convert_day(date.day);
                	convert_month(date.m.mth);
                	date.year = 0;
                	convert_year(date.year);
                	break;
		
		case 6: 
			break;
		
		default: 
			printf("\n Wrong choice entered");
	}
}
