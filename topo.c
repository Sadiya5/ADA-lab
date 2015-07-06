#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[10][10];

void topsort(int a[10][10],int n)
{
  int out[10],in[10],stack[10],u;
  int top=-1;
  int i,j,k=0;
  for(i=0;i<n;i++)
  {
    in[i]=0;
    for(j=0;j<n;j++)
    if(a[j][i]==1)
    {
      in[i]++;
      printf("\t %d inorder %d",i,in[i]);
    }
  }
  while(1)
  {
   for(i=0;i<n;i++)
   {
    if(in[i]==0)
    {
     stack[++top]=i;
     in[i]=-1;
    }
   }
   if(top==-1)
    break;
   u=stack[top--];
   printf("popped %d \n ",u);
   for(i=0;i<n;i++)
   {
    if(a[u][i]==1)
    {
      in[i]--;
    }
   }
   out[k++]=u;
   }
  printf("sorted array:");
  {
   for(i=0;i<n;i++)
   {
    printf("%d",out[i]);
   }
  }
}


void main()
{
  int i,a[10][10],n,j;
  printf("enter no. of elements \n ");
  scanf("%d",&n);
  printf("enter the elements :\n");
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    scanf("%d",&a[i][j]);
   }
  }
  topsort(a,n);
} 
