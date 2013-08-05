#include <iostream>
using namespace std;

class temp
{
protected :
int i;
public :
int j;
 temp(){ };
 temp(int){ };
 temp(temp &x) { i=x.i; }
 ~temp(){ cout<<"in dest"<< endl; }
};

class temp2 : public temp
{
public :
void display(){ i=200; }
};

int main()
{
temp A;
A.j = 400;
temp2 B;
B.j = 500;
//B.i = 5;

/*temp A(10);
A.i = 200;
temp B(A);
cout << "B.i" << B.i << endl;
{
temp C(30);
C=A;
cout << "C.i" << C.i << endl;
}
cout << "before return"<< endl;*/
return 0;
}
