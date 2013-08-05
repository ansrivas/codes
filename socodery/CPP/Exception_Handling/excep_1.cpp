#include<iostream>
using namespace std;

int main()
{
cout << "start";
try
{
cout << "\ntry";
throw 1;
cout << "\nnot executed";
}
catch(char a)
{
cout << "\n caught int" << a;
}

catch(...)
{
cout << "\ncaught";
}
cout << "end";

return 0;
}

