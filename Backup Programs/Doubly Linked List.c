#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node* prev;
  int data;
  struct node* next;
};
struct node* head=NULL;

struct node* create(struct node* head)
{
  struct node* ptr=NULL;
  for(int a=0;a<5;a++)
  {
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=rand()%21;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(head==NULL)
    {
      head=new_node;
      ptr=head;
    }
    else
    {
      ptr->next=new_node;
      ptr->next->prev=ptr;
      ptr=new_node;
    }
  }
  return head;
}

void display(struct node* head)
{
  struct node* ptr=head;
  while(ptr!=NULL)
  {
  printf("%d ", ptr->data);
  ptr=ptr->next;
  }
}

int main()
{
  head=create(head);
  display(head);
}
