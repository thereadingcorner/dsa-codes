#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int info;
	struct node *right;
};

void insert(int);
void delete(int);
void preorder(struct node*);

struct node *root=NULL;
int ch,item,c;

void main()
{
	printf("\n \n Binary Search Tree using Linked list\n\n");

	do
	{
		printf("\n 1-->INSERT\n 2-->REMOVE \n 3-->DISPLAY\n 4-->EXIT");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf(" Enter the item to insert:");
				scanf("%d",&item);
				insert(item);
				break;
			
			case 2:
				printf(" Enter the item to delete");
				scanf("%d",&item);
				delete(item);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				break;
			default:
				printf(" Wrong choice\n Try again...\a");
		}
	}while(ch!=4);
}

void insert(int item)
{
	struct node *curr,*p,*q;
	curr=(struct node*)malloc(sizeof(struct node));
	if(curr==NULL)
		printf(" Memory allocation failed");
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
				puts(" Avoid Duplicate Node ");
			else
			{
				if(q->info > item)		//CHECK HERE
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
		puts("Empty tree \a");
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
			puts("Item not found \a");
		else if(p->left==NULL)
			rp=p->right;
		else if(p->right==NULL)
			rp=p->left;
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
				p->left=rp->right;
				rp->right=p->right;
			}
			rp->left=p->left;	
		}
	
		if(q==NULL)		//if root is selected for deletion
			root=rp;	
		else
		{
			if(p==q->left)
				q->left=rp;
			else
				q->right=rp;
				
			p->left=NULL;
			p->right=NULL;
			free(p);
			p=NULL;
		}
	}
	return;
}

void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%4d",p->info);
		preorder(p->left);
		preorder(p->right);
	}
	return;
}
