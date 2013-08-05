#include <iostream>
using namespace std;

//class A;

class A
{
public:
int l;
char c;
static int x;
void display()
{
cout << x << "\n";
cout << x << endl;
cout << x << "\n";
cout << x << endl;
}
};

int A::x;

int main()
{
A aa;
cout << aa.l << endl;
cout << aa.c << endl;
A::x=50;
bool p;
int t;
cout << sizeof(p) << endl;
cout << sizeof(t) << endl;
cout << A::x << "\n";
cout << A::x << endl;
cout << A::x << "\n";
cout << A::x << endl;
}

