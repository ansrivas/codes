#include <stdio.h>
int main()
{
    FILE *fp;
    char name[10];
    fp = fopen("test","w");
    fprintf(fp,"\n%s","1 a 1");
    fclose(fp);
    fp = fopen("test","r");
    printf("%s\n",name);
    fscanf(fp,"%s",name);
    printf("%s\n",name);
    fclose(fp);
    return 0;
}
