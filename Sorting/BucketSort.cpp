/*
Program Name : BUCKET SORT
Written By : Prabhat Chand Sharma
Written On : 25 FEB 2019
*/
#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<double> a,int n)  //Insertion sort is used in bucket sort to sort the elements in each bucket
{
    int i,key;
    for(i=1;i<n;++i)
    {
        key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
    }
}
int main()
{
    int n;
    cin>>n;
    double arr[n];
    for(int i=0;i<n;++i)
       cin>>arr[i];
    vector<vector<double >> v(n);
    for(int i=0;i<n;++i)
    {
        int idx=n*arr[i];
        v[idx].push_back(arr[i]);
    }
    for(int i=0;i<n;++i)
       sort(v[i].begin(),v[i].end());
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<v[i].size();++j)
            cout<<v[i][j]<<"  ";
    }
    return 0;
}
