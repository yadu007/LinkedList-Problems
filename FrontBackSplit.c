#include<stdio.h>
#include<stdlib.h>

typedef struct NODE_MAIN{
int data;
struct NODE_MAIN* next;
}Node;

void Add(Node** headRef, int newData);
int Count();
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
  int count=Count();
  if(count%2==0){
     int position=(count/2);
	 
	 Node *head1 = (Node*)malloc(sizeof(Node));
	  //Node* make=head;
    Node *cur =head;
    Node* tem;
	 for(int i=2;i<=position;i++){
    cur=cur->next;		
		if(i==position){    
		head1=cur->next;
		cur->next=NULL;
		}
	 }
	}
  else{
	  int position=(count/2)+1;
	   Node* head1 = (Node*)malloc(sizeof(Node));
	   Node* make=head;
	    for(int i=1;i<position;i++){
        make=make->next;
		
		if(i==position){
			head1=make->next;
			make->next=NULL;
      make=head;
		}
	 }
	  

  }

  
  }

Node* BuildOneTwoThree(){
  int i;
  for(i=1;i<5;i++)
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

int Count(){
  Node* current;
  int count=0;
  int k=0;
  current=head;
  while(current->next!=NULL){
	  count++;
	  current=current->next;

	  }
	  return(count+1);

 }