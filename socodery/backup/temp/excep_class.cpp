#include <iostream>
//#include <exception>

using namespace std;

class abc : public exception
{
int a;

};

int main()
{
abc x;
try{
throw x;
}
catch(...)
{
cout << x.what() << endl;
}
return 0;
}
