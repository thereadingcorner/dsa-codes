// Print path of a given node in bst

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node* left;
	int info;
	struct Node* right;
}node;


node* insert(node*,int);
void Display(node*);
void PathPrint(node*,int);

void print_the_path(node *, int );
void main()
{
	printf("Enter number of elements:");
	int n;
	node *root=NULL;
	scanf("%d",&n);	

	root=insert(root,n);

	printf("Inorder:\n");
	Display(root);
	printf("Enter value to print path:");
	int value;
	scanf("%d",&value);
	PathPrint(root,value);
	
}

node* insert(node *root,int n)	
{
	node *curr,*p,*q;
	int item,i;
	for(i=0;i<n;i++)
	{
		curr=(node*)malloc(sizeof(node));
		if(curr==NULL)
		printf("Memory allocation failed");
	
		else
		{	
			scanf("%d",&item);
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
	}
	return root;
}

void Display(node *root)
{
	if(root==NULL) return ;
	Display(root->left);
	printf("%d ",root->info);
	Display(root->right);
}

void PathPrint(node *root,int value)
{
	if(root==NULL)
	{
	printf("Not present\n");
	 return;
	}
	else
	{
		if(root->info > value)
		{
			printf("%d->",root->info);
			PathPrint(root->left,value);
		}
		else if(root->info < value)
		{
		
			printf("%d->",root->info);
			PathPrint(root->right,value);
		}
		else
		printf("%d",root->info);
	}
}
