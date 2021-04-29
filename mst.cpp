#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
int fr, to, cost;
}p[6];
void prims(int *a, int b[][10], int i, int j, int n)
{
int c=0, temp=0, temp1=0;
a[i]=1;
while(c<6)
{
int min=999;
for(int i=0;i<n;i++)
{
if(a[i]==1)
{
for(int j=0;j<n;)
{
if(b[i][j]>=min || b[i][j]==0)
j++;
else if(b[i][j]<min)
{
min=b[i][j];
temp=i;
temp1=j;
}
}
}
}
a[temp1]=1;
p[c].fr=temp;
p[c].to=temp1;
p[c].cost=min;
c++;
b[temp][temp1]=b[temp1][temp]=1000;
}
cout<<"\n\t\tMINIMUM SPANNING TREE AND ORDER OF TRAVERSAL\n";
for (int k=0;k<n-1;k++)
{
cout<<"Source node : "<<p[k].fr<<endl;
cout<<"Destination node : "<<p[k].to<<endl;
cout<<"Weight of node : "<<p[k].cost<<endl<<endl;
}
}
int main()
{
int a[10]={0}, b[10][10], n;
cout<<"\nEnter the number of nodes:";
cin>>n;
cout<<"\nAdjacency matrix for a "<<n<<" node graph\n";
for(int i=0;i<n;i++)
{
cout<<"Enter values for row "<<(i+1)<<endl;
for(int j=0;j<n;j++)
cin>>b[i][j];
}
prims(a, b, 0, 0, n);
getch();
}
