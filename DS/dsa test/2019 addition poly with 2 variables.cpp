#include<stdio.h>
#include<stdlib.h>

struct poly
{
	int coff;
	int expx;
	int expy;
	struct poly*next;
};

void create(struct poly**h)
{
	int n;
	printf("enter the number of terms :");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		struct poly*curr,*ptr;
		curr=(struct poly*)malloc(sizeof(struct poly));
		printf("enter the cofficient,exponent x,exponent y:");
		scanf("%d\t %d\t %d",&(curr->coff),&(curr->expx),&(curr->expy));
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

void joint(struct poly **h1,struct poly *h2)
{
	struct poly* ptr;
	if(*h1==NULL)
	{
		*h1=h2;
	}
     ptr=*h1;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=h2;
}

void simplify(struct poly**h)
{
	struct poly*ptr,*ptr1,*pv;
	ptr=ptr1=*h;
	while(ptr!=NULL)
	{
		pv=ptr;
		ptr1=ptr->next;
		
		while(ptr1!=NULL)
		{
			if(ptr->expx==ptr1->expx&&ptr->expy==ptr1->expy)
			{
				ptr->coff=ptr->coff+ptr1->coff;
				pv->next=ptr1->next;
				free(ptr1);
				ptr1=pv->next;
			}
			else
			{
				pv=ptr1;
				ptr1=ptr1->next;
			}
			
		}
		ptr=ptr->next;
	}
}

void display(struct poly*h)
{
	struct poly*ptr=h;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->coff);
		ptr=ptr->next;
	}
}

int main()
{
	struct poly*head1,*head2;
	head1=head2=NULL;
	create(&head1);
	printf(" \n");
	display(head1);
	create(&head2);
	printf(" \n");
	display(head2);
	joint(&head1,head2);
	printf(" \n");
	display(head1);
	simplify(&head1);
	printf(" \n");
	display(head1);
	
	return 0;
	
}
