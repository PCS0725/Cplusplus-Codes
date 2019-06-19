/*
Program Name : LONGEST COMMON SUBSEQUENCE
Description: Given two strings, find the length of longest common subsequence
Written By : Prabhat Chand Sharma
Written On : 01 APR 2019
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cout<<"Enter the number of test cases : ";
    cin>>t;
    while(t--)
    {
        int n1,n2;
        cout<<"\nEnter the number of chars in string A and B : ";
        cin>>n1>>n2;
        char s1[n1],s2[n2];
        int ans[n1+1][n2+1];// The dp table to store answer
        cout<<"\nEnter the strings : ";
        for(int i=0;i<n1;++i)
            cin>>s1[i];
        for(int i=0;i<n2;++i)
            cin>>s2[i];
        for(int i=0;i<=n1;++i)
        {
            for(int j=0;j<=n2;++j)
            {
                if(i==0||j==0)     //if any of the strings is empty
                    ans[i][j]=0;
                else if(s1[i-1]==s2[j-1])   // if the last characters are matching
                        ans[i][j]=ans[i-1][j-1]+1;
                else
                    ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
            }
        }
        cout<<"Length of longest common subsequence is : "<<ans[n1][n2]<<"\n";
    }
    return 0;
}
