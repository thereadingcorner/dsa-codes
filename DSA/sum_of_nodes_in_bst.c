//Sum of all nodes in a bst

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
int sum_nodes(node*root);

int sum=0;

void main()
{
	printf("Enter number of elements:");
	int n;
	node *root=NULL;
	scanf("%d",&n);	

	root=insert(root,n);
	
	sum=sum_nodes(root);
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

int sum_nodes(node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		sum_nodes(root->left);
		sum+=root->info;
		sum_nodes(root->right);
	}
	
	return sum;
}
