#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int info;
	struct node *right;
};

void insert(int);
int count_node(struct node*);
void pre_order(struct node*);
void delete(int);

struct node *root=NULL;
int ch,item,c=0;

void main()
{
	printf(" Binary Search Tree \n");
	
	do
	{
		printf("\n 1. Insert \n 2. Remove \n 3. Display \n 4.Quit ");
		printf("\n Enter you're choice: '");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf(" Enter  the item to insert: ");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				c=count_node(root);
				printf("\n %d",c);
				break;
			case 3:
				pre_order(root);
				break;
			case 4:
				printf(" Enter the item to be deleted: ");
				scanf("%d",&item);
				delete(item);
				break;
			deafult: printf(" Wrong choice \n Try again...");
			break;
		}
	}while(ch!=5);
}

void insert(int item)
{
	struct node *curr,*p,*q;
	curr=(struct node *)malloc(sizeof(struct node));
	
	if(curr==NULL)
	{
		printf("Memory allocation failed");
	}
	else
	{
		curr->info=item;
		curr->left=NULL;
		curr->right=NULL;
		
		if(root==NULL)
			root=curr;
		
		else
		{
			p=root;
			while(p!=NULL && p->info!=item)
			{
				q=p;
				if(p->info > item)
					p=p->left;
				else
					p=p->right;
			}
			if(p!=NULL)
				printf("Avoid duplicates");
			else
			{
				if(q->info > item)
					q->left=curr;
				else
					q->right=curr;
			}
		}
	}
	return;
}

int count_node(struct node *p)
{
	if(p!=NULL)
	{
		c++;
		count_node(p->left);
		count_node(p->right);
	}
	return c;
}

void pre_order(struct node *p)
{
	if(p!=NULL)
	{
		printf("%4d",p->info);
		pre_order(p->left);
		pre_order(p->right);
	}
	return;
}

void delete(int item)
{
	struct node *p,*q=NULL,*f,*rp,*s;
	
	if(root==NULL)
		printf("Empty tree");
	else
	{
		p=root;
		while(p!=NULL && p->info!=item)
		{
			q=p;
			if(p->info > item)
				p=p->left;
			else
				p=p->right;
		}
		
		if(p==NULL)
			printf(" item not found");
		
		else if(p->left=NULL)
			p->right;
		else if(p->right=NULL)
			p->left;
		else
		{
			f=p;
			rp=p->right;
			s=rp->left;
			while(s!=NULL)
			{
				f=rp;
				rp=s;
				s=rp->left;
			}
			
			if(f!=p)
			{
				f->left=rp->right;
				rp->right=p->right;
			}
			rp->left=p->left;
		}
	}
	return;
}
