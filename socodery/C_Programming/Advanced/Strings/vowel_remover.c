/*************************************************************************
*
*  FILE NAME    : vowel_remover.c
*
*  DESCRIPTION  :Program to remove all vowels from a string
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/


#include <stdio.h>
/**************************************************************************
*
* FUNCTION NAME: isvowel
*
* DESCRIPTION: Function to check whether a character is vowel or not
*
* RETURNS: Returns TRUE or FALSE
**************************************************************************/

int isvowel(int c)
{
  switch (c) 
  {
    case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
    case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
      return 1;
  }
  return 0;
}
/**************************************************************************
*
* FUNCTION NAME: read_in
*
* DESCRIPTION: Reads characters from the standard input
*
* RETURNS: Number of characters read
**************************************************************************/
int read_in(char *s, int max)
{
  int p = 0;
  int c;

  while (p < max && /* There is space in the array. */
         (c = getchar()) != EOF && /* more input */
         c != '\n')
    s[p++] = c;
  
  s[p] = '\0';
  return p;
}
/**************************************************************************
*
* FUNCTION NAME: rm_vowels
*
* DESCRIPTION: Function to remove vowels from a string
*
* RETURNS: Nothing
**************************************************************************/

void rm_vowels(char *from)
{
  char *to = from;

  while (*from != '\0')
    if (isvowel(*from))
      from++;
    else
      *to++ = *from++;

  *to = '\0';
}
/**************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: main function for vowel remover program
*
* RETURNS: Nothing
**************************************************************************/

int main()
{
  char string[101];

  printf("Enter upto 100 characters:\n");
  read_in(string, 100);
  printf("Before: %s\n", string);
  rm_vowels(string);
  printf(" After: %s\n", string);

  return 0;
}

