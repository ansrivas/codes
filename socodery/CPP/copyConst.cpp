#include <iostream>
using namespace std;

class temp
{
public :
int i;
//temp(){i=20;}
/*temp(temp& X){ 
X.i = 500;
cout << "in const" << endl;}
temp(temp& X){ 
i = X.i;
cout << "in non-const" << endl;} */

};

int main()
{
temp A;
cout << "A.i=" << A.i << endl;
A.i=100;
temp B=A;
cout << "B.i=" << B.i << endl;
i/*const temp C;
cout << "C.i=" << C.i<< endl;
B=C;
cout << "B.i=" << B.i << endl;
*/
return 0;
}
