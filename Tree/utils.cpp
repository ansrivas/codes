

#include "stdafx.h"
#include "utils.h"


int CUtils::iFnMax(int iInputA, int iInputB)
{
	return (iInputA > iInputB)?iInputA:iInputB ;

}

int CUtils::iFnAbs(int iInput)
{
	if(iInput < 0 )
		return  -iInput ;

	return iInput ;


}

int CUtils::iFnMin(int iInputA, int iInputB)
{
	return (iInputA < iInputB) ? iInputA: iInputB ;
}