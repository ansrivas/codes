/****************************************************************************** 
********* Use of uninitialized memory
  
   Sources of uninitialized data are: 
   local variables that have not been initialized.

   The contents of malloc'd blocks, before writing something there.

    This is not a problem with calloc since it initializes each allocated bytes*    with 0
*******************************************************************************/
#include <stdlib.h>

int main()
{
	int p, t;
	if (p == 5)             /*Error occurs here*/
		t =p+1;
        
	return 0;
}



