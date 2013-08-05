// LargestAreaInHistogram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <limits.h>
#include <iostream>
#include<stack>
#include<stdio.h>
#include<conio.h>
using namespace std;

int iFindMinIndex(int *iArr, int iStart, int iEnd)
{
	if(iEnd < iStart)
		return -1;
	int iMin = INT_MAX;
	int i = 0 , iMinIndex = -1;
	for(i = iStart; i <= iEnd; i++){
		if( iArr[i] < iMin)
		{
				iMin = iArr[i];
				iMinIndex = i ;
		}
	}
	return iMinIndex;
}

void iFindArrHistogram(int *iArr, int iStart, int iEnd, int *iMaxArea)
{
	if(iEnd <= iStart)
		return ;

	int iMinInd = iFindMinIndex(iArr, iStart, iEnd);
	if(-1 == iMinInd)
		return ;
	int iTempArea = iArr[iMinInd]*(iEnd - iStart +1);
	if(*iMaxArea < iTempArea)
		*iMaxArea = iTempArea;
	iFindArrHistogram(iArr, iStart, iMinInd -1 ,iMaxArea);
	iFindArrHistogram(iArr, iMinInd +1, iEnd,iMaxArea);
	
}

int main(){
   
	int hist[] =  {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
	int x = 0 ; 
	iFindArrHistogram(hist,0,n-1,&x);
	printf("%d",x);
    getchar();
    return 0;
}

