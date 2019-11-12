#include<stdio.h>
#include<stdlib.h>


void fill_one(int a[][], int m, int n)
{
	while(1)
	{
		flag=0;
			for(i=1;i<m-1;i++)
				for(j=1;j<n-1;j++)
					if(a[i][j]==0 && a[i-1][j]==1 && a[i+1][j]==1 && a[i][j-1]==1 && a[i]
						[j+1]==1)
						{
							a[i][j]=1;
							flag=1;
						}
					if(flag==0) break;
	}
}
