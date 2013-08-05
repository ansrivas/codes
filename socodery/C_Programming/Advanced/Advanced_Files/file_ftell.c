/*************************************************************************
*
*  FILE NAME    : file_ftell.c
*
*  DESCRIPTION  : Demosntration of ftell
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
#include<stdlib.h>
int main ()
{
  FILE *file;
  long size;

  file = fopen ("test1.txt","rb");
  
  if (file == NULL) 
      perror ("Error reading my.txt.");
  else 
  {
    fseek (file, 0, SEEK_END);
    size = ftell(file);
    
    fclose (file);
    printf ("Size of my.txt is %ld bytes.\n",size);
  }
  return EXIT_SUCCESS;
}

