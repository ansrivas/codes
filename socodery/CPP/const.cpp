#include <iostream>
using namespace std;

class book
{
  mutable int refNo;
  void getname() const;
  void setname();
}; 

void book::setname()
{
}

void book::getname() const
{
  refNo = 1000;
  //setname();
}

int main()
{
int a, b;
a=10;
b=50;
int &ref=a;
cout<< "a:" << a << "b:" << b << "ref:" << ref << "\n";
ref=b;
cout<< "a:" << a << "b:" << b << "ref:" << ref << "\n";
return 0;
}
