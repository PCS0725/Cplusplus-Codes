/*
Program Name : Counting Sort
Written By : Prabhat Chand Sharma
Written On : 11 Feb 2019
*/
#include<bits/stdc++.h>
using namespace std;
void display(int a[],int n);
void count_sort(int a[],int n)
{
    int range;
    cout<<"Enter the maximum element : "; cin>>range;
    int aux_arr[range+1],ans_arr[n];
    for(int i=0;i<range+1;++i)
        aux_arr[i]=0;
    for(int i=0;i<n;++i)        //storing the count of each element in the given array
        aux_arr[a[i]]+=1;
    for(int i=1;i<range+1;++i)   //storing the cumulative count of each element of the given array
        aux_arr[i]=aux_arr[i-1]+aux_arr[i];
    for(int i=n-1;i>=0;--i)
    {
        ans_arr[aux_arr[a[i]]-1]=a[i];
        aux_arr[a[i]]-=1;
    }
    for(int i=0;i<n;++i)
        a[i]=ans_arr[i];
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
        count_sort(a,n);
        cout<<"Sorted array : "<<endl;
        display(a,n);
    }
    return 0;
}
