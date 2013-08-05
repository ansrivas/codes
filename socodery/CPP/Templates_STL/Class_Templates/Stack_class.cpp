#include <iostream>
#include "Stack_class.h"
using namespace std ;
int main()
{
	typedef Stack<float> FloatStack ;
	typedef Stack<int> IntStack ;

	FloatStack fs(5) ;
	float f = 1.1 ;
	cout << "Pushing elements onto float stack" << endl ;
	while (fs.push(f))
	{
		cout << f << ' ' ;
		f += 1.1 ;
	}
	cout << endl << "Stack Full." << endl
	<< endl << "Popping elements from float stack" << endl ;
	while (fs.pop(f))
		cout << f << ' ' ;
	cout << endl << "Stack Empty" << endl ;
	cout << endl ;

	IntStack is ;
	int i = 11 ;
	cout << "Pushing elements onto int stack" << endl ;
	while (is.push(i))
	{
		cout << i << ' ' ;
		i += 1 ;
	}
	cout << endl << "Stack Full" << endl
	<< endl << "Popping elements from int stack" << endl ;
	while (is.pop(i))
			cout << i << ' ' ;
	cout << endl << "Stack Empty" << endl ;
	return 0;
}

