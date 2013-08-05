#include <iostream> 
using namespace std; 
 void f(int test) 
{ 
  cout << "Inside f, test is: " << test << "\n"; 
  if(test) 
     throw test; 
} 
 
int main() 
{ 
  cout << "start\n"; 
 try { // start a try block 
    cout << "Inside try block\n"; 
    f(0); 
    f(1); 
    f(2); 
  } 
  catch (int i) { // catch an error 
    cout << "Caught an exception -- value is: "; 
    cout << i << "\n"; 
  } 
  cout << "end"; 
  return 0; 
}

