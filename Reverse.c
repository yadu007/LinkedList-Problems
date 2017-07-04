#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
   struct Node* next;
}Node;
 
void push(Node** head_ref, int new_data);
Node* Reverse(Node** headRef);

Node* Reverse(Node** headRef) {
Node* result = NULL;
Node* current = *headRef;
Node* next;
while (current != NULL) {
next = current->next;
current->next = result;
result = current;

current = next;
}
*headRef = result;
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

  reverse = Reverse(&a);
  
  printf("\n Reversed Linkedlist \n");
  printList(reverse);           

}
