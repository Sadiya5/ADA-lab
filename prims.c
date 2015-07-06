#include<stdio.h>
#include<stdlib.h>
int vi[10]={0};
int minc=0,min,c[10][10];
int a,b,u,v,i,j,n,ne=1;

void main()
{
  printf("enter the no. of nodes \n");
  scanf("%d",&n);
  printf("enter the adjacency matrix \n");
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
     scanf("%d",&c[i][j]);
     if(c[i][j]==0)
       c[i][j]=999;
      
    }
  }
  vi[1]=1;
  printf("\n");
  while(ne<n)
  {
    min=999;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
      {
       if(c[i][j]<min)
       {
        if(vi[i]!=0)
        {
          min=c[i][j];
          a=u=i;
          b=v=j;
        }
       }
      }
    }
    if((vi[u]==0)||(vi[v]==0))
    {
     printf("count:%d path:%d->%d,cost:%d \n",ne++,a,b,min);
     minc+=min;
     vi[b]=1;
    }
    c[a][b]=c[b][a]=999;
  }
  printf("minimum cost=%d",minc);
}
