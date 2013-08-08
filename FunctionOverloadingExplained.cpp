#include <iostream>
using namespace std;

class CTest{
  public:
         void vFnSomething(float f);
         void vFnSomething(int i);    
      
      
};

void CTest::vFnSomething(int i){

printf ("integer function%d", i);
return;  
}

void CTest::vFnSomething(float f){

printf ("float function%f", f);
return;  
}

int main(){
    
CTest testObj;
testObj.vFnSomething(5);
testObj.vFnSomething(2.5f);
getchar();
return 0;    
}
