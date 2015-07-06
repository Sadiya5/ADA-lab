#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<omp.h>
#define max 10000

void merge(int a[],int low,int mid,int high)
{
 int c[max],i,j,k;
 i=low;
 k=low;
 j=mid+1;
 while((i<=mid)&&(j<=high))
 {
  if(a[i]<a[j])
  {
   c[k++]=a[i++];
  }
  else
  {
   c[k++]=a[j++];
  }
 }
 while(i<=mid)
 {
  c[k++]=a[i++];
 }
 while(j<=high)
 {
  c[k++]=a[j++];
 }
 for(k=low;k<=high;k++)
 {
   a[k]=c[k];
 }
}

void mergesort(int a[],int low,int high)
{
 int mid;
 if(low>=high)
 return;
 mid=(low+high)/2;
 #pragma omp parallel shared(a,low,mid,high)
 {
  #pragma omp sections nowait
  {
   #pragma omp section 
	mergesort(a,low,mid);
   #pragma omp section 
	mergesort(a,mid+1,high);
  }  
 }
 merge(a,low,mid,high);
}

void main()
{
  int a[max],i,low,high,n;
  struct timeval tv;
  double start,end;
  int iCPU=omp_get_num_threads();
    omp_set_num_threads(iCPU);
  printf("no of cpu:-%d \n",iCPU);
  printf("enter the value of n");
  scanf("%d",&n);
  printf("unsorted array:");
  for(i=0;i<n;i++)
  {
   a[i]=rand()%10000;
  }
  low=0;
  high=n-1;
  gettimeofday(&tv,NULL);
  start=tv.tv_sec+(tv.tv_usec/1000000.00);
  mergesort(a,0,n-1);
  gettimeofday(&tv,NULL);
  end=tv.tv_sec+(tv.tv_usec/1000000.00);
  printf("\n %lf \n",end-start);
  printf("sorted array:");
  for(i=0;i<n;i++)
  {
  // printf("\n %d \n",a[i]);
  }
}


  
