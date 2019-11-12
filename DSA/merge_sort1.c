#include<stdio.h>
#define size 100

void merge_sort(int[],int,int);
void merge(int[],int,int,int);

void main()
{
	int arr[size],n,i;
	
	printf(" Enter the number of elements in the array: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf(" Enter number: ");
		scanf("%d",&arr[i]);
	}
	
	printf(" The given array is: ");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	
	merge_sort(arr,0,n-1);
	
	printf(" The sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	
}

void merge_sort(int arr[],int beg,int end)
{
	int mid;
	while(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(arr,beg,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}

void merge(int arr[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,k,index=beg,temp[size];
	
	while(i<=mid && j<=end)
	{
		if(arr[i] < arr[j])
		{
			temp[index]=arr[i];
			i++;
		}
		else
		{
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=arr[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
		arr[k]=temp[k];
}

