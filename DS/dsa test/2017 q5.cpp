#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
	int info;
	struct List *prev;
	struct List *next;
	
}NODE;



NODE *ptr;
for(ptr=start; ptr!=NULL; ptr=ptr->next);
ptr->next=start;
start->prev=ptr;
