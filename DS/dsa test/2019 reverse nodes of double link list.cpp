#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

void create(struct node**h,int n)
{
	struct node* ptr,*curr;
		
		for(int i=1;i<=n;i++)
		{
			printf("enter the %d element:\n",i);
			curr=(struct node*)malloc(sizeof(struct node));
			scanf("%d",&(curr->data));
			curr->next=NULL;
			curr->prev=NULL;
			
			if(*h==NULL)
			{
				ptr=*h=curr;
			}
			else
			{
				curr->prev=ptr;
				ptr->next=curr;
				ptr=curr;
			}
		}
}



void reverse(struct node*h,struct node**ptr1)
{
	struct node* temp,* ptr,*pv;
	ptr=h;
	while(ptr!=NULL)
	{
		pv=ptr;
		temp=ptr->prev;
		ptr->prev=ptr->next;
		ptr->next=temp;
		ptr=ptr->prev;
		
	}
	*ptr1=pv;
	h=NULL;
	
}

void display(struct node*h)
{ 
    struct node*ptr=h;
    
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
	    ptr=ptr->next;
	}
}

 int main()
 {
 	struct node* head=NULL;
 	struct node* head1=NULL;
 	int num;
 	
 	printf("enter the number of nodes to be inserted\n");
 	scanf("%d",&num);
 	create(&head,num);
 	display(head);
 	reverse(head,&head1);
 	printf("\n");
 	display(head1);
 	
 	return 0;
 }
