#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE]={NULL};

void insert()
{
	int key,index,i,flag=0,hash_index;
	printf("\n Enter a value to be inserted: \n");
	scanf("%d",&key);
	
	hash_index=key%TABLE_SIZE;
	
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(hash_index+i)%TABLE_SIZE;
		
		if(h[index]==NULL)
		{
			h[index]=key;
			break;
		}
	}
	if(i==TABLE_SIZE)
		printf("\n Cannot be inserted ");
	
}

void search()
{
	int key,index,i,flag=0,hash_index;
	printf("\n Enter element to search: ");
	scanf("%d",&key);
	
	hash_index=key%TABLE_SIZE;
	
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(hash_index+i)%TABLE_SIZE;
		
		if(h[index]==key)
		{
			printf(" Value is found at index %d ",index);
			break;
		}
	}
	if(i==TABLE_SIZE)
		printf("\n Element not found ");
}

int main()
{
	insert();
	search();
	return 0;
}
