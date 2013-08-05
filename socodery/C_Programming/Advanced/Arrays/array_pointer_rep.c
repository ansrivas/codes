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
*  26-JUN-09 Rashi			change as per requirement	
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int func1(int mat[][3]);
int func2(int (*ptr)[3]);
int func3(int *);
int func4(int **);
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
	int mat[3][3],i,j;

	for(i = 0 ; i < 3 ; i++)
		for(j = 0 ; j < 3 ; j++)
		{
			mat[i][j] = i + j;
		}

	printf(" Initialized data to: ");
	for(i = 0 ; i < 3 ; i++)
	{
		printf("\n");
		for(j = 0 ; j < 3 ; j++)
		{
			printf("%d  ", mat[i][j]);
		}
	}
	printf("\n");

	func1(mat);
	func2(mat);
	func3(mat);
	func4(mat);
}


 /* 
 Method #1 (No tricks, just an array with empty first dimension)
 ===============================================================
 You don't have to specify the first dimension! 
 */

/*PROPER METHOD*/

int func1(int mat[][3])   
{
        int i, j;

        printf(" Declare as matrix, explicitly specify second dimension: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%d  ", mat[i][j]);
                }
        }
        printf("\n");

        return;
}

 /*
 Method #2 (pointer to array, second dimension is explicitly specified)
 ======================================================================
 */

/*PROPER METHOD*/

int func2(int (*ptr)[3])
        {
        int i, j;

        printf(" Declare as pointer to column, explicitly specify 2nd dim: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%d  ", *(*(ptr+i)+j));
                }
	}        
	printf("\n Another way ");
        for(i = 0 ; i < 3 ; i++)
                {
		printf("\n");
                for(j = 0 ; j < 3 ; j++)
		        printf("%d  ", *(ptr[i]+j));
        	}
        printf("\n");

        return;
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

int func3(int *ptr)	
        {
        int i, j;

        printf(" Declare as single-pointer, manual offset computation: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%d  ", *(ptr + 3*i + j));
                }
        }
        printf("\n");

        return;
}

 /*

 Method #4 (double pointer, using an auxiliary array of pointers)
 ================================================================
 With this method you can create general-purpose routines,
 if you allocate "index" at run-time. 

 Add the dimensions to the formal argument list.
 */

/*IMPROPER METHOD*/

int func4(int **ptr)
        {
        int i, j, *index[3];

        for (i = 0 ; i < 3 ; i++)
                index[i] = (int *)ptr + 3*i;

        printf(" Declare as double-pointer, use auxiliary pointer array: ");
        for(i = 0 ; i < 3 ; i++)
                {
                printf("\n");
                for(j = 0 ; j < 3 ; j++)
                {
	                printf("%d  ",*((index[i])+j));
                }
        }
        printf("\n");

        return;
}



