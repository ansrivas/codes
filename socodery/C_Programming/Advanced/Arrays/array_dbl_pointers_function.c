/*************************************************************************
*
*  FILE NAME    : array_dbl_pointers_function.c
*
*  DESCRIPTION  : Program to demonstrate how to pass a 2D array to a funtion
*		  using pointers
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*  30-Aug-09  Sibu    C FG 1.0          Function prototypes changed from
*					int to void
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void func1(short mat[][3]);
void func2(short (*ptr)[3]);
void func3(short *);
void func4(short **);
void func5(short *ptr[3]);
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for 2D array - function program
*
* RETURNS: Nothing
**************************************************************************/
int main()
{
	short mat[3][3],i,j;

	for(i = 0 ; i < 3 ; i++)
		for(j = 0 ; j < 3 ; j++)
		{
			mat[i][j] = i*10 + j;
		}

	printf(" Initialized data to: ");
	for(i = 0 ; i < 3 ; i++)
	{
		printf("\n");
		for(j = 0 ; j < 3 ; j++)
		{
			printf("%5.2d", mat[i][j]);
		}
	}
	printf("\n");

	func1(mat);
	func2(mat);
	func3(mat);
	func4(mat);
	func5(mat);
	
	return 0;
}


 /* 
 Method #1 (No tricks, just an array with empty first dimension)
 ===============================================================
 You don't have to specify the first dimension! 
 */

/*PROPER METHOD*/

void func1(short mat[][3])   
{
        register short i, j;

        printf(" Declare as matrix, explicitly specify second dimension: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%5.2d", mat[i][j]);
                }
        }
        printf("\n");

}

 /*
 Method #2 (pointer to array, second dimension is explicitly specified)
 ======================================================================
 */

/*PROPER METHOD*/

void func2(short (*mat)[3])
        {
        register short i, j;

        printf(" Declare as pointer to column, explicitly specify 2nd dim: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%5.2d", mat[i][j]);
                }
        }
        printf("\n");

}

 /*
 Method #3 (Using a single pointer, the array is "flattened")
 ============================================================
 With this method you can create general-purpose routines.
 The dimensions doesn't appear in any declaration, so you 
 can add them to the formal argument list. 

 The manual array indexing will probably slow down execution.
 */
/*IMPROPER METHOD*/

void func3(short *mat)	
        {
        register short i, j;

        printf(" Declare as single-pointer, manual offset computation: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%5.2d", *(mat + 3*i + j));
                }
        }
        printf("\n");

}

 /*

 Method #4 (double pointer, using an auxiliary array of pointers)
 ================================================================
 With this method you can create general-purpose routines,
 if you allocate "index" at run-time. 

 Add the dimensions to the formal argument list.
 */

/*IMPROPER METHOD*/

void func4(short **mat)
        {
        short    i, j, *index[3];


        for (i = 0 ; i < 3 ; i++)
                index[i] = (short *)mat + 3*i;

        printf(" Declare as double-pointer, use auxiliary pointer array: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%5.2d", index[i][j]);
                }
        }
        printf("\n");

}

 /*
 Method #5 (single pointer, using an auxiliary array of pointers)
 ================================================================
 */


/*IMPROPER METHOD*/
void func5(short *mat[3])
        {
        short i, j, *index[3];
        for (i = 0 ; i < 3 ; i++)
                index[i] = (short *)mat + 3*i;

        printf(" Declare as single-pointer, use auxiliary pointer array: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%5.2d", index[i][j]);
                }
        }
        printf("\n");
}


