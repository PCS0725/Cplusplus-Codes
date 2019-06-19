/*
Program Name : FRACTIONAL KNAPSACK PROBLEM
Description :  Given n items with their weights and values. You have to put max value in a bag of given capacity
             Items can be broken into subparts
Written By : Prabhat Chand Sharma
Written On : 08 APR 2019
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n;
     cout<<"Enter no. of items :\n"; cin>>n;
    double val[n];
    int wt[n];
    int cp;
     cout<<"Enter the value of each item :\n";
    for(int i=0;i<n;++i)
       cin>>val[i];
    cout<<"Enter the weight of each item :\n";
    for(int i=0;i<n;++i)
       cin>>wt[i];
     cout<<"Enter the capacity of the bag :\n";
    cin>>cp;
    vector<double >rat(n);       //approach : Greedy
    vector<pair<int ,double> > v;
    for(int i=0;i<n;++i)
        rat[i]=val[i]/wt[i];
    sort(rat.begin(),rat.end());
    double ans=0;
    cout<<"Last"<<rat[n-1];
    for(int i=n-1;i>=0;--i)
    {
        if(cp==0)
            break;
        if(wt[i]<=cp)
        {
            ans+=val[i];
            cp-=wt[i];
            v.push_back(make_pair(wt[i],val[i]));
        }
        else
        {
            double v=(val[i]*cp)/wt[i];
            ans+=v;
            break;
        }
    }
    cout<<"The max value is : "<<ans;
    vector<pair<int,double> > ::iterator it;
   cout<<"\nItems taken : ";
   for(it=v.begin();it!=v.end();++it)
       cout<<it->first<<" "<<it->second<<"\n";
}
