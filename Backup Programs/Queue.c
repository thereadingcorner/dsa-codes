#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  int size;
  int capacity;
  int array[capacity];
  int front,rear;
}


struct Queue* create(int c)
{
  struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
  q->size=0;
  q->capacity=c;
  q->front=0;
  q->rear=q->capacity-1;
  return q;
}

int isFull(struct Queue* q)
{
  if(q->size==q->capacity)
  return 1;
  else
  return 0;
}

int isEmpty(struct Queue* q)
{
  if(q->size==0)
  return 1;
  else
  return 0;
}


void enqueue(struct Queue* q,int d)
{
  if(isFull(q)==1)
  {
    printf("Overflow");
    return;
  }
  q->rear=(q->rear+1)%(q->capacity+1);
  q->array[q->rear]=d;
  q->size++;
}
void dequeue(struct Queue* q)
{
  if(isEmpty(q)==1)
  {
  printf("Underflow");
  return;
  }
  q->front=(q->front+1)%(q->capacity+1);
  q->size--;
}
