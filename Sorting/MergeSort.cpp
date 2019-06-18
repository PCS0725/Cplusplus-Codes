/*
Program Name : Merge Sort
Written By : Prabhat Chand Sharma
*/
#include<bits/stdc++.h>
using namespace std;
void merg(int a[],int l,int m,int r);
void merge_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        merge_sort(a,l,m);     //the left half
        merge_sort(a,m+1,r);   //recur for the right half
        merg(a,l,m,r);         // merge two sorted list using merge() function
    }
    else
        return;
}
void merg(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;++i)       // copy the left half into a new array
        left[i]=a[l+i];
    for(int i=0;i<n2;++i)       //copy the right half into new array
        right[i]=a[m+i+1];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2)          //Merge the two sorted lists into the result array
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            ++i;++k;
        }
        else
        {
            a[k]=right[j];
            j++;k++;
        }
    }
    while(i<n1)
    {
        a[k]=left[i];
        ++i;++k;
    }
    while(j<n2)
    {
        a[k]=right[j];
        ++j;++k;
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
        merge_sort(a,0,n);
        cout<<"Sorted array : "<<endl;
        display(a,n);
    }
    return 0;
}
