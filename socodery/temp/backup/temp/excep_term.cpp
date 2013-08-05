#include <iostream>
#include <exception>

using namespace std;

// code picked from : http://msdn.microsoft.com/en-us/library/ycf93beb(VS.71).aspx
// http://publib.boulder.ibm.com/infocenter/lnxpcomp/v8v101/index.jsp?topic=/com.ibm.xlcpp8l.doc/language/ref/cplr164.htm
// http://web.mit.edu/sunsoft_v5.1/www/c-plusplus/c%2B%2B_ug/Exception_Handling.doc.html


void termfunction( ) 
{
   cout << "I'll be back." << endl;
  throw 1; 
   //abort( );
}

int main( ) throw (bad_alloc)
{
   terminate_handler oldHand = set_terminate(termfunction);
    try {
    try {
   // Throwing an unhandled exception would also terminate the program
   //throw bad_alloc( );
     throw 1;
    }
    catch (bad_alloc){

   cout << "in catch" << endl;
   //throw;

   }
   cout << "outside inner catch" << endl;
}
catch(...)
{

   cout << "in catch - 2" << endl;
}
   // The program could also be explicitely terminated with:
   cout << "outside catch" << endl;
    terminate( );
  return 0;
}

