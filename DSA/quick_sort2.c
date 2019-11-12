#include<stdio.h>
#define MAX 5

void quick(int a[],int,int);
void main()
{
	int i,j,a[MAX];
	printf(" Enter number: ");
	
	for(i=0;i<MAX;i++)
		scanf("%d",&a[i]);
		
	quick(a,0,MAX-1);
	
	for(i=0;i<MAX;i++)
		printf("%5d",a[i]);
	getch();
}

void quick(int a[],int first,int last)
{
	int low,high,mid,temp;
	mid=a[(first+last)/2];
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
		quick(a,low,last);
	if(first<high)
		quick(a,first,high);
	
	return;
}
