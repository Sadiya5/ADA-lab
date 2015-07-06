#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<omp.h>
void floyds(int a[10][10],int n);
void floydp(int a[10][10],int n);
//int min(int a,int b);

void main()
{
 struct timeval tv;
  double start,end;
  int iCPU=omp_get_num_threads();
  omp_set_num_threads(iCPU);
  printf("no of cpu:-%d \n",iCPU);

  int n,a[10][10],i,j;
  printf("enter the no. of nodes: \n");
  scanf("%d",&n);
  printf("enter the cost adjacency matrix \n");
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    scanf("%d",&a[i][j]);
   } 
  }
  gettimeofday(&tv,NULL);
  start=tv.tv_sec+(tv.tv_usec/1000000.00);
  floyds(a,n);
  gettimeofday(&tv,NULL);
  end=tv.tv_sec+(tv.tv_usec/1000000.00);
  printf("time1=%lf \n",end-start);
  gettimeofday(&tv,NULL);
  start=tv.tv_sec+(tv.tv_usec/1000000.00);
  floydp(a,n);
  gettimeofday(&tv,NULL);
  end=tv.tv_sec+(tv.tv_usec/1000000.00);
  printf("time2=%lf \n",end-start);


}


void floyds(int a[10][10],int n)
{
  int d[10][10],i,j,k,p[10][10];
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    d[i][j]=a[i][j];
    p[i][j]=0;
   }
  }
 for(k=1;k<=n;k++)
 { 
  
   for(i=1;i<=n;i++)
   {
    for(j=1;j<=n;j++)
   {
     if(d[i][j]>(d[i][k]+d[k][j]))                                               
     {
     d[i][j]=d[i][k]+d[k][j];
     p[i][j]=k;
     }
     else 
      {
      d[i][j]=d[i][j];
      }
    
 }

   }
   }
  printf("\n distance matrix is:\n");
  /*for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
  {
  printf("\npath from %d -> %d = %d",i,j,d[i][j]);  
 printf("\tpath via %d",p[i][j]);
  }
  printf("\n");
  }*/
  
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
  {
  	printf("%d\t",d[i][j]);  
  }
  printf("\n");
  }
}

//int min(int a,int b)
//{
 // if(a<b)
 // return a;
 // else
  //return b;
//}


void floydp(int a[10][10],int n)
{
  int d[10][10],i,j,k,p[10][10];
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    d[i][j]=a[i][j];
    p[i][j]=0;
   }
  }
 for(k=1;k<=n;k++)
 {

   for(i=1;i<=n;i++)
   {
    for(j=1;j<=n;j++)
   {
    #pragma omp parallel shared(d,i,j,k)
    {
     if(d[i][j]>(d[i][k]+d[k][j]))
     #pragma omp sections nowait
     {
     d[i][j]=d[i][k]+d[k][j];
     p[i][j]=k;
     }
     else
      {
      d[i][j]=d[i][j];
      }
    
     }

    } 
   }
  }
 printf("\n distance matrix is:\n");
 /* for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
  {
  printf("\npath from %d -> %d = %d",i,j,d[i][j]);
 printf("\tpath via %d",p[i][j]);
  }
  printf("\n");
  }*/
 
   for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
  {
        printf("%d\t",d[i][j]);
  }
  printf("\n");
  }
}
