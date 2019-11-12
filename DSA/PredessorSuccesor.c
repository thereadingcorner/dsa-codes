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

node *Create(node *,int arr[],int);
node *CreateNode(node*,int);

void Display(node*);
void DisplayArray(array*);
void PredeSucce(node*root);
void insert(node*root);
int CheckData(array *,int );

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
	
	printf("Inorder Traversal:\n");
	Display(root);
	printf("\nIn Array:\n");
	PredeSucce( root);
	DisplayArray(root1);
	printf("Enter number for which result is required:");
	int num;
	scanf("%d",&num);
	CheckData(root1,num);

	
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
	
	curr->left=NULL;
	curr->right=NULL;
	
	if(root==NULL) 
		root=curr;
	else 
	{
		node *p,*q;
		
		p=root;
		while(p!=NULL)
		{
			q=p;
			if(p->info > a)
				p=p->left;
			else 
				p=p->right;
		}
		
		if(q->info > a)
			q->left=curr;
		else 
			q->right=curr;
	}
	return root;
}

void Display(node* root)
{
	if(root==NULL) return;
	Display(root->left);
	printf("%d ",root->info);
	Display(root->right);
	
}

void PredeSucce(node* root)				//traverse inorder and put value in linkedlist
{
	if(root==NULL)
		return;
	PredeSucce(root->left);
	insert(root);
	PredeSucce(root->right);
	
}

void insert(node* root)
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

int CheckData(array *root1,int num)				//linear search in linkedlist
{
	array *q,*r=NULL;
	if(root1==NULL) 
	{
		printf("List Empty");
		return 0;
	}
	for(q=root1; q!=NULL && q->info!=num;r=q,q=q->next);
	if(q==NULL) 
		printf("\nEntered key not found");
	else 
	{
		if(r!=NULL && q->next==NULL) 		//last node in linkedlist
			printf("Successor is NULL\nPredecessor is %d\n",r->info);
		else if(r==NULL && q!=NULL) 		//first node in likedlist
			printf("Succesor is %d\nPredecessor is NULL",q->next->info);
		else								//rest nodes in linkedlist
		{
			printf("Predessor is %d\n",r->info);
			printf("Succesor is %d",q->next->info);
		}
	}
			

}



