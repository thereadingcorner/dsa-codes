#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node* create_list(node*,int);
node* count_duplicates(node*);
void display(node*);

void main()
{
	node* first=NULL;
	int n;
	
	printf("Enter the number of elements in the list: ");
	scanf("%d",&n);
	
	first=create_list(first,n);
	display(first);
	
	first=count_duplicates(first);
	
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

node* count_duplicates(node* first)
{
	node *p;
	int num,count=0;
	
	printf(" Enter the number to be searched: ");
	scanf("%d",&num);
	
	for(p=first;p->next!=NULL;p=p->next)
	{
		if(p->info==num)
			count++;
	}
	
	if(count==0)
	{
		printf(" No duplicates found");
		return;
	}
	else
		printf("%d duplicates found",count);
}

