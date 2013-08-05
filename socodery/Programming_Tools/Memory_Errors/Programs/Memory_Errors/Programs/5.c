/******************************************************************************
*****Memory Leak Detection

In this program p contains the address of a 20-byte block. But it is not freed anywhere in the program. So the pointer to this 20 byte block is lost forever. This is known as memory leaking. We can get the leak summary by using the Valgrind option --leak-check=yes. 
*******************************************************************************/

#include <stdlib.h>
int main()
{
        int *p, i;
        p = malloc(5*sizeof(int));
        for(i = 0;i < 5;i++)
                *(p+i) = i;
        free(p);
         return 0;
       
}


