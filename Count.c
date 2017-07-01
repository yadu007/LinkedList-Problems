#include<stdio.h>
#include<stdlib.h>

typedef struct NODE_MAIN{
int data;
struct NODE_MAIN* next;
}Node;

void Add(Node** headRef, int newData);
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
  int count = Count(List,2);
  printf("%d is %d time/s present in list\n",2,count);
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

int Count(Node* head,int num){
  Node* current;
  int count=0;
  int k=0;
  
  for(current=head;current->next != NULL;current= current->next){ 
    if(current->data == num)
      count++;
      }
  return(count);
 }
