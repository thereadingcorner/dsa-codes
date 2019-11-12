#include<stdio.h>
#include<stdlib.h>
#define MAX 6

struct STACK
{
	int a[MAX];
	int top;
}s[2];

int push(STACK *s,int v)
{
	if(s->top==(MAX-1))
	{
		printf("stack underflow!");
		return -1;
	}
	else
	{ 
		s->top=s->top+1;
		s->a[s->top]=v;
	}
	return 0; 
}

int pop(STACK *s,int *dv)
{
	if(s->top==-1)
	{
		printf("stack overflow!");
		return -1;
	}
	else
	{
		*dv=s->a[s->top];
		s->top--;
	}
	return 0;
}

bool isempty(STACK *s)
{
	if(s->top==-1)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

int copystack(STACK *s1,STACK *s2)
{
	int b;
	if(isempty(s1))
	{
		return -1;
	}
	pop(s1,&b);
	copystack(s1,s2);
	push(s2,b);
	
	return 0;
}

void  display(STACK *s)
{
	int b;
	/*if(isempty(s))
	{
		printf("the stack is empty!");
	}*/
	pop(s,&b);
	if(s->top!=-1)
	{
		display(s);
		
	}
	printf("the elements of the stack are:\n%d",b);
	printf(" \n");
	
}


int main()
{
	struct STACK *s1,*s2;
	s1=&s[0];
	s2=&s[1];
	int n;
	s[0].top=-1;
	s[1].top=-1;
	for(int i=0;i<MAX;i++)
	{
		printf("enter the elements:");
		scanf("%d",&n);
		push(s1,n);
	}
	//display(s1);
    copystack(s1,s2);
    //display(s1);
    display(s2);
    
    return 0;
}
