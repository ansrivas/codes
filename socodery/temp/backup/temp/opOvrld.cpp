#include <iostream>
using namespace std;

class A
{
     int x;
public :
     A(){ x = 10;}
     A(int yy){ 
       cout << "in const" << endl;
       x = yy;}

     A operator +(A obj1)
     {
       A ret;
       int yy;
       yy = x+ obj1.x; 
       cout << "before const" << endl;
       return A(yy);
     }
     void display()
{
 cout << "val of x\n" << x << endl;
}
};

int main()
{
A obj1, obj2, obj3;
obj3 = obj2 + obj1;
obj3.display();

}



