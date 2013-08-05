/*******************************************************************************
*
*  FILE NAME    : anagram_main.c
*
*  DESCRIPTION: main function for anagram program
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
*******************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include "anagram_port.h"
#include "anagram_util.h"
#include "anagram.h"


/*******************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Accepts the source and trial string and calls the functions
*
* RETURNS: Returns SUCCESS/FAILURE
*******************************************************************************/
S32_INT main()
{

    SCHAR line[MAX_LINE_LENGTH];

    S32_INT target[MAX_ANAGRAM_LEN], /* Count of characters for target string*/
            trial[MAX_ANAGRAM_LEN];  /* Count of characters in test string */


    A_TRACE(BRIEF_TRACE, "\nTRACE>> Program starting...\n");


    printf("Enter the target string:");

    if(SUCCESS != get_line(line,sizeof(line))) /* Read in target string */
    {
        A_TRACE(BRIEF_TRACE, "\nTRACE>> Invalid Read...\n");
        return FAILURE;
    }
    
    if(SUCCESS != count_letters(line, target)) /* Count the numbers for each 
						string */
    {
        A_TRACE(BRIEF_TRACE, "\nTRACE>> Invalid Read...\n");
        return FAILURE;
    }

    printf("Enter a test string (to exit just press ENTER key :\n");

    while (get_line(line, sizeof(line))) /* Read in candidates for comparison */
    {
         count_letters(line, trial); /* Count the numbers for each letter */

         if (SUCCESS == anagram_checker(target, trial)) /* Compare the letter 
							frequencies */
            printf("Anagram! One\n");
         else
           printf("Try again\n");
    }
    return SUCCESS;
}


