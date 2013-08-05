/*******************************************************************************
*
*  FILE NAME    : anagram_util.h
*
*  DESCRIPTION: Header file for trace, error levels
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

#ifndef _ANAGRAM_UTIL_H
#define _ANAGRAM_UTIL_H

/* for traces */
/* for disabling trace as a feature, comment the #define below */

#define TRACE_FEATURE  1 



#ifdef TRACE_FEATURE
 #define A_TRACE trace_print
#else
 #define A_TRACE 
#endif



/* trace levels */

#define NO_TRACE        0
#define BRIEF_TRACE     1
#define DETAILED_TRACE  2


/* Error levels */

#define ERR_ALL      4
#define ERR_CRITICAL 3
#define ERR_MAJOR    2
#define ERR_MINOR    1

/* Error Codes */

#define ERR_NONE            0
#define ERR_BLANK_LINE      1
#define ERR_UNEXPECTED_EOF  2
#define ERR_NULL_PTR_RECVD  3
#define ERR_BUFFER_FINISHED 4
#define ERR_INVALID_DATA    5

void trace_print( UCHAR trace_level, SCHAR *p_trace_string);
void ang_error(S32_INT err_level, S32_INT errno);

/* for porting */

#define PR_TYPE1  1   /* tells that prinf is being invoked from trace_print */
#define PR_TYPE2  2   /* tells that prinf is being invoked from ang_error */

#endif
