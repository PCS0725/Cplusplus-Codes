/*
Program Name : BREADTH FIRST TRAVERSAL
Written By : Prabhat Chand Sharma
Written On : 15 APR 2019
*/
#include<bits/stdc++.h>
using namespace std ;
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
    void addedge(int u,int w)
    {
        adj[u].push_back(w);
    }
    void bfs(int s);
};
void graph:: bfs(int s)
{
    bool *visited=new bool[v];        //to store whether a node has been visited or not
    memset(visited,false,sizeof(visited));
    visited[s]=false;
    list <int> q;
    q.push_back(s);
    list<int> :: iterator i;    //An implementation of queue data structure
    while(q.empty()==false)
    {
        s=q.front();
        cout<<s<<"  ";
        q.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();++i)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                q.push_back(*i);
            }
        }
    }
}
int main()
{
    graph g(5);// UI Not added yet
    g.addedge(0,3); g.addedge(0,1); g.addedge(1,3); g.addedge(1,2);
    g.bfs(0);

}
