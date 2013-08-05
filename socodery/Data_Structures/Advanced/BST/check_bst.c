#include<stdio.h>

#define MAX 20

struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
};

typedef struct tree *node;
node root;

int checkValue;
int checkStatus;


int checkLeft(node base)
{
  if (base->data > checkValue)
    return 0;
  else
  {
    if (base->left && base->right)
      return (checkLeft(base->left) && checkLeft(base->right));
    else if (base->left)
      return checkLeft(base->left);
    else if (base->right)
      return checkLeft(base->right);
  }
  return 1;
}

int checkRight(node base)
{
  if (base->data < checkValue)
    return 0;
  else
  {
    if (base->left && base->right)
      return (checkRight(base->left) && checkRight(base->right));
    else if (base->left)
      return checkRight(base->left);
    else if (base->right)
      return checkRight(base->right);
  }
  return 1;
}

void checkNode(node testNode)
{
  if (!testNode)
    return;
//  checkValue = testNode->data;
  if (testNode->left)
  {
    if (checkLeft(testNode->left) == 0)
      checkStatus = 0;
  }
  if (testNode->right)
  {
    if (checkRight(testNode->right) == 0)
      checkStatus = 0;
  }
  checkNode(testNode->left);
  checkNode(testNode->right); 
}

void travTree(node travNode)
{
  if (!travNode)
    return;
  travTree(travNode->left);
  printf(" %d",travNode->data);
  travTree(travNode->right);
}

void insertData(int value)
{
  node insertNode = (node)malloc(sizeof(struct tree));
  insertNode->data = value;
  insertNode->left = insertNode->right = NULL;
  if (!root)
    root = insertNode;
  else
  {
    node nextNode;
    node queue[MAX];
    int front = 0;
    int rear = -1;
    queue[++rear] = root;
    while (1)
    {
      nextNode = queue[front++];
      if (nextNode->left == NULL)
      {
        nextNode->left = insertNode;
        break;
      }
      else
        queue[++rear] = nextNode->left;
      if (nextNode->right == NULL)
      {
        nextNode->right = insertNode;
        break;
      }
      else
        queue[++rear] = nextNode->right;
    }
  }
}

int main()
{
  int value;
  root = NULL;
  checkStatus = 1;
  while (1)
  {
    printf("\nEnter next value: ");
    scanf("%d",&value);
    if (value == -1)
      break;
    insertData(value);
  }
  travTree(root);
  checkNode(root);
  if (checkStatus == 1)
    printf("\nIs a BST.\n\n");
  else
    printf("\nIs not a BST.\n\n");
}
