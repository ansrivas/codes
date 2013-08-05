/* Program to concatenate and display all the command line arguments */
#include <stdio.h>
#include <stdlib.h>

void concat(char *final, char *part);
int get_len(char *str);

int main(int argc, char *argv[])
{
   char *result;
   int result_len;
   int len_argument;
   int i;

   if (argc == 1)
   {
	fprintf(stderr, "Usage : %s arg1 [arg2 ...]\n", argv[0]);
	exit(1);
   }

   /* Calculate total length, so that memory can be allocated */
   for(i = 1; i < argc; i++)
   {
	len_argument = get_len(argv[i]);

	result_len += len_argument;
   }
   
   printf("Total length = %d\n", result_len);

   result = (char *) malloc(result_len + 1);

 
   if (result == NULL)
   {
	fprintf(stderr, "Unable to allocate memory\n");
	exit(1);
   }

   result[0] = 0;

   /* Start concatenating */
   i = 1;
   while (i < argc)
   {
	concat(result, argv[i]);
	i++;
   }
   
   printf("The result is \"%s\"\n", result);
     
   exit(0);
}

int get_len(char *str)
{
  int length = 0;

  while (*str)
  {
	length++;
	str++;
  }

  return length + 1;
}


/* concat : Function to concatenate the string part at end of string final */

void concat(char *final, char *part)
{
    int i, len_part, curr_index;

    curr_index = get_len(final)  + 1;

    len_part = get_len(part);


    for (i = 0; i < len_part - 1; i++)
       final[curr_index + i] = part[i];
    
    final[curr_index + i] = 0;
}
