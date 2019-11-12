#include<stdio.h>
int fact(int n)
{
   static int nu=1;
   {
    if(n!=0)
    {
        printf("%d",n);

            nu=nu*n;

        fact(n-1);

    }
   }
   printf("\n");
   return(nu);
}
int main()
{
    int num=0,t;
    printf("enter the number:");
    scanf("%d",&num);
    printf("%d",fact(num));
}
