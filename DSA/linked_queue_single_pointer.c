//Queue using linkedlist

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int info;
	struct Node *next;
}node;

node* enqueue(node*,node*,int);
node* dequeue(node*,node*);
void peek(node*);
void display(node*);
void isempty(node*);

void main()
{
	node *front=NULL,*rear=NULL;
	int val,item,n;
	int option;
	
	do
	{	
		printf("\n~~~~~~ MAIN MENU ~~~~~~");
		printf("\n 1.Insert");
		printf("\n 2.Delete");
		printf("\n 3.Peek");
		printf("\n 4.Display");
		printf("\n 5.IsEmpty");
		printf("\n 6.Exit");
		printf("\n Enter your choice:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				printf("\n Enter the value to be inserted");
				scanf("%d",&item);
				front=enqueue(front,rear,item);
				break;
			case 2:
				front=dequeue(front,rear);
				break;
			case 3:
				peek(front);
				break;
			case 4:
				display(front);
			case 5:
				isempty(front);
				break;
		}
	}while(option!=6);
}

node* enqueue(node *front,node *rear,int item)
{
	node *curr;
	curr=(node*)malloc(sizeof(node));
	if(curr==NULL)	
		printf("Memory Allocation failed");
	else
	{
	curr->info=item;
	curr->next=NULL;
	}

	if(front==NULL)
	{
		front=curr;
		rear=curr;
	}
	else
	{
		rear->next=curr;
		rear=curr;
	}
	
	return front;
}

node* dequeue(node *f,node *r)
{
	node *p;
	p=f;
	
	if(f==NULL)
		printf("Queue is Empty");
	else if(f==r)
	{
		free(p);
		f=r=NULL;
	}
	else
	{
		f=f->next;
		free(p);
	}
}

void peek(node *f)
{
	int val;
	val=f->info;
	printf("\n The value is:%d",val);
}

void display(node *f)
{
	node *p;
	p=f;
	if(f==NULL)
		printf("Queue is Empty");
	else
	{
		for(p=f;p->next!=NULL;p=p->next)
			printf("%d->",p->info);
		printf("%d",p->info);
	}
}

void isempty(node *f)
{
	if(f==NULL)
		printf("Queue is Empty");
}
