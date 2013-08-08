#include <iostream>
using namespace std;

class CTest{
  
  public:
         bool bIsItself(CTest &);    
      
};

bool CTest::bIsItself(CTest& testObj){

if(this == &testObj)
        return true;
return false;    
}

int main(){
 
 CTest testObj , testObj3;
 if(testObj.bIsItself(testObj3))
 printf ("true");
 else
 printf("false");
 getchar();
 
    
 return 0;   
}
