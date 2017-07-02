#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NODE_MAIN{
int data;
struct NODE_MAIN* next;
}Node;

void Add(Node** headRef, int newData);
int RemoveDuplicates(Node** headRef);
int Pop(Node** headref);

int Count(Node* head, int searchFor);
Node* BuildOneTwoThree();
Node* head = NULL; 

int main(){
  Node* List = BuildOneTwoThree();
  printf("List: ");
  Node *current;
  printf("[ ");

  for(current =head;current != NULL; current = current->next)
    {   
     printf("%d%s",current->data," ");
    }

  printf("]");
  printf("\n");
  //int count = Count(List,2);
  RemoveDuplicates(&head);
  printf("after inserting 5 to the position 1 \n");
  
for(current =head;current != NULL; current = current->next)
    {   
     printf("%d%s",current->data," ");
    }
  }

Node* BuildOneTwoThree(){
  int i;
  for(i=1;i<4;i++)
    {
       Add(&head,i);
    }
  return(head);
}

void Add(Node** headRef, int newData){
  Node *newNode;
  Node *current= *headRef;
  newNode = (Node*)malloc(sizeof(Node));

  if(newNode == NULL)
    { 
      printf("cant allocate\n");
      exit(0);
    }

  newNode->data = newData;
  newNode->next = NULL;

  if(head == NULL)
    { 
      head = newNode;
    }
  else
    {
      while(current->next != NULL)
     {
  current = current->next;
     }
     current->next = newNode;
    // current->next->data=newData;
     //current->next->next=NULL;
      }
}
int RemoveDuplicates(Node** headRef)
{
    Node* current = headRef;
 
    Node* next_next; 
   
    if (current == NULL) 
       return; 
 
    while (current->next != NULL) 
    {
       
       if (current->data == current->next->data) 
       {
                
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else 
       {
          current = current->next; 
       }
    }
 }