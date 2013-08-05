#include <stdio.h>


int iFnFindSetBit(int n){

if((n&(n-1))){
	return -1;
	}
unsigned int i = 1,
	     count = 0 ; 
int temp = 0 ;
while(!temp){
	temp = n & i;
	i = i << 1;
	count++;
}	
return count;
}

int main(int argc, char *argv){

printf("%d",iFnFindSetBit(4));
return 0;
}
