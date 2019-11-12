//display leaf nodes in a level

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
void DisplayKthlevelLeaf(node*,int,int);
int Height(node *root);
void Level(node *,int );

void main()
{
	printf("Enter number of elements:");
	int n;
	node *root=NULL;
	scanf("%d",&n);	

	root=insert(root,n);

	Display(root);
	printf("Enter Kth Height:");
	int value,level=Height(root);
	
	scanf("%d",&value);
	printf("\nPrint Kth Leaf:\n");
	DisplayKthlevelLeaf(root,value,level);	
}

node* insert(node* root,int n)
{
	node *curr,*p,*q;
	int i,item;
	for(i=0;i<n;i++)
	{
		curr=(node*)malloc(sizeof(node));
		if(curr==NULL)
		{
			printf(" MAF");
			return;
		}
		else
		{
			printf(" Enter number: ");
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
					printf(" Avoid duplicates \n ");
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

void DisplayKthlevelLeaf(node *root,int value,int level)
{
	
	if(value<=level)
		Level(root,value);
	
}

void Level(node *root,int level)
{
	if(root==NULL) 
		return;
		
	else if(level==1 && root->left==NULL && root->right==NULL)
		printf("%d ",root->info);
	else 
		Level(root->left,level-1);
		Level(root->right,level-1);	
}

int Height(node *root)
{
	int left,right;
	if(root==NULL) 
		return 0;
	else
	{
		left=Height(root->left);
		right=Height(root->right);
	}
	if(left>right) return left+1;
	else return right+1;	
}

