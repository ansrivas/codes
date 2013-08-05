/*************************************************************************
*
*  FILE NAME    : reset_beg_rewind.c
*
*  DESCRIPTION  : Demosntration of rewind
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
#include <string.h>

int main(void)
{
  char str[80];
  FILE *fp;

  if((fp = fopen("res.txt", "w+"))==NULL) 
  {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
  }

  do 
  {
    printf("Enter a string (CR to quit):\n");
    fgets(str,79,stdin);
    strcat(str, "\n");  /* add a newline */
    fputs(str, fp);
  } while(*str!='\n');

  rewind(fp);  /* reset file position indicator to start of the file. */
  
  while(!feof(fp)) 
  {
    fgets(str, 79, fp);
    printf(str);
  }

  return EXIT_SUCCESS;
}

