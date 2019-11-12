#include<stdio.h>
int binsearch(int arr[],int n,int key)
{
    int l=1,h=n;
    int mid=0;
    if(l<=h)
    {

    while(l<=h)

   {

    mid=(l+h)/2;
    if(key==arr[mid])
    {
        return(mid);
    }
    else if(key<arr[mid])
    {
        h=mid-1;
    }
    else
    {
        l=mid+1;
    }
    }
    }
    else
    {

        printf("element not found!\n");
         return 0;
    }
}
int main()
{
    int n;


    printf("enter the number of elements in the array:\n");
    scanf("%d",&n);
     int arr[n];
    for(int i=0;i<n;i++)
    {
         int num;
       scanf("%d",&num);
        arr[i]=num;
    }
    for(int i=0;i<n;i++)
    {
        printf("the elements of the array are:\t%d\n",arr[i]);
    }
     int t;
   t=binsearch(arr,n,5);
    printf("the position of the element is:\n%d",t);

    return 0;
}
