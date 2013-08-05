/********************************************************************************
*
*  FILE NAME    : main.c
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
*
*   2008,  Technologies (Holdings) Ltd
*
*******************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include "anagram.h"

/*******************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Accepts the source and trial string and calls the functions
*
* RETURNS: Returns 0
*******************************************************************************/
int main(int argc, char *argv[])
{
    char line[MAX_LINE_LENGTH];
    int target[MAX_ANAGRAM_LEN] = {0}, // Count of characters for target string
    trial[MAX_ANAGRAM_LEN]= {0};  // Count of characters in test string
    printf("Enter the target string:\n");
    get_line(line, sizeof(line)); // Read in target string
    count_letters(line, target); // Count the numbers for each letter

    printf("Enter a test string (to exit just press ENTER key :\n");
    while (get_line(line, sizeof(line))) // Read in candidates for comparison
    {
     count_letters(line, trial); // Count the numbers for each letter
     if (anagram_checker(target, trial)) //Compare the letter frequencies
        printf("Anagram! \n");
     else
       printf("Try again\n");
    }
    return 0;
}


