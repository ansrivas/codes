/*************************************************************************
*
*  FILE NAME    : file_fgetw.c
*
*  DESCRIPTION  : Demosntration of fgetw and fputw
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
/*************************************************************************
*               HEADER FILES
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
  FILE *file;
  int i;

  file = fopen ("integer.txt","wb+");
  putw (20,file);
  rewind (file);
  i=getw (file);
  fclose(file);
  printf("%d\n",i); 
  return EXIT_SUCCESS;
}


