#include<iostream>
using namespace std;

int main()
{
	int x = 10;
	int &ref = x;
	
	++ref;

	cout<<x<<"\t"<<ref<<endl;
	
	int y = 20;
	ref = y;

	++ref;

	cout<<y<<"\t"<<ref<<endl;
	
	int z = 30;
	ref = z;

	++ref;

	cout<<z<<"\t"<<ref<<endl;	

	cout<<x<<"\t"<<y<<"\t"<<z<<endl;
}

