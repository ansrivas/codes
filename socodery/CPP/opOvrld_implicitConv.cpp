#include <iostream>
using namespace std;

class temp
{
public :
temp() { cout << "in def const\n" ; }
temp(int x) { cout << "in const\n" ; }
int operator int()
{
cout << "operator int\n";
double x;
return x;
}

operator double()
{
cout << "operator int\n";
return 0;
}
};
 
int main()
{
temp T;
int x=T;
int y=int(T);
temp Y = 10;
int z = Y;
return 0;
}
