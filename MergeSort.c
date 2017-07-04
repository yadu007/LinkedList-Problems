#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
          Node** frontRef, Node** backRef);
 

void MergeSort(Node** headRef)
{
  Node* head = *headRef;
  Node* a;
  Node* b;

  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }
 
 FrontBackSplit(head, &a, &b); 

  MergeSort(&a);
  MergeSort(&b);
 
  *headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b)
{
  Node* result = NULL;
 
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);

  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

void FrontBackSplit(Node* source,
          Node** frontRef, Node** backRef)
{
  Node* fast;
  Node* slow;
  if (source==NULL || source->next==NULL)
  {

    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
 
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
 

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

void printList(Node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}
 
void push(Node** head_ref, int new_data)
{
  
  Node* new_node =
            (Node*) malloc(sizeof(Node));
  
 
  new_node->data  = new_data;
  
  new_node->next = (*head_ref);    
  
 
  (*head_ref)    = new_node;
} 
  
int main()
{
  
  Node* res = NULL;
  Node* a = NULL;

  push(&a, 15);
  push(&a, 10);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2); 

  MergeSort(&a);
  
  printf("\n Sorted\n");
  printList(a);           
  
  getchar();
  return 0;
}