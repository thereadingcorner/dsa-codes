#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node* create_list(node*,int);
node* insert_at_end(node*);
void display(node*);

void main()
{
	node *first=NULL;
	int n;
	
	printf(" Enter the number of elements you want to insert in the list: ");
	scanf("%d",&n);
	
	first=create_list(first,n);
	insert_at_end(first);
	printf("\n");
	display(first);
	
}

node* create_list(node* first,int n)
{
	node *curr,*p;
	int i;
	for(i=0;i<n;i++)
	{
		curr=(node*)malloc(sizeof(node));
		if(curr==NULL)
		{
			printf("Memory allocation failed");
			exit(0);
		}
		printf(" Enter number: ");
		scanf("%d",&curr->info);
		
		if(first==NULL)
			first=curr;
		else
			p->next=curr;
		
		p=curr;
	}
	p->next=NULL;
	return first;
}

node* insert_at_end(node* first)
{
	node *curr,*p;
	curr=(node*)malloc(sizeof(node));
	curr->next=NULL;
	
	printf("Enter number you want to insert");
	scanf("%d",&curr->info);
	
	for(p=first;p->next!=NULL;p=p->next);
	
	p->next=curr;
	printf("Node inserted successfully");
	return first;	
}

void display(node* first)
{
	if(first==NULL)
		printf("List is Empty");
	else
	{
		node *p;
		for(p=first;p->next!=NULL;p=p->next)
			printf("%d->",p->info);
		printf("%d",p->info);
	}
}
