#include<iostream>
using namespace std;

template <typename T>
class Myclass
{
    T a,b;
    public :
	     Myclass(T x, T y)
	     {
		a=x;
		b=y;
	     }
	     T getmax()
	     {
		T temp;
		temp = ((a>b)?a:b) ;
	        return temp;
	     }
};
int main()
{
    Myclass <int> O1(10,20);
    cout << O1.getmax() ;
    return 0;
}

