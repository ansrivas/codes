#include <iostream>
using namespace std;

class CTestCtorsDtors{
      
  int iVar;
  public:
             
      CTestCtorsDtors(); //ctor
    virtual  ~CTestCtorsDtors(); //dtor
      
}globalObj;

class CDerived:public CTestCtorsDtors{
    public:
           CDerived(){
           printf("inside CDerived Ctor\n");           
           } 
           ~CDerived(){
           printf("inside CDerived Dtor\n");           
           }   
};

CTestCtorsDtors::~CTestCtorsDtors(){      
printf("Inside dtor\n");                             
}

CTestCtorsDtors::CTestCtorsDtors(){
iVar = 1;
printf("inside Ctor\n");                                  
}

int main(){
printf("inside main\n"); //order of output, inside ctor, inside main, inside ctor , inside dtor
CTestCtorsDtors obj;    



CTestCtorsDtors *objBase;
objBase = new CDerived(); // now after this we are calling delete objBase
delete objBase;           /*The output will be
                          inside Ctor
                          inside CDerived Ctor
                          Inside dtor
                          Here we can see the derived class destructor is not being called, thus resulting in a memory leak
                          So we need to use a virtual keyword in front of base class destructor */

getchar();
return 0;    
}
