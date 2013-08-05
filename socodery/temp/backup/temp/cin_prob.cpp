#include <iostream>
using namespace std;

int main()
{
string bookStr;
/*
cout << "book name char*" << endl;
//cin >> bookStr;
//cin.getline(bookStr, 20);
cout << bookStr << endl;
*/
char book[20];
char book1[20];
/*cout << "book name char*" << endl;
cin.get(book, 20);
cout << book << endl;*/
cout << "book name char*" << endl;
cin.getline(book1, 20);
cout << book1 << endl;

return 0;
}
