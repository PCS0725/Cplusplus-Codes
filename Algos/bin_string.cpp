/*
Program : Printing all possible binary strings of length n.
Author : Prabhat Chand Sharma
Approach : Recursion + backtracking.
*/
#include<bits/stdc++.h>
using namespace  std;
void bin(int n,char a[])
{
    if(n<1)
        cout<<a<<endl;
    else
    {
        a[n-1]='0';   //fix the last position as 0.
        bin(n-1,a);   //recur for remaining positions
        a[n-1]='1';   //backtrack
        bin(n-1,a);
    }
}
main()
{
    cout<<"Enter the size of the string : "<<endl;
    int  n; cin>>n;
    char a[n+1];
    a[n]='\0';
    bin(n,a);
}
