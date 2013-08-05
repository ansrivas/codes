#include <iostream>
    
using namespace std;

void vFnHello(int i){
     printf("Hello");
     return;     
}

int main(){

void (*vPtrMyFuncPtr)(int i) = vFnHello;

(*vPtrMyFuncPtr)(5);

int a = 0 ;   
scanf("%d",&a);  
return 0;    
}
