#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct hash
{
	int count;
	struct hash *head;
};

struct hash *hash_table;

int slot_count;

struct node *nn_creation(int k)
{
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=k;
	nn->next=NULL;
	return nn;
	
}

void insert_to_hash(int k);
void search(int k);

int main()
{
	int arr[50],i,n,to_search;
	printf(" Enter the number of elements: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("\n Enter slot count");
	scanf("%d",&slot_count);
	
	hash_table=(struct hash*)calloc(slot_count,sizeof(struct hash));
	for(i=0;i<n;i++)
		insert_to_hash(arr[i]);
	
	printf("\n Enter the number to be searched: ");
	scanf("%d",&to_search);
	
	search(to_search);
	
	return 0;
	
}

void insert_to_hash(int k)
{
	int info=k;
	int hash_index=k%slot_count;
	
	struct node *nn=nn_creation(info);
	
	if(hash_table[hash_index].head==NULL)
	{
		hash_table[hash_index].head=nn;
		hash_table[hash_index].count=1;
		return;
	}
	
	nn->next=(hash_table[hash_index].head);
	hash_table[hash_index].head=nn;
	hash_table[hash_index].count++;
}

void search(int k)
{
	int hash_index=k%slot_count,flag=0;
	struct node *mn;
	mn=hash_table[hash_index].head;
	
	if(mn==NULL)
	{
		printf("\n Data not present ");
		return;
	}
	while(mn!=NULL)
	{
		if(mn->data==k)
		{
			printf("\n Element is found ");
			flag=1;
			break;
		}
		mn=mn->next;
	}
	
	if(flag==0)
		printf("\n Data unavailable ");
}


