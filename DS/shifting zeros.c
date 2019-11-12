#include<stdio.h>
int main()
{
   int a[15]={0,0,3,5,0,0,8,2,7,0,0,0,0,9,8};
   int j=0;
   int count=0;
   int i=0;
   int k=0;
   while(i<14)
   {

       if(a[i]==0)
       {
         a[count]=0;

         count++;
       }
       i++;

   }
   printf("%d\n",count);

    k=count;
    while(j<14)
   {
       if(a[j]!=0)
       {
           a[k]=a[j];
            k++;

       }
         j++;

   }


    for(int l=0;l<14;l++)
    {
     printf("%d \t",a[l]);

    }

}
