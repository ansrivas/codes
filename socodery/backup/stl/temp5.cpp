#include <iostream>
using namespace std;

class A
{
public :
int i;
void display(){ ; }
virtual ~A(){;}
};

class B : virtual public A
{
public :
int k;
void display(){ ; }
void show(){ ; }
};

class C : public virtual A
{

};

class D : public B, public C
{
public :
D()
{
i = 100;
}
};

int main()
{
A * ptrA;
B b;
ptrA=&b;
//ptrA->show();
ptrA->display();

A &c = b;
c.display();
c.show();
//ptrA->k=100;
return 0;
}
