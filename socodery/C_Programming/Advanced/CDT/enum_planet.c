/*************************************************************************
*
*  FILE NAME    : enum_planet.c
*
*  DESCRIPTION  : Simple program to demonstrate enum
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for enum demo
*
* RETURNS: Nothing
**************************************************************************/

int main ()
{
  enum planets
  {
    Mercury,
    Venus,
    Earth,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune,
    Pluto
  };

  enum planets planet1, planet2,planet3;

  planet1 = Mars;
  planet2 = Earth;

  if (planet1 > planet2)
    puts ("Mars is farther from the Sun than Earth is.");
  else
    puts ("Earth is farther from the Sun than Mars is.");
  
  printf("%s",planet3);
  return 0;
}


