#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void compute(struct node *head)
{
 	int count=0;
	int sum=0;
	
	struct node *ptr=head,*cur=head;
	
	while(ptr!=NULL && ptr->next!=NULL)
	{
		sum += ptr->data;
		if(sum==ptr->next->data)
		{
			printf("SUM=%d\n",sum);
			count++;
			sum=0;
			
			printf("\nGROUP %d:",count);
			
			while(ptr->next!=cur)
			{
				printf("%d ",cur->data); cur=cur->next;

			}
			printf("\n"); cur=ptr=ptr->next->next; 
		}
			else ptr=ptr->next;
	}
}
