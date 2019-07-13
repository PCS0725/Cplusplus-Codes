/*
Program : Cyclic rotation of array elements.
Author : Prabhat Chand Sharma
Approach : Reversal algorithm(reference : geeksforgeeks.com).
*/
#include<iostream>
using namespace std;
void rev(int a[],int s,int e)   //function for reversing and array from position s to e.
{
    while(s<e)
    {
        int temp=a[s];
        a[s]=a[e];
        a[e]=temp;
        s++;e--;
    }
}
void rot(int a[],int d,int n)
{
    //reverse the first d positions
    //Then, reverse the remaining positions
    //finally,reverse the whole array.
    rev(a,0,d-1);    //Left rotation.
    rev(a,d,n-1);   //For right rotation,first reverse the last d+1 elements.
    rev(a,0,n-1);
}
main()
{
    int n,d;
    cout<<"Enter the size of array : "<<endl;cin>>n;
    int a[n];
    cout<<"How many elements to be rotated ? "<<endl; cin>>d;
    cout<<"Enter the array elements :"<<endl;
    for(int i=0;i<n;++i)
        cin>>a[i];
    rot(a,d,n);
    cout<<"Resultant array is : "<<endl;
    for(int i=0;i<n;++i)
      cout<<a[i]<<"  ";
}


