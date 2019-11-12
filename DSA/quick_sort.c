#include<stdio.h>
#define MAX 5

void quick_sort(int[],int,int);

void main()
{
	int i,j,a[MAX];
	
	for(i=0;i<MAX;i++)
	{
		printf(" Enter number: ");
		scanf("%d",&a[i]);
	}
	
	quick_sort(a,0,MAX-1);
}

void quick_sort(int a[],int first,int last)
{
	int low,high,mid,temp;
	mid=a[(low+high)/2];
	
	low=first;
	high=last;
	
	do
	{
		while(mid>a[low])
			low++;
		while(mid<a[high])
			high--;
		
		if(low<=high)
		{
			temp=a[low];
			a[low]=a[high];
			a[high]=temp;
			
			low++;
			high--;
		}
	}while(low<=high);
	
	if(low<last)
		quick_sort(a,low,last);
	if(first<high)
		quick_sort(a,first,high);
	
	int  i;
	for(i=0;i<MAX;i++)
		printf("%5d",a[i]);

}
