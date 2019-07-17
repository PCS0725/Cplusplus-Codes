/*
Problem: Range minimum Queries
Author: Prabhat Chand Sharma
Solution : Using sparse tables
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;++i)
        cin>>vec[i];
    int z=log2(n)+1;
    int table[n][z];
    for (int i = 0; i < n; i++)
        table[i][0] = vec[i];

    for (int j = 1; j <= z; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            table[i][j] = min(table[i][j-1], table[i + (1 << (j - 1))][j - 1]);
    int t;
    cin>>t;
    int x,y;
    for(int i=0;i<t;++i)
    {
        cin>>x>>y;
        int po=log2(y-x+1);
        int m=min(table[x][po],table[y-(1<<po)+1][po]);
        cout<<m<<"\n";
    }
}
