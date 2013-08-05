/******************************************************************************
****Illegal read/write

Illegal read/write errors occurs when you try to read/write from/to an address that is not in the address range of your program. 
******************************************************************************/

#include <stdlib.h>
int main()
{
        int *p, a;
        p = malloc(10*sizeof(int));
        p[9]= 1;                /* invalid write error */
        a = p[9];   
        printf("%d",a);             /* invalid read error */
                free(p);
        return 0;
}



