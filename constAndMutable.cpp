#include <iostream>
using namespace std;

class CBase{
  
  public:
         int i;
         mutable int j;
         const int k;
          void vSeti (int x) const{ // Since we used a "const" keyword here, "this" pointer of the object which is calling this fucntion
                                   //would become constant so nothing can change in that object
 //           i = x; 
            return; 
         }  
         void vSetj(int x) const{
         
              j = x;
         return;     
         }
         void vPrintI(){
         
         printf("%d k = %d\n ",j,k);
         return;     
         }   
         
         //Constructor
         CBase() : k(10){ // Way to initialize a constant member variable
         }  
};

int main(){
    
CBase baseObj;
baseObj.vSeti(4); // We are trying to modify the object here (changing the value of i) so it would say, "read only structure"
baseObj.vSetj(2);
baseObj.vPrintI();
getchar();   
return 0;    
}
