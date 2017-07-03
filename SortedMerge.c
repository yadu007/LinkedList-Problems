
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;
void InsertSort(Node** headRef);
void MoveNode(Node** destRef,Node** sourceRef);
Node* SortedMerge(Node* a, Node* b)
{
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
 
        tail = tail->next;
    }
    return(dummy.next);
}

void MoveNode(Node** destRef, Node** sourceRef)
{
   
    Node* newNode = *sourceRef;
    assert(newNode != NULL);
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
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
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
int main()
{
    
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;
 
    
    push(&a, 5);
    push(&a, 10);
    push(&a, 15);
 
    push(&b, 2);
    push(&b, 3);
    push(&b, 6);

    res = SortedMerge(a, b);
 
    printf("Merged  \n");
   
    InsertSort(&res);
     printList(res);
    return 0;
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
    while (new1)
	{
		printf("%d\t", new1->data);
		new1 = new1->next;
	}
/////
}

