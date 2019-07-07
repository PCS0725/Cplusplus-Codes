/*
Program : A basic program to store and display an undirected and unweighted graph using adjacency matrix representation
Author : Prabhat Chand Sharma
*/
#include<bits/stdc++.h>
using namespace std;
struct graph
{
    int v,e;      //to store number of edges and vertices
    int **adj;    //adjacency matrix
};
graph* adjmatrix()
{
    graph* g=new graph;
    int a,b;
    cout<<" Enter the number of nodes in the graph : \n"; cin>>a;
    cout<<"Enter the number of edges in the graph : \n"; cin>>b;
    g->v=a; g->e=b;        //Initialization of the graph
    g->adj=new int*[b];
    for(int i=0;i<a;++i)    //setting all the adj[i][j] to 0 : Indicating that no edges were present in the beginning
    {
        g->adj[i]=new int[a];
        for(int j=0;j<b;++j)
          g->adj[i][j]=0;
    }
    cout<<"Enter the edges as e=(1st node,2nd node) : \n ";
    int x,y;
    for(int i=0;i<b;++i)
    {
        cin>>x>>y;
        g->adj[x][y]=1;      //For an undirected and unweighted edge between nodes 'x'and 'y', set adj[x][y] and adj[y][x] to 1
        g->adj[y][x]=1;
    }
    return g;
}
void display(graph* x)      //Displaying the information about the graph
{
    cout<<"The Number of nodes is : "<<x->v<<"\n";
    cout<<"The number of edges is : "<<x->e<<"\n";
    cout<<"The edes are between nodes : ";
    for(int i=0;i<x->v;i++)
    {
        for(int j=i;j<x->v;++j)      //j=i to make for the self loops
        {
            if(x->adj[i][j])
                cout<<"Node "<<i<<" and node "<<j<<endl;
        }
    }
}
int main()
{
    graph* g;
    g=adjmatrix();
    display(g);
    return 0;
}
