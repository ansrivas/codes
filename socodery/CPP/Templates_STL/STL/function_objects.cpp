
#include <iostream>
  using std::cout;
class Negate 
  {
  public: 
    Negate(){}
    int operator() (int n) { return -n;} 
  };

  void Callback(int n, Negate & neg) 
  {
    int val = neg(n);  //1 invoke overloaded () 
    cout << val;
  }
int main() 
{ 
Negate a;
Callback(5,a); 
//output -5 
} 
