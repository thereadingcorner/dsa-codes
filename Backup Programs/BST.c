#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node* left;
  int data;
  struct node* right;
};

struct node* root=NULL;

struct node* createNode(int k)
{
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->left=NULL;
  new_node->right=NULL;
  new_node->data=k;
  return new_node;
}
struct node* insert(struct node* root,int k)
{
  if(root==NULL)
  return createNode(k);
  else if(k<root->data)
  root->left=insert(root->left,k);
  else if(k>root->data)
  root->right=insert(root->right,k);
  return root;
}
void inorder(struct node* root)
{
  if(root!=NULL)
  {
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
  }
}

int main()
{
  int k;
  scanf("%d", &k);
  root=insert(root,k);
  for(int a=0;a<6;a++)
  {
    scanf("%d", &k);
    insert(root,k);
  }
  inorder(root);
}
