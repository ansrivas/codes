#include <stdlib.h>
int main()
{
        int *p, *a;
        p = malloc(10*sizeof(int));
        a = malloc(10*sizeof(int));
        a[3] = p[3];
        free(a);
        free(p);
        return 0;
}

/*  produce no errors */

