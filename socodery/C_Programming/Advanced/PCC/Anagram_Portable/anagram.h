/*******************************************************************************
*
*  FILE NAME    : anagram.h
*
*  DESCRIPTION: Header file function prototypes and macros
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

#ifndef _ANAGRAM_H
#define _ANAGRAM_H

#include "anagram_port.h"


#define MAX_ANAGRAM_LEN 5
#define MAX_LINE_LENGTH 50

typedef enum {SUCCESS = 0, FAILURE = 1}ang_return_et ;

extern ang_return_et letter_index(SCHAR );
extern ang_return_et count_letters(SCHAR *, S32_INT []);
extern ang_return_et letter_index_converter(SCHAR);
extern SCHAR index_letter_converter(S32_INT);
extern ang_return_et get_line(SCHAR [], size_t);
extern ang_return_et anagram_checker(S32_INT [], S32_INT []);

#endif



