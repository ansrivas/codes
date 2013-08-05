#include <iostream>
using namespace std;
class A;

class B
{
  public :
 void displayB(A objA)
  {
     
     objA.aa = 100;
     cout << "objA.a =" << objA.aa << endl;
  }

};

class A
{
int aa;
public :
 void displayA(){; }
 void friend B::displayB(A);

};



int main()
{
B bb;
A objA;

bb.displayB(objA);
return 0;
}
