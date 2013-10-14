#include <iostream>

using namespace std;

int iFnFact(int iNum){
    if(iNum < 0 ){
            printf("NAN\n");
            return iNum;
    }
    if(iNum == 0 || iNum == 1)
    return iNum;
    
    return iNum * iFnFact(iNum -1);    
    
    
}

int main(){
  
int iNum = 0;  
while(1){
printf("Enter the number to find out the factorial\nAnd a negative num to quit\n");
scanf("%d",&iNum);
if(iNum < 0 ){
        break;
}
else {  
        printf("%d\n", iFnFact(iNum));  
     }      
}  

getchar();
return 1;
    
}
