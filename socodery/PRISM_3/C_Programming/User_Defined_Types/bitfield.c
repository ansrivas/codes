#include<stdio.h>
typedef struct s
{
  unsigned int a:1;
  unsigned int b:2;
  unsigned int c:3;
  unsigned int d:4;
  unsigned int e:5;
}s;

int main()
{
  s v;
 unsigned int a;
 printf("Enter a no::");
 scanf("%u", &a);
 
v.a = a;

printf("the value of bit field data is %u\n", v.a);
return 0;
}
