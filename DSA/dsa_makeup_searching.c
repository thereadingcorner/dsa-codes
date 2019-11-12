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
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=k;
	nn->next=NULL;
	return;
}

void insert_to_hash(int k);
void search(int k);
void display();

void main()
{
    int opt,i,key,to_search;
    
    printf(" Enter the slot count ");
        scanf("%d",&slot_count);
    
    hash_table=(struct hash*)malloc(slot_count*sizeof(struct hash));
    
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        scanf("%d",&opt);
        
        switch(opt)
        {
            case 1:
            	
            	printf("Enter the number to be inserted: ");
            	scanf("%d",&key);
    			
                insert_to_hash(key);
                break;
                
            case 2:
                display();
                break;

            case 3:
            	printf(" Enter the element to be searched: ");
            	scanf("%d",&to_search);
                search(to_search);
                break;
            case 4:exit(0);
        }
    }
}

void insert_to_hash(int k)
{
	int info=k;
	int hash_index;

	hash_index=hash_func(info);
	
	struct node *nn=nn_creation(info);
	
	if(hash_table[hash_index].head==NULL)
	{
		hash_table[hash_index].head=nn;
		hash_table[hash_index].count=1;
		return;
	}
	
	nn->next=hash_table[hash_index].head;
	hash_table[hash_index].head=nn;
	hash_table[hash_index].count++;
	
}

void search(int k)
{
	int info=k,flag=0;
	int hash_index;
	hash_index=hash_func(info);
	
	struct node *mn;
	mn=hash_table[hash_index].head;
	
	if(mn==NULL)
	{
		printf(" Element not found");
		return;
	}
	while(mn!=NULL)
	{
		if(mn->data==info)
		{
			printf(" Element found at %d slot at %d position \n",hash_index,hash_table[hash_index].count);
			flag=1;
			break;
		}
		mn=mn->next;
	}
	if(flag==0)
		printf(" Element not found");
}

void display()
{	
	int i;
	
	for(i = 0; i<slot_count ; i++)
	{
		printf("\n%d:\t", i);
		struct node *ptr = hash_table[i].head;
		while(ptr!=NULL)
		{
			printf("%d, ", ptr->data);	
			ptr = ptr->next;
		}
	}
}

int hash_func(int k)
{	
	int sum,index,info=k;
	sum=sum_of_digits(info);
	
	index=sum%slot_count;

	return index;
	
}

int sum_of_digits(int k)
{
	int rem,sum=0;
	while(k!=0)
	{
		rem=k%10;
		sum+=rem;
		k=k/10;
	}
	return sum;
}
