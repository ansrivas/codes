/*******************************************************************************
*
*  FILE NAME    : anagram.h
*
*  DESCRIPTION: To find out whether a trial string is an anagram of a source
*                string or not.
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*  23-MAR-08 Shiv    NA                 Review comments
*
*  07-Jul-09 Vikas   NA                 Added runtime trace
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/


#ifndef _ANAGRAM_H
#define _ANAGRAM_H

#define SUCCESS 1
#define FAILURE 0
#define MAX_ANAGRAM_LEN 30
#define MAX_LINE_LENGTH 100

#define NO_TRACE       1
#define BRIEF_TRACE    2
#define DETAILED_TRACE 3

#define ERROR_NONE     1
#define ERROR_CRITICAL 2
#define ERROR_MAJOR    3
#define ERROR_MINOR    4

#define A_ERROR(err_level, err_code) ang_error(err_level, err_code)

#ifdef TRACE
 #define A_TRACE(level, x) if (g_trace_level >= level) printf x
#else
 #define A_TRACE(level, x) 
#endif

/* Error Codes */
#define ERROR_UNEXPECTED_EOF  0
#define ERROR_INVALID_CHAR    1

extern int letter_index(char );
extern void count_letters(char *, int []);
extern int letter_index_converter(char);
extern char index_letter_converter(int);
extern int get_line(char [], size_t);
extern int anagram_checker(int [], int []);
extern void ang_error(int, int);

#endif



