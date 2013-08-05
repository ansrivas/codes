/*************************************************************************
*
*  FILE NAME    : file_fseek.c
*
*  DESCRIPTION  : Demosntration of fseek
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

int main(int argc, char *argv[])
{
  FILE *fp;

  if(argc!=3) 
  {
    printf("Usage: <executable> filename byte\n");
    exit(EXIT_FAILURE);
  }

  if((fp = fopen(argv[1], "rb"))==NULL) 
  {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
  }

  if(fseek(fp, atol(argv[2]), SEEK_SET)) 
  {
    printf("Seek error.\n");
    exit(EXIT_FAILURE);
  }

  printf("Byte at %ld is '%c'\n", atol(argv[2]), fgetc(fp));
  fclose(fp);

  return EXIT_SUCCESS;
}

