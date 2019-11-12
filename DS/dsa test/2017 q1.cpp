#include<stdio.h>
#include<stdlib.h>

struct node // Node representation 
{
	int coeff;
	int expo;
	struct node *link;
};


struct node *insert(struct node *start,float co,int ex)
{
	struct node *ptr,*tmp;
	
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->coeff=co;
	tmp->expo=ex;
	/*list empty or exp greater than first one */
	if(start==NULL || ex > start->expo)
	{
		tmp->link=start;
		start=tmp;
	}
	else
	{
		ptr=start;
		while(ptr->link!=NULL && ptr->link->expo >= ex)
		ptr=ptr->link;
		tmp->link=ptr->link;
		ptr->link=tmp;
	
	}
	
	return start;
}



void multiply(struct node *p1, struct node *p2)
{
	struct node *start3;
	struct node *p2_beg=p2;
	
	start3=NULL;
	
	if(p1==NULL || p2==NULL)
	{
		printf("Multiplied polynomial is zero polynomial\n");
		return;
	}
	while(p1!=NULL)
	{
		p2=p2_beg;
		while(p2!=NULL)
		{
			start3=insert(start3,p1->coeff*p2->coeff,p1->expo+p2->expo);
			p2=p2->link;
		}
		p1=p1->link;
	}
}



