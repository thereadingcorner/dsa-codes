#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node* create_list(node*,int);
node* delete_specific(node*);
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
	first=delete_specific(first);
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
				printf(" Memory allcoation failed");
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

node* delete_specific(node* first)
{
	node *p=first,*q=NULL;
	int num;
	
	printf(" Enter the number which is to be shifted to front: ");
	scanf("%d",&num);
	
	for(p=first;p!=NULL && p->info!=num;q=p,p=p->next);
		
		if(p==NULL)
		{
			printf(" Number not found in the list ");
			return;
		}
		else
		{
			q->next=p->next;
			p->next=first;
			first=p;
		}
		
	return first;
}

void display(node* first)
{
	node *p;
	for(p=first;p->next!=NULL;p=p->next)
		printf("%d->",p->info);
	printf("%d",p->info);
}
