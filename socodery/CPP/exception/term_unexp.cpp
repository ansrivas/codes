#include <iostream.h>

//using namespace std;

void term_handler()
{
cout << "in term handler\n";
  throw ;
cout << "in term handler : after throw\n";
}

//void func1() throw (int, bad_exception)
void func1() throw () 
{
try{
throw int();
//throw exception();
}
catch (float) {
cout << "in catch\n";
}
}


int main()
{
set_unexpected(term_handler);
try{
try{
   func1();
}// outer try
catch(float)
{

cout << "in outer catch\n";
}
} // try 2
catch(int)
{

cout << "in int catch\n";
}

cout << "outside catch\n";
return 0;
}
