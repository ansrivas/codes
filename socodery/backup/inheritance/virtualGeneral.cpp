#include <iostream>
using namespace std;

     class Window // Base class for C++ virtual function example
     {
       public:
          virtual void Create() // virtual function for C++ virtual function example
          {
               cout <<"Base class Window"<<endl;
          }
     };
     class CommandButton : public Window
     {
       public:
          void Create()
          {
              cout<<"Derived class Command Button - Overridden C++ virtual function"<<endl;
          }
     };

     int main()
     {
         Window  *x, *y;
   
         x = new Window();
         x->Create();

         y = new CommandButton();
         y->Create();

         return 0;
     }

