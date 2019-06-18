// 24 APR 2019
// Author: Prabhat Chand Sharma
// Naive implementation of djikstra's algorithm!
// Solving the single source all vertices shortest path problem
// A simple BFS of the graph with a greedy step!!
#include<bits/stdc++.h>
using namespace std;
#define INF 100000001
class graph
{
    int v;
    list<pair<int,int> > *adj;
public :
    graph(int v)
    {
        this->v=v;
        adj=new list<pair<int,int> >[v];
    }
    void addedge(int x,int y,int w)
    {
        adj[x].push_back(make_pair(y,w));
    }
    void djikstra(int st);
};
void graph:: djikstra(int st)
{
    vector<pair<int,int> > dis(v);      // This representation will give pain later on , though !!
    for(int i=0;i<v;++i)
    {
        dis[i].second=i;                // first element: dist, second : Node
        if(dis[i].second==st)
             dis[i].first=0;
        else
             dis[i].first=INF;
    }

    int cnt=0;
    while(cnt<v)
    {
        sort(dis.begin()+cnt,dis.begin()+v);
        int node=dis[cnt].second;
        int dist=INF;
        for(int i=0;i<v;++i)             // Unnecessary!!
           if(dis[i].second==node)
              {
                  dist=dis[i].first;
                  break;
              }
        list<pair<int,int> > :: iterator i;
        for(i=adj[node].begin();i!=adj[node].end();++i)
        {
            int x;
            pair<int,int> p=*i;
            for(x=0;x<v;++x)
                if(dis[x].second==p.first)
                   break;
            if(dis[x].first>dist+p.second)
                dis[x].first=dist+p.second;
        }
        cnt+=1;
    }
    cout<<"The distance from source node to all nodes : ";
    for(int i=0;i<v;++i)
    {
        cout<<dis[i].second<<" -- "<<dis[i].first<<"\n";
    }
}
int main()
{
    graph g(4);
    g.addedge(0,1,3);     g.addedge(0,2,1);    g.addedge(2,3,9);    g.addedge(1,3,6);    g.addedge(2,1,1);
    g.djikstra(0);
}
