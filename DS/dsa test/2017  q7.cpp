#include<stdio.h>
#include<stdlib.h>

// reverse the data elements between tow indexes
void reverse(int a[],int low, int up)
{
	int tmp;
	
	while(low<up)
	{
		tmp=a[low];
		a[low]=a[up];
		a[up]=tmp;
		low++;
		up--;
	}
}



void format(int a[], int n)
{
	int i,j,order=-1;
	i=0;
	
	for(j=0; j<n-1; )
	{
		if(order==-1)
			order=(a[j] > a[j+1])?1:0;
		if((a[j] <= a[j+1] && order==0) || (a[j]>a[j+1] && order==1))
		{
			j++;
		}
		else if((a[j] <= a[j+1] && order==1) || (a[j]>a[j+1] && order==0))
		{
			reverse(a,i,j);
				j++;
				i=j;
				order=-1;
		}
	}
		if(i<j)
		reverse(a,i,j);
}

