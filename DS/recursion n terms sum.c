#include<stdio.h>
int print(int n)
{
    static int sum=0;
    {

    printf("%d",n);
      sum+=n;
     n--;
    if(n!=1)
    {

    print(n);

    }

    else
    {
        printf("1");
    }
    }
 printf("\n");
  return(sum+1);

}

int main()
{
    int num=0,t;
    printf("enter the number of elements to be printed :");
    scanf("%d",&num);
    t=print(num);
    printf("%d\n",t);
}
