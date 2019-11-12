#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *prev;
	int info;
	struct node *next;
}node;

node* create_list(node*,int);
void display(node*);

void main()
{
	node *first=NULL;
	int n;
	
	printf(" Enter the number of elements in the list: ");
	scanf("%d",&n);
	
	first=create_list(first,n);
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
			printf(" Memory allocation failed");
			return;
		}
		
		printf(" Enter number: ");
		scanf("%d",&curr->info);
		
		if(first==NULL)
		{
			curr->prev=NULL;
			first=curr;
			
		}
		else
		{
			p->next=curr;
			curr->prev=p;
		}
		curr->next=NULL;
		p=curr;
	}
	

	return first;	
}

void display(node* first)
{
	node *p;
	if(first==NULL)
	{
		printf(" List is empty");
		return;
	}
	
		for(p=first;p->next!=NULL;p=p->next)
			printf("%d->",p->info);
		printf("%d",p->info);
}
