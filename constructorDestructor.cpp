#include <iostream>
using namespace std;

class CTestCtorsDtors{
      
  int iVar;
  public:
             
      CTestCtorsDtors(); //ctor
      ~CTestCtorsDtors(); //dtor
      
}globalObj;

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

getchar();
return 0;    
}
