/*******************************************************************************
*
*  FILE NAME    : util.c
*
*  DESCRIPTION: Function definitions for anagram 
*
*    DATE    NAME    REFERENCE          REASON
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*  23-MAR-08 Shiv    NA			Review comments  
*
*  09-NOV-08 Shiv    Coding Skills FG	Updation for Coding skills program  
*
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/

/******************************************************************************
*      			Include Files
******************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "anagram.h"
#include "anagram_port.h"
#include "anagram_util.h"
#include "anagram_error_msg.h"

/******************************************************************************
*      			Global variables
******************************************************************************/
UCHAR g_error_level = ERR_ALL;
UCHAR g_trace_level = DETAILED_TRACE; 


/*******************************************************************************
*
* FUNCTION NAME: count_letters
*
* DESCRIPTION: Compute a frequency table for LETTERS in a string
*              which will result in a table like
*              table[0]=4  which means 4 instances of 'a'
*              table[1]=0  which means 0 instances of 'b'
*              table[2]=8  which means 8 instances of 'c'
*              .
*              .
*              .
* 
*
* RETURNS: Returns SUCCESS/FAILURE
*******************************************************************************/
ang_return_et count_letters(SCHAR *str, 
		   S32_INT table[MAX_ANAGRAM_LEN])
{
    S32_INT index = 0;

    A_TRACE(DETAILED_TRACE, "\nTRACE>> Entering count_letters Function\n"); 

    /* clear the table */
    memset(table,0, sizeof(table));

    
    while (*str != '\0') 
    {
     A_TRACE(BRIEF_TRACE, str);
     
     index = letter_index_converter(*str); // Which number does the letter 
                                          // correspond to
     if (index >= 0 && index < MAX_ANAGRAM_LEN) // If it is a letter, increment 
                                          // the appropriate table entry
     {
         table[index]++;
     }
     else
     {
	ang_error(ERR_MAJOR, ERR_INVALID_DATA);
        return FAILURE;
     }

     str++; //Move to next character
    }
  
    return SUCCESS;

    A_TRACE(DETAILED_TRACE, "\nTRACE>> Exiting count_letters Function\n"); 
}

/*******************************************************************************
*
* FUNCTION NAME: letter_index_converter 
*
*DESCRIPTION: Finds out what number does the letter stored in 'c' correspond to.
*
* RETURNS: Returns an integer for a character ranging from 0 to 25(0-A,1-B,)
*          or FAILURE
*******************************************************************************/

ang_return_et letter_index_converter(SCHAR c)
{
   A_TRACE(DETAILED_TRACE, "\nTRACE>> Entering letter_index_converter Function\n"); 
     if (isalpha(c))
         return c - 'A';
     return FAILURE;
   A_TRACE(DETAILED_TRACE, "\nTRACE>> Exiting letter_index_converter Function\n"); 
}


/*******************************************************************************
*
* FUNCTION NAME: get_line 
*
* DESCRIPTION: Read a line of text from the keyboard
*
* RETURNS: Returns SUCCESS/FAILURE
*******************************************************************************/

ang_return_et get_line(SCHAR buf[], 
             size_t len)
{
      S32_INT c = 0, temp_len = len;

      A_TRACE(DETAILED_TRACE, "\nTRACE>> Entering get_line Function\n"); 

      while (len > 1 && (c = getchar()) != EOF && c != '\n') // Read characters                                                    //until the buffer fills up, 
                          //end- of-file is reached or a new line is encountered
      {
         *buf = c;
         buf++;
         len--;
      }

      if(len <= 1 )
      {
        ang_error(ERR_CRITICAL, ERR_BUFFER_FINISHED);
        
        return FAILURE;
      }

      if (temp_len == len)
      {
        ang_error(ERR_MINOR, ERR_BLANK_LINE);
        return 0;
      }

      if (len > 0) // Terminate the string with null character
      {
          *buf = '\0';
      }

      return SUCCESS;

      A_TRACE(DETAILED_TRACE, "\nTRACE>> Exiting get_line Function\n"); 
} 

/******************************************************************************
*
* FUNCTION NAME: anagram_checker
*
* DESCRIPTION: Compare two frequency tables
*
* RETURNS: Returns SUCCESS if match found else FAILURE
*******************************************************************************/

ang_return_et anagram_checker( S32_INT table1[MAX_ANAGRAM_LEN], 
			 S32_INT table2[MAX_ANAGRAM_LEN])
{
        S32_INT index;
        S32_INT match = 0;

        A_TRACE(DETAILED_TRACE, "\nTRACE>> Entering anagram_checker Function\n"); 
        for (index = 0; index < MAX_ANAGRAM_LEN; index++) // Go through each 
                                                          // count of letters
        {
          if (table1[index] != table2[index]) // Is there a differnce 
                                              // between tables
          {
            A_TRACE(BRIEF_TRACE, "\nTRACE>> the 2 tables are different\n"); 
            match = FAILURE;
            break;
          }
          else // All the table entries matched
          {
            match = SUCCESS;
          }
        }
        A_TRACE(DETAILED_TRACE, "\nTRACE>> Exiting anagram_checker Function\n"); 
        return match;
}

/******************************************************************************
*
* FUNCTION NAME: trace_print
*
* DESCRIPTION: It prints the traces. This function exists only if TRACE_FEATURE flad is defined. It compares the trace string's level and prints it only if it is of lesser or the same level as the global trace level setting (BRIEF/DETAILED)
*
* RETURNS: void
*
*******************************************************************************/
void trace_print( UCHAR trace_level, 
		  SCHAR *p_trace_string)
{
  
  if(trace_level <= g_trace_level)
  {
        if(p_trace_string)
        {
              anagram_printf(PR_TYPE1, "%s",p_trace_string);
        }
        else
        {
              ang_error(ERR_MAJOR, ERR_NULL_PTR_RECVD);
        }
  }
}

/******************************************************************************
*
* FUNCTION NAME: ang_error
*
* DESCRIPTION: Prints the error message along with the error number
*
* RETURNS: Returns void
*******************************************************************************/
void ang_error(S32_INT err_level,
               S32_INT errno)
{
    if(g_error_level == ERR_ALL || err_level == g_error_level)
    {
        anagram_printf(PR_TYPE2,  "Error (%d) %s\n", errno, ang_error_msg[errno]);
    }
}


