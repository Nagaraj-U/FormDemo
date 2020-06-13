#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int n=0;
void main()
{
    int i;
    clock_t start,end;
    double totaltime;
    printf("\n enter the number of elements \n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    mergesort(a,0,n-1);
    end=clock();
    printf("sorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;

printf("\n time taken %f ",totaltime);
}  
void mergesort(int a[],int i,int j)
{
    int mid;
    if(i<j)
    {
        int m=(i+j)/2;
        mergesort(a,i,m);
        mergesort(a,m+1,j);
        merge(a,i,m,m+1,j);
    }
}
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[n];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;
    while(i<=j1 && j<=j2)
    {
        if(a[i]<a[j])
        temp[k++]=a[i++];
        else 
        temp[k++]=a[j++];
    }
    while(i<=j1)
    temp[k++]=a[i++];
    while(j<=j2)
    temp[k++]=a[j++];
    for(i=i1,j=0;i<=j2;i++,j++)
    a[i]=temp[j];
}