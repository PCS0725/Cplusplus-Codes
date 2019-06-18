//24 APR 2019
//Single source all vertices shortest path algorithm
//Traverse the list of all the edges |v|-1 times(there can be at most |v|-1 edges between two vertices)
#include<bits/stdc++.h>
using namespace std;
#define INF 10001        // Sentinel
class graph
{
    int v,e;
    list<pair<int,int> > *adj;
public :
    graph(int v,int e)
    {
        this->v=v;
        this->e=e;
        adj=new list<pair<int,int> >[v];
    }
    void addedge(int x,int y,int w)
    {
        adj[x].push_back(make_pair(y,w));
    }
    void bellman(int st);
};
void graph:: bellman(int st)
{
    int dis[v];
    memset(dis,INF,sizeof(dis));
    dis[st]=0;
    for(int j=0;j<v-1;++j)
    {
    for(int i=0;i<v;++i)
    {
        list<pair<int,int> > :: iterator it;
        for(it=adj[i].begin();it!=adj[i].end();++it)
        {
            pair<int ,int> p=*it;
            if(dis[p.first]>dis[i]+p.second)
                dis[p.first]=dis[i]+p.second;
        }
    }
    }
    cout<<"Min distances from starting node to all nodes is : \n";
    for(int i=0;i<v;++i)
        cout<<i<<" --- "<<dis[i]<<"\n";
}
int main()
{
    graph g(4,5);
    g.addedge(0,1,3);     g.addedge(0,2,1);    g.addedge(2,3,9);    g.addedge(1,3,6);    g.addedge(2,1,1);
    g.bellman(0);

}
