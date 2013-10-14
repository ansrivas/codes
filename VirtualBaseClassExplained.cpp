#include <iostream>

using namespace std;

class CBase{
  public:
         int iBase;    
     
};

class CDerived1: /*just use a virtual keyword here to avoid diamond problem*/virtual public CBase{
      
      
};

class CDerived2: /*just use a virtual keyword here to avoid diamond problem*/virtual public CBase{
      
};

class CDerived : public CDerived1,public CDerived2{ //thus the CBase is inherited here twice by CDerived1 & CDerived2
      
};


int main(){

CDerived objDerived;
objDerived.iBase = 4; 

printf("%d\n",objDerived.iBase); /*request for the member is ambiguous since we have derived
                                 the base class twice and thus two copies of "i"
                                 exist. 
                                 Now this is called a DIAMOND PROBLEM
                                 To avoid this, we can inherit one of the base classes as VIRTUAL Base Class */
                                 


getchar();     
return 0;    
}


