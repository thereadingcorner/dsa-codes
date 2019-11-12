// Program to sort an array of n integers

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr,size,i,j,temp;
	
	printf("Enter the size of the array");
	scanf("%d",&size);
	
	ptr=(int*)malloc(size*sizeof(int));
	
	if(ptr==0)
		printf("Memory allocation failed");
	else
	{
		printf("Enter the array elements");
		for(i=0;i<size;i++)
		{
			printf("Enter number: ");
			scanf("%d",(ptr+i));
		}
		
		printf("The sorted array is: ");
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(*(ptr+i)>=*(ptr+j))
				{
				temp=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=temp;
				}
			}
		}
		for(i=0;i<size;i++)
			printf("%d",*(ptr+i));
	}
	return 0;
}
