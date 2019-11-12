#include<stdio.h>
#include<stdlib.h>

struct node
{
	
	int coeff;
	int pow;
	struct node *next;
};

struct node* polyadd(struct node * poly1, struct node * poly2)
{
		struct node * head=NULL;
		struct node* ptr;
		
		while(poly1->next!=NULL && poly2->next!=NULL)
		{
			struct node *poly=(struct node*)malloc(sizeof(struct node));
			poly->pow=0;
			poly->coeff=0;
			poly->next=NULL;
// If power of 1st polynomial is greater than 2nd, then store 1st as it is and move its pointer
			if(poly1->pow > poly2->pow)
			{
				poly->pow = poly1->pow;
				poly->coeff = poly1->coeff;
				poly1 = poly1->next;
			}
		
			else if(poly1->pow < poly2->pow)
			{
				poly->pow = poly2->pow;
				poly->coeff = poly2->coeff;
				poly2 = poly2->next;
			}
		
			else
			{
				poly->pow = poly1->pow;
				poly->coeff = poly1->coeff+poly2->coeff;
				//printf("%d",poly->coeff);
				poly1 = poly1->next;
				poly2 = poly2->next;
			}
			if(head==NULL)
			{
				head = ptr=poly;
			}
			else
			{
				ptr->next=poly;
				ptr=poly;
			}
				
		}

		/*	while(poly1->next!=NULL || poly2->next!=NULL)
			{
				if(poly1!=NULL)
				{
					poly->pow = poly1->pow;
					poly->coeff = poly1->coeff;
					poly1 = poly1->next;
				}
				if(poly2!=NULL)
				{
					poly->pow = poly2->pow;
					poly->coeff = poly2->coeff;
					poly2 = poly2->next;
				}
					poly->next = (struct node *)malloc(sizeof(struct node));
					poly = poly->next;
					poly->next = NULL;
			}*/
		return head;
}
struct node* add(struct node * poly1, struct node * poly2, struct node * poly3)
{
	return (polyadd (polyadd(poly1, poly2), poly3));
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
		printf("enter the cofficient,exponent ");
		scanf("%d\t%d",&(curr->coeff),&(curr->pow));
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


void display(struct node*h)
{
	struct node*ptr=h;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->coeff);
		ptr=ptr->next;
	}
}

int main()
{
	struct node*head1,*head2,*head3,*a1;
	head1=head2=head3=NULL;
	create(&head1);
	printf(" \n");
	display(head1);
	create(&head2);
	printf(" \n");
	display(head2);
	create(&head3);
	printf("\n");
	display(head3);
	a1=add(head1,head2,head3);
	printf(" \n");
	display(a1);
	
	return 0;
	
}
