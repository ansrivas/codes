/*  sample2.c : A C program example for practising static code analysis
 *  This program is filled with errors and NOT intended to ever be run
 */
#include <stdio.h>

int main()
{
	int *p;

	/* Splint should catch the fact that the storage pointed to by 
     * p is not yet defined
	 */ 
	printf ("integer value : %d", *p);
	return 0;
}

