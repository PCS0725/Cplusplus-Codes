/*
Program Name : Radix Sort
Written By : Prabhat Chand Sharma
Written On : 11 MAR 2019
*/
#include<bits/stdc++.h>
using namespace std;

void display(int a[],int n)
{
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
void count_sort(int a[],int n,int exp)  //Count sort is used to sort each digit
{
    int aux_arr[10]={0};
    int ans_arr[n];
    for(int i=0;i<n;++i)
        aux_arr[(a[i]/exp)%10]+=1;
    for(int i=1;i<10;++i)
        aux_arr[i]=aux_arr[i-1]+aux_arr[i];
    for(int i=n-1;i>=0;--i)
    {
        ans_arr[aux_arr[(a[i]/exp)%10]-1]=a[i];
        aux_arr[(a[i]/exp)%10]-=1;
    }
    for(int i=0;i<n;++i)
        a[i]=ans_arr[i];
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
        for(int i=0;i<n;++i)     //Input
            cin>>a[i];
        int mx = a[0];
        for (int i = 1; i < n; i++)   //get the maximum element
           if (a[i] > mx)
              mx = a[i];
        cout<<"Sorted array : "<<endl;
        int e=1;                    //the exponent to get the digit
        for(int i=1;mx/e;e*=10)
        {//logic for radix sort
            count_sort(a,n,e);
            display(a,n);
            cout<<endl;
        }
        display(a,n);
    }
    return 0;
}
