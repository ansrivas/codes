#include<stdio.h>

int main()
{
int a;
  int *b[2]={&a};
int **c=b;
printf("%d   %d", **c, *b[0]);
return 0;
}
  
