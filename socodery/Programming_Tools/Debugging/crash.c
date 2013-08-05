#include<stdio.h>

char *out;

main()
{
  char *in = "original text";
  
  printf("\n\nin contains (%s)\n",in);

  copy_fn(in);
}

copy_fn(char *in2)
{
  char *more="supercalifragilisticexpialidocious some more text...";
  more[2] = 'z';
  //strcpy(out,more);
   //strcat(out,in2);
  printf("the data (%s) has been copied..\n\n",out);
}

