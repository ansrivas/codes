#include <iostream>
using namespace std;

class CTest{
      
  char *cptr;
  
  public:
         CTest(char *src="", int iLen){
            cptr = new char[iLen +1] ;
            strncpy(cptr,  src, iLen);
            cptr[iLen] = '\0' ;                        
         }   
         ~CTest(){
         printf("dest called\n");
         delete[] cptr;
         cptr = NULL;         
         }
   void vFnPrintPtr(){
   if(cptr)
   printf("%s\n" ,cptr);
   else 
   printf("NULL\n");     
   }   
};
int main(){
   
CTest testObj("hello",5);
testObj.vFnPrintPtr();
{
 //Now this is an example of shallow copy... exact assignment is done here, so even the POINTERS (addressses) are being copied.     
 CTest tempObj = testObj;   //please notice that tempObj is a local object so the destructor would be called here.   
}    
testObj.vFnPrintPtr(); //Now since the destructor is called, the object destroyed already (same address) , segmentation fault would result
getchar();
return 0;  
}
