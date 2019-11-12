#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node* create_list(node*,int);
node* delete_at_specific_location(node*);
void display(node*);

void main()
{
	node *first=NULL;
	int n;
	
	printf(" Enter the number of element in the list: ");
	scanf("%d",&n);
	
	first=create_list(first,n);
	display(first);
	first=delete_at_specific_location(first);
	printf("\n Deleting the given node \n");
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

node* delete_at_specific_location(node* first)
{
	node *p=first,*q=NULL;
	int num;
	
	printf("\n Enter the number which has to be deleted: ");
	scanf("%d",&num);
	
	for(p=first;p->next!=NULL && p->info!=num;q=p,p=p->next);
	
	q->next=p->next;
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
