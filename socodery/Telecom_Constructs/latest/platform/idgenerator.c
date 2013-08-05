/*
ID Generator Module : source code file
*/

#include <stdio.h>
#include "prototype.h"
#include "idgenerator.h"

#define ID_LIST_SIZE		1024

const	uIdType		idFree = 0;
const	uIdType		idBusy = 1;

/*
This is not a good way to initalize it as the type is uIdType.
It will be better if it is done through a function
*/
uIdType idList[ID_LIST_SIZE] = {(uIdType)0};

/*
This will not be used right now but maye be later when we size of the list from the user

unsigned int idListSize = ID_LIST_SIZE;
*/


ReturnType allocateid(uIdType * pUid)
{
	int index = 0;
	while(index < ID_LIST_SIZE)
	{
		if (idFree == idList[index])
		{
			idList[index] = idBusy;
			*pUid = (uIdType)index;
			break;
		}
		index++;
	}
	if (index == ID_LIST_SIZE)
		return FAILURE;
	return SUCCESS;
}


ReturnType freeid(uIdType id)
{
	if ((id >= ID_LIST_SIZE) || (id < 0))
		return FAILURE;
	idList[id] = idFree;
	return SUCCESS;
}
