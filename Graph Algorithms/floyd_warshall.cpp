//24 APR 2019
// Author: Prabhat Chand Sharma
// All pairs shortest path problem using DP
// In the shortest path for every pair of vertices, any other vertex van either be present or not.
// We make a choice of adding or not adding all the vertices (b/w all pairs) and find the min distance!
#include<bits/stdc++.h>
using namespace std;
#define INF 10001
void addedge(int *adj,int v,int x,int y,int w)
{
        *((adj+x*v) + y)=w;
}
void warshall(int *adj,int v)
{
    int ans[v][v];
    for(int i=0;i<v;++i)
    {
        for(int j=0;j<v;++j)
        {
            if(*((adj+i*v) + j)==-1)
                 *((adj+i*v) + j)=INF;
            ans[i][j]=*((adj+i*v) + j);
        }
    }
    for(int k=0;k<v;++k)
    {
        for(int i=0;i<v;++i)
        {
            for(int j=0;j<v;++j)
            {
                ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
            }
        }
    }
    cout<<"The shortest paths are : \n";
    for(int i=0;i<v;++i)
    {
        cout<<endl;
        for(int j=0;j<v;++j)
        {
            cout<<ans[i][j]<<"  ";
        }
    }
}
int main()
{
    int v;
    cin>>v;
    int adj[v][v]={ {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
    //adj[0][1]=3; adj[0][2]=1;adj[2][3]=9;adj[1][3]=6;adj[2][1]=1;
    //addedge((int*)adj,v,0,1,3);     addedge((int*)adj,v,0,2,1);    addedge((int*)adj,v,2,3,9);    addedge((int*)adj,v,1,3,6);    addedge((int*)adj,v,2,1,1);
    warshall((int*)adj,v);
}
