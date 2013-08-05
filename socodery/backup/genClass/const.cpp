#include <iostream>
using namespace std;

class gen
{
mutable int a;
const int b;

public:
void display() const;

void read() const
{
a=100;
display();
//write();
}

void write()
{
//b=100;
display();
//a=20;
}

};

int main()
{

return 0;
}
