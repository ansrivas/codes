#include <iostream>

using namespace std;

class CBase{
  public:
         int i;
         char c;
         CBase(){
           i = 0 ;
           c = 'a';      
         }
};


class CDerived: public CBase{
  public:
         int i;
         char c; 
         float f;  
         CDerived(){
           i = 5;
           c = 'b';
           f = 0.5f;           
         }
           
      
};

int main(){
CBase objBase;
printf("%d %c\n",objBase.i, objBase.c);
CDerived objDer;

printf("%d %c\n",objDer.i, objDer.c);

objBase = objDer;
printf("%d %c\n",objBase.i, objBase.c); //class CBase has no member named 'f'
                                                   //So only those objects have been copied which already existed in Derived
                                                   //This is called object slicing

getchar();
return 0  ;
    
}
