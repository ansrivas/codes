#include <iostream>
#include <string>
#define MULTIPLY(x) (x*2)

using namespace std;
//using namespace string;

inline int multiply(int x)
{
return (x*2);
}

int main()
{
string s1,s2,s3;
/*
s2="Razzaque Khan";
s3="Aarush Khan";

cin >> s1;
cout << s1 << endl;
cout << s2 << endl;
cout << s3 << endl;
*/
int res= MULTIPLY(2+10);
cout << "res=" << res << endl;
res=multiply(2+10);
cout << "res=" << res << endl;

int * ptr = new (nothrow) int[2];
if(ptr!=NULL)
{
;
}
//cout << *ptr << endl;

for(int i=0; i<5; i++)
{
cout << *ptr << endl;
cout << "i=" << i << endl;
ptr++; 
}
return 0;
}
