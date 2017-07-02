#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NODE_MAIN{
int data;
struct NODE_MAIN* next;
}Node;

void Add(Node** headRef, int newData);
void InsertSort(Node** headRef);
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
  printf("after sorting\n");
  InsertSort(&head);
  
for(current =head;current != NULL; current = current->next)
    {   
     printf("%d%s",current->data," ");
    }
  }

Node* BuildOneTwoThree(){
  int i;
  for(i=10;i>3;i--)
    {
      if(i%2==0){
       Add(&head,i);}
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
void InsertSort(Node** headRef)
{
/////
Node *new1, *count;
new1 = *headRef;
	for( ; new1->next != NULL; new1 = new1->next)
	{
		for(count = new1->next; count != NULL; count = count->next)
		{
			if(new1->data > count->data)
			{
				int temp = new1->data;
				new1->data = count->data;
				count->data = temp;
			}
		}
	}
	//nw = first->next;
    while (head)
	{
		printf("%d\t", head->data);
		head = head->next;
	}
/////
}
