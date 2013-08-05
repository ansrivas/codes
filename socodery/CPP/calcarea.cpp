#include <iostream>
using namespace std;

#define calcarea(x) (x*x)

inline int calculateArea(int x)
{
return (x*x);
}

int main()
{
int res = calculateArea(2+3);
cout <<"area = " << res << endl;
res = calcarea(2+3);
cout <<"area = " << res << endl;
return 0;
}

