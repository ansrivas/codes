#include <iostream>
using namespace std;

class BaseClass {
  int i, j;
public:
 //BaseClass(){;}
  BaseClass(int x, int y) { 
     cout << "in base constructor\n";
     i = x; 
     j = y; 
  }
  void showij() { 
 cout << "in base class\n" ;
     cout << i << ' ' << j << '\n'; 
  }
};

class DerivedClass : public BaseClass {
  int k;
public:
 // DerivedClass(){;}
  DerivedClass(int a, int b, int c) : k(a), BaseClass(b, c) {
    cout << "in derived constructor\n";
    k = a;
  }
  void show() { 
    cout << k << ' '; 
    showij(); 
 }
  /*void showij() { 
  
 cout << "in derived class\n" ;
  }*/
};

int main()
{
  DerivedClass ob(1, 2, 3);
  ob.showij();
  //DerivedClass x;
/*
  ob.show();
*/
  return 0;
}

