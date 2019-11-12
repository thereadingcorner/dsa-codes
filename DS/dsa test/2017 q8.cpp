#include<stdio.h>
#include<stdlib.h>
#define N 10

struct stack
{
	int stackContainer[N];
	int top;
};

void push(struct stack s, int element)
{
	int n;
	if (s.top==n-1)
	{
		printf("Overflow");
		return;
	}
		s. stackContainer[s. top++] = element;
}

int pop(struct stack s)
{
	if (s.top==-1)
	{
		printf("Underflow");
		return -1;
	}
	
		return s.stackContainer[s.top--];
}

