/******************************************************************************
******Invalid free
Valgrind keeps track of blocks allocated to your program with malloc/new. So it can easily check whether argument to free/delete is valid or not.
******************************************************************************/

#include <stdlib.h>
int main()
{
        int *p, i;
        p = malloc(10*sizeof(int));
        for(i = 0;i < 10;i++)
                p[i] = i;
        free(p);
     //   free(p);        Error: p has already been freed 
        return 0;
}


