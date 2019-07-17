#include<bits/stdc++.h>
using namespace std;
int construct(int a[],int n,int l,int r,int node,int seg[])
{
    if(l==r)
    {
        seg[node]=a[l];
        return a[l];
    }
    int mid=(l+r)/2;
    int lsum= construct(a,n,l,mid,2*node+1,seg);
    int rsum=construct(a,n,mid+1,r,2*node+2,seg);
    seg[node]=lsum+rsum;
    return (lsum+rsum);
}
int getsum(int a[],int ql,int qr,int l,int r,int node,int seg[])
{
    if(ql<=l&&qr>=r)
        return seg[node];
    else if((ql<l&&qr<l)||(ql>r&&qr>r))
        return 0;
    else
    {
        int mid=(l+r)/2;
        return (getsum(a,ql,qr,l,mid,2*node+1,seg)+getsum(a,ql,qr,mid+1,r,2*node+2,seg));
    }
}
void update(int a[],int l,int r,int idx,int val,int node,int seg[])
{
    if((l==r)&&(r==idx))
    {
        seg[node]=seg[node]+val;
        a[l]=a[l]+val;
        return;
    }
    else if((l<=idx)&&(idx<=r))
    {
        int mid=(l+r)/2;
        seg[node]=seg[node]+val;
        update(a,l,mid,idx,val,2*node+1,seg);
        update(a,l,mid,idx,val,2*node+1,seg);
    }
    else
        return;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int seg[4*n]={0};
    for(int i=0;i<n;++i)
        cin>>a[i];
    construct(a,n,0,n-1,0,seg);
    cout<<"\n";
    int b=0;
    do
    {
        int c;
        cout<<"\nEnter your choice : \n1.Get Sum of a range\n2.Update a value ";
        cin>>c;
        if(c==1)
        {
            int x,y;
            cout<<"\nEnter a valid range : ";
            cin>>x>>y;
            cout<<getsum(a,x,y,0,n-1,0,seg);
        }
        else if(c==2)
        {
            int id;
            cout<<"\nEnter the index of the value to be updated : ";
            cin>>id;
            int v;
            cout<<"\nEnter the new value : ";
            cin>>v;
            update(a,0,n-1,id,v-a[id],0,seg);
        }
        cout<<"\nWant to continue?(0 or 1) :";
        cin>>b;
    }while(b);
}
