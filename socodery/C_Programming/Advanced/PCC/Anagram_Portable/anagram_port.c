/*******************************************************************************
*
*  FILE NAME    : anagram_port.c
*
*  DESCRIPTION: Handles portability aspect for anagram program
*
*  DATE    NAME    REFERENCE          REASON
*
*  08-MAR-08 Sibu    C FG 1.0           Initial creation
*
*  23-MAR-08 Shiv    NA                 Review comments
*
*  09-NOV-08 Shiv    Coding Skills FG   Updation for Coding skills program
*
*  07-JUL-09 Sibu    NA                 Modified for PCC Sessions
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/

#include<stdio.h>
#include<stdarg.h>
#include"anagram_port.h"
#include"anagram_util.h"


S32_INT anagram_printf(S32_INT pr_type,...)
{
	va_list ptr;  /* Variable to handle variable arguments */
        S32_INT num = 0;
        SCHAR *p_string1 = NULL, *p_string2 = NULL;

#ifdef OS_VX
	FILE *fd = NULL;
        fd = fopen("LOG.txt","a");
#endif
	va_start (ptr, pr_type);

	p_string1 = va_arg(ptr,SCHAR *);
	
	if(pr_type == PR_TYPE2)
        {
		num = va_arg(ptr, S32_INT);
        }

	p_string2 = va_arg(ptr,SCHAR *);

	if(pr_type == PR_TYPE2)
        {
	
#ifndef OS_VX
        	printf(p_string1, num, p_string2);
#else

		fprintf(fd,p_string1, num, p_string2);
#endif
        }
        else  /* PR_TYPE1*/
        {
	
#ifndef OS_VX
        	printf(p_string1, p_string2);
#else

		fprintf(fd,p_string1, p_string2);
#endif
        }

#ifdef OS_VX
	fclose(fd);
#endif
        
	va_end(ptr);
	return 1;
}

