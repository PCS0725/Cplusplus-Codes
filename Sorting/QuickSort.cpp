/*
Program Name : Quick Sort
Written By : Prabhat Chand Sharma
*/
#include<bits/stdc++.h>
using namespace std;
int partion(int a[],int,int);
void quick_sort(int a[],int beg,int ed)
{
    if(beg<ed){
        int pindex=partion(a,beg,ed);  //The index to partition the parent array across
        quick_sort(a,beg,pindex-1);  //Recur for the left part of pindex
        quick_sort(a,pindex+1,ed);    //recur for the right part of the pindex
    }

}
int partion(int a[],int beg,int ed)
{
    int pindex=beg-1;
    int pivot=a[ed];                      //Choosing the last element as the pivot element
    for(int i=beg;i<=ed-1;++i)
    {
        if(pivot>=a[i])
        {
            pindex++;
            int temp=a[i];
            a[i]=a[pindex];
            a[pindex]=temp;
        }
    }
     int temp=a[ed];
     a[ed]=a[pindex+1];
     a[pindex+1]=temp;                //Place the pivot element at its correct index and return the index
     return pindex+1;
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
        quick_sort(a,0,n);
        cout<<"Sorted array : "<<endl;
        display(a,n);
    }
    return 0;
}
