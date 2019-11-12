#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void display(struct node*h)
{
	struct node*ptr=h;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}


void create(struct node**h)
{
	int n;
	printf("enter the number of terms :");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		struct node*curr,*ptr;
		curr=(struct node*)malloc(sizeof(struct node));
		printf("enter the data values:");
		scanf("%d",&(curr->data));
		curr->next=NULL;
		if(*h==NULL)
		{
			*h=curr;
			ptr=curr;
			
		}
		else
		{
			ptr->next=curr;
			ptr=curr;
		}
	}
}


rev_even(struct node **head)
{
	struct node *ptr1, *ptr2, *prv;
	
	if(*head==NULL)
	{
		return-1;
	}
		
	for(ptr2=*head; ptr2->next!=NULL && ptr2->next->next!=NULL ;ptr2=ptr2->next->next)
	{
	
		for(ptr1=*head ; ptr1!=ptr2 && (ptr2->next==NULL || ptr2->next->next!=ptr1);ptr1=ptr1->next->next)
		{
			int tmp=ptr1->data;
			ptr1->data=ptr2->data;
			ptr2->data=tmp;
			
			for(prv=ptr1;prv->next->next!=ptr2;prv=prv->next->next)
			{
				ptr2=prv;
			}
		}
	}
}



int main()
{
	struct node*head;
	head=NULL;
	create(&head);
	printf(" \n");
	display(head);
	printf(" \n");
	rev_even(&head);
	printf(" \n");
	display(head);
	
	return 0;
	
}
