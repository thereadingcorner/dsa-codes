#include<stdio.h>
#include<stdlib.h>

struct node *head;
del()
{
	
	struct node *ptr=head;
	
	while(ptr!=NULL)
	{
		int flag=0;
		
		flag1=flag2=1;
		
	for(ptr1=ptr->prv;ptr1!=NULL;ptr1=ptr1->prv)
	
		if(ptr1->data>ptr->data)
		{
			flag1=0; break;
		}
	for(ptr1=ptr->next;ptr1!=NULL;ptr1=ptr1->next)
	
		if(ptr1->data<ptr->data)
		{
			flag2=0; 
				break;
		}
		if(flag1 && flag2)
		{
			if(head==ptr)
			{
				head=head->next;
					free(ptr);
					ptr=head;
					ptr->prv=NULL;
			}
			else if(ptr->next==NULL)
			{
				ptr->prv->next=NULL;
					free(ptr);
					ptr=NULL;
			}
			else
			{
				ptr=ptr->next;
				ptr->prv=ptr->prv->prv;
				free(ptr->prv->next);
				
				ptr->prv->next=ptr;
			}
		}
	}
}
