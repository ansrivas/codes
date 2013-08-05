#include <iostream>
using namespace std;

void calc(int a, int b=0)
{
cout<< "def assign" << endl;
}

void calc(int a)
{
cout << "only one param" << endl;
}

int main()
{
calc(10);
return 0;
}
