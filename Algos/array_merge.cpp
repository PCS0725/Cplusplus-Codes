/*
Program : Sorting and then merging two arrays.
Author : Prabhat Chand Sharma
Note : Duplicate elements will not be removed.
*/
#include<iostream>
using namespace std;
void srt(int *p,int n)           //insertion sort
{
    for(int j=1;j<n;++j)
    {
        int key=*(p+j);
        int k=j-1;
        while(k>=0&&key<*(p+k))
        {
            *(p+k+1)=*(p+k);
            --k;
        }
        *(p+k+1)=key;
    }

}
int main()
{
    cout<<"Enter the size of both the arrays(separated by space) : ";
    int n; cin>>n;
    int m;cin>>m;
    int a[n],b[m];
    cout<<"\n Enter the first array : ";
    for(int i=0;i<n;++i)
        cin>>a[i];
    cout<<"\n Enter the second array : ";
    for(int i=0;i<m;++i)
        cin>>b[i];
    srt(a,n);
    srt(b,m);
    int j,k,l;
    j=k=l=0;
    int c[n+m];              //the resultant array.
    while(k<n||l<m)          //same logic for merging is used to merge arrays in merge sort.
    {
        if(a[k]<b[l])
        {
            c[j++]=a[k++];
        }
        else
        {
            c[j++]=b[l++];
        }
    }
    while(k<n)
    {
        c[j++]=a[k++];
    }
    while(l<m)
    {
        c[j++]=a[l++];
    }
    for(int i=0;i<n+m;++i)     //displaying the resultant array
        cout<<c[i]<<" ";
    return 0;
}
