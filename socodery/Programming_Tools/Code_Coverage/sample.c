#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

extern void link_file();
const int MAXARGS = 16;

int *my_malloc(int size)
{
  int *ptr=NULL;
  ptr=(int*)malloc(size*sizeof(int));
  #ifdef MACRO1
  int var1=0;
  printf("fail?");
  scanf("%d",&var1);
  if(var1!=0)
  { 
	ptr=NULL;
  }
 
  #endif
  return ptr;
}

int main( int argc, char* argv[] ) 
{
    int i;
    int *ptr;
 
   /* Establish pair-wise equality between arguments */
    for (i = 1; i < argc-1; i++) 
    {
        if (0 == strcmp(argv[i],argv[i+1])) 
        {
            printf("Check!\n");
        }
        else if ( 0 == strcmp(argv[i],"Hey!" )) 
        {
            printf("Huh?\n");
        }
        else 
        {
            printf("oops\n");
        }
    }

   ptr = my_malloc(sizeof(int) * 10);
   
    if (ptr == NULL)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }
    ptr[0]=1;
    ptr[1]=2;
   
    free(ptr);
    
    link_file();
    return 0;
}

