#include <iostream>
using namespace std;

class temp
{
public :

	void operator++()
	{
           cout << "in overloaded prefix ++ op\n";

	}
	void operator++(int)
	{
           cout << "in overloaded postfix ++ op\n";

	}

};

int main()
{
temp T;
T++;
//T++(10);
T.operator++(0);
++T;
return 0;
}
