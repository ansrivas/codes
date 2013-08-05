#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ( ) 
{
     vector<int> numbers;
     int number;
     while (cin >> number) 
    {
               if (find (numbers.begin ( ), numbers.end ( ), number) != numbers.end ( )) 
		        cout << "Duplicate" << endl;
	       else numbers.push_back(number);
     }
     cout << "number of unique values: " << numbers.size( );
return 0;
}
