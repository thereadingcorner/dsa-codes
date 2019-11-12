#include<stdio.h>
#include<stdlib.h>

struct node // node definition
{

	int data;
	struct node *next;
};

void rearrange(struct node *head) // head is the variable pointing or to point to 1st node.
{
	struct node *ptr = NULL;
	
	if (head==NULL && head->next ==NULL) // 0 or 1 node
	{
		return;
	}
	
	for (ptr = head; ptr != NULL || ptr-> next != NULL ; ptr = ptr -> next -> next)
	{
		ptr ->data = ptr ->data + ptr->next->data;
		ptr->next->data = ptr ->data - ptr->next->data;
		ptr->data = ptr ->data - ptr->next->data;
	}
}


/*
void rearrange(struct node *start)
{
	struct node *ptr, *nptr;
	int temp;
		
	if (!start || !start->next)
		return;
		
	ptr = start;
	nptr = start->next;
	
	while(nptr!=NULL)
	{
		temp = ptr->info;
		ptr->info = nptr->info;
		nptr->info = temp;
		ptr = nptr->next;
		nptr = ptr?ptr->next:NULL;
	}
}*/
