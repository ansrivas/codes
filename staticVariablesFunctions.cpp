#include <iostream>
using namespace std;

class CStatic{
   
   public:
   int iMemberVar;
   static int iStatic;   
   static void vUpdateStatic();
   static void vUpdateMemberVar();
};


int CStatic::iStatic = 0; // wont work since variable is private, would work if variable is public.


void CStatic::vUpdateStatic(){
     
CStatic::iStatic++ ; //will work perfectly
return;
}

void CStatic::vUpdateMemberVar(){
     
iMemberVar++; //this will throw error. Now since this is a static function, only on copy of it is going to exist.
              // So static function can't update the member variable here. It has to be associated with an object.
return;
}

int main(){
 
CStatic obj;

obj.iStatic++ ;
CStatic::iStatic++;

printf ("%d", obj.iStatic);
printf ("%d", CStatic::iStatic);


getchar();
return 0;    
}
