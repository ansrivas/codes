#iclude<stdio.h>

int *f(){

int (*a)[2] = (int (*)[2])malloc(10));


return a;

}

int main()
{
f();

}


