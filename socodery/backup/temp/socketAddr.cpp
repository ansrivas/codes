#include <iostream>
//#include </usr/include/sys/socket.h>
#include <netinet/in.h>

using namespace std;

int main()
{
short short_val;
//unsigned short ushort_val;
struct sockaddr_in addr;
int size = sizeof(addr);
//cout << "size = " << size << endl;
cout << "size = " << sizeof(size) << endl;
cout << "size of short = " << sizeof(short_val) << endl;
//cout << "size of short = " << sizeof(ushort_val) << endl;

return 0;
}
