#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[4][6]={9,2,4,5,17,2,1,6,3,0,9,6,2,1,4,7,12,3,6,2,3,9,14,2};
    int i,j,m;
    for(i=0;i<4;i++)
    {
        for(j=0;j<6;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
int num1=0,num2=0,r=0;
int max=a[0][0];
int min=a[0][0];
for(i=0;i<4;i++)
{  max=a[i][0];
    for(j=0;j<6;j++)
    {
        num1=a[i][j];
        if(max<=num1)
           {
             max=num1;
             r=j;
           }

    }

    for(m=0;m<4;m++)
    {

        num2=a[m][r];
        if(min>num2)
            min=num2;

    }
     if(max==min)
        break;



}



if(max==min)
{
    printf("the saddle point is: %d \n",max);
}
else
    printf("saddle point not found");

}
