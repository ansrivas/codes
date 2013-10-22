#include <iostream>

using namespace std;

class CSingleton{
 static CSingleton *ptr;
 CSingleton(){}
 CSingleton(CSingleton &){}
 CSingleton& operator=(CSingleton &){}
 public :
      static  CSingleton *  createSingleton(){
           if(ptr == NULL){
           ptr = new CSingleton();
           }       
           return ptr;     
        }
        int i;
 
      
};
CSingleton* CSingleton:: ptr = NULL;

int main(){
 CSingleton * singleton = CSingleton::createSingleton();
 singleton->i = 5;
 printf("%d", singleton->i);
 getchar();
 return 0 ;    
    
}
