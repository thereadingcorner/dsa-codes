//print left nodes in bst

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node* left;
	int info;
	struct Node* right;
}node;

node* insert(node*,int);
void InorderDisplay(node*);
void lprintf(node*root);

void main()
{
	printf("Enter number of elements:");
	int n;
	node *root=NULL;
	scanf("%d",&n);	

	root=insert(root,n);
	
	lprintf(root);
	
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

void lprintf(node *root)
{
	if(root==NULL) 
		return;
	
	if(root->left!=NULL)
	{
		printf("%d ",root->left->info);
		lprintf(root->left);
	}
	
	if(root->right!=NULL)
	{
		lprintf(root->right);
	}
}

