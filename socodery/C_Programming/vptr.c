#include<stdio.h>
main()
{
void *vptr;
short int *iptr;
char *cptr;
int num=10;
char ch='A';

iptr=&num;
cptr=&ch;
printf("%d ,size: %d and %c , size: %d\n",*iptr,sizeof(iptr),*cptr,sizeof(cptr));
vptr=iptr;

printf("Void %d n size is %d\n",*((int *)vptr),sizeof(vptr));
vptr=cptr;
printf("\nVoid char %c n size is %d\n",*((char *)vptr),sizeof(vptr));

printf("Iptr value b4: %u n %u\n",iptr,cptr);
iptr=iptr+1;
cptr=cptr+1;
printf("iptr value now %u n %u\n",iptr,cptr);

}

