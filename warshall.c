#include<stdio.h>
#include<stdlib.h>


void warshall(int p[10][10],int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
 {
  for(j=1;j<=n;j++)
  {
   for(i=1;i<=n;i++)
  {
   if((p[i][j]==0)&&(p[i][k]==1)&&(p[k][j]==1))
   {
    p[i][j]=1;
   }
  }
 }
}
 printf("\n the path matrix is:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("%d \t",p[i][j]);
  }
  printf("\n");
 }
}

void main()
{
  int a[10][10],n,i,j;
 printf("enter no. of nodes :");
 scanf("%d",&n);
 printf("enter the adjacency matrix: \n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 printf("the adjacency matrix is \n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("%d \t ",a[i][j]);
  }
  printf("\n");
}
warshall(a,n);
}


