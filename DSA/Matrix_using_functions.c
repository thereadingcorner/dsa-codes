// a).	Find the number of non-zero elements in array
// b).	find the sum of elements above leading diagonal
// c).	display the elements below lower diagonal
// d).	find the product of the diagonal elements


#include<stdio.h>
#include<stdlib.h>

int count_elements(int arr[5][5]);
int sum_elements(int arr[5][5]);
int display_elements(int arr[5][5]);
int product_diagonals(int arr[5][5]);

int main()
{
	int arr[5][5],i,j;
	
	printf(" Enter the elements of a 3X3 matrix \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter number: ");
			scanf("%d",&arr[i][j]);
		}
	}
	
	count_elements(arr);
	sum_elements(arr);
	display_elements(arr);
	product_diagonals(arr);
	
	return 0;
	
}

int count_elements(int arr[5][5])
{
	int i,j,count=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arr[i][j]!=0)
				count++;
		}
	}
	
	printf("%d non-zero elements are present",count);
}

int sum_elements(int arr[5][5])
{
	int i,j,sum=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i>j)
				sum+=arr[i][j];
		}
	}
	printf("\n The sum of elements below the Major diagonal is: %d",sum);
}

int display_elements(int arr[5][5])
{
	int i,j;
	printf("\n The elements below the minor diagonal are: ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if((i+j)>=3)			//for minor diagonal Aij=(i+j)>N+1;
				printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int product_diagonals(int arr[5][5])
{
	int i,j,prod=1;
	printf("\n The product of the diagonal elements is: ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j || (i+j)==2)
				prod=prod*arr[i][j];
		}
	}
	printf("%d \n",prod);
}
