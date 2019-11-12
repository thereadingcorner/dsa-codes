//print next greatest number NGE

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr,i,j,temp,temp2,n;
	
	printf(" Enter the number of elements: ");
	scanf("%d",&n);
	
	ptr=(int*)malloc(n*sizeof(int));
	
	if(ptr==NULL)
		printf(" Memory allocation failed");
	else
	{
		printf("\n Enter the array elements: \n");
		for(i=0;i<n;i++)
		{
			printf("Enter number: ");
			scanf("%d",(ptr+i));
		}
		
		printf("\n Element \t NGE \n");
		for(i=0;i<n;i++)
		{
			temp=*(ptr+i);
			for(j=i+1;j<n;j++)
			{
				if(*(ptr+j)>temp)
				{
					temp2=*(ptr+j);
					break;
				}
				else if(temp==*(ptr+j))
				{
					temp2=-1;
					break;
				}
				else 
					temp2=-1;
			}
		if(i==n-1)
			temp2=-1;
		printf(" %d \t\t %d \n",temp,temp2);
		}
	}
	return 0;
}
