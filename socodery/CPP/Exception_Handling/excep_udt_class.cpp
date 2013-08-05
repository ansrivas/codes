#include <iostream>
#include <stdexcept>
using namespace std;
class int_divide_by_zero : public runtime_error
{
public :
    int_divide_by_zero(const string &int_error_string):
                   runtime_error(int_error_string){ }
};

class float_divide_by_zero : public runtime_error
{
public :
    float_divide_by_zero(const string &float_error_string):
                   runtime_error(float_error_string){ }
};
int divide_int()
{
    cout << " enter 2 int values ... " << endl;
    int num, den;
    cin >> num >> den;
    if(den == 0)
        throw int_divide_by_zero("int_divide_by_zero runtime error");   // throw exception
    int res = num/den;
    cout << "division result = " << res << endl;
    return res;
}
float divide_float()
{
    cout << " enter 2 float values ... " << endl;
    float num, den;
    cin >> num >> den;
    if(den == 0)
        throw float_divide_by_zero("float_divide_by_zero runtime error"); // throw exception
    float res = num/den;
    cout << "division result = " << res << endl;
    return res;
}
int main()
{
    try
    {
        divide_int();
        divide_float();
    }
    catch (int_divide_by_zero &int_excep) // catch for int exception thrown
    {
        cout << int_excep.what() << endl;  // to print the string passed to exception object
    }
    catch (float_divide_by_zero &float_excep) // catch float exception thrown
    {
        cout << float_excep.what() << endl;   // to print the string passed to exception object
    }
    catch (...) // catch any uncaught exception
    {
        cout << "caught all uncaught exceptions" << endl;
    }
    return 0;
}

