/*************************************************************************
*
*  FILE NAME    : fgets_fputs.c
*
*  DESCRIPTION  : Demosntration of fgets and fputs
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
#include<string.h>
int main(int argc, char *argv[])
{
  FILE *fp;
  char str[80],*s;
  char ch;

  if((fp = fopen("test1.txt", "r+"))==NULL) 
  {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
  }
  
//max 79 char's fetched from file including \n & last 80th char is \0
  
  while((s=fgets(str, 80, fp))!=NULL)
			
  {
    printf("length=%d \n %s", strlen(str), s);

  }

  fclose(fp);

  return EXIT_SUCCESS;
}
