// Insert element at end in circular linkedlist

#include<stdio.h>
#include<stdlib.h>

 typedef struct node
 {
 	int info;
 	struct node *next;
 }node;
 
 node* create_circular_linklist(node*,int n);
 node* insert_at_end(node*);
 void display(node*);
 
 void main()
 {
 	node *first=NULL;
	int n;
	
	printf(" Enter the number of elements in the list: ");
	scanf("%d",&n);
	
	first=create_circular_linklist(first,n);
	display(first);
	
	printf("\n");
	
	first=insert_at_end(first);
	display(first);
 }
 
 node* create_circular_linklist(node* first,int n)
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
	 p->next=first;
	 return first;
 }
 
 void display(node* first)
 {
 	node *p;
 	
 	if(first==NULL)
 		printf(" List is empty");
 	else
 	{
 		for(p=first;p->next!=first;p=p->next)
 			printf("%d->",p->info);
 		printf("%d",p->info);
	}
 }

node* insert_at_end(node *first)
{
	node *curr,*p;
	
	curr=(node*)malloc(sizeof(node));

	if(curr=NULL)
	{
		printf(" Memory allocation failed");
		return;
	}
	
	printf(" Enter number to be inserted: ");
	scanf("%d",&curr->info);
		
	for(p=first;p->next!=first;p=p->next);
	p->next=curr;
	curr->next=first;
	
	return first;
}
 
