//display odd even and prime numbers in bst

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

void EvenDisplay(node*);
void OddDisplay(node*);

int CheckPrime(int);
void PrimeDisplay(node*);

void main()
{
	printf("Enter number of elements:");
	int n;
	node *root=NULL;
	scanf("%d",&n);	
	
	root=insert(root,n);

	printf("Inorder:\n");
	Display(root);
	
	printf("\nPrint Even:");
	EvenDisplay(root);
	
	printf("\nPrint Odd:");
	OddDisplay(root);
	printf("\nPrint Prime:");
	PrimeDisplay(root);
	
	
	
}

node* insert(node* root,int n)
{
	node *curr,*p,*q;
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

void EvenDisplay(node *root)
{
	if(root==NULL)
		return ;
		
	EvenDisplay(root->left);
	if((root->info)%2==0) 
		printf("%d ",root->info);
	EvenDisplay(root->right);
}

void OddDisplay(node *root)
{
	if(root==NULL)
		return ;
		
	OddDisplay(root->left);
	if((root->info)%2!=0) printf("%d ",root->info);
	OddDisplay(root->right);
}

void PrimeDisplay(node *root)
{
	
	if(root==NULL) 
		return ;
		
	PrimeDisplay(root->left);
	if(CheckPrime(root->info)==0) 
		printf("%d ",root->info);
	PrimeDisplay(root->right);
}

int CheckPrime(int n)
{
	int i;
	for(i = 2; i <= n/2; i++)
    {
        	
       	if(n%i == 0)
       	{
        	return 1;
           	break;
        }
    }
    return 0;
}
