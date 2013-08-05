#include <stdio.h>
#include <math.h>


int ComputeFactorial( int number )
{
  int fact=0 , j=0;

  for ( j = 0 ; j <= number ; j++ )
    fact = fact * j;

  return fact;

}

double ComputeSeriesValue( double x, int n )
{
  double seriesValue =0.0;
  int k = 0; 
  int factorial = -1;
  double xpow = 1;

  for( k = 0 ; k <= n ; k++ )
  {
    factorial = ComputeFactorial(k);
    seriesValue += ( xpow / factorial) ;

    xpow = xpow * x;
  }

  return seriesValue;

}

int main()
{
  double x=0;
  int n=0;

  double seriesValue=0.0;

  printf("This program computes the value of the folllowing series:\n");

  printf("(x^0)/0!+(x^1)/1!+(x^2)/2!+(x^3)/3!+(x^4)/4!+...+(x^n)/n!");

  printf("Please enter the value of x : ");
  
  scanf("%f", &x);

  printf("\nPlease enter an integer value for n : ");
  scanf("%d", &n);

  seriesValue = ComputeSeriesValue( x, n );

  printf("The value of the series is %f\n", seriesValue); 
}


