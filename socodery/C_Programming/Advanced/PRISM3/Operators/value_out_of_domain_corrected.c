/*************************************************************************
*
*  FILE NAME    : value_out_domain_corrected.c
*
*  DESCRIPTION  : Demonstrates how to tackle "value out of domain" error
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
int main()
{
        long long unsigned int fact=1;
        int count,num;
        printf("Enter a number:");
        scanf("%d",&num);
        for(count = 1;count <= num;count++)
        {
                fact = fact * count;
        }
        printf("factorial of %d is :%llu\n",num,fact);
        return 0;
}

