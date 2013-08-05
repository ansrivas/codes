#include <iostream>
using namespace std;

class A
{
   int a;

public :
   A() { 
    cout << "In const\n";
    //a=x;
    }

   static A* newObj()
   {
        return new A;

   }
   void setVal(int x)
   {
     a=x;
     cout << "val of a =" << a << endl; 
   }
};


int main()
{
   A* a = A::newObj();
   a->setVal(200);
   return 0;
}


