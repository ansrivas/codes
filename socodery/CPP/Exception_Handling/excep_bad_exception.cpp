#include <iostream>
using namespace std;

void my_unexpected() {
  cout << "Call to my_unexpected" << endl;
  throw;
}

void f() throw(float,bad_exception) {
  cout << "In function f()" << endl;
  throw int();
}
int main() {
  set_unexpected(my_unexpected);
  try {
         f();
//    throw int();
  }
  catch (float e) {
    cout << "Exception in main(): " << endl;
  }     
  catch(bad_exception b)
 {
    cout << "caught bad exception " << b.what();
 }
}

