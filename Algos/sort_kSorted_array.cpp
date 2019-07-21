/*
Program : Sorting an almost sorted array. Each array is displaced from its position in sorted array by at most k positions.
Author  : Prabhat Chand Sharma
*/
#include<bits/stdc++.h>
using namespace std;

void kSort(int a[],int n,int k)
{
    int op=0;                       //maintain a minheap of size k. It holds the min element for position 'op'
    priority_queue<int, vector<int>,greater<int> > minHeap;
    for(int i=0;i<=k;++i)             //copy the first k elements
        minHeap.push(a[i]);
    for(int i=k+1;i<n;++i)
    {
        a[op]=minHeap.top();          //extract th minimum element each time and push it to correct position in the array.
        minHeap.pop();
        ++op;
        minHeap.push(a[i]);
    }
    while(!minHeap.empty())              //copy the remaining elements.
    {
        a[op]=minHeap.top();
        minHeap.pop();
        ++op;
    }
}
int main()
{
    cout<<"Enter the size of array value of k : ";
    int n,k;
    cin>>n>>k;
    cout<<"\nEnter the array elements : ";
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    cout<<"The sorted array is : ";
    kSort(a,n,k);
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
}
