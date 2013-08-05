#include <iostream>
using namespace std;

class CBase{
int a;
int b;
public:
       CBase(){
       a = 1;
       b = 1;        
       }
       //friend function
       friend void vFriendFunc(CBase cbaseObj); //Now it can access the private members of the class.  
           
      //friend class : this can access everything from this class
      friend class CFriendClass;
      
};

void vFriendFunc(CBase cbaseObj){
   
printf("%d", cbaseObj.a);  
return;
}

class CFriendClass{
     CBase baseObj;
     public:
            void vFnPrintCBase(){
            printf("%d",baseObj.a);
            return;     
            } 
      
};


int main(){

CFriendClass *friendClassObj = new CFriendClass();

friendClassObj->vFnPrintCBase();
delete friendClassObj;  
CBase baseObj;
vFriendFunc(baseObj);
int a;
scanf("%d",&a);
return 1;

}
