#include <iostream>
using namespace std;

int divide_func()
{
    int num, den;
    cin >> num >> den;

    if(den == 0)
        throw int();  // throw exception

    int res = num/den;
    cout << "division result = " << res << endl;
    return res;
}
int main()
{
    try
    {
        try
        {
            divide_func();
        }
        catch (int int_excep) // catch for the int exception that could be thrown
        {
            cout << "caught divide_by_zero exception : inner block" << endl;
           throw;                   // rethrows the same exception !!!
        }
     }
    catch (int int_excep) // catch for the int exception that could be thrown
    {
        cout << "caught divide_by_zero exception: outer block" << endl;
    }
    return 0;
}

