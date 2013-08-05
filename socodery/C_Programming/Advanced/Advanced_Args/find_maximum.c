

/*************************************************************************
*
*  FILE NAME    : find_maximum.c
*
*  DESCRIPTION  : Finds out the maximum arbitrary number of variables using
*		  variadic functions
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int maxof(int , ...) ;
void initial(void);

int main()
	{
        initial();
        exit(EXIT_SUCCESS);
	}

/**************************************************************************
*
* FUNCTION NAME: maxof
*
* DESCRIPTION: Finds out the maximum of arguments
*
* RETURNS: Maximum integer
**************************************************************************/

int maxof(int n_args, ...)
{
        register int i;

        int a,max;

        va_list ap;


        va_start(ap, n_args);

        max = va_arg(ap, int);

        for(i=2;i<=n_args;i++)
        {
                if((a = va_arg(ap, int)) > max)
                        max = a;
        }
     

        va_end(ap);
        return max;
}

/**************************************************************************
*
* FUNCTION NAME: initial
*
* DESCRIPTION: Invokes function maxof
*
* RETURNS: Nothing
**************************************************************************/

void initial(void) 
{
        int i = 5;
        int j[256];
        j[42] = 24;
        printf("%d\n",maxof(3, i, j[42], 0));
        printf("%d\n",maxof(0));
	printf("%d\n",maxof(6,33,12,-8,78,34,100));
}

