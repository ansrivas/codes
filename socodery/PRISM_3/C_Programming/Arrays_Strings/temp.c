#include<stdio.h>
int min(int a, int b)
{
   return (a<b?a:b);
}
int max(int a, int b)
{
   return (a>b?a:b);
}
int find_max_min(int a, int b, int(*f)(int, int))
{
  
  int m = f(a,b);
  return m;
}
int main()
{
  //int (*fptr)(int, int)=NULL;

  int (*fptr1)(int, int, int(*)(int, int))=NULL;
  

  int m;

  fptr1 = &find_max_min;

  m = fptr1(10,20,max);
  
  printf("\n%d\n", m);

//  fptr = &min;
//  m = fptr(10,20);
//  printf("\n%d\n", m);






  return 0;
}	
