//22 APR 2019
//Problem : Finding no. of connected components in an *undirected* graph.
//Author: Prabhat Chand Sharma
//This algorithm has Numerous applications!
#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int> *adj;
public :
    graph(int v)
    {
      this->v=v;
      adj=new list<int>[v];
    }
    void dfsutil(int v,bool visited[]);
    int dfs_components();
    void addedge(int u,int w);
};
void graph::dfsutil(int x,bool visited[])
{
    visited[x]=true;
    list<int> :: iterator i;
    for(i=adj[x].begin();i!=adj[x].end();++i)
    {
        if(!visited[*i])
            dfsutil(*i,visited);
    }
}
int graph:: dfs_components()
{
    bool *visited=new bool[v];   // to avoid cycles
    for(int i=0;i<v;++i)
        visited[i]=false;
    int cpt=0;
    for(int i=0;i<v;++i)         //dfsutil is called for all nodes to handle a disconnected graph.
    {
        if(!visited[i])
        {
              cpt++;              // If a node has not been visited in dfs yet, it must be a new component
              dfsutil(i,visited);
        }

    }
    return cpt;
}
void graph:: addedge (int u,int w)
{
    adj[u].push_back(w);
}
int main()
{
    graph g(5);
    g.addedge(0,1); g.addedge(0,2);  g.addedge(1,3);
    cout<<"No. of connected components of the given graph is : "<<g.dfs_components();;

}


