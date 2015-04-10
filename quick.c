#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/time.h>
#define max 10000

void swap(int a[],int i,int j)
{
   int temp;
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
}

int partition(int a[],int l,int r)
{
  int p=a[l];
  int i=l+1;
  int j=r;
  while(i<=j)
  {
   while(a[i]<=p && i<=r)
   {
    i=i+1;
   }
   while(a[j]>p && j>=0)
   {
    j=j-1;
   }
   if(i<=j)
   {
    swap(a,i,j);
   }
  }
   swap(a,l,j);
   return j;
}

void qs(int a[],int l,int r)
{
 int s;
 if(l<r)
 {
   s=partition(a,l,r);
   qs(a,l,s-1);
   qs(a,s+1,r);
 }
}


void main()
{
  int a[max],n,i,r,l;
  struct timeval t;
  double start,end;
printf("enter the valueof n");
 scanf("%d",&n);
 //for(n=100;n<=1000;n=n+100)
//{
  //printf("%d",n);
for(i=0;i<n;i++)
{
  a[i]=rand()%1000;
  //printf("\n %d \n",a[i]);
}
l=0;
r=n-1;
gettimeofday(&t,NULL);
start=t.tv_sec+(t.tv_usec/1000000.00);
qs(a,0,n-1);
gettimeofday(&t,NULL);
end=t.tv_sec+(t.tv_usec/1000000.00);
printf("\n %lf \n ",end-start);
printf("sorted elements are:");
for(i=0;i<n;i++)
{
 printf("%d \n ",a[i]);
}
//}
}
