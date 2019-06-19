//Program : Dynamic Connectivity problem(Union-Find Algorithm)
//Author : Prabhat Chand Sharma
// id[i] represents the parent of object i
// each tree is a set of connected components
#include<bits/stdc++.h>
using namespace std;
int root(int arr[],int i)       //Returns the root of the given element
{
    while(arr[i]!=i)
    {
        i=arr[i];
        arr[i]=arr[arr[i]];
    }
    return i;
}
void unn(int arr[],int p,int q) // this may result in skewed tree and 'n' access operations int the worst case
{                                // to avoid this , maintain no. of objects in each tree in a separate array
                                 // the smaller tree goes below the larger tree
    int r1=root(arr,p);
    int r2=root(arr,q);
    arr[r1]=r2;
}
bool connected(int arr[],int p,int q)   //returns whether two elements are connected or not
{
    return (root(arr,p)==root(arr,q));
}
int main()
{
    int n;
    cin>>n;
    int id[n+1];
    for(int i=0;i<=n;++i)
        id[i]=i;
    unn(id,4,5); unn(id,4,1);unn(id,9,6);unn(id,1,3);
    if(connected(id,5,1))
        cout<<"Yes";
    else
        cout<<"NO";
}
