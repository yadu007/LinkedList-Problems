#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NODE_MAIN{
int data;
struct NODE_MAIN* next;
}Node;

void Add(Node** headRef, int newData,int check);
Node* SuffleMerge(Node** headref,Node** headref1);

int Count(Node* head, int searchFor);
Node* BuildOneTwoThree();
Node* head = NULL; 
Node* head1=NULL;

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
  
 
  Node* shuffle;
shuffle=SuffleMerge(&head,&head1);
for(current =shuffle;current != NULL; current = current->next)
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
      else{

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



Node* SuffleMerge(Node** a,Node** b)
{
   
  Node dummy;
  Node* tail = &dummy;
  dummy.next = NULL;
  while (1) 
  {
   if (a==NULL) 
   {
  tail->next = head1;
  break;
   }
  else if (head1==NULL)
   {
  tail->next = head;
  break;  
   }
  else {
  tail->next = head;
  tail = head;
  head = head->next;
  tail->next = head1;
  tail = head1;
  head1 = head1->next;
      }
  }
  return(dummy.next);
}