#include <iostream>
#include "A1.h"
#include "A2.h"

using namespace std;

class Employee
{
public : 

   void demo1() const;
   void demo2();

   void display() const
{
    demo1();
    //demo2();
}
   static int val; 
};

int main()
{

cout << x << endl;
cout << y << endl;

int a;
	
cout<<"Enter a number : ";
cin>>a;

int b = a;		// Dynamic initialization
cout<<a<<"\t"<<b<<endl;

int *p = (int*) malloc(sizeof(int));

Employee *e1 = new Employee;

return 0;
}
