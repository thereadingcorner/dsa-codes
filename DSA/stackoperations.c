#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 3

int stack[MAX],top=-1;
void push(int stack[],int val);
int pop(int stack[]);
int peek(int stack[]);

int main()
{
	int val,option;
	do{
		printf("\n********MENU********");
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Peek");
		printf("\n4.Display");
		printf("\n5.Exit");
		printf("\n Enter your option:");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
					printf("Enter the number to be pushed on stack");
					scanf("%d",&val);
					push(stack,val);
					break;
			case 2:
					val=pop(stack);
					if(val!=-1)
					printf("The value deleted from stack is:%d",val);
					break;
			case 3:
					val=peek(stack);
					if(val!=-1)
					printf("\nThe value stored at the top of stack is:%d",val);
					break;
			case 4:
					display(stack);
					break;
		}
	}while(option!=5);
	return 0;
}
void push(int stack[],int val)
{
	if(top==MAX-1)
		printf("\nSTACK OVERFLOW");
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	int val;
	if(top==-1)
	{
		printf("\nSTACK UNDERFLOW");
		return -1;
	}
	else
	{
		val=stack[top];
		top--;
		return val;
	}
}
void display(int stack[])
{
	int i;
	if(top==-1)
	printf("Stack Is Empty");
	else
	{
		for(i=top;i>=0;i--)
		printf("\n %d",stack[i]);
		printf("\n");
	}
}
int peek(int stack[])
{
	if(top==-1)
	{
		printf("Stack is Empty");
		return -1;
	}
	else
	return(stack[top]);
}
