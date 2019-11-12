#include <stdio.h>
#include <stdlib.h>

void swap(int *xp,int *yp)
{
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}

bubble_sort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}


void print_array(int arr[],int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		printf("%d\n",arr[i]);
	}
}

int main()
{
	int a[4]={1,3,5,8};
	int b[8]={2,4,6,9};
	int i;
	
		for(i=0;i<4;i++)
		{
			b[4+i]=a[i];
		}
		
	print_array(b,8);	
	bubble_sort(b,8);
	printf("the sorted array is:\n");
	print_array(b,8);
	return 0;
}
