#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct Node
{
    int data;
    struct Node* next;
};
 

void MoveNode(struct Node** destRef, struct Node** sourceRef) ;
 
void AlternatingSplit(struct Node* source, struct Node** aRef, 
                            struct Node** bRef) 
{

  struct Node* a = NULL; 
  struct Node* b = NULL;
   
  struct Node* current = source;
  while (current != NULL) 
  {
    MoveNode(&a, &current); 
    if (current != NULL) 
    {
       MoveNode(&b, &current); 
    }
  }
  *aRef = a;
  *bRef = b;
}

void MoveNode(struct Node** destRef, struct Node** sourceRef) 
{
  
  struct Node* newNode = *sourceRef; 
  assert(newNode != NULL);
   
  
  *sourceRef = newNode->next;
   
  
  newNode->next = *destRef; 
   
  *destRef = newNode; 
}
 

void push(struct node** head_ref, int new_data)
{
  
  struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
  new_node->data  = new_data;

  new_node->next = (*head_ref);     
 
  
  (*head_ref)    = new_node;
}
 

void printList(struct Node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
} 
 

int main()
{
 
  struct Node* head = NULL;
  struct Node* a = NULL;
  struct Node* b = NULL;  

  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);                                    
  push(&head, 0);  
 
  printf("\n List:  ");
  printList(head); 
 
  
  AlternatingSplit(head, &a, &b); 
 
  printf("\n Result 'a' ");
  printList(a);            
 
  printf("\n Result'b' ");
  printList(b);            
 

}