/****************************************************************************
*	FILENAME : writecode.c
*	DESCRIPTION:Contains Code for a demo that will try to write in the 
*	code secton (a separate region protected by the OS)  
*	Invoke the Executable as a.out   
*	 2009  
****************************************************************************/

#include<stdio.h>
#include<signal.h>

void f();
void s_handler(int signum);

main()
{
	int *ip , count;

	/*Getting the starting address of the function f in variable ip*/
	ip = (int*)f;
	signal(SIGSEGV,s_handler);
	/*Registering sigal Numbers from 1 to 50*/
//	for (count = 0;count <= 50;count++)
//		signal(count,s_handler);


	printf("Trying to Write  in the Code segment \n");
	fflush(stdout);

	/*Trying to Write , where the function f starts*/
	*ip = 1;

	printf("Wrote in the Code segment ");
}

/************************************************************************
*	FUNCTION NAME:s_handler
*	DESCRIPTION: A standard signal Handler 
*	NOTES : No Error Checking is done .
*	RETURNS :void 
************************************************************************/
void s_handler(int signum)
{
	/*The signal number correspondind to the generated signal is printed*/
	printf("Caught Signal Number %d", signum);
	exit(1);
}

/************************************************************************
*	FUNCTION NAME:f
*	DESCRIPTION: A demo function , whose purpose is nothing here.
*	NOTES : No Error Checking is done .
*	RETURNS :void 
************************************************************************/
void f()
{
	printf("A demo function\n");
}
