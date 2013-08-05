//Structure Padding

#include <iostream>

using namespace std;

struct padding{
  char c; //if int size is 4 bits now, this char is placed in one bit, now to optimize the next set of bits is stored
          // in next set of memory location, to avoid multiple passes in fetching the integer.
  int i ;
  char d;     
       
};

int main(){
struct padding pad ;

printf("%d" ,sizeof(struct padding));
int i;
scanf ("%d",&i);
return 0;   
    
}
