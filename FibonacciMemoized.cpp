#include <iostream>
#include <string.h>

using namespace std;

int iFnFib(int iNum){
    if(iNum <= 2){
            return 1;
    }
    return (iFnFib(iNum-1) + iFnFib(iNum-2));   
}


int iMemoArray[100];
int iFnFibMemo(int iNum){
    if( iNum <= 2)
        return 1;
    else{
         if(iMemoArray[iNum] != 0 )
         {
             return iMemoArray[iNum];                    
         }
         iMemoArray[iNum] = iFnFibMemo(iNum - 1) + iFnFibMemo(iNum -2);  
         return iMemoArray[iNum];                 
    }    
}


int main(){

memset(iMemoArray,0, 100);

int iNum = 0 ; 
while(1){
         printf("Enter the number or a -ve number to quit\n");
         scanf("%d",&iNum);
         if(iNum < 0){
                 break;
         }
         else{
              printf("%d\n",iMemoArray[iNum]);
              printf("%d\n",iFnFibMemo(iNum));     
         }         
}    
getchar();    
return 1;
}
