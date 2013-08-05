#include <iostream>
#include <cstdlib>

/* 
int atoi( const char *str );

The atoi() function converts str into an integer, and returns that integer. str should start with whitespace or some sort of number, and atoi() will stop reading from str as soon as a non-numerical character has been read. For example:

 int i;  i = atoi( "512" );  i = atoi( "512.035" );  i = atoi( "   512.035" );  i = atoi( "   512+34" );  i = atoi( "   512 bottles of beer on the wall" );
All five of the above assignments to the variable i would result in it being set to 512.

If the conversion cannot be performed, then atoi() will return zero:
*/

using namespace std;

class myclass {
  int a;
public:
  myclass(int x) { 
     a = x; 
  } 
  myclass(char *str) { 
     a = atoi(str); 
  }
  int geta() { 
     return a; 
  }
};
 
int main()
{
//myclass D;

  myclass object1 = 4;     
  myclass object2 = "123"; 
  myclass object3 = "a"; 

  cout << "object1: " << object1.geta() << endl;
  cout << "object2: " << object2.geta() << endl;
  cout << "object3: " << object3.geta() << endl;

  return 0;
}

