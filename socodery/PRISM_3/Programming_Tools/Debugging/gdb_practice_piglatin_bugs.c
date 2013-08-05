/********************************************************************************
*
* FILE NAME : Piglatin_finder.c
*
* DESCRIPTION: Generate the pig Latin word of a given word
*
* DATE NAME REFERENCE REASON
*
*  2007,  Technologies (Holdings) Ltd
*
********************************************************************************/
#include<stdio.h>
/********************************************************************************
Global Declarations
********************************************************************************/
char vowels[11]={'a','e','i','o','u','A','E','I','O','U'};
int vowel_pos_finder(char *,int);
int string_length(char *);
void piglatin_converter(char *,int,int);
/*******************************************************************************
*
* FUNCTION NAME: piglatin_converter
*
* DESCRIPTION: Prints the word from the character immediately after the vowel, in a rotated way till
that character.
*
* RETURNS: Returns void
********************************************************************************/
void piglatin_converter(char *str,int len,int index)
{
 int i;
 if(index!=-1)
 {
  for(i=index+1;i<len;i++)
    printf("%c",*(str+i));
  for(i=0;i<=index;i++)
    printf("%c",*(str+i));
 }
 else
 {
  for(i=0;i<len;i++)
   printf("%c",*(str+i));
 }
 printf("\n");
}
/*******************************************************************************
*
* FUNCTION NAME: string_length
*
* DESCRIPTION: Finds the length of the string
*
* RETURNS: Returns length of the string
********************************************************************************/
int string_length(char *string)
{
 int length_string=0;
 while(*string++)
  return length_string;
}
/*******************************************************************************
*
* FUNCTION NAME: vowel_pos_finder
*
* DESCRIPTION: Finding the position of the first vowel in the string.
*
* RETURNS: Returns the position of the first vowel else -1
********************************************************************************/
int vowel_pos_finder(char str_array[],int str_length)
{
 int index1,index2;
 for(index1 = 0;index1 < str_length;index1++)
 {
  for(index2 = 0;index2 < 10;index2++)
  {
   if(str_array[index1]==vowels[index2])
   {
    return index1;
   }
  }
 }
 return -1;
}
/*******************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Takes the input string and calls appropriate functions
*
* RETURNS: Returns 0
********************************************************************************/
int main()
{
 int length_str;
 int vow_index;
 char *input_string = NULL; 
 printf("\nEnter the string \n");
 scanf("%s",input_string);
 length_str = string_length(input_string);
 vow_index = vowel_pos_finder(input_string,length_str);
 printf("\n");
 piglatin_converter(input_string,length_str,vow_index);
 return 0;
}
