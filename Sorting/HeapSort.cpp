/*
Program Name : Heap Sort
Written By : Prabhat Chand Sharma
Written On : 04 Feb 2019
*/
#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i)
{
    int s=i;         //let ith element be the smallest element
    int l=2*i+1;    //the left child
    int r =2*i+2;  //the right child
    if(l<n&&a[l]<a[s])
        s=l;
    if(r<n&&a[r]<a[s])
        s=r;
    if(s!=i)
    {
        int temp=a[i];
        a[i]=a[s];
        a[s]=temp;
        heapify(a,n,s);
    }
}
void heap_sort(int a[],int n)
{
    for(int i=n/2;i>=0;--i)   //create the heap from given array
        heapify(a,n,i);
    for(int i=n-1;i>=0;--i)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }

}
void display(int a[],int n)
{
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
        cout<<endl;
}
int main()
{
    int t;
    cout<<"No. of test cases : ";
    cin>>t;
    while(t--)
    {
        cout<<"No. of elements : ";
        int n; cin>>n;
        int a[n];
        cout<<"Unsorted array : "<<endl;
        for(int i=0;i<n;++i)
            cin>>a[i];
       heap_sort(a,n);
       cout<<"Sorted array : "<<endl;
       display(a,n);
    }
    return 0;
}

