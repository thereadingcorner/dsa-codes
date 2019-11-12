#include<stdio.h>
int print(int n)
{
    if(n!=0)
    {
        print(n-1);
        printf("%d%d",n,n);
    }
    /* n--;
    if(n!=1)
    {

    print(n);
    {
        printf("%d",n);
    }

    }

    else
    {
        printf("%d",n);
    }

  printf("%d",n);*/
}

int main()
{
    int num=0,t;
    printf("enter the number of elements to be printed :");
    scanf("%d",&num);
    print(num);

}

