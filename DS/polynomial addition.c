#include<stdio.h>
#include<stdlib.h>
struct poly
{
 int coff;
 int exp;
 struct poly* next;
};
void create(struct poly** h)
{
    struct poly *curr,*ptr;
    printf("Enter the degree of the polynomial:");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num1,num2;
        curr=(struct poly*)malloc(sizeof(struct poly));
        scanf("%d%d",&num1,&num2);
        curr->coff=num1;
        curr->exp=num2;
        curr->next=NULL;
        if(*h==NULL)
        {
            *h=curr=ptr;
        }
        else
        {
            ptr->next=curr;
            ptr=curr;
        }
    }

}



void join(struct poly** h1,struct poly *h2)
{
    struct poly *ptr;
    if(*h1==NULL);
    {
        *h1=h2;
    }
    for(ptr=*h1;ptr->next!=NULL;ptr=ptr->next)
    {
        ptr->next=h2;
    }
}

void simplify(struct poly*h)
{
    struct poly* ptr,*ptr1,*pv;
    ptr=h;

    while(ptr!=NULL)
    {
        pv=ptr;
        ptr1=ptr->next;

        while(ptr1!=NULL)
        {
            if(ptr->exp=ptr1->exp)
            {
                ptr->coff+=ptr1->coff;
                pv->next=ptr1->next;

                free(ptr1);
                ptr1=pv->next;
            }
            else
            {
                pv=ptr;
                ptr1=ptr->next;
            }
        }
    }
}
int main()
{
    struct poly* h1=NULL;
    struct poly* h2=NULL;

    create(&h1);
    create(&h2);
    join(&h1,h2);
    simplify(h1);
}
