//Level order traversal in bst

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
int height_bst(node*);
void LevelOrderDisplay(node*,int);
void Level(node*,int);

void main()
{
	printf("Enter number of elements:");
	int n;
	node *root=NULL;
	scanf("%d",&n);	
	
	root=insert(root,n);
		
	printf("Inorder Traversal:\n");
	InorderDisplay(root);
	
	printf("\nLevel order Traversal:\n");
	int height=height_bst(root);
	
	LevelOrderDisplay(root,height);
	
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

int height_bst(node *root)
{
	int left,right;
	if(root==NULL) 
		return 0;
	else
	{	
		left=height_bst(root->left);
		right=height_bst(root->right);
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
void LevelOrderDisplay(node *root,int height)
{
	int i;
	for(i=1;i<=height;i++)
	{
		Level(root,i);
	}	
}
