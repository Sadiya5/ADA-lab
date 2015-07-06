#include<iostream>
#include<iomanip>

#define max 10
using namespace std;

int path[max];
static int k=0;
int count=0;
int perm[120][7];
int tourcost[120];

void swap(int *x,int *y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}

void dfs(int curr,int v[max],int g[max][max],int n)
{
  int i;
  v[curr]=1;
  path[k++]=curr;
  for(i=0;i<n;i++)
  {
   if((g[curr][i])&&(!v[i]))
   dfs(i,v,g,n);
  }
}

void permute(int *a,int i,int n)
{
  int j,k;
  if(i==n)
  {
   for(k=0;k<=n;k++)
   {
    perm[count][k+1]=a[k];
   }
   count++;
  }
  else
  {
   for(j=i;j<=n;j++)
   {
    swap((a+i),(a+j));
    permute(a,i+1,n);
    swap((a+i),(a+j));
   }
  }
}

int appTSP(int n,int cost[max][max])
{
 int t[max][2],p[max],d[max],s[max],visited[max],tree[max][max];
 int i,j,u,v,sum,k,source,count,min,excost=0;
 for(i=0;i<n;i++)
 {
  visited[i]=0;
 }
 min=9999;
 source=0;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if((cost[i][j]!=0)&&(cost[i][j]<=min))
   {
    min=cost[i][j];
    source=i;
   }
  }
 }
 for(i=0;i<n;i++)
 {
  d[i]=cost[source][i];
  s[i]=0;
  p[i]=source;
 }
 s[source]=1;
  sum=0;
  k=0;
  count=0;
  while(count!=(n-1))
  {
   min=9999;
   u=-1;
   for(j=0;j<n;j++)
   {
    if(s[j]==0)
    {
     if(d[j]<=min)
     {
      min=d[j];
      u=j;
     }
    }
   }
   t[k][0]=u;
   t[k][1]=p[u];
   k++;
   count++;
   sum+=cost[u][p[u]];
   s[u]=1;
   for(v=0;v<n;v++)
   {  
    if((s[v]==0)&&(cost[u][v]<d[v]))
    {
     d[v]=cost[u][v];
     p[v]=u;
    }
   }
  }
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    tree[i][j]=0;
   }
  }
  if(sum>=9999)
   cout<<"\nthe spanning tree does not exit."<<endl;
  else
  {
   for(i=0;i<k;i++)
   {
    tree[t[i][0]][t[i][1]]=tree[t[i][1]][t[i][0]]=1;
   }
  }
  dfs(0,visited,tree,n);
   cout<<"\n the approximate minimum cost tour is:"<<endl;
  for(i=0;i<=k;i++)
  {
   cout<<path[i]<<"->";
   excost+=cost[path[i]][path[i+1]];
  }
  cout<<path[0];
  excost+=cost[path[i]][path[0]];
  cout<<"\nthe approximate cost of tour is:"<<excost<<endl;
  return excost;
}


int main()
{
 int a[max][max]; //={{0,4,8,9,12},{4,0,6,8,9},{8,6,0,10,11},{9,8,10,0,7},{12,9,11,7,0}};
 int numofcity; //=5;
 int intercities=4;
 int mct=9999;
 int i,j,mctindex,appmct;
 int city[4]={1,2,3,4}; 
 cout<<"enter the number of city";
 cin>>numofcity;
 cout<<"enter the cost matrix\n";
 for(i=0;i<5;i++)
 {
  for(j=0;j<5;j++)
  {
   cin>>a[i][j];
  }
 }
 permute(city,0,intercities-1);

 for(i=0;i<24;i++)
 {
  for(j=0;j<5;j++)
  {
   tourcost[i]+=a[perm[i][j]][perm[i][j+1]];
  }
  if(mct>tourcost[i])
  {
   mct=tourcost[i];
   mctindex=i;
  }
 }
 cout<<"the exact minimum cost tour is:"<<endl;
 for(i=0;i<numofcity;i++)
 {
  cout<<perm[mctindex][i];
  cout<<"->";
 }
 cout<<"0";
 cout<<"\nthe exact cost of tour is:"<<mct<<endl;
 appmct=appTSP(numofcity,a);
 cout<<"\nthe error in approximation is:"<<appmct-mct<<".units"<<endl;
 cout<<"\nthe accuracy ratio is:"<<(float)appmct/mct<<endl;
 cout<<"\nthe approximate tour is "<<(((float)appmct/mct)-1)<<"longer than the optimal tour."<<endl;
 
 return 0;
}
   
   
