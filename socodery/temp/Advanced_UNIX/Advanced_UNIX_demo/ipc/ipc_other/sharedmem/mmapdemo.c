/***************************************************************************
*	FILENAME :mmapdemo.c 
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of mmap function.	
*	Invoke the Executable as a.out
*	 2009  
****************************************************************************/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<fcntl.h>
main(int argc ,
	char *argv[])
{
	int fdin , fdout;
	char *src,*dst;
	struct stat statbuf;
	
	if (argc != 3)
	{
		printf("Usage is a.out <src file > <dst file>\n");
		exit(1);
	}
	if ((fdin = open(argv[1],O_RDONLY)) < 0)
	{
		printf("Error in Opening source file %s\n" , argv[1]);
		exit(1);
	}	
	if ((fdout = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,S_IRWXU)) < 0)
	{
		printf("Cannot Create Destination file %s\n" , argv[2]);
		exit(1);
	}	
	/*Getting the Source File Size*/
	if (fstat(fdin,&statbuf) < 0)
	{
		printf("Error in Function Fstat\n");
		exit(1);
	}
	
	/*Set the size of Output file */
	if (lseek(fdout,statbuf.st_size - 1 , SEEK_SET ) == -1)
	{
		printf("Error in Seeking Output File\n");
		exit(1);
	}
	/*Do a Character Write to set the file size */
	if (write(fdout,"",1) != 1)
	{
		printf("Write Error\n");
		exit(1);
	}	
	/*Now map the I/P File */
	if ((src = mmap(0,statbuf.st_size,PROT_READ,MAP_SHARED,
		fdin,0)) == (caddr_t) -1)
	{
		printf("Error in Mapping I/P File \n");
		exit(0);
	}
	if ((dst = mmap(0,statbuf.st_size,PROT_READ|PROT_WRITE,
		MAP_SHARED,fdout,0)) == (caddr_t) -1)
	{
		printf("Error in Mapping I/P File \n");
		exit(0);
	}
	/*Does the File Copy*/
	memcpy(dst,src,statbuf.st_size);	
	exit(0);
	
}
