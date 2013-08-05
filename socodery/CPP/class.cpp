#include <iostream>
using namespace std;

class temp
{
public :
int x;
/*
void setVal_ref(temp &i)
{
i.x=100;
cout << "in pass by ref - i.x =" << i.x << endl;
}
void setVal(temp i)
{
i.x = 200;
cout << "ipass by val - i.x =" << i.x << endl;
}*/
};

int main()
{

temp A , B;
A.x = 100;
B.x =2100;
temp &c = A;
     c = B;
cout << c.x  << endl;
/*
B.x = 10;
A.setVal_ref(B);

cout << "in main - B.x = " << endl;
B.x = 50;
A.setVal(B);
cout << "in main - B.x = " << B.x << endl; 
*/
//return 0;
}
