#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
const char *delimiter=";:|!"; 
char *s;
 
//char *str="abc;pqr;xyz";

char str[]="abc;pqr:xyz|hello!how;r|u";
  

  
   s = strtok(str, delimiter);

	printf("%s\n",s);

while((s = strtok(NULL,delimiter))!=NULL)

	printf("%s\n",s);

printf("%s\n",str);
puts(str);
return 0;
}
