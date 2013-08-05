#include <iostream>
using namespace std;

class base
{
//base(){;}
public :
virtual ~base() {cout<<"base dest\n"; }

};

class der : public base
{
public :
~der() {cout<<"der dest\n"; }
//~der(){;}
};
 
 int main()
{
base *ptr=new der;
delete ptr;
return 0;
}
