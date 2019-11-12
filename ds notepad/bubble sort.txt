#include<stdio.h>

    void swap(int* x,int* y)
    {
        int temp=*x;
        *x=*y;
        *y=temp;
    }

    void bubble_sort(int arr[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(&arr[j],&arr[j+1]);
                }
            }
        }
    }

    void display(int a[],int n)
    {

        for(int i=0;i<n;i++)
        {

            printf("%d\t",a[i]);
        }
    }

    void main()
    {
        int n=0;
        printf("enter the number of elements to be inserted in the array:");
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        bubble_sort(arr,n);
        printf("the sorted array is :");

        display(arr,n);

    }

