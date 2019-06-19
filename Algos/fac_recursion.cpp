/*
Program : Calculation of factorial using recursion
Author : Prabhat Chand Sharma
*/
#include<iostream>
using namespace std;
unsigned long long int factorial(int);
int main()
{
     int t;
     cin>>t;
     while(t--)
     {
       unsigned long long int n;
       cin>>n;
       cout<<factorial(n)<<endl;
     }
     return 0;
}
unsigned long long int factorial(int n)
{
    if(n==1)
        return n;
    else
      return (n*factorial(n-1));
}
