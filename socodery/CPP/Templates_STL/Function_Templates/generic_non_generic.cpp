#include<iostream>
using namespace std;
#include<string.h>
template <typename T>

T minimum(T a, T b)
{
   cout << "\nGeneric ";
   return (a<b ?a:b);
}
template <>
char * minimum(char * a, char * b)
{
   cout << "\nNon Generic ";
   return (strcmp(a,b)>0 ?a:b);
}

int main()
{
   int a=10 , b= 34;
   cout << minimum(a,b);
 
   double d=28.3 , f=34.1;
   cout << minimum(d,f);   

   char s1[] ="hello";
   char s2[]= "how";
   cout << minimum(s1,s2);
   return 0;
}
