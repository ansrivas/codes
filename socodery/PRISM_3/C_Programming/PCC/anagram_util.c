/*********************************************************************
*
*  FILE NAME    : util.c
*
*  DESCRIPTION: Function definitions for anagram 
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*  23-MAR-08 Shiv    NA			Review comments  
*
*
*   2008,  Technologies (Holdings) Ltd
*
*********************************************************************/

/********************************************************************
*      			Include Files
********************************************************************/

#include <ctype.h>
#include <stdio.h>
#include "anagram.h"

/********************************************************************
*      			Global variables
********************************************************************/
int g_trace_level = NO_TRACE;

/*********************************************************************
*
* FUNCTION NAME: set_trace_flag
*
* DESCRIPTION: Modify the global trace flag as per input param
* 
*
* RETURNS: Returns void
*********************************************************************/

void set_trace_flag(int trace_val)
{
    g_trace_level = trace_val;
    A_TRACE(DETAILED_TRACE, ("set_trace_flag: trace flag set to %d\n", g_trace_level)); 
}

/*********************************************************************
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
* RETURNS: Returns void
*********************************************************************/

void count_letters(char *str, 
		   int table[MAX_ANAGRAM_LEN])
{
    int index = 0;

     A_TRACE(DETAILED_TRACE, ("count_letters : function entered (%s)\n", str)); 


    /* clear the table */
    memset(table,0, sizeof(table));

    while (*str != '\0') 
    {
     
     index = letter_index_converter(*str); // Which number does the letter 

                                          // correspond to


         A_TRACE(DETAILED_TRACE, ("count_letters : index = %d MAX = %d  \n",index, MAX_ANAGRAM_LEN )); 




     if (index >= 0 && index < MAX_ANAGRAM_LEN) // If it is a letter, increment 
                                          // the appropriate table entry
     {
         A_TRACE(DETAILED_TRACE, ("count_letters : Incrementing count for char %c \n", *str)); 
         table[index]++;
     }
     else
     {
         A_TRACE(DETAILED_TRACE, ("count_letters : Ignoring invalid character %c \n", *str)); 
     }

     str++; //Move to next character
    }

    A_TRACE(DETAILED_TRACE, ("count_letters : function exited\n")); 

}

/*********************************************************************
*
* FUNCTION NAME: letter_index_converter 
*
*DESCRIPTION: Finds out what number does the letter stored in 'c' correspond to.
*
* RETURNS: Returns an integer for a character ranging from 0 to 25(0-A,1-B,)
*********************************************************************/
int letter_index_converter(char c)
{
     A_TRACE(DETAILED_TRACE, ("letter_index_converter : function entered (%c)\n", c)); 

     if (isalpha(c))
     {
         return c - 'A';
     }
     else
     {
         A_TRACE(BRIEF_TRACE, ("letter_index_converter: Got invalid character %c \n", c)); 
         A_ERROR(ERROR_MAJOR, ERROR_INVALID_CHAR);

         return -1;
     }

}


/*********************************************************************
*
* FUNCTION NAME: get_line 
*
* DESCRIPTION: Read a line of text from the keyboard
*
* RETURNS: Returns 0 or 1
*********************************************************************/
int get_line(char buf[], 
             size_t len)
{
      int c = 0, temp_len = len;
      char *input;
      
      input = buf;

      while (len > 1 && (c = getchar()) != EOF && c != '\n') // Read characters                                                    //until the buffer fills up, 
                          //end- of-file is reached or a new line is encountered
      {
         *buf = c;
         buf++;
         len--;
      }

      if (temp_len == len)
      {
        A_TRACE(BRIEF_TRACE, ("get_line : Got Empty Line\n")); 
        return 0;
      }

      if (len > 0) // Terminate the string with null character
      {
          *buf = '\0';
      }

      A_TRACE(BRIEF_TRACE, ("get_line : Read the line [%s]\n", input)); 
      A_TRACE(DETAILED_TRACE, ("get_line : Returning \n")); 
      return 1;
} 

/********************************************************************
*
* FUNCTION NAME: anagram_checker
*
* DESCRIPTION: Compare two frequency tables
*
* RETURNS: Returns SUCCESS if match found else FAILURE
*********************************************************************/
int anagram_checker(int table1[MAX_ANAGRAM_LEN], int table2[MAX_ANAGRAM_LEN])
{
        int index;
        int match = 0;

        A_TRACE(DETAILED_TRACE, (" anagram_checker entering \n")); 

        for (index = 0; index < MAX_ANAGRAM_LEN; index++) // Go through each 
                                                          // count of letters
        {
          if (table1[index] != table2[index]) // Is there a differnce 
                                              // between tables
          {
             A_TRACE(BRIEF_TRACE,(" anagram_checker:Mismatch for index %d (%d Versus %d)\n",
                  index, table1[index], table2[index])); 
            match = FAILURE;
            break;
          }
          else // All the table entries matched
          {
            match = SUCCESS;
          }
        }

        A_TRACE(BRIEF_TRACE, (" anagram_checker returned %d \n", match)); 
        return match;
}

