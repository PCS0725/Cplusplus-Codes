//Problem : Maximum sum of a subarray such that all elements are non-adjacent.\
//Author : Prabhat Chand Sharma
//Solution : Using a modified kadane algorithm
#include<bits/stdc++.h>
using namespace std;
int maxSum(int a[],int n)
{
    int mSum[n]={0};
    mSum[0]=a[0]?a[0]:0;
    mSum[1]=a[1]?a[1]:0;
    for(int i=2;i<n;++i)
    {
        if(a[i])
            mSum[i]=mSum[i-2]+a[i];
        else
            mSum[i]=mSum[i-2];
    }
    return *(max_element(mSum,mSum+n));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    cout<<maxSum(arr,n)<<"\n;
    }
}
