#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr,*ptr1,i,size,prev,next,temp;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	
	ptr=(int*)malloc(size*sizeof(int));
	ptr1=(int*)malloc(size*sizeof(int));
	
	for(i=0;i<size;i++)
	{
		printf("Enter number: ");
		scanf("%d",(ptr+i));
	}
	
	for(i=0;i<size;i++)
	{
		if(i==0)
			temp=*(ptr+i) * (*(ptr+(i+1)));
		else if(i==size-1)
			temp=*(ptr+(i-1)) * (*(ptr+i));
		else
			temp=*(ptr+(i-1)) * (*(ptr+i)) * (*(ptr+(i+1)));
		
		*(ptr1+i)=temp;
 	}
 	
	for(i=0;i<size;i++)
		*(ptr+i)=*(ptr1+i);
	
	for(i=0;i<size;i++)
		printf("%d \n",*(ptr+i));
}
