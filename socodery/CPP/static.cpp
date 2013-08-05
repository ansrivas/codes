#include<iostream>

using namespace std;

class temp
{
public:
int x;
static int y;
static void display()
{
cout << "in display"<< endl;
}
};

int temp::y = 200 ;

int main()
{
cout << "y =" << temp::y << "\n";
temp A;
A.display();
temp::display();
return 0;
}
