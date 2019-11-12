#include <stdio.h>
#include <stdlib.h>

struct array_list
{
  int arr[5];
  int no;
}l;

void display()
{
    for(int i=0;i<5;i++)
    {
        printf("the values of the array are: %d",l.arr[i]);
    }
}


int insert(int v)

{
    if(l.no==5)
    {
         return(-1);
    }
    else
       {

        l.arr[l.no]=v;
        l.no++;
       }
        return(l.no);

}

int insert_at_point(int pos,int v)
{
if(pos==5)
{
    printf("the array is full!");
}
else if(pos>5)
{
    printf("invalid position!");
}
else if(l.no<=pos)
{

   int i=0;
   for(i=3;i>=l.no;i--)
   {
       l.arr[i+1]=l.arr[i];

   }
l.arr[l.no]=v;
}
l.no++;
return(l.no);
}

int main()
{
    l.no=0;
    int i=insert(5);
    int j=insert_at_point(4,1);

    display();
    printf("%d",i);
    printf("%d",j);

}
