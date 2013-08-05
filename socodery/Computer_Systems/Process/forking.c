#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int var = 0;
	printf("L0\n");
	printf("L1\n");
	var = fork();
	printf("Bye\n");
        return 1;
}
