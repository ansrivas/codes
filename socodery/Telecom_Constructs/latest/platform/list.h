#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <pthread.h>
#include "prototype.h"
#include "idgenerator.h"

typedef uIdType KeyType;
typedef void * pListObject;

typedef struct ListNode
{
	KeyType		key;
	pListObject 	pObject;
	struct ListNode *next;
	struct ListNode *prev;
}ListNode, *pListNode;

typedef int (*pListInsertFunc)(pListNode *, pListNode);
typedef int (*pListDeleteFunc)(pListObject);

typedef struct List
{
	pListNode	pHead;
	pListInsertFunc	pInsert;
	pListDeleteFunc	pDelete;
}List;

extern void delete(List *, KeyType, int *);

extern ReturnType insert(List *, pListObject, int *, KeyType *);

extern ReturnType allocatekey(KeyType * pKey);

extern ReturnType freekey(KeyType key);

typedef pListNode IteratorType;

extern ReturnType inititerator(pListNode, IteratorType *);

extern ReturnType getnext(IteratorType, pListObject *);

#endif
