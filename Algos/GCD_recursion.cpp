/*
Program : Calculation of GCD using Euclid's Algorithm
Author : Prabhat Chand Sharma
*/
#include<iostream>
using namespace std;
int gcd(int,int);
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}
int gcd(int x,int y)
{
    if(x==y)
        return x;
    if(x%y==0)
        return y;
    if(y%x==0)
        return x;
    if(x>y)
        return (gcd(x%y,y));
    if(y>x)
        return (gcd(x,y%x));
}
