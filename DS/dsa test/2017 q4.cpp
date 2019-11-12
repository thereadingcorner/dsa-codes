#include<stdio.h>
#include<stdlib.h>

struct node // Node definition
{
	int data;
	struct node *next;
}; // head_ref is the variable pointing to 1st node.

void delete(struct node *head_ref, int itemToDelete)
{
// Store head node
	struct node *temp = head_ref;
	struct node *prev = NULL;
// If head node itself holds the key to be deleted
	if (temp != NULL && temp->data == key)
	{
		head_ref = temp->next; // Changed head
		free(temp); // free old head
		return;
	}
// Search for the key to be deleted, keep track of the
// previous node as we need to change 'prev->next'
	while (temp != NULL && temp->data != itemToDelete)
	{
		prev = temp;
		temp = temp->next;
	}
// If key was not present in linked list
	if (temp == NULL) 
	
	return;
// Unlink the node from linked list
	prev->next = temp->next;
	free(temp);
	 // Free memory of the node matching the data
	temp = head_ref;
// Traverse till one node before previous node
	while (temp != NULL && temp->next != prev)
	{
		temp = temp->next;
	}
	if (temp->next = = NULL)
		return;
		
	temp -> next = prev -> next;
		free(prev); // Free memory of the previous node
}

