#include <stdio.h>

int gsimple = 0;

int simplelink(int lflag)
{
  int retval = 0;
  printf("\nENTER simplelink function");
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
  printf("\nEXIT simplelink function");
  return retval; 
}

int anotherfuncion(int lflag)
{
  int retval = 0;
  printf("\nENTER simplelink function");
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
  printf("\nEXIT simplelink function");
  return retval; 
}

