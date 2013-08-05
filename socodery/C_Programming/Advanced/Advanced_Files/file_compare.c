/***********************************************************************
*
*  FILE NAME    : file_compare.c
*
*  DESCRIPTION: Takes two files as input and compare them byte by byte. 
*		Displys the byte number where the first difference is. 
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
*************************************************************************/
/************************************************************************
*		INCLUDE FILES
*************************************************************************/
#include<stdio.h>
#include <stdlib.h>

/****************************************************************************
* FUNCTION NAME: main
*
* DESCRIPTION: Takes the two files and compares them.
*
* RETURNS: Returns 0
*****************************************************************************/

int main(int argc, char *argv[]) 
{
  FILE *fp1, *fp2;
  char ch1, ch2, same;
  unsigned long l;
  if(argc!=3) 
  {
    printf("Usage: compare <file 1> <file 2>\n");
    exit(EXIT_FAILURE);
  }

  if((fp1 = fopen(argv[1], "rb"))==NULL) 
  {
    printf("Cannot open first file.\n");
    exit(EXIT_FAILURE);
  }

  if((fp2 = fopen(argv [2], "rb"))==NULL) 
  {
    printf("Cannot open second file.\n");
    exit(EXIT_FAILURE);
  }
  
  l = 0;
  same = 1;
  
  while(!feof(fp1)) 
  {
    ch1 = fgetc(fp1);
    if(ferror(fp1))
    {
      	printf("Error reading first file.\n");
        exit(EXIT_FAILURE);
    }
    ch2 = fgetc(fp2);
    if(ferror(fp2)) 
    {
        printf("Error reading second file.\n");
        exit(EXIT_FAILURE);
    }
    
    if(ch1 != ch2) 
    {
      	printf("Files differ at byte number %lu", l);
      	same = 0;
      	break;
    }
    l++;
  }
  
  if(same)
        printf("Files are the same.\n");

  if(fclose( fp1 ) == EOF) 
  {
       printf("Error closing first file.\n");
       exit(EXIT_FAILURE);
  }
  if(fclose( fp2 ) == EOF) 
  {
       printf("Error closing second file.\n");
       exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}

