#include <iostream>

using namespace std;

class CBase{
  public:
         int iBase; 
         virtual void vPrint(){
         printf("Inside Base/n");     
         }   
     
};

class CDerived1: /*just use a virtual keyword here to avoid diamond problem*/virtual public CBase{
       public:
       void vPrint(){
         printf("Inside Derived1/n");     
       }    
      
};

class CDerived2: /*just use a virtual keyword here to avoid diamond problem*/virtual public CBase{
      public:
      void vPrint(){
           printf("Inside Derived2/n");     
      }    
};

class CDerived : public CDerived1,public CDerived2{ //thus the CBase is inherited here twice by CDerived1 & CDerived2
      public:
      void vPrint(){
           printf("This is CDerived\n");
      }
};


int main(){

CDerived objDerived;
objDerived.iBase = 4; 

printf("%d\n",objDerived.iBase); /*request for the member is ambiguous since we have derived
                                 the base class twice and thus two copies of "i"
                                 exist. 
                                 Now this is called a DIAMOND PROBLEM
                                 To avoid this, we can inherit base class as VIRTUAL Base Class */
                                 

CDerived *objDynamic = new CDerived();
objDynamic->vPrint();/*Thus the definition was ambiguous but finally we defined it in CDerived*/
getchar();     
return 0;    
}


