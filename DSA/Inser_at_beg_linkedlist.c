#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int info;
	struct node* next;
}node;

node* create_list(node*,int);
node* insert_at_beg(node*);
void display(node*);

void main()
{
	node* first=NULL;
	int n;
	printf(" Enter the number of you want to store: ");
	scanf("%d",&n);
	
	first=create_list(first,n);
	first=insert_at_beg(first);
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
			return;
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

node* insert_at_beg(node* first)
{	
	node *curr;
	curr=(node*)malloc(sizeof(node));
	
	printf(" Enter the number to be inserted: ");
	scanf("%d",&curr->info);
	
	curr->next=first;
	first=curr;
	
	return first;
}

void display(node* first)
{
	node *p;
	if(first==NULL)
		printf("List is empty");
	else
	{
		for(p=first;p->next!=NULL;p=p->next)
			printf("%d->",p->info);
		printf("%d",p->info);
	}
}
