/******************************************************************************
****** Errors Occur Due to Invalid System Call Parameter

Valgrind checks all parameters to system calls. 
******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
int main()
{
        int *p;
        p = malloc(10);
        read(0, p, 100);        /* Error: unaddressable bytes */
        free(p);
        return 0;
}



