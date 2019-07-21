/*
Program : Length of longest increasing subsequence.
Author : Prabhat Chand Sharma
Reference : geeksforgeeks.com
*/
#include<bits/stdc++.h>
using namespace std;
int llis(int a[],int n)     //Using DP to solve the problem.
{
   int ans[n];            //ans[i] stores the length of longest increasing subsequence ending at ith index.
   ans[0]=1;
   int global_max=INT_MIN;
   for(int i=1;i<n;++i)          //for each element, find the elements on its left that are smaller and compare the lengths of LIS.
   {
       int flag=0;
       for(int j=i-1;j>=0;--j)
       {
           if(a[i]>a[j])
           {
               if((ans[j]+1)>global_max)
               {
                    global_max=ans[j]+1;
                    flag=1;
               }

           }
       }
       if(flag)
        ans[i]=global_max;
       else                   //if this element was smaller then all elements, save 1;
        ans[i]=1;
   }
  int mx=INT_MIN;
  //for(int i=0;i<n;++i)
    //if(ans[i]>mx)
      //  mx=ans[i];
  //return mx;
  return *(max_element(ans,ans+n));  //return the maximum of ans[] array.
}
int main()
{
    cout<<"Enter the number of test cases : ";
    int t; cin>>t;
    while(t--)
    {
        cout<<"Enter the number of elements in the array : ";
        int n;
        cin>>n;
        cout<<"Enter the array elements : ";
        int arr[n];
        for(int i=0;i<n;++i)
            cin>>arr[i];
        cout<<"\nThe length of longest increasing subsequence in the given array is : "<<llis(arr,n);
        cout<<"\n";
    }
}
