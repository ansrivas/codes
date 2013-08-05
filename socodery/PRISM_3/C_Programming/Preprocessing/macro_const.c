/*************************************************************************
*
*  FILE NAME    : macro_const.c
*
*  DESCRIPTION  : Demonstrates how macros are used as defined constants
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>

#define PI 3.14

int main()
{
 int radius = 0;
 float area = 0.0;
 printf("Enter the radius of the circle\n");
 scanf("%d", &radius);

 /* Finds out the area of the circle for given radius */
 area = PI * radius * radius;

 printf("Area of the circle is %f\n", area);
 return 0;
}
