#include <list>
#include <iostream>
using namespace std;
int main ( ) {
    list<int>L;     
    L.push_back (9);
    L.push_back (7);
    L.push_back (5);
    L.push_back (3);
    L.push_front (4);
    list<int>::iterator p; 
    for (p = L.begin ( ); p != L.end ( ); p++)  
	cout << *p << endl;
    for (p = L.begin ( ); p != L.end ( ); p++)
	(*p)++;
    for (p = L.begin ( ); p != L.end ( ); p++)
	cout << *p << endl;
    return 0;
}

