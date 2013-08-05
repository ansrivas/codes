#include<iostream>
using namespace std;
// functio pointers and polymorphism

class base
{
public :
   int b;
   virtual void display()
   {
      cout << "In base\n";
   }

   ~base()
   {
      cout << "In base destruct\n"<< endl;
   }
};

class derived : public base
{
public : 
   int der;

   ~derived()
   {
      cout << "In derived destruct\n" << endl;
   }

   //virtual void display()
   void display()
   {
      //der = 100;
      cout << "In derived\n";
      cout << "der = " << der << endl;
   }

};

int main()
{
   base *bptr;
   base b;
   derived d;

   bptr = &b;
   bptr->display();

   bptr = &d;
   bptr->display();
   
   derived *dptr;
   dptr = &d;
   dptr->display(); 

   //dptr = &b;  //invalid conversion from base to derived. compilation error 
   //dptr->display();

  /*cout << "asisgning base to derived\n" << endl;
  * dptr = (derived *)b;  // compilation error: cannot convert base to derived
   dptr->display();
   ( (base *)dptr)->display(); */

  cout << "asisgning base to derived done\n" << endl;

   ((derived *)bptr)->der = 200;
   ((derived *)bptr)->display();

return 0;
}
