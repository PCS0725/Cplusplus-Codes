/*
Program Name : Insertion Sort
Written By : Prabhat Chand Sharma
*/
#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int a[],int n)
{
    int i,key;
    for(i=1;i<n;++i)
    {
        key=a[i];   // Choose the key element and place it at its correct position in already sorted array to its left
        int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
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
        insertion_sort(a,n);
        cout<<"Sorted array : "<<endl;
        display(a,n);
    }
    return 0;
}
