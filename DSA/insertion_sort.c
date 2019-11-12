#include<stdio.h>
#include<stdlib.h>
#define size 100

void insertion_sort(int [],int);

void main()
{
	int arr[size],i,n;
	
	printf(" Enter the number of elements in the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf(" Enter number: ");
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
		
	insertion_sort(arr,n);
	
	
}

void insertion_sort(int arr[],int n)
{
	int i,item,j;
	
	for(i=0;i<n;i++)
	{
		item=arr[i+1];
		for(j=i;j>=0 && item<arr[i];j--)
			arr[j+1]=arr[j];
	
	arr[j+1]=item;
	}
	
		for(i=0;i<n;i++)
		printf("\n %d\t",arr[i]);
	

}


