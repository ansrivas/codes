#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "list.h"

void delete(List * pList, KeyType lkey, int * lposn)
{
	int         position = 1;
	pListNode   pTemp;
	if (NULL == pList)
	{
		*lposn = 0;
		return;
	}
	pTemp = pList->pHead;
	while (NULL != pTemp)
	{
		if (lkey == pTemp->key)	
			break;
		position++;
		pTemp = pTemp->next;
	}
	if (NULL == pTemp)
	{
		*lposn = 0;
		return;
	}
	if (1 == position)
	{
		pList->pHead = pTemp->next;
	}
	else
	{
		pTemp->prev->next = pTemp->next;
		pTemp->next->prev = pTemp->prev;
	}
	free(pTemp->pObject);
	free(pTemp);
	freekey(lkey);
	*lposn = position;
	return;
}

ReturnType allocatekey(KeyType * pKey)
{
	return(allocateid((uIdType*)pKey));
}

ReturnType freekey(KeyType key)
{
	return(freeid((uIdType)key));
}

ReturnType insert(List * pList, pListObject lpObject, int * lposn, KeyType* pKId)
{
	pListNode	lpNode;
	/*
	If the key is not already allocated, allocate it
	*/
	if (*pKId < 0)
	{
		if (FAILURE == allocatekey(pKId))
		{
			return FAILURE;
		}
	}
	lpNode = (pListNode)malloc(sizeof(ListNode));
	if (NULL == lpNode)
	{
		//return of freekey function should be checked here
		freekey(*pKId);
		return FAILURE;
	}
	lpNode->pObject = lpObject;
	lpNode->key = *pKId;
	*lposn = pList->pInsert(&pList->pHead, lpNode);
	return SUCCESS;
}

ReturnType inititerator(pListNode pNode, IteratorType *pIter)
{
	return SUCCESS;
}

ReturnType getnext(IteratorType lIter, pListObject *pObject)
{
	return SUCCESS;
}
