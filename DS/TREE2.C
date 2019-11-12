#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
struct node
{
	 char val;
	 struct node* left;
	 struct node* right;
};
typedef struct node Tree;
char pt1[10][10];
void printarr(char path[],int k);
Tree * insert(Tree * r, char data)
{
	 if(r==NULL)
	 {
		r = (Tree *) malloc(sizeof(Tree));
		r->val = data;
		r->left = NULL;
		r->right = NULL;
	 }
	 else if(data <= r->val)
		r->left = insert(r->left, data);
	 else
		r->right = insert(r->right, data);
	 return r;
}

void longpath(Tree *r, char path[], int ac)
{
	static int f=0;
	 if (r == NULL)
		return;
	 path[ac++] = r->val;
	 if (r->left== NULL && r->right == NULL)
	 {
		printarr(path,ac);
		path[ac]='\0';
		strcpy(pt1[f],path);
		f++;
	 }
	 else
	 {
		  longpath(r->left,path,ac);
		  longpath(r->right,path,ac);
	 }
}
void printarr(char p[],int k)
{
	int i;
	//c=sizeof(p)/2;
	for(i=0;i< k;i++)
		printf("%c-->",p[i]);
	printf("\n");
}

void display(Tree *r, int level)
{
	int i;
	if(r)
	{
		display(r->right,level+1);
		for(i=0;i<level;i++)
			printf("    ");
		printf("%c",r->val);
		printf("\n");
		display(r->left,level+1);
	}
}
void preorderit(Tree *r)
{
	Tree *arr[10],*t;
	int ls=0;
	arr[ls]=r;
	printf("\n");
	while(ls>=0)
	{
		t=arr[ls--];
		printf("%c ",t->val);
		if(t->right)
			arr[++ls]=t->right;
		if(t->left)
			arr[++ls]=t->left;
	}
}
void preorderit1(Tree *r)
{
	Tree *arr[10],*t;
	int ls=-1;
	printf("\n");
	while(1)
	{
		while(r)
		{
			printf("%c ",r->val);
			arr[++ls]=r;
			r=r->left;
		}
		if(ls<0)
			break;
		r=arr[ls--];
		r=r->right;
	}
}

void inorderit(Tree *r)
{
	Tree *arr[10],*t;
	int ls=-1;
	printf("\n");
	t=r;
	while(1)
	{
		while(t)
		{
			arr[++ls]=t;
			t=t->left;
		}
		if(ls<0)
			break;
		t=arr[ls--];
		printf("%c ",t->val);
		t=t->right;
	}
}
/**/
void postorderit(Tree *r)
{
	Tree *arr[20], *out[20], *t;
	int ls=-1,lso=-1;
	arr[++ls]=r;
	while(ls>=0)
	{
    	t=arr[ls--];
		out[++lso]=t;
		if(t->left)
			arr[++ls]=t->left;
		if(t->right)
        	arr[++ls]=t->right;
	}
  	while (lso>=0)
	{
		printf("%c ",out[lso--]->val);	
	}
}

void levelorder(Tree *r)
{
	Tree *arr[10],*t;
	int rear=-1,front=0;
	arr[++rear]=r;
	while(front<=rear)
	{
		t=arr[front++];
		printf("%c ",t->val);
		if(t->left)
			arr[++rear]=t->left;
		if(t->right)
			arr[++rear]=t->right;
	}
}

void levelorderrev(Tree *r)
{
	Tree *que[10],*stk[10],*t;
	int rear=-1,front=0,ls=-1;
	que[++rear]=r;
	while(front<=rear)
	{
		t=que[front++];
		if(t->right)
			que[++rear]=t->right;
		if(t->left)
			que[++rear]=t->left;
		stk[++ls]=t;
	}
	while(ls>=0)
	{
		t=stk[ls--];
		printf("%c ",t->val);
	}
}
//count no of nodes in the tree
//find maximum node of the tree
//search a node in a tree
//find level of tree
//find deepest node of the tree
//find number of leaf nodes of the tree
int findlevel(Tree *r)
{
	int l=0,rear=-1,front=0;
	Tree *arr[20];
	arr[++rear]=r;
	arr[++rear]=NULL;
	while(front<=rear)
	{
		r=arr[front++];
		if(r==NULL)
		{
			l++;
			if(front<=rear)
				arr[++rear]=NULL;
		}
		else
		{
			if(r->left)
				arr[++rear]=r->left;
			if(r->right)
				arr[++rear]=r->right;
		}
	}
	return(l-1);
}
void leftView(Tree *r)
{
	int l=0,rear=-1,front=0;
	Tree *arr[20];
	arr[++rear]=r;
	arr[++rear]=NULL;
	printf("%c ",arr[front]->val);
	while(front<=rear)
	{
		r=arr[front++];
		if(r==NULL)
		{
			if(front<=rear)
			{
				printf("%c ",arr[front]->val);
				arr[++rear]=NULL;
			}		
		}
		else
		{
			if(r->left)
				arr[++rear]=r->left;
			if(r->right)
				arr[++rear]=r->right;
		}
	}
}
void rightView(Tree *r)
{
	int l=0,rear=-1,front=0;
	Tree *arr[20];
	arr[++rear]=r;
	arr[++rear]=NULL;
	while(front<=rear)
	{
		r=arr[front++];
		if(arr[front]==NULL)
			printf("%c ",r->val);
		if(r==NULL)
		{
			if(front<=rear)
				arr[++rear]=NULL;
		}
		else
		{
			if(r->left)
				arr[++rear]=r->left;
			if(r->right)
				arr[++rear]=r->right;
		}
	}
}

Tree *findmin(Tree *r)
{
	if(r->left==NULL)
		return(r);
	else
		return(findmin(r->left));
}
Tree *delnode(Tree *r, int v)
{
	Tree *t;
	if(r==NULL)
		printf("Tree is empty");
	else
	{
		if(v < r->val)
			r->left=delnode(r->left,v);
		else if(v > r->val)
			r->right=delnode(r->right,v);
		else if(r->left && r->right)
		{
			t=findmin(r->right);
			r->val=t->val;
			r->right=delnode(r->right,r->val);
		}
		else
		{
			t=r;
			if(r->left==NULL)
				r=r->right;
			else
				r=r->left;
			free(t);
		}
	}
	return(r);
}
void mirror(Tree *r)
{
	Tree *rt1;
	if(r->left==NULL && r->right==NULL)
		return;
	else
	{
		rt1=r->left;
		r->left=r->right;
		r->right=rt1;
		if(r->left)
			mirror(r->left);
		if(r->right)
			mirror(r->right);
	}
}
int finddepth(Tree *r, int l)
{
	static int d=0;
	if(r)
	{
		if(l>d)
			d=l;
		finddepth(r->left,l+1);
		finddepth(r->right,l+1);
	}
	return(d);
}
Tree* buildInPre(char in[], char pre[], int inst, int inend)
{
  static int prein = 0;
  int i,mind;
  Tree *tn;
  if(inst > inend)
	  return NULL;

  tn = (Tree *) malloc (sizeof(Tree));
  tn->val=pre[prein++];
  tn->left=NULL;
  tn->right=NULL;

  if(inst == inend)
	 return tn;

  for(i=inst;i<=inend;i++)
	if(in[i]==tn->val)
	{
		mind=i;
		break;
	}
  tn->left = buildInPre(in, pre, inst, mind-1);
  tn->right = buildInPre(in, pre, mind+1, inend);

  return tn;
}
Tree* buildPrePost(char pre[], char post[], int prest, int preend,
int postst, int postend)
{
  int i,premid,postmid;
  Tree *tn;
  if(prest > preend)
	  return NULL;

  tn = (Tree *) malloc (sizeof(Tree));
  tn->val=pre[prest];
  tn->left=NULL;
  tn->right=NULL;
  //prein++;
  if(prest == preend)
	 return tn;

  if(pre[prest+1]==post[postend-1])
  {
	prest=prest+1;
	postend=postend-1;
	tn->left=buildPrePost(pre,post,prest,preend,postst,postend);
  }
  else
  {
	for(i=postst;i<=postend;i++)
		if(post[i]==pre[prest+1])
		{
			postmid=i;
			break;
		}
	for(i=prest;i<=preend;i++)
		if(pre[i]==post[postend-1])
		{
			premid=i;
			break;
		}
	tn->left=buildPrePost(pre,post,prest+1,premid-1,postst,postmid);
	tn->right=buildPrePost(pre,post,premid,preend,postmid+1,postend-1);
  }
  return tn;
}
/*void topview(Tree *r,int w,int l)
{
	//int mw=w;
	if(r)
	{
		//mw=w;
		if(r->left)
			topview(r->left,w-1,l+1);
		if(abs(w)==l)
			printf("%c ",r->val);
		if(r->right)
			topview(r->right,w+1,l+1);
	}
	return;
}*/
int main()
{
	 Tree *root = NULL, *rt;
	 int n, i, choice;
	 char v;
	 char pt[40];
	 char in[]={'G','D','K','H','B','A','E','C','F'};
	 char pre[]={'A','B','D','G','H','K','C','E','F'};
	 char post[]={'G','K','H','D','B','E','F','C','A'};
	 system("cls");
	 do
	{
		system("cls");
		printf("\n----Main Menu----");
		printf("\n1:Create Tree");
		printf("\n2:Disp Tree");
		printf("\n3:Preorder");
		printf("\n4:Inorder");
		printf("\n5:Postorder");
		printf("\n6:Insert a node");
		printf("\n7:Delete a node");
		printf("\n8:Longest path");
		printf("\n9:Mirror image");
		printf("\n10:Minimum of tree");
		printf("\n11:Level order reverse");
		printf("\n12:Level order");
		printf("\n13:Form tree from in/pre");
		printf("\n14:Left view of the tree");
		printf("\n15:Exit");
		printf("\nEnter you choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nHow many nodes do you want to insert?");
				scanf("%d", &n);
				fflush(stdin);
				for(i=0; i<n; i++)
				{
					printf("Data %d: ", i+1);
					scanf("%c", &v);
					fflush(stdin);
					root = insert(root, v);
				}
				break;
			case 2:
				display(root,0);
				getch();
				break;
			case 3:
				preorderit(root);
				preorderit1(root);
				getch();
				break;
			case 4:
				//inorder(root);
				inorderit(root);
				getch();
				break;
			case 5:
				//postorder(root);
				//postorderit1(root);
				printf("\n");
				postorderit(root);
				getch();
				break;
			case 6:
				fflush(stdin);
				printf("\nEnter value to be inserted in tree:");
				scanf("%c",&v);
				root=insert(root,v);
				getch();
				break;
			case 7:
				fflush(stdin);
				printf("\nEnter value to be deleted in tree:");
				scanf("%c",&v);
				root=delnode(root,v);
				getch();
				break;
			case 8:
				longpath(root,pt,0);
				for(i=0;i<5;i++)
					printf("%s\n",pt1[i]);
				getch();
				break;
			case 9:
				mirror(root);
				getch();
				break;
			case 10:
				rt=findmin(root);
				printf("\nMinimum value:%c",rt->val);
				getch();
				break;
			case 11:
				levelorderrev(root);
				getch();
				break;
			case 12:
				levelorder(root);
				getch();
				printf("\nlevel :%d",findlevel(root));
				break;
			case 13:
				root=buildInPre(in,pre,0,8);
				display(root,0);
				getch();
				printf("\n");
			  root=NULL;
				root=buildPrePost(pre,post,0,8,0,8);
				display(root,0);
				getch();
				break;
			case 14:
				leftView(root);
				printf("\n");
				rightView(root);
				getch();
				break;
			case 15:
				printf("Good Bye");
				break;
		}
	}while(choice!=15);
	return 0;
}
