/*
Program : Calculation of nth number of fibonacci series using recursion
Author : Prabhat Chand Sharma
*/
#include<iostream>
using namespace std;
int fibo(int);
int main()
{
    int n; cin>>n;
    cout<<fibo(n)<<endl;
    return 0;
}
int fibo(int n)
{
    if(n==2||n==1)
        return 1;
    else
     return (fibo(n-1)+fibo(n-2));
}
