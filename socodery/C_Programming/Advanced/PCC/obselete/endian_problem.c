#include <stdio.h>


int main()
{
 long int str[2] = {0x41424344, 0x0}; /* ASCII ``ABCD'' */
 printf ("%s\n", (char *)&str);
}

