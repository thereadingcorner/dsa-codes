//print predecessor and successor of a given node in bst

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node* left;
	int info;
	struct Node* right;
}node;

typedef struct ARRAY
{
	int info;
	struct ARRAY *next;
}array;

array *root1=NULL;
array *insertp=NULL;

node* insert(node*,int);
void Display(node*);
void DisplayArray(array*);
void PredeSucce(node*root);
void insert_in_ll(node*root);
void CheckData(array *,int );

void main()
{
	int n;
	node *root=NULL;
	
	printf("Enter number of elements:");
	scanf("%d",&n);	

	root=insert(root,n);
	
	
	printf("Inorder Traversal:\n");
	Display(root);
	
	printf("\n In_order representation in Array:\n");
	PredeSucce( root);						//puts in_order values in linkedlist named array;
	DisplayArray(root1);					//displays linkedlist names array;
	
	printf("Enter number for which result is required:");
	int num;
	scanf("%d",&num);
	CheckData(root1,num);					//checks the predessesor and successor from the linkedlist;
		
}

node* insert(node *root,int n)						//inserts item in bst
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

void Display(node* root)				//displays the in_order form of tree
{
	if(root==NULL) 
		return;
	Display(root->left);
	printf("%d ",root->info);
	Display(root->right);
}

void PredeSucce(node* root)				//traverse inorder and put value in linkedlist
{
	if(root==NULL)
		return;
	PredeSucce(root->left);
	insert_in_ll(root);
	PredeSucce(root->right);
}

void insert_in_ll(node* root)
{
	array *curr=(array*)malloc(sizeof(array));
	curr->info=root->info;
	curr->next=NULL;
	if(root1==NULL) 
		root1=curr;
	else
	{
		insertp->next=curr;		//p->next=curr;
	}
	insertp=curr;				//p=curr;	
}

void DisplayArray(array *root1)					//linkedlist display
{
	array* q;
	
	for(q=root1;q!=NULL;q=q->next) 
		printf("%d ",q->info);
}

void CheckData(array *root1,int num)				//linear search in linkedlist
{
	array *q,*r=NULL;
	if(root1==NULL) 
	{
		printf("List Empty");
		return ;
	}
	for(q=root1; q!=NULL && q->info!=num;r=q,q=q->next);
	if(q==NULL) 
		printf("\nEntered key not found");
	else 
	{
		if(r!=NULL && q->next==NULL) 										//last node in linkedlist
			printf("Successor is NULL\nPredecessor is %d\n",r->info);
		else if(r==NULL && q!=NULL) 										//first node in likedlist
			printf("Succesor is %d\nPredecessor is NULL",q->next->info);
		else																//rest nodes in linkedlist
		{
			printf("Predessor is %d\n",r->info);
			printf("Succesor is %d",q->next->info);
		}
	}
}
