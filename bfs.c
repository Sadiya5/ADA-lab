#include<stdio.h>
#include<stdlib.h>

int a[200][200],q[200],visited[200];
int n,i,j;
int f=0;
int r=-1;

void bfs(int v)
{
  for(i=1;i<=n;i++)
    if((a[v][i]) && (!visited[i]))
     q[++r]=i;
    if(f<=r)
  {
   visited[q[f]]=1;
   bfs(q[f++]);
  }
}

void main()
{
  int v;
  printf("\n enter the number of vertices:");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
   q[i]=0;
   visited[i]=0;
  }
  printf("\n enter graph data in matrix form:\n");
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    scanf("%d",&a[i][j]);
   }
  }
  printf("\n enter the starting vertex:");
  scanf("%d",&v);
  bfs(v);
  printf("\n the node which are reachable are:\n");
  { 
   for(i=1;i<=n;i++)
   if(visited[i])
   printf("%d\n",i);
   else
    printf("\nBFS is not possible\n");
  } 
 }   
  
