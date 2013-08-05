/*************************************************************************
*
*  FILE NAME    : cmndline_display.c
*
*  DESCRIPTION  : Display command line arguments and environment variables
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>

int main( int argc, /* Number of strings in array argv */
 char *argv[])       /* Array of command-line argument strings */
{
    int count;

    /* Display each command-line argument. */
    printf( "\nCommand-line arguments:\n" );
    for( count = 0; count < argc; count++ )
        printf( "  argv[%d]   %s\n", count, argv[count] );

    return 0;
}


