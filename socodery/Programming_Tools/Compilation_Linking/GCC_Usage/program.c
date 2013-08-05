#include <stdio.h>

int gsimple = 0;
int gcomplex = 0;


/*
This comment would be removed
*/

int complexlink(int lflag)
{
  int retval = 0;
  printf("\nENTER complexlink function");
  if (lflag == 0)
  {
    printf("\nlflag is equal to zero");
    gcomplex = 0;
    retval = 1;
  }
  else
  {
    printf("\nlflag is different from zero");
    gcomplex = 1;
    retval = 0;
  }
  printf("\nEXIT complexlink function");
  return retval;
}

int simplelink(int lflag)
{
  int retval = 0;
  printf("\nENTER simplelink function");
  if (lflag == 0)
  {
    printf("\nlflag is equal to zero");
    gsimple = 1;
    retval = 0;
  }
  else
  {
    printf("\nlflag is different from zero");
    gsimple = 0;
    retval = 1;
  }
  printf("\nEXIT simplelink function");
  return retval;
}

int main()
{
  int flag = 1;
  int retval = 0;
  gsimple = flag + gsimple;
  printf("\ngsimple before simplelink call: %d \n", gsimple);
  retval = simplelink(flag);
  printf("\ngsimple after simplelink call: %d \n", gsimple);
  printf("\nreturn value from simplelink : %d \n", retval);

  printf("\ngcomplex before complexlink call: %d \n", gcomplex);
  retval = complexlink(flag);
  printf("\ngcomplex after complexlink call: %d \n", gcomplex);
  printf("\nreturn value from complexlink : %d \n", retval);
  return retval;
}

