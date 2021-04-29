#include<bits/stdc++.h>
using namespace std;
int comp = 0;
void merge(int A[], int lb, int mid, int ub)
{
 int i = lb;
 int j = mid+1;
 int B[ub+1],k=lb;
 while(i<=mid && j<=ub)
 {
 ++comp;
 if(A[i]<=A[j])
 {
 B[k] = A[i];
 i++;
 }
 else
 {
 B[k] = A[j];
 j++;
 }
 k++;
 }
 if(i>mid)
 {
 while(j<=ub)
 {
 B[k] = A[j];
 k++;
 j++;
 }
 }
 else
 {
 while(i<=mid)
 {
 B[k] = A[i];
 k++;
 i++;
 }
 }
 for(k=lb;k<ub+1;k++)
 {
 A[k] = B[k];
 }
}
void mergesort(int A[], int lb, int ub)
{
 if(lb<ub)
 {
 int mid = (lb+ub)/2;
 mergesort(A,lb,mid);
 mergesort(A,mid+1,ub);
 merge(A,lb,mid,ub);
 }
}
int main()
{
 int n;
 cout<<"Enter no. of elements in array:\t";
 cin>>n;
 int i,A[n];
 cout<<"\nEnter array elements: ";
 for(i=0; i<n; i++)
 {
 cin>>A[i];
 }
 mergesort(A,0,n-1);
 cout<<"\nTotal No. of Comparisions: "<<comp;
 cout<<"\nSorted array is:\n\t";
 for(i=0;i<n;i++)
 cout<<A[i]<<" ";
 return 0;
}
