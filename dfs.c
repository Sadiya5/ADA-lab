#include<stdio.h>
#include<stdlib.h>


void dfs(int n,int cost[100][100],int u,int t[100][100],int s[])
{
  int v;
  static int k=1;
  s[u]=1;
  for(v=1;v<=n;v++)
  {
   if((cost[u][v]==1)&&(s[v]==0))
   {
    t[k][1]=u;
    t[k][2]=v;
    k++;
    dfs(n,cost,v,t,s);
   }
  }
}


void main()
{
 int n,i,j,source,cost[100][100],s[100],t[100][100];
 printf("enter the no. of nodes \n");
 scanf("%d",&n);
 printf("enter the cost adjacency matrix \n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
  }
 }
 printf("enter the source\n");
 scanf("%d",&source);
 for(i=1;i<=n;i++)
 {
  s[i]=0;
 }
 dfs(n,cost,source,t,s);
 for(i=1;i<=n;i++)
 {
  if(s[i]==1)
  printf("%d is reachable\n",i);
  else
  printf("%d is not reachable\n",i);
 }
 for(i=1;i<=n;i++)
 {
  if(s[i]==0)
  {
   printf("Graph is not connected\n");
   exit(0);
  }
 }
 printf("Graph is connected \n");
 printf("the spanning tree is shown below \n");
 for(i=1;i<=(n-1);i++)
 {
  printf("%d%d\n",t[i][1],t[i][2]);
 }
}

