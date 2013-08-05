/******************************************************************************
keywords                :       gdb, linked list

File Name               :       gdb_sample_list_1_0.c

Date of Creation        :       21/01/2008

Owner                   :       Sibu Cyriac

Date of Modification    :

Reason for modification :

Modifier                :

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define merror() {printf("memeory allocation error\n");exit(0);}

struct NODE_STRUCT 
{
  int value;
  struct NODE_STRUCT * next;
}; 

typedef struct NODE_STRUCT NODE;

NODE* MakeNode(int);
void Insert(NODE**,int);
void Insert1(NODE*,int);
NODE* Find(NODE*,int);
void Delete(NODE**,NODE*);
void DeleteList(NODE**);
void Display(NODE*);

NODE* MakeNode(int value) 
{
  NODE* t;
  t = (NODE*) malloc(sizeof(NODE));
  if (t==0) 
    merror();
  t->next=NULL;
  t->value=value;
  return t;
}

void Insert(NODE** listAddr,int value) 
{
  if (*listAddr==NULL)
    (*listAddr)=MakeNode(value);
  else
    Insert1(*listAddr,value);
}

void Insert1(NODE* list,int value) 
{
  NODE* curr;
  for(curr=list; curr->next!=NULL; curr=curr->next);
  curr->next=MakeNode(value);
}

NODE* Find(NODE* list,int value) 
{
  NODE* curr;
  for(curr=list; curr!=NULL; curr=curr->next)
    if (curr->value==value)
      return curr;
  return NULL;
}

void Delete(NODE** listAddr,NODE* t) 
{
  NODE *prev, *curr;
  prev=*listAddr;
  curr=prev->next;
  if (curr==t) {  // delet 1st node
    *listAddr=curr->next;
    free((void*)t);
    return;
  }
  // must delete middle node
  prev=curr;
  curr=curr->next;
  for(  ; curr!=NULL; prev=curr,curr=curr->next)
    if (curr==t) {
      prev->next=curr->next;
      free((void*)t);
      return;
    }
  return;
}

void DeleteList(NODE** listAddr) {
  NODE *curr, *next;
  if (*listAddr==0) return;
  for(curr=*listAddr; curr!=NULL; curr=next) {
    next=curr->next;
    free((void*)curr);
  }
  *listAddr=NULL;
}
    
void Display(NODE* t) 
{
  if (t==NULL) 
  {
    printf("list empty\n");
    return;
  }
  printf("List at address %u:\n",(unsigned long)t);
  for( ; t!=NULL; t=t->next)
    printf("    NODE (&=%u,value=%d)\n",(unsigned long) t,t->value);
}

int main()
{
  NODE* list1=NULL;
  NODE* list2=NULL;
  NODE* t;

  Insert(&list1,2);
  Insert(&list2,2);
  Insert(&list1,3);
  Insert(&list2,3);
  Insert(&list1,4);
  Insert(&list2,4);

  Display(list1);
  Display(list2);

  DeleteList(&list1);
  if(t=Find(list2,2)) 
     Delete(&list2,t);
  
  Display(list1);
  Display(list2);

  if (t=Find(list2,7)) 
     Delete(&list2,t);

  Display(list2);

  return;
}



