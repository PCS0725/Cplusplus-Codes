/*
Program  : Answering RANGE MINIMUM queries using segment trees.
Author   : Prabhat Chand Sharma
Complexity : O(n) for precomputing and O(logn) for each query.
Note :     Update operation does not work.
*/
#include<bits/stdc++.h>
using namespace std;
int construct(int a[],int n,int l,int r,int node,int seg[])   //constructing the segment tree
{
    if(l==r)                                                 //If we reach a leaf node
    {
        seg[node]=a[l];
        return a[l];
    }
    int mid=(l+r)/2;                                          //divide the current segment into two halves
    int lmin= construct(a,n,l,mid,2*node+1,seg);              //Value of parent node is the minimum of values returned by child nodes
    int rmin=construct(a,n,mid+1,r,2*node+2,seg);
    seg[node]=min(lmin,rmin);
    return min(lmin,rmin);
}
int getmin(int a[],int ql,int qr,int l,int r,int node,int seg[]) //Answering the queries
{
    if(ql<=l&&qr>=r)                           //if node range lies completely within the query range
        return seg[node];
    else if((ql<l&&qr<l)||(ql>r&&qr>r))        //if the query range is completely outside the current node range
        return INT_MAX;
    else                                       // if node range is larger or overlaps partially with query range, return min of the values returned by children nodes.
    {
        int mid=(l+r)/2;
        return min(getmin(a,ql,qr,l,mid,2*node+1,seg),getmin(a,ql,qr,mid+1,r,2*node+2,seg));
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the array elements : ";
    int seg[4*n]={0};       //the max size of segment tree array can be 4*n ...
    //The segment tree is a full tree(0 or 2 Children). If n is a power of 2, number of nodes=2*n-1.
    //If n is not a power of two, then no. of nodes=2*x-1, x=next power of 2.
    //Height of tree= log2(n)
    for(int i=0;i<n;++i)
        cin>>a[i];
    construct(a,n,0,n-1,0,seg);
    cout<<"\n";
    int b=0;
    do
    {
        int c;
        cout<<"\nEnter your choice : \n1.Get Min of a range ";
        cin>>c;
        if(c==1)
        {
            int x,y;
            cout<<"\nEnter a valid range : ";
            cin>>x>>y;
            cout<<getmin(a,x,y,0,n-1,0,seg);
        }
        cout<<"\nWant to continue?(0 or 1) :";
        cin>>b;
    }while(b);
}
