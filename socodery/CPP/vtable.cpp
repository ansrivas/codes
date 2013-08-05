#include <iostream>

using namespace std;

class Bas
{
public :
//int x;
virtual void display(){ };

};

class Bas1
{
//int t;
//virtual void display1(){ };

};

class Bas5
{
//int x;
virtual void display2(){ };

};
class Bas2 : public Bas, public Bas1, public Bas5
//class Bas2 : public Bas
{
//int y;
//int z;
//int a;
virtual void display(){ };

};

class Bas3
{
int x;
virtual void display(){ };
virtual void display1(){ };

};
int main()
{
Bas3 obj;
cout << "sizeof class Ba =" << sizeof(Bas) <<  endl;
cout << "sizeof class Ba1 =" << sizeof(Bas1) << endl;
cout << "sizeof class Ba5 =" << sizeof(Bas5) << endl;
cout << "sizeof class Ba2 =" << sizeof(Bas2) << endl;
cout << "sizeof class Ba3 =" << sizeof(Bas3) <<  endl;
cout << "sizeof class Ba3 =" << sizeof(obj) <<  endl;
return 0;
}
