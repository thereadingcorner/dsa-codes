#include<stdio.h>
#include<stdlib.h>

struct node // node definition
{
	struct node *prev;
	int data;
	struct node *next;
};


// head is the variable pointing to 1st node.
// tail is the variable to point to last node.
void reverse (struct node *head, struct node *tail)
{
		if ((head==NULL && tail==NULL) || head==tail)
		{
			return;
		}
		for(head!=tail || tail->prev!=head ; head=head->next; tail=tail->prev)
		{
			head->data=head->data+tail->data;
			tail ->data=head->data-tail->data;
			head ->data=head->data-tail->data;
		}
}


