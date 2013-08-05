# include <iostream>
using namespace std;

void f()
        {
                throw -37;
        }

        int main()
        {
                try {
                        f();
                }
                catch (char* s) {
                }
cout << "before return\n";
                return 0;
        }


