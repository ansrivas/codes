#include <iostream>
using namespace std;

class base1 {
protected:
  int i;
public:
  base1(int x) { i = x; cout << "Constructing base1\n"; }
  ~base1() { cout << "Destructing base1\n"; }
};

class base2 {
protected:
  int k;
public:
  base2(int x) { k = x; cout << "Constructing base2\n"; }
  ~base2() { cout << "Destructing base2\n"; }
};

class derived: protected base1, private base2 {
  int j;
public:
  derived(int x, int y, int z): base1(y), base2(z)
    { j = x; cout << "Constructing derived\n"; }

  ~derived() { cout << "Destructing derived\n"; }
  void show() { cout << i << " " << j << " " << k << "\n"; }
};

class derivedLevel2 : public derived {
public:
  derivedLevel2(int x, int y, int z): derived(x,y,z)
    { cout << "Constructing derivedL2\n"; }

  ~derivedLevel2() { cout << "Destructing derivedL2\n"; }
  void showDerivedL2() { cout << i << " " << k << "\n"; }
};

int main()
{
  derived ob(3, 4, 5);
  ob.show();  // displays 4 3 5

  derivedLevel2 ob2(7, 8, 9);
  ob2.showDerivedL2();

  return 0;
}

