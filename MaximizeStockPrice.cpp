// MaximizeStockPrice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <limits.h>
#include <malloc.h>

int iFnReturnMaxBuySell(int *iArr, int iLen, int *iStart, int *iEnd){

	int iCurrentStock = 0,
		iMaxStockPrice = INT_MIN , 
		iMinSofar = iArr[0];
	
		*iStart = 0 ;
	for(int i = 1 ; i < iLen ;i++){

		if(iArr[i-1] < iMinSofar){
			iMinSofar = iArr[i-1];
			*iStart = i-1 ; 
		}


		iCurrentStock = iArr[i] - iMinSofar;

		if(iCurrentStock > iMaxStockPrice){
			iMaxStockPrice = iCurrentStock;
			*iEnd = i ; 
		}
	}

return iMaxStockPrice;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int iArr[] = {100, 180, 260, 310, 40, 535, 695};
	int iLen = sizeof(iArr)/sizeof(iArr[0]);
	int iStart = 0 , 
		iEnd = 0 ; 
	int iMaxStock = iFnReturnMaxBuySell(iArr,iLen, &iStart,&iEnd);
	printf("Max stock = %d, startIndex = %d, endIndex = %d",iMaxStock,iStart,iEnd);
	return 0;
}

