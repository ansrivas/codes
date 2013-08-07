#include <iostream>
using namespace std;


int i;

int main(){
int i = 10;
::i = 12;
printf("%d", i); //output 10;
printf("%d",::i); //output 12;
getchar();
return 0;
}
