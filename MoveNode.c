#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NODE_MAIN{
int data;
struct NODE_MAIN* next;
}Node;

void Add(Node** headRef, int newData,int check);
int MoveNode(Node** headRef,Node** headRef1);
int Pop(Node** headref);

int Count(Node* head, int searchFor);
Node* BuildOneTwoThree();
Node* head = NULL; 
Node* head1 = NULL;

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
  MoveNode(&head,&head1);
 // printf("after inserting 5 to the position 1 \n");
  
for(current =head;current != NULL; current = current->next)
    {   
     printf("%d%s",current->data," ");
    }
    printf("\n");
for(current =head1;current != NULL; current = current->next)
    {   
     printf("%d%s",current->data," ");
    }

  }

Node* BuildOneTwoThree(){
  int i;
  for(i=1;i<4;i++)
    {
       Add(&head,i,1);
       Add(&head1,i,2);
       
    }
  return(head);
}

void Add(Node** headRef, int newData,int check){
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
if(check==1){
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
if(check==2){
  if(head1 == NULL)
    { 
      head1 = newNode;
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

}
int MoveNode(Node** headRef,Node** headRef1)
{   Node* next;
    Node* current = head;
    Node* current1 = head1;
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data=head1->data;
    newNode->next=head;
    head=newNode;
    
       next = current1->next;
       free(current1);
       head1 = next;
  
 }