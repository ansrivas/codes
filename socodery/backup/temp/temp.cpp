#include <iostream>
using namespace std;

int main()
{
int count;

cout << " no of array members = \n";
cin  >> count ;
cout << endl;

//int *array = new int [count];
char *array = new char [count];

for (int i=0; i< count; i++)
{
cin >> array[i] ;
cout << endl;
}

for (int i=0; i< count; i++)
{
cout << array[i] << "\n";
}

return 0;
}
