#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr,i,j,size,temp;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	
	ptr=(int*)malloc(size*sizeof(int));
	
	printf("Enter the elements of the array \n");
	for(i=0;i<size;i++)
	{
		printf("Enter numbers: ");
		scanf("%d",(ptr+i));
	}
	
	for(i=0;i<size;i++)
	{	
		for(j=i+1;j<size;j++)
		{
			if(*(ptr+j)>*(ptr+i))
			{
				temp=*(ptr+j);
				break;
			}
			else if (*(ptr+j)==*(ptr+i))
			{
				temp==-1;
				break;
			}
			else
			{
				temp=-1;
			}
		}

	if(i==size-1)
		temp=-1;
		
	*(ptr+i)=temp;
	}
	
	for(i=0;i<size;i++)
		printf("%2d \n",*(ptr+i));
}
