/************************************************************************:wq
*
*
*  FILE NAME    : fgets_fputs.c
*
*  DESCRIPTION  : Demosntration of fread and fwrite
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

double d[10] = {1.3, 1.7, 1.23, 1.9, 0.97, 1.5, 7.4, 2.0, 1.01, 8.75};
int e[10] = {11,22,33,44,55,66,77,88,99,101};
double out1[10];
int out2[10];
int main(void)
{
  int i;
  FILE *fp;

  if((fp = fopen("binary", "wb")) == NULL) 
  {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
  }

  if(fwrite(e, sizeof (int), 10, fp) != 10 ) 
  {
    printf("Write error.\n");
    exit(EXIT_FAILURE);
  }

  if(fwrite(d, sizeof(double), 10, fp) != 10 )
  {
   printf("Write error.\n");
   exit(EXIT_FAILURE);
  }
  
  fclose(fp);
   //fseek(fp,0,SEEK_SET);

  if((fp = fopen("binary", "rb"))==NULL) 
  {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
  }
 if(fread(out2, sizeof(int), 10, fp) != 10)
 {
   printf("Read error.\n");
   exit(EXIT_FAILURE);
 }

  if(fread(out1, sizeof (double)/4, 40, fp) != 40) 
  {
    printf("Read error.\n");
    exit(EXIT_FAILURE);
  }
  fclose(fp);

  /* display the array */
  for(i = 0; i < 10; i++) 
      printf("%f\t", out1[i]);
  
  /* display the array */
  for(i = 0; i < 10; i++)
    printf("%d\t", out2[i]);
  
  printf("\n");
  return EXIT_SUCCESS;
}
