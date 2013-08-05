/*************************************************************************
*
*  FILE NAME    : break_continue.c
*
*  DESCRIPTION  : Demonstrates the use of break and continue. Program prints 
*		  2,4, stops for a while and start printing -ve numbers
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include<stdio.h>
int main()
{
   int num = 0;
   while(((num += 1) > 0) || ((num += 1) < 10))
   {
      if(num > 4)
      {
         num++;
         continue;
      }
      if(num > 8) 
      {
         break; /* This will never be executed */
      }
      num++;
      printf("%d\n",num);
   } /*End of while */
   return 0;
}
