#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node* create_list(node*,int);
node* delete_last(node*);
void display(node*);

void main()
{
	node *first=NULL;
	int n;
	
	printf(" Enter the number of elements in the list: ");
	scanf("%d",&n);
	
	first=create_list(first,n);
	display(first);
	printf("\n Deleting the last node \n");
	first=delete_last(first);
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
			
			printf("Enter number: ");
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

node* delete_last(node* first)
{
	node *p=first,*q=NULL;
	
	for(p=first;p->next!=NULL; q=p,p=p->next);
	
	q->next=NULL;
	free(p);
	
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
