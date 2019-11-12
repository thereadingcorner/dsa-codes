//Sum of leaf nodes of a given level in a bst

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
int sum_leaf_nodes(node*,int);

int sum_leaf=0;

void main()
{
	printf("Enter number of elements:");
	int n,level,sum=0;
	node *root=NULL;
	scanf("%d",&n);	

	root=insert(root,n);
	
	printf(" Enter the level: ");
	scanf("%d",&level);
	
	sum=sum_leaf_nodes(root,level);
	printf("The sum of nodes is: %d",sum);
	
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

int height(node *root)
{
	int left,right;
	
	if(root==NULL)
		return 0;
	else
	{
		left=height(root->left);
		right=height(root->right);
	}
	if(left > right)
		return(left+1);
	else
		return (right+1);
}

int sum_leaf_nodes(node *root,int level)
{
	if(root==NULL)
		return 0;
	else if(level==1 && root->left==NULL && root->right==NULL)
	{
		printf(" %d ",root->info);
		sum_leaf+=root->info;
	}
	else
	{
		sum_leaf_nodes(root->left,level-1);
		sum_leaf_nodes(root->right,level-1);
	}	
	
	return sum_leaf;
}

