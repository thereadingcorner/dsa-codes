#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* left;
	int info;
	struct Node *right;
}node;

node *Create(node *,int arr[],int);
node *CreateNode(node*,int);
void Display(node*);
void main()
{
	int n;
	node *root=NULL;

	printf("Enter number of elements:");
	scanf("%d",&n);	
	
	int i, arr[n];
	
	for(i=0;i<n;i++) 
		scanf("%d",&arr[i]);
		
	root=Create(root,arr,n);
	Display(root);
}

node *Create(node* root,int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		root=CreateNode(root,arr[i]);
	}
	
	return root;
}

node *CreateNode(node *root,int a)
{
	node *curr=(node*)malloc(sizeof(int));
	curr->info=a;
	curr->left=curr->right=NULL;
	if(root==NULL) root=curr;
	else 
	{
		node *p=root,*q;
		while(p!=NULL)
		{
			q=p;
			if(p->info>a) p=p->left;
			else p=p->right;
		}
		
		if(q->info>a) 
			q->left=curr;
		else 
			q->right=curr;
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

