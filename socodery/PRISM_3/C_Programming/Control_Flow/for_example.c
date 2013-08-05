/*************************************************************************
*
*  FILE NAME    : for_example.c
*
*  DESCRIPTION  : Program to print the binary of 'd'
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
int main(void)
{
  char ch;
  int i;
  ch = 'd';
  /* Iterates for 128, 64, 32, 16, 8, 4, 2 and 1 */
  for(i = 128; i > 0; i = i / 2)
  {
    if(i & ch) /* a non-zero value */
        printf("1 ");
    else
        printf("0 ");
  }
  return 0;
}
