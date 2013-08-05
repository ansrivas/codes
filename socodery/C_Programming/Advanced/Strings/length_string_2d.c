/*************************************************************************
*
*  FILE NAME    : length_string_2d.c
*
*  DESCRIPTION  : Contains functions to demonstrate string functions
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/


/*
 * A function that deletes all occurrences of an item in an array.
 */
#include<string.h>

int tableDelete(char *a[], int num, char *elem)
{
  int to = 0;
  int from = 0;

  for (; from < num; from++)
    if (strcmp(a[from],elem) != 0)  
    {         /* item to keep */
      if (to != from)
        a[to] = a[from];   
      to++;   
    }
  return to == 0 ? to : to - 1;
}



/*
 * Reverses each string in a table of strings, using strrev.
 */
#include <string.h>

void reverseTab(char *table[], int n)
{
  void strrev(char *line);

  int i;

  for (i = 0; i < n; i++)
    strrev(table[i]);
}

void strrev(char *line)
{
  char *endptr = line + strlen(line);
  char temp;

  for (endptr--; endptr > line; line++, endptr--)
  {
    temp = *endptr;
    *endptr = *line;
    *line = temp;
  }
}


/*
 * Print length of each string in a table of character strings.
 */
#include <string.h>

void printTableLen(char *table[], int n)
{
  int i;
  
  for (i = 0; i < n; i++)
    printf("%i\n", strlen(table[i]));
}
