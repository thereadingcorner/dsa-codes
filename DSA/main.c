#include <stdio.h>
#include <stdlib.h>

struct t
{   int val;
    struct t *right;
    struct t *left;
};
typedef struct t tree;
tree * insert(tree *r,int val)
{
    if(r==NULL)
    {
        r=(tree*)malloc(sizeof(tree));
        r->val=val;
        r->right=r->left=NULL;
        printf("inserted successfully\n");
    }
    else if(val<r->val)
        r->left=insert(r->left,val);
    else r->right=insert(r->right,val);
    return r;
}
void display(tree *r,int level)
{
    if(r)
    {
        display(r->right,level+1);
        for(int i=0;i<=level;i++)
            printf("  ");
        printf("%d\n",r->val);
        display(r->left,level+1);
    }
}
tree * minnode(tree *r)
{
    if(r==NULL)
    {
        printf("Invalid\n");
        return r;
    }
    while(r->left)
        r=r->left;
    return r;
}
tree * deletee(tree *r,int val)
{
    if(r==NULL)
    {
        printf("Element not present\n");
        return r;
    }
    else if(val<r->val)
        r->left=deletee(r->left,val);
    else if(val>r->val)
        deletee(r->right,val);
    else if(r->right &&r->left)
    {
        tree *t=minnode(r->right);
        r->val=t->val;
        r->right=deletee(r->right,r->val);
    }
    else
    {
        tree *t=r;
        if(r->right)
            r=r->right;
        else r=r->left;
        free(t);

    }
    return r;
}
void inorder(tree *r)
{
    if(r)
    {
        inorder(r->left);
        printf("%d ",r->val);
        inorder(r->right);
    }

}
void preorder(tree *r)
{
    if(r)
    {
        printf("%d ",r->val);
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(tree *r)
{
    if(r)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->val);
    }
}
void mirror(tree *r)
{
    if(r)
    {
        tree *t=r;
        t=r->left;
        r->left=r->right;
        r->right=t;
        if(r->left)
        mirror(r->left);
        if(r->right)
            mirror(r->right);
    }
}
void levelorder(tree *r)
{
    tree * arr[20],*t;
    int rear=-1,front=0;
    arr[++rear]=r;
    while(front<=rear)
    {
        t=arr[front++];
        printf("%d  ",t->val);
        if(t->left)
            arr[++rear]=t->left;
        if(t->right)
            arr[++rear]=t->right;
    }
}
int height(tree *r)
{
    tree *arr[20],*t;
    int front=0,rear=-1,lvl=-1;
    arr[++rear]=r;
    arr[++rear]=NULL;
    while(front<=rear)
    {
        t=arr[front++];
        if(t==NULL)
        {
            lvl++;
            if(front<=rear)
                arr[++rear]=NULL;
        }
        else{ if(t->left)
            arr[++rear]=t->left;
            if(t->right)
            arr[++rear]=t->right;
    }
    }
    printf("height of tree is %d\n",lvl);
}
int heightr(tree *r,int lvl)   ///Provide a value of -1 at the function call
{
    static int level=-1;
    if(r==NULL && lvl>level)
        level=lvl;
    if(r)
    {
        //if(r->left)
        heightr(r->left,lvl+1);
        //if(r->right)
        heightr(r->right,lvl+1);

    }
    return level;
}
int main()
{  tree *root=(tree*)malloc(sizeof(tree));
    root=NULL;
    root=insert(root,3);
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,8);
    root=insert(root,5);
    root=insert(root,9);
    display(root,0);
    printf("\n");
    //root=deletee(root,3);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    mirror(root);
    display(root,0);
    printf("\n");
    levelorder(root);
    printf("\n");
    height(root);
    printf("height of tree is %d\n",heightr(root,-1));
    //display(root,0);

    return 0;
}
