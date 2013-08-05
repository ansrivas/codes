#include <iostream> 
using namespace std;

    //Declaration of the function to be made as friend for the C++ Tutorial sample
    int AddToFriend(int x);

    class CPP_Tutorial
    {
       int private_data;
    public: 
       CPP_Tutorial() 
      {
          private_data = 5;
       }
       friend int AddToFriend(int x);
    };

    int AddToFriend(int x)
    {
       CPP_Tutorial var1; 
       return var1.private_data + x;
    } 

    int main()
    {
       cout << "Added Result for this C++ tutorial: "<< AddToFriend(4)<<endl;
    }  

