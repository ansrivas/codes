/*************************************************************************
*
*  FILE NAME    : identifier.c
*
*  DESCRIPTION  : Demonstates variables and constants. Also emphaizes
*		  the "initialization of local variable".
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
        int i,k;
	const int num;
        for(i = 0;i < 9;i++)
        {
                k = k + 1;
        }
//	num = num + k; /* Compiler gives the error here */
        printf("final value of k:%d\n",k);
        printf("value of num:%d\n",num);
        return 0;
}

