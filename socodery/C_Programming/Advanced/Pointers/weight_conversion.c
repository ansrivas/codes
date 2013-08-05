/*************************************************************************
*
*  FILE NAME    : weight_conversion.c
*
*  DESCRIPTION  : Weight Conversion. To demonstrate the fundamentals of C.
*          
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*  5-JUN-08  Sibu    C FG 1.1           Modified to reflect the changes
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/
/*************************************************************************
*                       Include Files
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*************************************************************************
*                       Macro Definitions
**************************************************************************/

#define KILOS_PER_POUND .45359

/**************************************************************************
*
* FUNCTION NAME: pointer_display 
*
* DESCRIPTION: Prints the size of different data types and its pointers
*
* RETURNS: Returns void
**************************************************************************/


void pointer_display()
{
	/* Variable Declarations*/
	short int s_int;
	int int_dummy;
	unsigned u_int_dummy;
	long int l_int_dummy;
	char c_dummy;
	float f_dummy;
	double d_dummy;

	/*Pointer Declarations*/
	int *i_ptr = &int_dummy;
	unsigned int *u_int_ptr = &u_int_dummy;
	long int *l_int_ptr = &l_int_dummy;
	char *c_ptr = &c_dummy;
	float *f_ptr = &f_dummy;
	double *d_ptr = &d_dummy;
	printf("Size of short int= %d\n", sizeof(s_int));
	printf("Size of int = %d Size of int ptr = %d\n", 
			sizeof(int_dummy), sizeof(i_ptr));

	printf("Size of u_int = %d Size of u_int ptr = %d\n", 
			sizeof(u_int_dummy), sizeof(u_int_ptr));

	printf("Size of long int = %d Size of long int ptr = %d\n", 
			sizeof(l_int_dummy), sizeof(l_int_ptr));

	printf("Size of char = %d Size of char ptr = %d\n", 
			sizeof(c_dummy), sizeof(c_ptr));

	printf("Size of float = %d Size of float ptr = %d\n", 
			sizeof(f_dummy), sizeof(f_ptr));

	printf("Size of double = %d Size of double ptr = %d\n", 
			sizeof(d_dummy), sizeof(d_ptr));
}
	
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Prints converted weight in British Metric System
*
* RETURNS: Returns EXIT_SUCCESS
**************************************************************************/


int main()
{       
	int pounds;

	int *p_pounds = &pounds;

	int **p_p_pounds = &p_pounds;


/*        printf(" US lbs      UK st. lbs       INT Kg\n");

        for(pounds = 10; pounds < 50; pounds += 10)
        {       int stones = *p_pounds / 14;
                int uklbs = **p_p_pounds % 14;
                float kilos = pounds * KILOS_PER_POUND;
                printf("   %d          %d   %d       %f\n",
                                   pounds, stones, uklbs, kilos);
        }

	printf("\n");
	getchar();*/
	pointer_display();

	exit(EXIT_SUCCESS);
}
