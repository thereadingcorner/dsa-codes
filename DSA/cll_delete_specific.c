#include<stdio.h>
#include<stdlib.h>

 typedef struct node
 {
 	int info;
 	struct node *next;
 }node;
 
 node* create_circular_linklist(node*,int n);
 node* delete_specific(node*);
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
	
	first=delete_specific(first);
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
 
node* delete_specific(node* first)
{
	node *p,*q=NULL;
	int num;
	
	printf(" Enter the number after which node has to be deleted: ");
	scanf("%d",&num);
	
	for(p=first;p->next!=first && p->info!=num;q=p,p=p->next);
	{
		if(p==first)	
		{
			printf(" Number not found: ");
			return;
		}
		else
		{
			q->next=p->next;
			free(p);
		}
	}
	return first;
}
