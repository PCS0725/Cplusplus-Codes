// Problem : No of ways to decode a string, given a mapping : A=1,B=2....Z=26
// Author : Prabhat Chand Sharma
// Solution : Using recursion
#include<bits/stdc++.h>
using namespace std;
int ways(int s[],int i,int n)
{
    if(i==n-1)
        return 1;
    else if(i>=n)
        return 0;
    else
    {
        if(s[i]==1)
            return(ways(s,i+1,n)+ways(s,i+2,n));
        else if(s[i]==2&&s[i+1]<=6&&i==n-2)
            return(2);
        else if(s[i]==2&&s[i+1]<=6&&i<n-2)
            return (ways(s,i+1,n)+ways(s,i+2,n));
        else
            return (ways(s,i+1,n));
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
       cin>>arr[i];
    cout<<ways(arr,0,n);
}
