#include <iostream>
#include <sys/socket.h>

int main()
{
struct sockaddr_in addr;
int size = sizeof(addr);
cout << "size = " << size << endl;

return 0;
}
