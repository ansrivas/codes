#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
 char *mess = "If you dont think about yourself at least once in your life time, you are going to miss the best comedy in life";

 char str1[32] = "I am with you";

 char *str = NULL;

 str = (char *) malloc(32 * sizeof(char));

 printf("String is %s", str);

 str1 = str;

 printf("String1 is %s", str1);

// free (str1);
 
}
