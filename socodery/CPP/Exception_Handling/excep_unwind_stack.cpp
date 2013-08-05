#include <iostream>
using namespace std;
//using std::endl;
#include <stdexcept>
//using std::runtime_error;

// function3 throws run-time error
void function3() throw ( runtime_error )
{
	throw runtime_error( "runtime_error in function3" ); // fourth
}

// function2 invokes function3
void function2() throw ( runtime_error )
{
	function3(); // third
}
//function1 invokes function2
void function1()throw( runtime_error )
{
	function2(); // second
}

// demonstrate stack unwinding
int main()
{
// invoke function1
try {
	function1(); //first
} // end try

// handle run-time error
catch ( runtime_error &error ) // fifth
{
	cout << "Exception occurred: " << error.what() << endl;
} // end catch
return 0;
}  // end main
