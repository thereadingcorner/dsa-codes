#include<stdio.h>
#include<stdlib.h>
    struct node
    {
        int data;
        struct node* next;

    };


    void display(struct node*h)
    {
        struct node* ptr=h;
        if(ptr==NULL)
        {
            printf("no element present!");

        }
        else
        {
            while(ptr->next!=h)
            {
                printf("%d\t",ptr->data);
                ptr=ptr->next;
            }
            printf("%d",ptr->data);
        }
    }

    int main()
    {
        struct node* head=NULL,*curr,*ptr;
        int n,num;

        printf("enter tne number of nodes to be inserted in the list:\n");
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            curr=(struct node*)malloc(sizeof(struct node) );

            printf("enter the data to be inserted in the node:");
            scanf("%d",&num);

            curr->data=num;
            curr->next=NULL;

              if(head==NULL)
              {
                 head=curr;
                 curr->next=head;
                 ptr=head;
              }
              else
              {
                  curr->next=head;
                  ptr->next=curr;
                  ptr=curr;
              }
        }
        display(head);
    }

