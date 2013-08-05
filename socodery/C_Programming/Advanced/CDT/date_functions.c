/*************************************************************************
*
*  FILE NAME    : date_functions.c
*
*  DESCRIPTION  : Function Definitions for date converter program
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
/**************************************************************************
*		HEADER FILES
***************************************************************************/

#include "date_prototype.h"


/*****************************************************************************
* FUNCTION NAME: convert_day
*
* DESCRIPTION: Adds the subscript with the day
*
* RETURNS: Returns Null
*****************************************************************************/
void convert_day(int day)
{
 if ((day>0) && (day<=31))
 {
  switch(day)
  {
   case 1:
   case 21:
   case 31: printf("The %dst day of the month ",day);
                break;
   case 2:
   case 22 : printf("The %dnd day of the month ",day);
                break;
   case 3:
   case 23 : printf("The %drd day of the month ",day);
                break;

   default: printf("The %dth day of the month ",day);
                break;
  }
 }
 else
  printf("\nWrong Day entered");
}


/*****************************************************************************
* FUNCTION NAME: convert_month
*
* DESCRIPTION: It prints the month in character
*
* RETURNS: Returns Null
*****************************************************************************/
void convert_month(int month)
{
 if ((month>0)&&(month <13))
 {
  switch(month)
  {
   case 1:printf("January");
        break;
   case 2:printf("February");
        break;
   case 3:printf("March");
        break;
   case 4:printf("April");
        break;
   case 5:printf("May");
        break;
   case 6:printf("June");
        break;
   case 7:printf("July");
        break;
   case 8:printf("August");
        break;
   case 9:printf("September");
        break;
   case 10:printf("October");
        break;
   case 11:printf("November");
        break;
   case 12:printf("December");
  }
 }
 else
  printf("\nWrong month entered");
}


/*****************************************************************************
* FUNCTION NAME: convert_year
*
* DESCRIPTION: Writes the year as per the format
*
* RETURNS: Returns Null
*****************************************************************************/
void convert_year(int year)
{
 int d;
 d=year;
 int count=0;
 while(d!=0)
 {
  d=d/10;
  count++;
 }
 
 switch(count)
 {
  case 0: 
    printf(" of the year 2007 ");
    break;
  case 1:
    printf(" of the year 200%d ",year);
    break;
  case 2:
    printf(" of the year 20%d ",year);
    break;
  case 4:
    printf(" of the year %d ",year);
    break;
  default: 
    printf("\n Wrong year entered");
 }
}


/*****************************************************************************
* FUNCTION NAME: convert_mon_to_int
*
* DESCRIPTION: It convert the month from string to number
*
* RETURNS: Returns month number
*****************************************************************************/
int convert_mon_to_int(char mon[4])
{
 int i;
 if(strcmp(mon,"Jan")==0)
        return 1;
 else if(strcmp(mon,"Feb")==0)
 	return 2;
 else if(strcmp(mon,"Mar")==0)
 	return 3;
 else if(strcmp(mon,"Apr")==0)
 	return 4;
 else if(strcmp(mon,"May")==0)
 	return 5;
 else if(strcmp(mon,"Jun")==0)
 	return 6;
 else if(strcmp(mon,"Jul")==0)
 	return 7;
 else if(strcmp(mon,"Aug")==0)
 	return 8;
 else if(strcmp(mon,"Sep")==0)
 	return 9;
 else if(strcmp(mon,"Oct")==0)
 	return 10;
 else if(strcmp(mon,"Nov")==0)
 	return 11;
 else if(strcmp(mon,"Dec")==0)
 	return 12;
}
