#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
};

struct node* head=NULL;

struct node* create(struct node* h)
{
  struct node* ptr=NULL;
  for(int a=1;a<=5;a++)
  {
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    scanf("%d", &(new_node->data));
    new_node->next=NULL;
    if(h==NULL)
    {
    h=new_node;
    ptr=h;
    }
    else
    {
      ptr->next=new_node;
      ptr=new_node;
    }
  }
  return h;
}


void display(struct node* h)
{
  struct node* ptr=h;
  if(h==NULL)
  printf("Linked List Deleted");
  else
  {
    while(ptr!=NULL)
    {
      printf("%d ", ptr->data);
      ptr=ptr->next;
    }
  }
  printf("\n");
}

void reversePrint(struct node* h)
{
  if(h==NULL)
  return;
  else
  reversePrint(h->next);
  printf("%d ", h->data);
}

void deleteLinkedList(struct node* h)
{
  if(h==NULL)
  return;
  deleteLinkedList(h->next);
  free(h);
}

/*int isPalindrome(struct node* h,struct node* ptr_end)
{
  struct node* ptr=NULL;
  for(ptr=h;ptr->next!=ptr_end;ptr=ptr->next);
  if(h->data!=ptr_end->data)
  return -1;
  if(h==NULL && ptr_end==NULL || h==ptr_end)
  return isPalindrome(h->next,ptr); */


//}

int main()
{
  head=create(head);
  display(head);
  //reversePrint(head);
  //deleteLinkedList(head);
  //printf("Linked List Deleted\n");
  //struct node* ptr=NULL;
  //for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
  //isPalindrome(head,ptr);
}
