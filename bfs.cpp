#include<iostream>
#include<cstdlib>

using namespace std;

int cost[10][10],i,j,k,n,qu[10],front,rare,v,visit[10],visited[10];

int main()
{
    int m;
    cout <<"\nEnter no of vertices : ";
    cin >> n;
    cout <<"\nEnter no of edges : ";
    cin >> m;
    cout <<"\nEDGES \n";
    for(k=1;k<=m;k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }

    cout <<"\nEnter initial vertex : ";
    cin >>v;
    cout <<"\nVisitied vertices\n";
    cout << v;
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                qu[rare++]=j;
            }
        }
        v=qu[front++];
        cout<<v << " ";
        k++;
        visit[v]=0; visited[v]=1;
    }
    return 0;
}
