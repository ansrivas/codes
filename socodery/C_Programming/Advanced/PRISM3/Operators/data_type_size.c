/*************************************************************************
*
*  FILE NAME    : data_type_size.c
*
*  DESCRIPTION  : Displays size of different data types
*
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>

int main()
{
 printf("%d\n", sizeof (signed char));
 printf("%d\n", sizeof (unsigned char));

 printf("%d\n", sizeof (short int));
 printf("%d\n", sizeof (unsigned short int));
 
 printf("%d\n", sizeof (long int));
 printf("%d\n", sizeof (unsigned long int));

 printf("%d\n", sizeof (float));
 
 printf("%d\n", sizeof (double));
 printf("%d\n", sizeof (long double));
 return 0;
}
