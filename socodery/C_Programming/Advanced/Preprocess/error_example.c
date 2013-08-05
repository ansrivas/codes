/*************************************************************************
*
*  FILE NAME    : error_example.c
*
*  DESCRIPTION  : Program to demonstrate #error
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#define USA 1
#define EUP 1

#include <stdio.h>


#if (!defined (USA) || !defined (EUP))
   #error ERROR: NO_CURRENCY rate is specified.
#endif

main()
{
    int rs;
    rs = 10;
    printf ("%d\n", rs);
}










     
