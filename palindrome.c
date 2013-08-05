#include<stdio.h>
#include<stdlib.h>

#define false 0
#define true 1

int bFnPalindrome(int iInput)
{
	int iOriginal = iInput,
		iTemp = 0,
		iCompare = 0;
	if(iInput < 0 )
	{
		iInput = -iInput;
	}
	
	while(iInput)
	{
		iTemp = iInput%10;
		iInput = iInput/10;
		iCompare = iTemp + iCompare*10;
	}

	if(iCompare == iOriginal){
		return true;
	}
	return false;
}


int isDigit(int iNum)
{
	//To check if number contains only one digit
	return (iNum >= 0 && iNum < 10);
}

int bFnPalRecursive(int iNum, int *iDes)
{
	if(isDigit(iNum)){
		return (iNum == (*iDes) % 10);
	}

	if(!bFnPalRecursive(iNum/10, iDes))
	{
		return false;
	}

	*iDes = *iDes/10;

	return (iNum%10 == (*iDes)%10);
}


int main(int argc, char *argv[])
{
int x = 0 ;
int tempX = 0 ;  
	while(1){
	printf("Enter the number or -1 or discontinue\n");
	scanf("%d",&x);
	tempX = x;
	if(-1 == x){
		break;
	}
	if(bFnPalRecursive(x,&tempX)){
		printf("Its a pal\n");
	}
}
return 0;
}


