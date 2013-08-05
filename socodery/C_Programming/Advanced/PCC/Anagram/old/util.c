/*******************************************************************************
*
*  FILE NAME    : util.c
*
*  DESCRIPTION: Function definitions for anagram 
*
*    DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  sIBU    C FG 1.0           Initial creation
*
*  23-MAR-08 sHIV    NA			Review comments  
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
#include "anagram.h"

/******************************************************************************
*      			Global variables
******************************************************************************/
int g_error_level = ERR_ALL;

/******************************************************************************
*
* FUNCTION NAME: ang_error
*
* DESCRIPTION: Prints the error message along with the error number
*
* RETURNS: Returns void
*******************************************************************************/
void ang_error(int err_level,
               int errno)
{
    if(g_error_level == ERR_ALL || err_level == g_error_level)
    {
        perror ("\n[ERROR] - ");
        printf( "Error No : (%d)\n", errno );
    }
}


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
* RETURNS: Returns void
*******************************************************************************/

void count_letters(char *str, 
		   int table[MAX_ANAGRAM_LEN])
{
    int index = 0;

    A_TRACE("\n Entering count_letters Function\n"); 

    /* clear the table */
    memset(table,0, MAX_ANAGRAM_LEN*sizeof(int));

    while (*str != '\0') 
    {
     
     index = letter_index_converter(*str); // Which number does the letter 
                                          // correspond to
     if (index >= 0 && index < MAX_ANAGRAM_LEN) // If it is a letter, increment 
                                          // the appropriate table entry
     {
         table[index]++;
     }

     str++; //Move to next character
    }

    A_TRACE("\n Exiting count_letters Function\n"); 
}

/*******************************************************************************
*
* FUNCTION NAME: letter_index_converter 
*
*DESCRIPTION: Finds out what number does the letter stored in 'c' correspond to.
*
* RETURNS: Returns an integer for a character ranging from 0 to 25(0-A,1-B,)
*******************************************************************************/
int letter_index_converter(char c)
{
   A_TRACE("\n Entering letter_index_converter Function\n"); 
     if (isalpha(c))
         return c - 'A';
     return -1;
   A_TRACE("\n Exiting letter_index_converter Function\n"); 
}


/*******************************************************************************
*
* FUNCTION NAME: get_line 
*
* DESCRIPTION: Read a line of text from the keyboard
*
* RETURNS: Returns 0 or 1
*******************************************************************************/
int get_line(char buf[], 
             size_t len)
{
      int c = 0, temp_len = len;
      A_TRACE("\n Entering get_line Function\n"); 
	  
    memset(buf,0,sizeof(buf));

   while (len > 1 && (c = getchar()) != EOF && c != '\n') // Read characters                                                    //until the buffer fills up, 
                          //end- of-file is reached or a new line is encountered
      {
         *buf = c;
         buf++;
         len--;
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

      return 1;
      A_TRACE("\n Exiting get_line Function\n"); 
} 

/******************************************************************************
*
* FUNCTION NAME: anagram_checker
*
* DESCRIPTION: Compare two frequency tables
*
* RETURNS: Returns SUCCESS if match found else FAILURE
*******************************************************************************/
int anagram_checker(int table1[MAX_ANAGRAM_LEN], int table2[MAX_ANAGRAM_LEN])
{
        int index;
        int match = 0;
        A_TRACE("\n Entering anagram_checker Function\n"); 
        for (index = 0; index < MAX_ANAGRAM_LEN; index++) // Go through each 
                                                          // count of letters
        {
          if (table1[index] != table2[index]) // Is there a differnce 
                                              // between tables
          {
            match = FAILURE;
            break;
          }
          else // All the table entries matched
          {
            match = SUCCESS;
          }
        }
        A_TRACE("\n Exiting anagram_checker Function\n"); 
        return match;
}

#ifndef TRACE

no_print(char * str)
{
    
}
#endif

