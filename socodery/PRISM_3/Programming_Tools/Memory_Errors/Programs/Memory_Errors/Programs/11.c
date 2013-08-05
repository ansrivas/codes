/******************************************************************************
****Illegal read/write

Illegal read/write errors occurs when you try to read/write from/to an address that is not in the address range of your program. 
******************************************************************************/

#include <stdlib.h>
int main()
{
        int *ptr,ptr1, a;
        ptr = malloc(sizeof(int));
        ptr1= ptr;                /* invalid write error */
        *ptr = 9;   
        printf("%d\n",*ptr);             /* invalid read error */
                free(ptr);
       *ptr=20; 
       printf("%d\n %d\n",ptr,*ptr);
   
    
        return 0;
}



