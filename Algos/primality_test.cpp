/*
Program : A fast and efficient primality test
Author : Prabhat Chand Sharma
Approach : Every prime number can be expressed as (6k+1) or (6k-1).
*/
#include<iostream>
using namespace std;
bool isprime(int n)
{
   if(n<=1)
    return false;
   if(n<=3)
    return true;
   if(n%2==0||n%3==0)  // To exclude check for 1st five numbers.
    return false;
   for(int i=5;i*i<=n;i+=6)
   {
       if(n%i==0||n%(i+2)==0)
        return false;
   }
   return true;
}

main()
{
    cout<<"Enter the number to be checked : ";
    int n;cin>>n;
    if(isprime(n))
        cout<<"Prime!";
    else
        cout<<"Not a prime";
}
