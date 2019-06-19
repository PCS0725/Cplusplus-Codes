/*
Program Name : 0-1 KNAPSACK PROBLEM
Description: Given n items with their weights and values. You have to put max value in a bag of given capacity
             Items cannot be broken into subparts
Written By : Prabhat Chand Sharma
Written On : 08 APR 2019
*/
#include<bits/stdc++.h>
using namespace std;
int solve(int v[],int wt[],int n,int we)
{
    int i, w;
    int K[n+1][we+1];   //The dp table to store the answer
    for (i=0;i<= n; i++)
    {
       for (w=0;w<=we;w++)
       {
           if (i==0||w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w]=max(v[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
           else
                 K[i][w]=K[i-1][w];
       }
   }
   return K[n][we];
}
int main()
{
    int n;
    cout<<"Enter no. of items :\n";
    cin>>n;

    int val[n],weight[n];
    cout<<"Enter the capacity of the bag :\n";
    int w;cin>>w;
    cout<<"Enter the value of each item :\n";
    for(int i=0;i<n;++i)
        cin>>val[i];
    cout<<"Enter the weight of each item :\n";
    for(int i=0;i<n;++i)
        cin>>weight[i];
    cout<<"\nAnswer : "<<solve(val,weight,n,w)<<"\n";
}
