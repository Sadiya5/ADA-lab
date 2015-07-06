#include<stdio.h>
#include<stdlib.h>
void dij(int n,int v,int c[10][10],int dis[10])
{
  int i,u,count,w,flag[10],min;
  for(i=1;i<=n;i++)
  flag[i]=0,dis[i]=c[v][i];
  count=2;
  while(count<=n)
  {
   min=999;
   for(w=1;w<=n;w++)
   {
     if((dis[w]<min)&&(!flag[w]))
     {
       min=dis[w],u=w;
       flag[u]=1;
       count++;
     }
   }
   for(w=1;w<=n;w++)
   {
    if((dis[u]+c[u][w])<dis[w]&&(!flag[w]))
    dis[w]=dis[u]+c[u][w];
   }
  }
}

void main()
{  
  int n,v,i,j,c[10][10],dis[10];
  printf("enter the no. of nodes:\n");
  scanf("%d",&n);
  printf("enter the cost matrix:\n");
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    scanf("%d",&c[i][j]);
    if(c[i][j]==0)
    c[i][j]=999;
   }
  }
  printf("enter the source matrix:\n");
  scanf("%d",&v);
  dij(n,v,c,dis);
  printf("shortest path:\n");
  for(i=1;i<=n;i++)
  {
   if(i!=v)
   {
    printf("%d->%d,cost=%d \n",v,i,dis[i]);
   }
  }
}  
