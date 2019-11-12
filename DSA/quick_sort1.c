#include<stdio.h>
#include<stdlib.h>
#define size 100
void quick_sort(int [],int,int);

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
	
	quick_sort(arr,0,n-1);
	
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}

quick_sort(int arr[],int first,int last)
{
	int low,high,temp,mid;
	mid=arr[(first+last)/2];
	
	low=first;
	high=last;
	
	do
	{
	while(mid>arr[low])
		low++;
	while(mid<arr[high])
		high--;
		
	if(low<=high)
	{
		temp=arr[low];
		arr[high]=arr[low];
		arr[high]=temp;
		low++;
		high--;
	}
	}while(low<=high);
	
	if(low<last)
		quick_sort(arr,low,last);
	
	if(high>first)
		quick_sort(arr,first,high);
	
	return;
}
