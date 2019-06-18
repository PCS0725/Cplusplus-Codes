/*
Program Name : DEPTH FIRST SEARCH TRAVERSAL
Description : Given a graph, do a depth first traversal
Written By : Prabhat Chand Sharma
Written On : 08 APR 2019
*/
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
    void dfs();
    void addedge(int u,int w);
};
void graph::dfsutil(int x,bool visited[])
{
    visited[x]=true;
    cout<<x<<"  ";
    list<int> :: iterator i;
    for(i=adj[x].begin();i!=adj[x].end();++i)
    {
        if(!visited[*i])
            dfsutil(*i,visited);
    }
}
void graph:: dfs()
{
    bool *visited=new bool[v];   // to avoid cycles
    for(int i=0;i<v;++i)
        visited[i]=false;
    for(int i=0;i<v;++i)         //dfsutil is called for all nodes to handle a disconnected graph.
    {
        if(!visited[i])
              dfsutil(i,visited);
    }
}
void graph:: addedge (int u,int w)
{
    adj[u].push_back(w);
}
int main()
{
    graph g(5);
    g.addedge(0,3); g.addedge(0,1); g.addedge(1,3); g.addedge(2,4);
    cout<<"The DFS traversal of the given graph is : \n";
    g.dfs();

}

