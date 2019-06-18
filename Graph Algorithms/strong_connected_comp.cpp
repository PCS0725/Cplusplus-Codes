// Problem: Print all the strongly connected components of a given graph.  --- ||||||||KOSARAJU's ALGORITHM||||||||
//Author: Prabhat Chand Sharma
// DFS of a graph can either result in a forest or a tree, depending on the node where we start dfs from.
// To find all the SCCs, we have to start from the nodes which have min no of out-edges.
// In first DFS we try to order the nodes in topological order
// In 2nd DFS, we print all the components
#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int> *adj;
    vector<int> vec;
public:
    graph(int v)
    {
        this->v=v;
        adj=new list<int>[v];
        vec.resize(v);
    }
    void topo_util(int x,bool visited[],stack<int> &s);
    void topo_util2(int x,bool visited[]);
    void dfs2();
    graph getTranspose();
    void addedge(int u,int w)
    {
        adj[u].push_back(w);
    }
    void topo_sort();
};
void graph:: topo_util(int x,bool visited[],stack<int> &s)
{
    visited[x]=true;
    list<int> ::iterator i;
    for(i=adj[x].begin();i!=adj[x].end();++i)
    {
        if(!visited[*i])
            topo_util(*i,visited,s);
    }
    s.push(x);
}
void graph:: topo_sort()
{
    bool *visited=new bool[v];
    memset(visited,false,sizeof(visited));
    stack<int> s;
    for(int i=0;i<v;++i)
    {
        if(!visited[i])
            topo_util(i,visited,s);
    }
    int i=0;
    while(s.empty()==false)
    {
        int y=s.top();
        vec[i++]=y;
        s.pop();
    }
   // for(int i=0;i<v;++i)
     //   cout<<vec[i]<<"  ";
}
void graph:: topo_util2(int x,bool visited[])
{
    visited[x]=true;
    list<int> ::iterator i;
    cout<<x<<"  ";
    for(i=adj[x].begin();i!=adj[x].end();++i)
    {
        if(!visited[*i])
            topo_util2(*i,visited);
    }
}
void graph:: dfs2()
{
    bool *visit2=new bool[v];
    memset(visit2,false,sizeof(visit2));
    graph gr=getTranspose();
    for(int i=0;i<v;++i)
    {
        int node=vec[i];
        if(!visit2[node])
        {
            gr.topo_util2(node,visit2);
            cout<<"\n";
        }
    }

}
graph graph::getTranspose()    // return a graph with opposite edges.
{
    graph g(v);
    for (int x = 0; x < v; x++)
    {
        list<int>::iterator i;
        for(i = adj[x].begin(); i != adj[x].end(); ++i)
        {
            g.adj[*i].push_back(x);
        }
    }
    return g;
}
int main()
{
    graph g(5);
    g.addedge(1,0);  g.addedge(0,2); g.addedge(2,1); g.addedge(0,3); g.addedge(3,4);
    g.topo_sort();
    cout<<"The strongly connected components of the given graph are : ";
    g.dfs2();
}
