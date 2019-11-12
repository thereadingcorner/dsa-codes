#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE]={NULL};

void insert()
{
	int key,i,index,flag=0,hash_index;
	printf(" Enter number to be inserted: ");
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
	int key,i,index,flag=0,hash_index;
	printf(" Enter the number to be searched: ");
	scanf("%d",&key);
	
	hash_index=key%TABLE_SIZE;
	
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(hash_index+i)%TABLE_SIZE;
		
		if(h[index]==key)
		{
			printf(" Element found at %d",index);
			break;
		}
	}
	if(i==TABLE_SIZE)
		printf(" Element not present ");
}

int main()
{
	insert();
	search();
}
