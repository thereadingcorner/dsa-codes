#include<stdio.h>
#include<stdlib.h>


struct sparse
{
	int r,c,v;
	struct sparse* next;
};


void display(struct sparse*h)
{
	struct sparse*ptr=h->next;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->v);
		ptr=ptr->next;
	}
}


void create(struct sparse**h)
{
	int n,row,col;
	printf("enter the number of rows,columns and number of non zero elements :");
	scanf("%d\n%d\n%d",&row,&col,&n);
	
	*h=(struct sparse*)malloc(sizeof(struct sparse));
	(*h)->r=row;
	(*h)->c=col;
	(*h)->v=n;
	(*h)->next=NULL;
	
	struct sparse*curr,*ptr;
	ptr=(*h);
	
	for(int i=0;i<n;i++)
	{
		curr=(struct sparse*)malloc(sizeof(struct sparse));
		printf("enter the row,column and value :");
		scanf("%d\n%d\n%d",&(curr->r),&(curr->c),&(curr->v));
		curr->next=NULL;
		ptr->next=curr;
		ptr=curr;
		
	}
}

void transpose(struct sparse**h)
{
	struct sparse*ptr;
	ptr=*h;
	int temp;
	while(ptr!=NULL)
	{
		temp=ptr->r;
		ptr->r=ptr->c;
		ptr->c=temp;
		ptr=ptr->next;
	}
}

void joint(struct sparse **h1,struct sparse *h2)
{
	struct sparse* ptr;
	if(*h1==NULL)
	{
		*h1=h2;
	}
	
		for(ptr=*h1;ptr->next!=NULL;ptr=ptr->next)
		{
		}
		ptr->next=h2->next;
	/*
     ptr=*h1;
     while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=h2;*/
	
}

/*void simplify(struct poly**h)
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
*/

int main()
{
	struct sparse*head1,*head2;
	head1=head2=NULL;
	create(&head1);
	printf(" \n");
	display(head1);
	printf(" \n");
	head2=head1;
	transpose(&head2);
	printf(" \n");
	display(head2);
	joint(&head1,head2);
	printf("\n");
	display(head1);
	
	
	return 0;
}

