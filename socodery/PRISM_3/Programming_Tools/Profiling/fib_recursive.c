#include <stdio.h>
int fibonacci(int n);
int main (int argc, char **argv)
{
   int fib;
   int n;
   char str[20];
   for (n = 0; n <= 30; n++) {
      fib = fibonacci(n);
      printf("fibonnaci(%d) = %d\n", n, fib);
   }
   scanf("%c",&str);
   return 0;
}
int fibonacci(int n)
{
   int fib;
   if (n <= 0) {
      fib = 0;
   }
   else if (n == 1) {
      fib = 1;
   }
   else {
      fib = fibonacci(n -1) + fibonacci(n - 2);
   }
   return fib;
}


