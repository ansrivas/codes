#include <iostream>
using namespace std;

    class CPP_Tutorial
    {
       int private_data;
       friend class friendclass;

    public: 
       CPP_Tutorial()
       {
          private_data = 5; 
       }
    };

    class friendclass
    {
    public: 
       int subtractfrom(int x)
       { 
          CPP_Tutorial var2;
          return var2.private_data - x;
       }
    }; 

    int main()
    {
       friendclass var3;
       cout << "Subtracted Result for this C++ tutorial: "<< var3.subtractfrom(2) <<endl;
    } 

