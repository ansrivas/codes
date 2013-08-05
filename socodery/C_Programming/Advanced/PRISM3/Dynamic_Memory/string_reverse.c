/*************************************************************************
*
*  FILE NAME    : string_reverse.c
*
*  DESCRIPTION  :Program to reverse a string using different methods
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* StrReverse(char*);
char* StrReverse1(char*);
char* StrReverse2(char*);
void StrReverse3(char*);
void StrReverse4(char*);

/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for string reverse program
*
* RETURNS: Nothing
**************************************************************************/

int main(void)
{

	char str[50];
	int temp=0;

	printf("Enter a string: ");
	scanf("%s", str);
	printf("The reverse of the string is: %s\n", StrReverse(str));
	printf("The reverse of the string is: %s\n", StrReverse1(str));
	printf("The reverse of the string is: %s\n", StrReverse2(str));

	StrReverse3(str);
	printf("The reverse of the string is: %s\n", str);
	
	//Get back the original string
	StrReverse3(str);
	
	//Reverse it again
	printf("The reverse of the string is: ");
	StrReverse4(str);
	printf("\n");

	scanf("%d", &temp);

}

/**************************************************************************
*
* FUNCTION NAME: StrReverse
*
* DESCRIPTION: Reverses string using array notation
*
* RETURNS: Pointer to reversed string
**************************************************************************/

char* StrReverse(char* str)
{
	char *temp, *ptr;
	int len, i;

	temp=str;
	for(len=0; *temp !='\0';temp++, len++);
	
	ptr=malloc(sizeof(char)*(len+1));
	
	for(i=len-1; i>=0; i--) 
		ptr[len-i-1]=str[i];
	
	ptr[len]='\0';
	return ptr;
}

/**************************************************************************
*
* FUNCTION NAME: StrReverse1
*
* DESCRIPTION: Reverses string using pointers
*
* RETURNS: Pointer to the reversed string
**************************************************************************/

char* StrReverse1(char* str)
{
	char *temp, *ptr;
	int len, i;

	temp=str;
	for(len=0; *temp !='\0';temp++, len++);
	
	ptr=malloc(sizeof(char)*(len+1));
	
	for(i=len-1; i>=0; i--) 
		*(ptr+len-i-1)=*(str+i);
	
	*(ptr+len)='\0';
	return ptr;
}
/**************************************************************************
*
* FUNCTION NAME: StrReverse2
*
* DESCRIPTION: Reverses string using array notation and swapping
*
* RETURNS: Pointer to reversed string
**************************************************************************/

char* StrReverse2(char* str)
{
	int i, j, len;
	char temp;
	char *ptr=NULL;
	i=j=len=temp=0;

	len=strlen(str);
	ptr=malloc(sizeof(char)*(len+1));
	ptr=strcpy(ptr,str);
	for (i=0, j=len-1; i<=j; i++, j--)
	{
		temp=ptr[i];
		ptr[i]=ptr[j];
		ptr[j]=temp;
	}
	return ptr;
}
/**************************************************************************
*
* FUNCTION NAME: StrReverse3
*
* DESCRIPTION: Reverses string using array notation
*
* RETURNS: Nothing
**************************************************************************/


void StrReverse3(char* str)
{
	int i, j, len;
	char temp;
	i=j=len=temp=0;

	len=strlen(str);
	for (i=0, j=len-1; i<=j; i++, j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}

/**************************************************************************
*
* FUNCTION NAME: StrReverse4
*
* DESCRIPTION: Reverses string recursively
*
* RETURNS: Nothing
**************************************************************************/


void StrReverse4(char *str)
{
	if(*str)
	{
		StrReverse4(str+1);
		putchar(*str);
	}
}
