#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
   struct Node* next;
}Node;
 
void push(Node** head_ref, int new_data);
Node* RecursiveReverse(Node** headRef);

Node* RecursiveReverse(Node** headRef) {
 Node* first;
 Node* rest;
if (*headRef == NULL) return(*headRef);
first = *headRef;
rest = first->next;
if (rest == NULL) return(*headRef);
RecursiveReverse(&rest);
first->next->next = first;
first->next = NULL;
*headRef = rest;
 return(*headRef);
}
void push(Node** head_ref, int new_data)
{
    
    Node* new_node =
            (Node*) malloc(sizeof(Node)); 
    new_node->data  = new_data;
   new_node->next = (*head_ref);    
  (*head_ref)    = new_node;
}
 
void printList(Node *node)
{
  while (node != NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}

int main()
{

  Node* a = NULL;
  Node* b = NULL;
  Node *reverse = NULL;
  
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);                                   

  reverse = RecursiveReverse(&a);
  
  printf("\n Reversed Linkedlist \n");
  printList(reverse);           

}