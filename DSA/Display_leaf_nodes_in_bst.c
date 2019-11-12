//Display leaf nodes in bst

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* left;
	int info;
	struct Node *right;
}node;

node* insert(node*,int);
void Display(node*);
void DisplayLeafLeft(node*);
void DisplayLeafRight(node*);

void main()
{
	printf("Enter number of elements:");
	int n;
	node *root=NULL;
	scanf("%d",&n);	
	
	root=insert(root,n);
	
	Display(root);
	printf("\nPrint Left to right Leaf:\n");
	DisplayLeafLeft(root);
	printf("\nPrint Right to Left Leaf:\n");
	DisplayLeafRight(root);
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

void DisplayLeafLeft(node *root)
{
	if(root==NULL) 
		return;
		
	DisplayLeafLeft(root->left);
	if(root->left==NULL && root->right==NULL) 
		printf("%d ",root->info);
	DisplayLeafLeft(root->right);
}

void DisplayLeafRight(node *root)
{
	if(root==NULL) 
		return;
		
	DisplayLeafRight(root->right);
	if(root->left==NULL && root->right==NULL) 
		printf("%d ",root->info);
	DisplayLeafRight(root->left);
}
