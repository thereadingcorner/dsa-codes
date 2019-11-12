#include<stdio.h>
#include<stdlib.h>
int slots;

struct node
{
	int data;
	struct node *next;
};

struct hash
{
	struct node *head;
	int count;
};
struct hash *hashtable;

struct node *create(int k)
{
	struct node *nn = (struct node *) malloc(sizeof(struct node));
	nn->data = k;
	nn->next = NULL;
	return nn;
}

int hash_index(int k)
{
	int sum =0;
	while(k!=0)
	{
		sum+= k%10;
		k/=10;
	}
	return (sum%slots);
}

void insert(int k)
{
	struct node *nn = create(k);
	if(hashtable[hash_index(k)].head == NULL)
	{
		hashtable[hash_index(k)].head = nn;
		hashtable[hash_index(k)].count++;
		return;
	}
	nn->next = hashtable[hash_index(k)].head;
	hashtable[hash_index(k)].head = nn;
	hashtable[hash_index(k)].count++;
}

void display()
{	
	int i;
	for(i = 0; i<slots; i++)
	{
		printf("\n%d:\t", i);
		struct node *ptr = hashtable[i].head;
		while(ptr!=NULL)
		{
			printf("%d, ", ptr->data);	
			ptr = ptr->next;
		}
	}
}

void search(int k)
{
	struct node *ptr = hashtable[hash_index(k)].head;
	int i=0;
	while(ptr!=NULL)
	{
		if(ptr->data == k)
		{
			printf("%d found at slot-%d position %d", k, hash_index(k), i);
			return;
		}
		i++;
		ptr = ptr->next;
	}
	printf("%d NOT found", k);
}

void main()
{
	printf("\nEnter number of slots: ");
	scanf("%d", &slots);
	hashtable = (struct hash *)calloc(slots,sizeof(struct hash));
	int ch, val;
	printf("\n1.Insert\n2.Display\n3.Search\n4.Exit");
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\nEnter value: ");
				  scanf("%d", &val);
				  if(val<0)
				  {
				  	do
				  	{
				  		printf("\nEnter a positive number: ");
				  		scanf("%d", &val);
				  	}while(val<0);
				  }
				  insert(val);
				  break;
			case 2: display();
				  break;
			case 3: printf("\nEnter value to be searched: ");
				  scanf("%d", &val);
				  search(val);
				  break;
			case 4: printf("\nExit");
				  break;
			default: printf("\nWrong Input");
		}
	}while(ch!=4);
}
