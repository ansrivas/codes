#include <stdio.h>

int gcomplex = 0;

int complexlink(int lflag)
{
  int retval = 0;
  printf("\nENTER complexlink function");

  if (lflag == 0)
  {
    printf("\nlflag is equal to zero");
    retval = 1;
  }
  else
  {
    printf("\nlflag is different from zero");
    retval = 0;
  }

  if (lflag == 0)
  {
    printf("\nlflag is equal to zero");
    retval = 1;
  }
  else
  {
    printf("\nlflag is different from zero");
    retval = 0;
  }

  if (lflag == 0)
  {
    printf("\nlflag is equal to zero");
    retval = 1;
  }
  else
  {
    printf("\nlflag is different from zero");
    retval = 0;
  }

  printf("\nEXIT complexlink function");
  return retval; 
}

