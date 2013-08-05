#include "stdio.h"
#include "simplelink.h"
#include "complexlink.h"

int main()
{
  int flag = 0;
  int retval = 0;
  retval = simplelink(flag);
  gsimple = retval;
  retval = complexlink(flag);
  gcomplex = retval;

  printf("\nflag: %d & return value: %d\n", flag, gsimple);
  printf("\nflag: %d & return value: %d\n", flag, gcomplex);
  return retval;
}

