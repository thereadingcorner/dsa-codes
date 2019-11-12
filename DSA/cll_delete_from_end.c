#include<stdio.h>
#include<stdlib.h>

 typedef struct node
 {
 	int info;
 	struct node *next;
 }node;
 
 node* create_circular_linklist(node*,int n);
 node* delete_from_end(node*);
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
	
	first=delete_from_end(first);
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
 
node* delete_from_end(node* first) 
{
	node *p,*q;
	
	for(p=first;p->next!=first;q=p,p=p->next);
		q->next=first;
		
	free(p);
		
	return first;
}
