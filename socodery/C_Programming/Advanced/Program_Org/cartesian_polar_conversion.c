/*************************************************************************
*
*  FILE NAME    : cartesian_polar_conversion.c
*
*  DESCRIPTION  : Program for conversion from polar system to cartesian and
*		  vice versa using functions
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*                       Include Files
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
/*
* FUNCTION NAME: polar2cart
*
* DESCRIPTION: Converts polar cordinate system to cartesian system
*
* RETURNS: Nothing
**************************************************************************/

void polar2cart(double *xp, double *yp,
                double rad, double arg)
{
  *xp = rad * cos(arg);
  *yp = rad * sin(arg);
}
/**************************************************************************
*
* FUNCTION NAME: cart2polar
*
* DESCRIPTION: Converts cartesian cordinate system to polar system
*
* RETURNS: Nothing
**************************************************************************/
void cart2polar(double *radp, double *argp,
                double x, double y)
{
  *argp = atan2(y, x);
  *radp = sqrt(x * x + y * y);
}

int main()
{
  double rad, arg;
  double x = 20.0, y = 45.0;

  /* Show initial cartesian co-ords. */
  printf("x = %.3g, y = %.3g\n", x, y);

  /* Convert to polar. */
  cart2polar(&rad, &arg, x, y);

  /* Double the radius. */
  rad *= 2;

  /* Convert back to cartesian. */
  polar2cart(&x, &y, rad, arg);

  /* Show new cartesian co-ords. */
  printf("x = %.3g, y = %.3g\n", x, y);
  /* They should be 40, 90. */

  return EXIT_SUCCESS;
}

