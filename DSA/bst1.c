#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int info;
	struct node *right;
};

void insert(int);
void delete(int);
void pre_order(struct node*);

struct node *root=NULL;
int ch,item,c;

void main()
{
	printf("Binary tree using linked list");
	
	do
	{
		printf("\n 1-->INSERT\n 2-->DELETE\n 3-->DISPLAY \n 4-->EXIT");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter the item to be inserted: ");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				printf("Enter the item to be deleted: ");
				scanf("%d",&item);
				delete(item);
				break;
			case 3:
				pre_order(root);
				break;
			case 4:
				break;
			default: printf("Wrong choice\n Try again.....");
		}
	}while(ch!=4);
}

void insert(int item)
{
	struct node *curr,*p,*q;
	curr=(struct node*)malloc(sizeof(struct node));
	if(curr==NULL)
		printf("Memory allocation failed");
	
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
				printf("Avoid duplication ");
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
		
		if(p==NULL)					//item not found
			printf("Item not found");
		else if(p->left==NULL)		//left node NULL
			rp=p->right;
		else if(p->right==NULL)		//right node NULL
			rp=p->left;
		else						//Find the in-order successor
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
		
		if(q==NULL)		//root node to be deleted
			root=rp;
		else
		{
			if(p==q->left)
				q->left=rp;
			else
				q->right=rp;
		}
		p->left=NULL;
		p->right=NULL;
		free(p);
		p=NULL;
	}
	return;
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
