//Print even number first then the odd numbers in array

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr,size,i;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	
	ptr=(int*)malloc(size*sizeof(int));
	
	if(ptr==NULL)
		printf("Memmory allocation failed");
	else
	{
		printf("Enter the array elements: \n");
		for(i=0;i<size;i++)
		{
			printf("Enter number: ");
			scanf("%d",(ptr+i));
		}
		
		for(i=0;i<size;i++)
		{
			if(*(ptr+i)%2==0)
				printf("%d",*(ptr+i));
		}
		
		for(i=0;i<size;i++)
		{
			if(*(ptr+i)%2!=0)
				printf("%d",*(ptr+i));
		}
	}
	return 0;
}
