#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
main()
{
	int fd1,n;
	int data =10;
	/*create a file for writing */
	fd1=open("file1",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
	/*Check the return value of functions for success/failure*/
	if (fd1 < 0)
	{
		printf("File opening Failed\n");
		exit(1);
	}
	/*Write some data in the file*/
	n=write(fd1,&data, sizeof(int));
	if (-1 == n)
	{	printf("Error in eriting the file\n");
		exit(1);
	}
	printf("Number of bytes written =%d\n",n);
	/*Closing the file descriptor*/
	close(fd1);
}




