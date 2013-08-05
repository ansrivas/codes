#include<iostream>
using namespace std;

/*inline int add(int x,int y)
{
        cout << " int add\n";
	return x + y;
}*/
inline double add(float x,float y)
{
        cout << " float add\n";
	return x + y;
}

/*inline double add(int x,double y)
{
        cout << " int double add\n";
	return x + y;
}*/
inline double add(double x,double y)
{
        cout << " double add\n";
	return x + y;
}

inline char* add(char* x,char* y)
{
	char *temp = (char*) malloc(strlen(x) + strlen(y) + 1);
	strcpy(temp,x);
	strcat(temp,y);

	return temp;
}

int main()
{
cout << "size of op" << sizeof(56.7) << endl;
cout << "size of op" << sizeof(56.0) << endl;

	cout<<add(100,200)<<endl;	

	cout<<add("Hello"," World!")<<endl;	

	cout<<add(34.45,56.7)<<endl;
	cout<<add(34,56.7)<<endl;
	cout<<add(34.09809898,56.7000)<<endl;
        float x=100;
        float z=200;
	cout<<add(x,z)<<endl;
return 0;
}
