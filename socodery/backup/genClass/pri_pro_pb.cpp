#include <iostream>
using namespace std;
int x;

class temp
{
int a;
protected :
int b;
public :
int c;

void display()
{
cout << "In display\n";
a=10;
b=20;
c=30;
cout << x << endl;
x=50;
cout << x << endl;
}
};

int main()
{
void *YY;

temp AA;
//YY = (void *)AA;

YY->display();
AA.display();

int x;
//AA.a=100;
//AA.b=200;
AA.c=300;
cout << x << endl;
cout << ::x << endl;
x=500;
cout << x << endl;
cout << ::x << endl;

AA.display();
return 0;
}
