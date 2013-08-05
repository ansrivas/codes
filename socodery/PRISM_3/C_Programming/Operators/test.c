#include <stdio.h>
#include <limits.h>

int main()
{

    unsigned long num  = LONG_MAX;

        printf("value is:%ul\n",num);
	num = num + 1; 	/* Val of out of bounds */
        printf("value is:%ul\n",num);
/*
	unsigned int i ; 
        unsigned int j = 1;
        unsigned int k = 0 ;

	printf("Enter i:");
	scanf("%ud\n",&i);
        k = i & 1 ;
	printf("i is :%d\n",i);
	printf("K is:%d",k);	

        if (k == 0)
		printf("\n i is divisible by 2 ");
        else
		printf("\n i is not divisible by 2" );

        return 0;
*/
}

