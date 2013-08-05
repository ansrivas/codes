#include <stdlib.h>

void spin (int x)
{
    int i = 0;
    for (i = 0; i < x;  ++i)
     ;
}

void call_spin(int x)
{
    int i = 0;
    for (i = 0; i < x;  ++i)
        spin(x);
}

int main(int argc, char *argv[])
{
     int count = 1000;
     if (1 < argc) count  =  atoi(argv[1]);	
     call_spin(count);
     return 0;	
}
	
