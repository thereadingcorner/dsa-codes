#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node* create_list(node*,int);
node* delete_node(node*,int);
void display(node*);

void main()
{
	node* first=NULL;
	int n;
	
	printf("Enter the number of elements in the list: ");
	scanf("%d",&n);
	
	first=create_list(first,n);
	display(first);
	
	first=delete_node(first,n);
	display(first);
}

node* create_list(node* first,int n)
{
	node *curr,*p;
	int  i;
	
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

node* delete_node(node* first,int n)
{
	node* p=first,*q=NULL;
	int m,pos,count=0;
	
	printf(" Enter the position of node from end: ");
	scanf("%d",&m);
	
	pos=n-(m-1);		//mth node from last = n-(m-1)th node from start
	
	while(p->next!=NULL)
	{
		count++;
		
		if(count==pos)
		{
			q->next=p->next;
			p->next=NULL;
			free(p);
			
			break;
		}
		q=p;
		p=p->next;
	}
	return first;
}

void display(node* first)
{
	node *p;
	if(first==NULL)
	{
		printf("List is empty");
		return;
	}
	
	for(p=first;p->next!=NULL;p=p->next)
		printf("%d->",p->info);
	printf("%d",p->info);	
}

