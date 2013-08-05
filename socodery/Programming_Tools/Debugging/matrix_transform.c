#include <stdlib.h>
#include <stdio.h>

#define LIMIT 10

//function prototypes
void transformMatrix(int matrix[LIMIT][LIMIT]);
int bimod(int value);

#define MAX 100

int main()
{
  int i, j;
  int matrix[LIMIT][LIMIT];

  //load values into matrix
  for (i = 0; i < LIMIT; i++)
  {
   for (j = 0; j < LIMIT; j++)
    {
      matrix[i][j] = (i+1) * (j+1);
    }
  }

  //display initial contents of matrix
  printf("Initial matrix contents:\n");
  for (i = 0; i < LIMIT; i++)
  {
    for (j = 0; j < LIMIT; j++)
    {
      printf("%4i", matrix[i][j]);
    }
    printf("\n");
  }

  transformMatrix(matrix);

  //display transformed contents of matrix
  printf("\nTransformed matrix contents:\n");
  for (i = 0; i < LIMIT; i++)
  {
    for (j = 0; j < LIMIT; j++)
    {
      printf("%4i", matrix[i][j]);
    }
    printf("\n");
  }

  exit(0);
}


void transformMatrix(int matrix[LIMIT][LIMIT])
{
  int i, j;

  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      matrix[i][j] = bimod(matrix[i][j]);
}


int bimod(int value)
{
  if (value % 2 == 0)
    return(1);
  else
    return(0);
}
  

