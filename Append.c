#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct NODE_MAIN{
int data;
struct NODE_MAIN* next;
}Node;

void Add(Node** headRef, int newData,int a);
void Append(Node** headRef,Node** headRef1);
int Pop(Node** headref);

int Count(Node* head, int searchFor);
Node* BuildOneTwoThree();
Node* head = NULL; 
Node* head1= NULL;

int main(){
  //Node* List = 
  BuildOneTwoThree();
  printf("List after merging: ");
  Node *current;

  Append(&head,&head1);
  
  }

Node* BuildOneTwoThree(){
  int i;
  for(i=10;i>3;i--)
    {
      if(i%2==0){
       Add(&head,i,0);
       Add(&head1,i,1);
      }
    }
    
 // return(head);
}

void Add(Node** headRef, int newData,int a){
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

  if(a==0){
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
  if(a==1){

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
void Append(Node** headRef,Node** headRef1)
{
/////
Node* current;
  int count=0;
  int k=0;
  
   Node *currentNode = head;
  while (currentNode->next !=0) {
        currentNode = currentNode->next;
        
    }
    currentNode->next=head1;
 Node *currents;
for(current =head;current != NULL; current = current->next)
    {   
     printf("%d%s",current->data," ");
    }


}
