// 22 april 2019
//Problem: Given a directed,acyclic graph, return the topological sorting.
// the graph can be disconnected
// In the ordering, for every edge uv, node u should come before node v
//Author: Prabhat Chand Sharma
// We create a stack and push into it such that every node is pushed only after its adjacent nodes are pushed!
#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int> *adj;
public:
    graph(int v)
    {
        this->v=v;
        adj=new list<int>[v];
    }
    void addedge(int u,int w)
    {
        adj[u].push_back(w);
    }
    void topo_util(int v,stack<int> &s,bool visited[]);
    void topo_sort();
};
void graph:: topo_util(int x,stack<int> &s,bool visited[])
{
    visited[x]=true;
    list<int> ::iterator i;
    for(i=adj[x].begin();i!=adj[x].end();++i)
        if(!visited[*i])
          topo_util(*i,s,visited);
    s.push(x);                              // IMP : The last node in the dfs will be pushed first ...
}
void graph :: topo_sort()
{
    bool *visited= new bool[v];
    stack<int> s;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<v;++i)                  // Called for all nodes to handle the disconnected graph
        if(!visited[i])
         topo_util(i,s,visited);
    while(s.empty()==false)
    {
        cout<<s.top()<<"  ";
        s.pop();
    }
    cout<<endl;                                  //if the graph has several disconnected components, there will be multiple orders,
                                                // one for each of the component!. To separate them, endl is used!!
}
int main()
{
    graph g(5);
    g.addedge(1, 0);
    g.addedge(0, 2);
    g.addedge(2, 1);
    g.addedge(0, 3);
    g.addedge(3, 4);
    cout << "Following is a Topological Sort of the given graph \n";
    g.topo_sort();
}
