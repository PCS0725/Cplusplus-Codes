/*
Program : Printing the permutations of a given string with no duplicate characters.
Author : Prabhat Chand Sharma
Note : The given implementation cannot handle duplicate characters.
*/
#include<bits/stdc++.h>
using namespace std;
void perm(char s[],int i,int n)
{
    static int cnt;           //will be created only once
    if(i==n)
    {
        cnt++;
        cout<<s<<endl;
    }
    else
    {
        for(int j=i;j<=n;++j)        //fix positions one by one
        {
          swap(s[i],s[j]);
          perm(s,i+1,n);             // fix the ith position and recur for remaining string
          swap(s[i],s[j]);
        }

    }
}
main()
{
    int n;
    cout<<"Enter the size of string : ";
    cin>>n;
    char p[n];
    cout<<"\nEnter the string(No duplicate characters) : ";
    for(int i=0;i<n;++i)
        cin>>p[i];
    cout<<"The permutations of the given string are : ";
    perm(p,0,n-1);
}
