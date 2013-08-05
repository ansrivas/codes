// File:    ~ftp/pub/class/cplusplus/inheritance/ProtectedMember.cpp
// Purpose: Inherite protected members of the base class

#include <iostream>
using namespace std;

class base {
protected:
  int i, j; 
public:
  void set(int a, int b) { i = a; j = b; }
  void show() { cout << i << " " << j << "\n"; }
};

class derived : public base {
  int k;
public:
  // derived may access base's i and j
  void calcArea() { k = i*j; }

  void displayArea() { cout << k << "\n"; }
};

int main()
{
  derived ob;

  ob.set(2, 3); // OK, known to derived
  ob.show();    // OK, known to derived

  ob.calcArea();
  ob.displayArea();

  return 0;
}

