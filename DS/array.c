#include<stdio.h>
#include<stdlib.h>
int search(int* a,int n,int num)
{
    int flag=0,i;
 for(i=0;i<n;i++)
 {
     if(num==a[i]){
        flag++;
        break;
     }
 }
    if(flag==0){
        printf("the element not found!");
        return(-1);
     }
     else
     {
        printf("the element is found! position is :\n");
        return(i+1);
     }
 }


int main()
{
    int n=0,t;
    printf("enter the number of elements to be inserted in the array :");
    scanf("%d",&n);
    int* arr;
    arr=(int *)malloc(n*sizeof(int));
    for(int j=0;j<n;j++)
    {
        *(arr+j)=rand()%11;
    }
     for(int j=0;j<n;j++)
    {
        printf("the elements of the array are :%d\n",*(arr+j));
    }
    printf("%d",search(arr,n,5));
    return 0;
}
