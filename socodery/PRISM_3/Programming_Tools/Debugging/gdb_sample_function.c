/******************************************************************************
keywords		:	gdb, functions 

File Name		:	gdb_sample_function_1_0.c

Date of Creation	:	29/06/2007

Owner			:	Sibu Cyriac

Date of Modification	:

Reason for modification	:

Modifier		:

*******************************************************************************/

#include <stdio.h>

int wib(int,int);

/******************************************************************************

	Function to wib the two numbers

*******************************************************************************/


int wib(int number_1, int number_2)

{
  
   int result, difference;
  
   difference = number_1 - number_2;
  
   result = number_1 / difference;
  
   return result;

}



int main(int argc, char *argv[])

{
  
   int value, divisor, result, index, total;

  
   value = 10;
   divisor = 6;
   total = 0;

  
   for(index = 0; index < 10; index++)
  
   {
    
    result = wib(value, divisor);
    
    total = total + result;
    
    divisor++;
     
    value--;
  
   } 

  printf("%d wibed by %d equals %d\n", value, divisor, total);
  
  return 0;

}

