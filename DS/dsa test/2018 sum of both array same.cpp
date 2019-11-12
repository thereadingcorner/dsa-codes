#include<stdio.h>
#include<stdlib.h>

void sort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j]>arr[i])
			{
				int swap=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=swap;
			}
		}
	}
}

void findpair(int a[],int n,int b[],int m)
{
	int sum1=0,sum2=0,i=0,j=0;
	for(int i=0;i<n;i++)
	sum1+=a[i];
	
	for(int i=0;i<n;i++)
	sum2+=b[i];
	
	int sum=(sum1-sum2)/2;
	
	sort(a,n);
	sort(b,m);
	
	if(sum==0)
	return;
	
	while(i<n&&j<m)
	{
		if(a[i]-b[j]==sum)
		{
			printf("%d from a and %d from b are the pairs",a[i],b[j]);
			return;
		}
		else if(a[i]-b[j]<sum)
		i++;
		else
		j++;
		
	}
	printf("no such pairs!");
	return;
}


int main()
{
	int a[]={3,2,10,12};
	int b[]={6,4,9,10};
	findpair(a,sizeof(a)/sizeof(a[0]),b,sizeof(b)/sizeof(b[0]));
	return 0;
}
