#include<stdio.h>
#include<stdlib.h>
int p[20],w[20],x[20],v[20][20];
int max(int a,int b)
{
  return a>b?a:b;
}

void knap(int m,int n,int w[],int p[])
{
  int i,j;
  for(i=0;i<=n;i++)
  {
   for(j=0;j<=m;j++)
   {
    if(i==0||j==0)
    {
      v[i][j]=0;
    }
    else if(j-w[i]<0)
    {
     v[i][j]=v[i-1][j];
    }
    else
    {
     v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
    }
   }
  }
  printf("the output is \n");
  for(i=0;i<=n;i++)
  {
   for(j=0;j<=m;j++)
   {
    printf("%d \t",v[i][j]);
   }
   printf("\n");
  }
  printf("the optimal solution is %d \n",v[n][m]);
  for(i=0;i<n;i++)
   x[i]=0;
   i=n;
   j=m;
   while(i>0 && j>0)
   {
    if(v[i][j]!=v[i-1][j])
    {
      x[i]=1;
      j=j-w[i];
    }
    i=i-1;
   }
   printf("The items choosen are:\n < \t");

   for(i=1;i<=n;i++)
   {
     printf("%d \t",x[i]);
   } 
   printf(">");
}

void main()
{
  int i,n,m;
  printf("enter the no. of objects \n");
  scanf("%d",&n);
  printf(" enter the weights of objects \n");
  for(i=1;i<=n;i++)
  scanf("%d",&w[i]);
  printf(" enter the profits of the objects \n");
  for(i=1;i<=n;i++)
  scanf("%d",&p[i]);
  printf("enter the capacity of the knapsack \n");
  scanf("%d",&m);
  knap(m,n,w,p);
}
