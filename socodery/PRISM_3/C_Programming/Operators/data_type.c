/*************************************************************************
*
*  FILE NAME    : data_type.c
*
*  DESCRIPTION  : Demonstrates "value  out of domain error " 
*
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include<stdio.h>
#include<limits.h>
int main()
{
        int num  = INT_MAX;
        printf("value is:%d\n",num);
	num = num + 1; 	/* Value goes of out of bounds */
        printf("value is:%d\n",num);
        return 0;
}

