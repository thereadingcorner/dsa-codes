#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node* left;
	int info;
	struct Node* right;
}node;

node *Create(node *,int arr[],int);
node *CreateNode(node*,int);
void InorderDisplay(node*);
void LevelOrderDisplay(node*,int);
void Level(node*,int);
void main()
{
	printf("Enter number of elements:");
	int n;
	node *root=NULL;
	scanf("%d",&n);	
	
	int i, arr[n];
	
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
		root=Create(root,arr,n);
		
	printf("Inorder Traversal:\n");
	InorderDisplay(root);
	
	printf("\nLevel order Traversal:\n");
	int level=height(root);
	
	LevelOrderDisplay(root,level);
	
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
		
		if(q->info>a) q->left=curr;
		else q->right=curr;
	}
	return root;
}

int height(node *root)
{
	int left=right=NULL;
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
		return(right+1);
	
}

void InorderDisplay(node *root)
{
	if(root==NULL) return ;
	InorderDisplay(root->left);
	printf("%d ",root->info);
	InorderDisplay(root->right);
}

void Level(node*root,int level)
{
	if(root==NULL) 
		return;
	else if(level==1)
		printf("%d ",root->info);
	else 
		Level(root->left,level-1);
		Level(root->right,level-1);	
}
void LevelOrderDisplay(node *root,int level)
{
	int i;
	for(i=1;i<=3;i++)
	{
		Level(root,i);
	}	
}
