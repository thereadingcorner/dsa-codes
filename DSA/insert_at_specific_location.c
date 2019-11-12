#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node* create_list(node*,int);
node* insert_at_specific_location(node*);
void display(node*);

void main()
{
	node *first=NULL;
	int n;
	printf(" Enter the number of elements in the list: ");
	scanf("%d",&n);
	
	first=create_list(first,n);
	display(first);
	printf("\n");
	first=insert_at_specific_location(first);
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
				first=curr;
			else
				p->next=curr;
		p=curr;
	}
	p->next=NULL;
	return first;
}

node* insert_at_specific_location(node* first)
{
	node *curr,*p;
	int pos;
	
	printf(" Enter the number after which node is to be inserted: ");
	scanf("%d",&pos);
	
	curr=(node*)malloc(sizeof(node));
	
	if(curr==NULL)
	{
		printf(" Memory allocation failed");
		return;
	}
	
	printf(" Enter number to be inserted: ");
	scanf("%d",&curr->info);
	
	if(first==NULL)
		first=curr;
	else
	{
	
		for(p=first;p!=NULL && p->info!=pos;p=p->next);
		if(p==NULL)
			printf("Specified item not found");
		else
		{
			curr->next=p->next;
			p->next=curr;
		}
	}
	return first;
}

void display(node* first)
{
	node *p;
	if(first==NULL)
	{
		printf(" List is Empty");
		return;
	}
	
	for(p=first;p->next!=NULL;p=p->next)
		printf("%d->",p->info);
	printf("%d",p->info);
}
