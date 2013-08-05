/*******************************************************************************
*
*  FILE NAME    : anagram_port.h
*
*  DESCRIPTION: Header file to handle portability
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
*****************************************************************************/

#ifndef _ANAGRAM_PORT_H
#define _ANAGRAM_PORT_H

typedef unsigned char UCHAR ;
typedef char SCHAR;


#ifdef OS_LINUX64

typedef unsigned short U32_INT;
typedef short S32_INT; 

#else

typedef unsigned int U32_INT;
typedef int S32_INT; 

#endif
extern S32_INT anagram_printf(S32_INT,...);

#endif

