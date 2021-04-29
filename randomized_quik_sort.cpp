#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int comp = 0;
int partition(int a[],int p,int r)
{
 int x=a[r];
 int i=p-1;
 for(int j=p;j<=r-1;j++){
 comp++;
 if(a[j]<=x){
 i++;
 swap(a[i],a[j]);
 }
 }
 swap(a[i+1],a[r]);
 return i+1;
}
int randomizedPartition(int a[],int p,int r)
{
 srand(time(NULL));
 int i=p+rand()%(r-p);
 swap(a[r],a[i]);
 return partition(a,p,r);
}
void RandomizedQuickSort(int a[],int p,int r)
{
 if(p<r){
 int q=randomizedPartition(a,p,r);
 RandomizedQuickSort(a,p,q-1);
 RandomizedQuickSort(a,q+1,r);
 }
}
int main()
{
 int n,a[n],i;
 cout<<"\n Enter size of the array :";
 cin>>n;
 cout<<"\n Enter array elements :";
 for(i=0;i<n;i++)
    cin>>a[i];
 RandomizedQuickSort(a,0,n-1);
 cout<<"\n After Sorting : \n\t";
 for(i=0;i<n;i++)
 cout<<a[i]<<" ";
 cout<<"\nNo. of comparisons : "<<comp<<endl;
 return 0;
}
