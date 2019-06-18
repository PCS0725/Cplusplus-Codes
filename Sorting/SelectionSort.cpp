/*
Program Name : Selection Sort
Written By : Prabhat Chand Sharma
*/
#include<bits/stdc++.h>
using namespace std;
void selection_sort(int a[],int n)
{
    int min_idx;  // Find the minimum index each time
    for(int i=0;i<n-1;++i)
    {
        min_idx=i;
        for(int j=i+1;j<n;++j)
        {
            if(a[j]<a[min_idx])
                min_idx=j;
        }
        int temp=a[i];
        a[i]=a[min_idx];
        a[min_idx]=temp;
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
        selection_sort(a,n);
        cout<<"Sorted array : "<<endl;
        display(a,n);
    }
    return 0;
}
