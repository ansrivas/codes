/*************************************************************************
*
*  FILE NAME    : bit_count.c
*
*  DESCRIPTION  : Count the number of 1-bits in a variable
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

/**************************************************************************
*
* FUNCTION NAME: bitcount
*
* DESCRIPTION: Finds out the number of 1-bits
*
* RETURNS: Returns number of bits
**************************************************************************/


int bitcount(unsigned char x) 
{ 
	int count=0;
 


	for (count=0; x != 0; x>>=1){
	    	if ( x & 01)
			count++;

	}

 	return count;
}


/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Calls the function bitcount
*
* RETURNS: Returns EXIT_SUCCESS / EXIT_FAILURE
**************************************************************************/

int main()
{
	unsigned char u_c_char = 'b';

	unsigned u_i_result = bitcount(u_c_char);

	printf("\nThe number of 1-bits in %c is %u\n", u_c_char, u_i_result); 	

	exit(EXIT_SUCCESS);
}
