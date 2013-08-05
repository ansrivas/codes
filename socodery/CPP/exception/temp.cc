#include <iostream>

using namespace std;

void func ()
{
   cout << "in term " << endl;
  throw 5;

}

int main()
{
set_terminate(func);
 try {
  throw "xyz";
    }
 catch (int &x)
  {
     cout << " in catch in main " << endl;
  } 
return 0;
}

