#include <iostream>
using namespace std;

class CBase{
      
     public:
            virtual void vFunc(){
                 printf("inside Base\n");
                 return;     
            } 
};

class CDerived : public CBase{
      public:
             int i;
             void vFunc(){
             printf("inside CDerived\n");
             return ;     
             }    
};


int main(){
CBase baseObj;

baseObj.vFunc(); //inside CBase , without virtual keyword
CDerived derObj;

derObj.vFunc(); //inside CDerived, without virtual keyword

/*Now if we assign a derived class address to a base pointer */
CBase *basePtr;
basePtr = &derObj;
basePtr->vFunc();// This would print "inside base" , but this is wrong since we are pointing to an address of a derived object
                    //For this we use the keyword VIRTUAL while defining a function in BASE class which is about to be inherited
                    //by the derived class
                    //if we call the same function by writing the keyword VIRTUAL in base class function it would help in
                    //determing the correct version of function to be called so, the output would be "inside CDerived" 
                    
                    
printf("Size of Base class %d\n",sizeof(baseObj)); // This would print 4 bytes, since a v-ptr is inserted in the base class.
printf("size of Derived class %d\n",sizeof(derObj));// This would also print 4 bytes , v-ptr is shared between the classes being derived
getchar();
return 0;    
}
