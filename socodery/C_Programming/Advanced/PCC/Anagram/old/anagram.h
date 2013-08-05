/*****************************************************************************
*
* File NAME : anagram.h
*
* Description: header file
*
*****************************************************************************/

#ifndef _ANAGRAM_H
#define _ANAGRAM_H

#define SUCCESS 1
#define FAILURE 0
#define MAX_ANAGRAM_LEN 30
#define MAX_LINE_LENGTH 100

#define ERR_ALL      4
#define ERR_CRITICAL 3
#define ERR_MAJOR    2
#define ERR_MINOR    1


#ifdef TRACE
#define A_TRACE printf
#else
 #define A_TRACE no_print
#endif

/* Error Codes */

#define ERR_BLANK_LINE      102
#define ERR_UNEXPECTED_EOF  103

extern int letter_index(char );
extern void count_letters(char *, int []);
extern int letter_index_converter(char);
extern char index_letter_converter(int);
extern int get_line(char [], size_t);
extern int anagram_checker(int [], int []);

#endif



