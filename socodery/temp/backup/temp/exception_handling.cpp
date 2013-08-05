#include <iostream>
using namespace std;


void f()
{
throw 1;
}


int main()
{
int x;
f();
try
{
  cout << "in try " << endl;
}


catch(...)
{

  cout << "in catch" << endl;
  try{

  cout << "in try-1" << endl;
    }
   catch(...)
{

  cout << "in catch- 1" << endl;
   }
}
  cout << "outside catch" << endl;
return 0;
}
