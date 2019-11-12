#include<stdio.h>
#include<stdlib.h>
#define SIZE 25 //size can be any number


struct Stack
{
	int top;
	int s[SIZE];
};


int isEmpty(struct Stack st)
{
	return (st.top == -1);
}


int pop(struct Stack st)
{
	if (isEmpty(st))
	
		return INT_MIN;
		return st.s[st.top--];
}


void push(struct Stack st, int x)
{
	if (st.top == SIZE-1)
	
	return;
	
	st.s[++st.top] = x;
}

int peek(struct Stack st)
{
	return st.s[st.top];
}
