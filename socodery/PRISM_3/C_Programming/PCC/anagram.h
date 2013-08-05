/*******************************************************************
*
* File NAME : anagram.h
*
* Description: header file
*
*******************************************************************/

#ifndef _ANAGRAM_H
#define _ANAGRAM_H

#define SUCCESS 1
#define FAILURE 0


#define MAX_ANAGRAM_LEN 5
#define MAX_LINE_LENGTH 100


/* trace details */
#define NO_TRACE       1
#define BRIEF_TRACE    2
#define DETAILED_TRACE 3

#ifdef TRACE_FEATURE
 #define A_TRACE(level, x)  if (g_trace_level >= level) printf x
#else
 #define A_TRACE(level, x) /* no definition */
#endif


/* error details */

#define ERROR_NONE     1
#define ERROR_CRITICAL 2
#define ERROR_MAJOR    3
#define ERROR_MINOR    4

/* ang_error is defined in anagram_error.c */
#define A_ERROR(err_level, err_code) ang_error(err_level, err_code)

/* Error Codes */
#define ERROR_UNEXPECTED_EOF  0
#define ERROR_INVALID_CHAR    1
#define ERROR_MEMORY_FAILURE  2
#define ERROR_INVALID_INPUT   3






extern int letter_index(char );
extern void count_letters(char *, int []);
extern int letter_index_converter(char);
extern char index_letter_converter(int);
extern int get_line(char [], size_t);
extern int anagram_checker(int [], int []);
extern void ang_error(int, int);

#endif



