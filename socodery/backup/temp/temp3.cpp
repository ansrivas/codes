#include <iostream>
using namespace std;


class Base1
{
public : 
   int a;

};

class Derived1 : public Base1
{
public : 
   int b;

};

class Derived2 : public Base1
{
public : 
   int b;

};

class DerivedLev3: public Derived1, public Derived2
{

};

int main()
{
DerivedLev3 A;
A.Derived2::a = 10;
A.Derived1::b = 100;
return 0;
}
