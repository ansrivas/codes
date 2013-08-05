#include <iostream>
using namespace std;

int main(){
    
char cName[20];
memset(cName, 20, '0');    

gets(cName); //Now just enter a string > 20 characters.
             //This would eventually corrupt the memory location > 20 bits and booom 
             // Segmentation Fault is on its way :P
puts(cName); 
int a;
scanf("%d",&a);  
return 0;    
}
