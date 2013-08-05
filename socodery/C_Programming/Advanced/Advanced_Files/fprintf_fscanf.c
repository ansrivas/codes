/*************************************************************************
*
*  FILE NAME    : fprintf_fscanf.c
*
*  DESCRIPTION  : Demonstration of fscanf and fprintf
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

int main(int argc, char *argv[])
{
  FILE *fp;
  double ld;
  int d,d1;
  int count=0,temp;
  char str[80],str1[80];



  if((fp = fopen("sample", "w"))==NULL) 
  {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
  }

 // fprintf(fp, "%f %d %s %s %d", 345.342,908, "hiiiiiiii10","hello");
  fprintf(fp, "%d %s %s", 908, "hiiiiiiii10","hello");
  fclose(fp);

  if((fp = fopen("sample", "r"))==NULL) 
  {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
  }

  count = fscanf(fp, "%d %s %s", &temp, str, str1);
  printf("%s %d   %d   %s\n",str,count,temp,str1);



/*
  count = fscanf(fp, "%lf %d %s", &ld, &d, str);
  printf("%f %d %s %d\n", ld, d, str,count);
 
  count = fscanf(fp, "%d", &d);
  count = fscanf(fp, "%s %d", str,&d1);
  fprintf(stdout," %d  %s  %d\n", d, str,d1);
*/ 
 fclose(fp);

  return EXIT_SUCCESS;
}











