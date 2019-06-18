//27 APRIL 2019
//Problem: Using the union-find algorithm to find cycle in graph!
//Author : Prabhat Chand Sharma
//If an edge is added such that its both the vertices have same root, then report a cycle!
#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int > *adj;
    int *parent;
public :
    graph(int x)
    {
        x=v;
        adj=new list<int>[v];
        parent=new int[v];
        for(int i=0;i<v;++i)
            parent[i]=i;
    }
    int root(int x);
    bool fnd(int x,int y);
    void addedge(int x,int y)
    {
        if(fnd(x,y))
        {
            cout<<"Cycle Formed ! \nAborting....";
            return;
        }
        cout<<"Edge from "<<x<<" to "<<y<<" added ! \n";
        adj[x].push_back(y);
        int r1=root(x);
        int r2=root(y);
        parent[r2]=r1;           // to avoid a skewed tree in the parent array! otherwise, finding root of a node will become costly !
    }
};
int graph:: root(int x)
{
    int i=x;
    while(parent[i]!=i)
    {
        i=parent[i];
        parent[i]=parent[parent[i]];
    }
    return i;
}
bool graph:: fnd(int x,int y)
{
    int r1=root(x);
    int r2=root(y);
    return (r1==r2);
}
int main()
{
    graph g(4);
    g.addedge(0,1); g.addedge(3,2);  g.addedge(1,3); g.addedge(1,2);

}
