#include <iostream>
using namespace std;

class CBase{
//int iLen;

protected:
          

public:   
      int iLen;
          CBase(){
          printf("Base CTor\n");        
          }   
      
         ~CBase(){
          printf("Base DTor\n");        
          }
      
      
};

/*here we mention the name of the access modifier*/ 
class CDerived : private CBase{
      
  public:
  int iLenDer; 
  CDerived(){
  printf("Derived CTor\n");
  }  
  
  ~CDerived(){
  printf("Derived DTor\n");
  }   
   
};

int main(){
{
CDerived obj;
}
//obj.iLen = 5; //we are accessing the base's private member here, private members never inherited.
getchar();
return 0;    
}
