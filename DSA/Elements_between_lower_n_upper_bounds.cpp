//Find and display the number of elements between two elements lower and upper

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr,i,size,lower,upper,count=0;
	
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	
	ptr=(int*)malloc(size*sizeof(int));
	
	if(ptr==NULL)
		printf("Memory allocation failed");
	else
	{
		printf("Enter the array elements: ");
		for(i=0;i<size;i++)
		{
			printf("Enter number: ");
			scanf("%d",(ptr+i));
		}
		
		printf("Enter the lower and upper bounds: ");
		scanf("%d %d",&lower,&upper);
		
		for(i=0;i<size;i++)
		{
			if(*(ptr+i)>=lower && *(ptr+i)<=upper)
			{
				printf("%d",*(ptr+i));
				count++;
			}
		}
		printf("%d Elements between lower and upper bound",count);
	}
	return 0;
}
