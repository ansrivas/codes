/*************************************************************************
*
*  FILE NAME    : file_fgetc.c
*
*  DESCRIPTION  : Opens a file and reads it character by character
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
/*************************************************************************
*		HEADER FILES
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp,*fp1;
  char ch;
  int count = 0;

if((fp1=fopen("test2.txt","w"))==NULL)
{
    printf("Cannot open test2.\n");
    exit(EXIT_FAILURE);
}

	
  if((fp = fopen("test1.txt","r"))==NULL) 
  {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
  }

  while((ch = fgetc( fp )) != EOF) 
  {
    printf("%c", ch);
    fputc(ch,fp1);
    count++;
  }
  fclose(fp);
  printf("%d\n", count);
  return EXIT_SUCCESS;
}





