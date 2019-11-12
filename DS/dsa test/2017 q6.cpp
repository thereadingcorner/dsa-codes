#include<stdio.h>
#include<stdlib.h>


struct node // node definition 
{
	int data;
	struct node *next;
};


void format(struct node *head) // head is pointing to 1st node
{
	struct node *h1=NULL,*ptr,*p,*last;
	
	if(head==NULL)
	return;
	
	for(ptr=head;ptr->next!=NULL;ptr=ptr->next)
	{
		p=ptr->next;
		ptr->next=p->next;
		p->next=NULL;
		
		if(h1==NULL)
		{
			last=p;
			h1=p;
		}
		else
		{
			last->next=p;
			last=p;
		}
		if(ptr->next==NULL)
			break;
	}
		ptr->next=h1;
}
