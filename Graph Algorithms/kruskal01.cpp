//WARNING: The code is incomplete(algorithm is correct,implementation has an issue.
/*
Problem: Given a weighted graph,find the minimum spanning tree with the minimum cost as well(Kruskal's Algorithm)
Author: Prabhat Chand Sharma
*/
#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v,e;
    list<pair<int,int> > *adj;
    vector< int> *edges;         // ISSUE : how to store the edge list so that it is easy to sort later on.............
    vector<pair<int, int> > *mst;
    int *parent;
public :
    graph(int x,int y)
    {
        x=v;
        e=y;
        adj=new list<pair<int,int> >[v];
        edges=new vector<pair<int, pair<int,int> > >[e];
        mst=new vector<pair<int, int> >[v-1];
        parent=new int[v];
        for(int i=0;i<v;++i)
            parent[i]=i;
    }
    void addedge(int x,int y,int w)
    {
        adj[x].push_back(make_pair(w,y));// adding weight as first element for easy sorting,if required.
        edges->push_back(make_pair(w,make_pair(x,y)));
        int r1=root(x);
        int r2=root(y);
        parent[r2]=r1;
    }
    int root(int x);
    bool checkcycle(int x,int y);
    int kruskal();
    void displayMST();
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
bool graph:: checkcycle(int x,int y)
{
    int r1=root(x);
    int r2=root(y);
    return (r1==r2);
}
int graph:: kruskal()
{
    sort(edges->begin(),edges->end());
    int cost=0;
    for(int i=0;i<e;++i)
    {
        if(!checkcycle(edges[i].second.first,edges[i].second.second))
        {
            cost+=edges[i].first;
            mst->push_back(make_pair(edges[i].second.first,edges[i].second.second));
        }
    }
    return cost;
}
void graph :: displayMST()
{
    for(int i=0;i<v-1;++i)
        cout<<"Source : "<<mst[i].first<<"  Destination : "<<mst[i].second<<"\n";
}
int main()
{
    graph g(4,5);
    g.addedge(0,1,10); g.addedge(0,2,6);g.addedge(0,3,5);g.addedge(1,3,15);g.addedge(2,3,4);
    cout<<"The cost of MST of the given graph is : "<<g.kruskal()<<"\n";
    cout<<"The MST is : "<<g.displayMST();
}
