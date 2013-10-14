#include <iostream>

using namespace std;

class CBase{
  public:
         virtual void vFunc()= 0 ;     //Works as a skeleton for the derived objects
         
};

class CDerived: public CBase{
      public:
             void vFunc(){
               printf("inside CDerived\n");      
             }
      
};

int main(){
//CBase objBase; // We can't create an object of CBase here.
CDerived objCDerived;
objCDerived.vFunc();
getchar();
return 0 ; 
}
