#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
void set (int & val); 
void display (int val); 
int main( ) {
   vector<int> A(5);
   for_each (A.begin ( ), A.end ( ), set);  // would not work if vector<int> A; used
   for_each (A.begin ( ), A.end ( ), display);
   cout << endl;
   sort (A.begin ( ), A.end ( ));      // operator< must be defined for A's element type
   for_each (A.begin ( ), A.end ( ), display);
   cout << endl;
   return 0;
}
void set (int & val) {
   val = rand ( );
}
void display (int val) {
   cout << "  " << val;
}


